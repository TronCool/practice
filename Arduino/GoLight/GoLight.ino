#include <Servo.h>
#include <Thread.h>
#define intervaltime 100
#define avgNum 20
#define AngleFeedback 0

//暗趋向1023，亮趋向0
int light1 = 0;
int light2 = 0;
int light3 = 0;
int light4 = 0;  
int joyX = 0;
int joyY = 0;

int avgL1[avgNum] = {0};
int avgL2[avgNum] = {0};
int avgL3[avgNum] = {0};
int avgL4[avgNum] = {0}; 
int avgX[avgNum] = {0};
int avgY[avgNum] = {0};
int indexOfAvg = 0;
float angleBase = 0;
float angleTop = 0;
int angleBaseFk=0;
int angleTopFk=0;

Servo servoTop;
Servo servoBase;
Thread myThread = Thread();
int bAuto = 0;
int autoCount = 10;//1-10  1快，10慢
int intrruptCount = 0;
int autoTimer = 0;
void setup() {
  // put your setup code here, to run once:
  String s = "start GoLight...";
  Serial.begin(115200);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);  
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);  
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  pinMode(A6,INPUT);
  pinMode(A7,INPUT);
  pinMode(3, INPUT_PULLUP);
  analogReference(EXTERNAL);

  delay(5000);//等待超级电容充满电，再启动，有助于系统稳定
  s = "init ok";
  Serial.println(s); 
#if AngleFeedback
  getFeedback();
  s = String(angleBaseFk)+ " | " + String(angleTopFk);
  Serial.println(s);   
  servoTop.attach(4); 
  servoBase.attach(5);   
  servoBase.write(angleBaseFk);
  servoTop.write(angleTopFk); 
#else
  servoTop.attach(4); 
  servoBase.attach(5); 
  servoBase.write(90);
  servoTop.write(90); 
#endif 
  attachInterrupt(digitalPinToInterrupt(3), buttonDown, RISING ); 
  delay(1000);
  myThread.onRun(threadAction);
  myThread.setInterval(intervaltime);
}
void buttonDown()
{
  intrruptCount++;
//  Serial.println("buttonDown");
}
void loop() {
  // put your main code here, to run repeatedly:
  if(myThread.shouldRun())
    myThread.run();
  detectLight();
  detectJoyStick();
  checkIndex();
}

void checkIndex()
{
  indexOfAvg++;
  if(indexOfAvg>=avgNum)
    indexOfAvg = 0;
}

int getAvgX()
{
  int sum = 0;
  for(int i=0;i<avgNum;i++)
  {
    sum+=avgX[i];
  }
  return sum/avgNum;
}

int getAvgY()
{
  int sum = 0;
  for(int i=0;i<avgNum;i++)
  {
    sum+=avgY[i];
  }
  return sum/avgNum;
}

int getLight(int n)
{
  int sum = 0;
  for(int i=0;i<avgNum;i++)
  {
    if(n == 1)
      sum+=avgL1[i];
    else if(n ==2)
      sum+=avgL2[i];
    else if(n ==3)
      sum+=avgL3[i];
    else if(n ==4)
      sum+=avgL4[i];
  }
  return sum/avgNum;  
}
void detectLight()
{
  light1 = analogRead(A0);
  light2 = analogRead(A1);
  light3 = analogRead(A2);
  light4 = analogRead(A3);  

  avgL1[indexOfAvg] = light1;
  avgL2[indexOfAvg] = light2;
  avgL3[indexOfAvg] = light3;
  avgL4[indexOfAvg] = light4;

  light1 = getLight(1);
  light2 = getLight(2);
  light3 = getLight(3);
  light4 = getLight(4);
//  String s = String(light1) + " | " + String(light2) + " | "+String(light3) + " | "+String(light4) + " | "+String(joyX) + " | "+String(joyY);
//  Serial.println(s);
}
void detectJoyStick()
{
  joyY = analogRead(A4);
  joyX = analogRead(A5);
  if(intrruptCount>1 && digitalRead(3)== HIGH)
  {  
    intrruptCount = 0;
    bAuto = !bAuto;
    if(bAuto){
      digitalWrite(9,HIGH);
    }
    else
      digitalWrite(9,LOW);
    Serial.println(bAuto);
  }
}

