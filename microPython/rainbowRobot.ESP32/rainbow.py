# 以下彩虹屁数据用36进制数表示汉字，编号序号对照表，编号是36进制数，1 - 767 对应 01 - lb
base36 = dict(list(zip(list('0123456789'), range(10))) + list(zip([chr(i) for i in range(97, 123)], range(10, 36))))

rainbow = [
    "1tes0eaka8cicfcrla71c33kjvlbgi8nes0eak1tlb",
    "8n53bh5n5uedkklakk4fed2fla4u1e1pa422ed1tlb",
    "8nab010djebd12la8nedbdla07j46wab1tlb",
    "juayhw7ydzabdd1tlb",
    "1t3u6ccqcb4klaj8b88n1c6wgobvchddc351lb",
    "8nedesc90724jzlabyc3clci1e8n5ilb",
    "1m8ka268cn2s925xjihuedctabb58dlb",
    "5e8niieaed5c5f051tab8nai4feddrdwlb",
    "155u1tab0n6lb9hq0706ed64en4plb",
    "1t6waba9kwla07294n3bet8ned80lb",
    "8n07eyjkbjjv4zedabicla8n4led2hab1tlb",
    "kr06ay8g1tlahw7y012zjogd647y074889i3lb",
    "dd8ih4ab3j2yctla8n8g0t1t3j0v2ylb",
    "h4cm8d07go6rflla8kdd7yah5qed12ab8nlb",
    "iaa8a864ened12016habc1akhuj41tedeseulb",
    "1t2a5ngued2ye5g0laab8n01e1jvaik3edjm0deb5ulb",
    "12e107658i0u3j0k2i0nla3r0f010vlb",
    "1tab8n6ffc72ajjvedgy5pe1b1lb",
    "ak12k68na95uab140ila0wab8n8giofk01bgjihu1tlb",
    "5ej85242ed120ak7la8n8g4u1ten01enbvjalb",
    "iaa8a87w10ed12la016hc1hu1tedeseulb",
    "46htbpbg018g341tlae14t1x2dct0s8i0jlb",
    "l77i7rhj5e0xjvla1t7i7rhj5e80jvlb",
    "1tab8nj801e1461jjihu01bged8e53lb",
    "3mjfgi7k0764la8q1b8n7li31t53bh8n34gglb",
    "1teyjk48dded33f9ab140i4il81ted4e69lb",
    "ak659l9kedf4jxab6r2t3hazla8ned800o46abap4h1tlb",
    "7baoa9kwgo6r1tcpb5d0la953ud3iwlacteieeabb58dlb",
    "1t07koht5mc8la590f1tdn3o0s010d2yg1lb",
    "kw2f07651tes7jla5u5f073w1t86jvlb",
    "07648i89la01076u808x8qaked53bhjof0341tix050slb",
    "53bh1tlafj99gid5d1la01a08qak3q3v256y8qaklb",
    "5n6bke6hlaar123mfr3a2rlb",
    "1ted4e69laab8nhuj4aiezed8di7lb",
    "931n0s1tla8n6w9bak0s9u0d0ae5lb",
    "eh8i1b71c3la71c3073w1tlb",
    "8n6wj8b801itiviviuiu9met6ua8a8is341t80jv51lb",
    "7bao155uedbdjvaklajr62hlfqhahchiaxj7ak1tlb",
    "hkd7dh1bfa0fijla1mj7ab8gg51t7w5q7w5qddlb",
    "1takc1akk934d4d6ed4sjklajmab8ned805e0f1tdbd4lb",
    "1tfnekab12fpgd6ced5zjdlb",
    "1tab8ned5ueola8nedcgcwla8nedgubo07colb",
    "dd8dab011d7y1oed0ula48abdd1t8n17ayc1ak2y6qlb",
    "65b00ae5eoed0753bh1tlajm0ae56wab8ned9r120slb",
    "1tab8neddrdw1tab8nedh2la6ul3ed8di846g58c5ylb",
    "jihu1tedjm5ulabfh27mct3n71lb",
    "6og51t2h6e6geddd4ugt5v44gubv3ded8985lb",
    "8nht281t7h5xed6ud9la0f1t8tihbdjved8bl7lb",
    "71c3jakbla12k7d2cylaa001ab1tlaa00107ab1tlb",
    "ho1td0ilj4edal3x5bla6wabe0e05b4w50l9",
    "l65u5t5dab1tlaeg0ah6kiab1tla8i0e120oab1tlb",
    "8nakd0h280la53bhbp010d1tlb",
    "4dab03dhe1k3ed4tdvla0f1p1t6wj80i64enlb",
    "8a8neseuhj071n800ula019i341ted4e696wcpb5c6culb",
    "8gdi1ted8rla17803bla3444fala346y5xlb",
    "8n8g8n1j7m668g851tla48ab8n31318sjihu0s1tlb",
    "1t7ii95eck6i05b3la590f1tab6iig4plb",
    "53bh1t78g3ipj40c2yjylaa0c59n5851lb",
    "055u5v27800sla1t010dkj0e0s033k1hd0lb",
    "dngtinj4h3h3hdhdla081t4dhn8sak0s2flb",
    "a86vab6e6ged91kwlagi1tab6e6g0eaigd64ede14t1olb",
    "6r1ted53bh4807abfe652maylaabhgid780hlb",
    "i55q0u8dla8nabgt1tiola8s7m668gedlb",
    "a1d7joht42ggla076501io4klb",
    "3uhu1tedit05lajbkwjoabe0edlb",
    "hy08494bla6f0578gplah1h0ha97lb",
    "8ndd1tdz0waaa2lae63ia6aplb",
    "1t0o5v64en0s4kl9648g11gt5e1tixj38j411tedl239lb",
    "8429bk3z9tl2394kla1tj80dceix2dctl239ed6m1ilb",
    "8n016hhtff5e1t8qd5dded0ae5jvk4k43z2flb",
    "acab2h0ae5edacla6fab9cg51ted6flb",
    "2iksdtdu5vfu0sla8n468gi1641tlb",
    "5e01iolal4bshfef0oab9q0ulb",
    "8n0f1tgf71iq73laa080enkwadlb",
    "12cih8h8laitjfjljllabzcj12cxjvlajihu1teo64lb",
    "4yak1ted2fj1lago2acwj47173edhhknlb",
    "15aca3d0evhwlaa65uio7hj7htg7g853bh1tlb",
    "1tab8ne88fe1cc0e4y01edh6kibd8glb",
    "1tedeseujvaka8j25tcila1tabho057c4oj4ed6d68lb",
    "0ak703dheeh5la1ta6ei7pgmed27dd6wab9siklb",
    "8n8ge28r9gjvft9jedcpafla8u1na42fjv7zfhedbeb8lb",
    "1tix05ak8n1qe1ed4sjklb",
    "828o0782la07ir1b8m0fla9w0s8n8g1teddve3lb",
    "03dheeakhpe9lajmab2fj9ayed5f9ylb",
    "8nai5ted7gf6la6wab1tg5ed5e0llb",
    "cp71iybufva83k03073w1temes3m2ylb",
    "8n6r1teddd6w2a9896au0571izizd1d1lb",
    "1teoab0dkf0sgrgrgrgrgl1b5p01a0ab5led6udo4rlb",
    "aqg32ci5la9pgtdj3353bh1tla07648i890slb",
    "iadfksabda5rlaia6j5eab5weplaiaeoedab8g1tlb",
    "1ted6nkv7ii9e4ib4c6x9xfy7slb",
    "33882fkdcwk3la8n1j5e1tix9zla4x88eb3zh3h3lb",
    "8n53bh1tlafk0145ab26edlafk0v450oab26edlb",
    "7bao2u7f4fla47ju8ned07abk8jylagiab1ted5kktlb",
    "65b012fp0oak6z79edi8la8nenhu1tgk6h1j9lioaylb",
    "ds6j0ae5012z78eyed6khv6a5ejvla8nai53bh1tlb",
    "1t178nks37g9g9inj4eda422la5ubtjo42aeanlb",
    "1tdj3364ladj33cpb5ladj33247ylb",
    "bpbg1t3zal3x5bla8n6w3v340s9d8raubckseda422lb",
    "155u5ubteo64la8nakd08g1t0slb",
    "1t481b07fagc2h0ae5la1m1tht07gv7y8nlb",
    "590fak1tla8q1bak0s4faylb",
    "ia07cn0f140idd1tla1m1t6wab8n07dd3312eddve3lb",
    "1tab8nj801e1461jjihu01bged8e53lb",
    "65b01tab0y7tedfrlajm8n6w7r1y8z1t6u6uedfrfzlb",
    "53bh1t3v2v3vgdla3ve03vd1lb",
    "8n6r2ee1ed53bhla1pbkjy8i0v69lb",
    "h501d0c12jfsla8ne0lb",
    "7qbu043k8n464001dxla1t6wabjm0ddxlb",
    "840med9y7oak7w5qlaaiek9hedla6wabhu341tlb",
    "1t075e8rj3la8r01ek8g1tlb",
    "ib1ti0eo4hkw6c6c870i7u8n86jvk0lb",
    "8nedj5bt4634jihu1tla9h06ayedla6whtgt773c390slb",
    "gt178n1celjila1tab8neb5ul55r07heeda8lb",
    "5qen1t01es6w80iyla9b9301066wc2khlb",
    "1tab8ned0b3nhs3hlagnj4012zh371cabulb",
    "8g4u1tiala155ued0x4u1tlajo3j2y48ddlb",
    "1teq0106esla6wgfka0s8n80jveda95nf72qlb",
    "j8ab140ig60a6u48ddla870ienjoab8n53bhedfp5hlb",
    "1t2n07ayla8nht06kl0slb",
    "8n0fedab8ned80lb",
    "a4gu15a2la1t16ab8ned2fgzlb",
    "8ngbed3v07abdd8dla8ngbedab1t50l9",
    "590fak1tlajb155uedhea2johw7y48ddlb",
    "1tab155uj80icv10laj7abbp5ujoj80icv1050lb",
    "8n6j5e53bh1tjm01ixi73ela8ndd1t2add01kyi701b8lb",
    "8x1tedgjat23g58nla4l8nia6y72ajed8di8lb",
    "07htk68n80jvakc1ak1tla8n1q2f0ejoab1tlb",
    "1tab8ncwcw1qe1jv0ja03ykuedbd8glb",
    "d5dd4894cwk372ajlb",
    "e1cc7wi13tlaj7641t5s48ddlb",
    "05j06848goabf3jrkx9vla01hu341t6w7m807y2oc7lb",
    "0ae5kohti4i4jkdvla1m8nai27801tlb",
    "goi28ndm60edlakf0s5tkk6w46ak1t0slb",
    "8n6tbvja830wgt77la91a88paj604hdv8g4u1tlb",
    "155ukf0s53bh1tla8n140i33ed0u0o0728lb",
    "1teder0eak7175c3cdlagnj48nhng3it05ed012z07avlb",
    "1tia1t02d01jaylajm8n6w1j01ekfl7vlb",
    "kw4ua2afla1a128k8ibvjacc063ulb",
    "1tenioay642a7w644alb",
    "1ted1vgq7ii9356h0f5a6m01fx6idhlb",
    "1e631c5qcv10laaq3w1texijlb",
    "1teyjkedla1tab8n8t0721edd5ddlb",
    "65b048dd481b2yflfxla1t016habdjfllb",
    "aqi6ec0vf82jlaa1hugx12la800egtbm2lhbkz0rlb",
    "53bhab01ap015oladd1tab17803b3444falb",
    "4688j86v0a5455la4yak1t86ab8n4y016fjh0k8qlb",
    "jihu1tlaab8qak9q0ued7m66lb",
    "8x6r1ted53bhjs8mjplaecjv5peddpjojt0slb",
    "07ht2n9o5x3z0slaay9o8n4kl9",
    "ddab749alaabft7plaab67gelaabfg6hlaab1tlb",
    "a3eyjk6wg51tfr0sla1t70d75e8n80jv9e0rlb",
    "07hti28nenhu1tla07d7hu01bg53bh01bglb",
    "1t06bgitj4lago07go073gin8nedl1la7d8ninlb",
    "aj10ab8n8yedf17ala0cksjoabbdhu1tlb",
    "1tgq05ed07abbxbugiabdrdwh2edkpbulb",
    "1ti28neyjklac0jc0w1tlaab8n4t6hed0ulb",
    "8n842p072w8di80sla468ghu1t01kslb",
    "155rbyc30kcsla46108nedjqc4czla46d88ned800512lb",
    "fk01bgen346e6glaab4u1t57eiel6reda422lb",
    "j6asghimlaj61tghe0lb",
    "ci7jajab5u05ajlaes3712ab800512lb",
    "06j0688n8gbr8qak12joa3d0jihu1tlad74fkg1t01e1lb",
    "904q0106la8n42800sla155ued8nbraa5uah53bh1t0slb",
    "71c3jakbla12k7d2cya001ab1tlaa00107ab1tlb",
    "8neoedkh2gdd8d0slabp5ujoj80i803blb",
    "ak12ia1t0764enla8n0vi807iag5180q0s466sejdkl9",
    "8n6tbvja830wgt77la91a88paj604hdv8g4u1tlb",
    "aj10ho56f20s428ma8a8la1t6whj5ecw5ueda82fjvlb",
    "8nab1tedhr060kgslady8k20kyf9gslb",
    "k505esla8jhw9u0d0ae54638061ted5kktlb",
    "1t07ab1h0mgdla1tab8ned2f50lb",
    "1ge1eeh5la46ak1tabhahc4s2bedlb",
    "ai64edddabkg1llaai64edkwadab081t4denlb",
    "a9kw2ngd0obr07051tedfhlac1huj41ted12071ja60slb",
    "5953bh1tla23et1ted2flaewhu0s17aqhuj4ed0ae5lb",
    "0a0u650pla8n27dd1tj80145lb",
    "esjvjoab1tla1303a8j2dl073wlb",
    "65b0ak015u8n1c2y7m0slajmec7f0k4f8n3ubdjv8w1tlb",
    "1thtab8k8ila8n6wbvja6a5elb",
    "1b4f01ioe1010d6i6ila016m0443ladedeai09lb",
    "hu341tla8ned3oakbi6wipb70slb",
    "65b01tay0slaa95u6w481bla07e2ay0slb",
    "338llaaj100obl5e5tcib45ljch8lb",
    "15a2ke6hlaar122hfr3u2rlb",
    "155uioayenhu5vkc2fla80jvak01d0l02klb",
    "1b800u06jpa75tjtla5tjt4fa74g800ula800u2hab1tlb",
    "1tab48dded616dla8nab48ddlb",
    "1ted4e69laab8nhuj4aiezed8di7lb",
    "8ned8kaoab015rag6pla07d7931t0ohnlb",
    "32jg07ey1265dqla2njg78ab8i0e12lb",
    "3p1u8n7pdggwdcla0o7bao5e1tesjv8nabai64ed6iiglb",
    "a6a6a378eca0f581la27271tab01eckm01lb",
    "03dheeak074dlabr65la8nak1tlagi181cc1aklb",
    "7bao1tabkqa9la0oabgg1llb",
    "8ned80aba5jwedl3la5e1tedesjv8w340s5ufdlb",
    "5r7ecmc0jvla1t6wab8neda8lb",
    "1tf97y05012zgd64la1t6wabgd64arixlb",
    "1tfh0106la8ned806w3b0slb",
    "1t6r8ned64la94j40s8nj43u8qg33sj4eda95nf72qlb",
    "aa5ubw1rla1ria8n1ca0gala8nds5e071z1rla461z1tlb",
    "en7107ab71laenci07abcilaen1tab8n6iiglb",
    "65b01tj47y077gf6la8n8q28ed012z8sab7x3flb",
    "ji3453bhed126whti0eo53bhlb",
    "icgok2j41tj80i64ed19614rl865b0k2j4la0765gtawlb",
    "1t870ik38mj8b8l8fi4b8n2hjn8giflb",
    "8ndd18laab590f182add8darixi9akedb868lb",
    "53bh1ted01ecbnla6wjo0zg58n4klb",
    "6e6g1ge14vh50ela1t6wabjm01a83md0ed48ddlb",
    "57ci2ihbla3kf7030ala8n4653bh1tlb",
    "5rabczcy071fla1tabddguby8hlb",
    "336r8n1ue2gd12hzla4j308n1j6thz6whzlb",
    "enhu1tjm0136la8jhw2a4a9f0s1j7zfhedfrb0lb",
    "enet1tla761sa2ed063lh9johte0052u2ylb",
    "8n8k8igv7n012zla1b8g851tg2bm01e1lb",
    "140iab806fla1t6wabfmbblb",
    "1t1b0f8n2xb2072gla8n1b0f1tecbq071wlb",
    "ew1tj80cfo2iedbt5gla078v5j6wam1tl9",
    "5ubt075s64c12jfsla1t5s646whn51lb",
    "e1cc07abd5hm3bcwla1m1tbvjaab8ned0ghxlb",
    "8k1t1bcr6u4mfbla1b1k5tg46zlb",
    "hsfwb64ue7h7la5cie4ukzk1hila8n53bhed124u1tlb",
    "0f1tla3k3k0303jjlb",
    "j80a058qaked0ujo07go8j4dix4146go901bcpb5lb",
    "53bh8nao4h335la41the5e8nix05edei2flb",
    "0aedjoba68073w1te0gdlb"
]