void moveArm()
{
  float accBase,accTop;
  float scale = 10.0;
  float mapValue = 10*scale;  
  angleBase = servoBase.read();
  angleTop = servoTop.read();
  accBase = (float)map(joyX,0,1023,-mapValue,mapValue)/scale;
  accTop = (float)map(joyY,0,1023,mapValue,-mapValue)/scale;
  if(abs(accBase)<=0.5)accBase = 0;
  if(abs(accTop)<=0.5)accTop = 0;
  if(abs(accBase)>=10)accBase = 0;
  if(abs(accTop)>=10)accTop = 0;
  if(accBase == 0 && accTop == 0)return;
  
  angleBase += accBase;
  angleTop += accTop;
  if(angleBase<0)angleBase = 0;
  if(angleBase>180)angleBase = 180;
  if(angleTop<0)angleTop = 0;
  if(angleTop>180)angleTop = 180;  

  servoBase.write(angleBase);
  servoTop.write(angleTop); 
  
  String s ="moveArm "+ String(accBase) + " | " + String(accTop)+ " | " + String(angleBase)+ " | " + String(angleTop);
  Serial.println(s);   

//  测试 反馈映射值
//  delay(100);
//  getFeedback();
//  String s = String(angleBase) + " | " + String(angleTop)+ " | " + String(angleBaseFk)+ " | " + String(angleTopFk);
//  Serial.println(s);   
  
}

void moveArmAuto()
{
  static int autoCount = 0;
  autoCount++;
  if(autoCount%2 == 0)
    digitalWrite(9,HIGH);
  else
    digitalWrite(9,LOW);
  
  float accBase,accTop;
  angleBase = servoBase.read();
  angleTop = servoTop.read();

  float scale = 10.0;
  float mapValue = 10*scale;
  int L1 = map(light1,1023,0,0,mapValue);
  int L2 = map(light2,1023,0,0,mapValue);
  int L3 = map(light3,1023,0,0,mapValue);
  int L4 = map(light4,1023,0,0,mapValue);
//  String s = String(L1) + " | " + String(L2) + " | "+String(L3) + " | "+String(L4);
//  Serial.println(s); 
  int left = L1+L2;
  int right = L3+L4;
  int top = L2+L3;
  int bottom = L1+L4;
  if(left<scale&&right<scale&&top<scale&&bottom<scale){
    servoBase.write(angleBase);
    servoTop.write(angleTop);
    return;//没有光线的时候不动
  }
  accBase = (left-right)/scale;  
  accTop = (bottom-top)/scale;

  if(abs(accBase)<1 && abs(accTop)<1)
  {
    servoBase.write(angleBase);
    servoTop.write(angleTop);
    return;//误差较小的时候不动
  }

  if(accBase>0)accBase = 1;
  else if(accBase<0)accBase = -1;
  if(accTop>0)accTop = 1;
  else if(accTop<0)accTop = -1;
    
  angleBase += accBase;
  angleTop += accTop;

  
  if(angleBase<0)angleBase = 0;
  if(angleBase>180)angleBase = 180;
  if(angleTop<0)angleTop = 0;
  if(angleTop>180)angleTop = 180;    

  servoBase.write(angleBase);
  servoTop.write(angleTop);
  String s = String(accBase) + " | " + String(accTop)+ " | " +String(angleBase) + " | " + String(angleTop);
  Serial.println(s);  
}

void threadAction()
{
  if(bAuto)
  {
    autoTimer++;
    if(autoTimer % autoCount == 0)
      moveArmAuto();
  }
  else
    moveArm();
}

void getFeedback()
{
  int volateBase[avgNum] = {0};
  int volateTop[avgNum] = {0};

  for(int i= 0;i<avgNum;i++)
  {
    volateBase[i]= analogRead(A7);
    volateTop[i]= analogRead(A6);
    delay(5);
  }
  
  //sort 小到大
  bool done = false;    
  int test = 0;                           
  while(done != true){             
    done = true;
    for (int i=0; i<avgNum-1; i++){
      if (volateBase[i] > volateBase[i + 1]){ 
        test = volateBase[i + 1];
        volateBase [i+1] = volateBase[i] ;
        volateBase[i] = test;
        done = false;
       }
    }
  }  
  done = false;
  while(done != true){             
    done = true;
    for (int i=0; i<avgNum-1; i++){
      if (volateTop[i] > volateTop[i + 1]){
        test = volateTop[i + 1];
        volateTop [i+1] = volateTop[i] ;
        volateTop[i] = test;
        done = false;
       }
    }
  } 
  int sumBase = 0;
  int sumTop = 0;
  for(int i = 5;i<15;i++)
  {
    sumBase += volateBase[i];
    sumTop += volateTop[i];
  }

  angleBaseFk = sumBase /10;
  angleTopFk = sumTop/10;

// 5伏下的映射
//  angleBaseFk = map(angleBaseFk,90,660,0,180);
//  angleTopFk = map(angleTopFk,116,600,0,180);

// 3.3伏下的映射
  angleBaseFk = map(angleBaseFk,145,720,0,180);
  angleTopFk = map(angleTopFk,142,817,0,180);
}
