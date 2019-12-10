# os-tools
Käyttöjärjestelmät ja systeemiohjelmointi, Syksy 2019, LUT University

*Rami Saarivuori*

*Aarne Savolainen*

### UNIX UTILITIES

 my-cat on meidän oma versio Unixin cat -konsolikomennosta. Siinä annetaan argumentiksi tiedoston nimi ja käytännössä vain luetaan tiedosto ja tulostetaan konsoliin tulos.
 
 `mycat file1 [-file2] ... `
 
 my-grep on meidän oma versio Unixin grep -konsolikomennosta. Siinä annetaan argumentiksi merkkijono ja tiedosto(t). Komento käy läpi tiedostot ja etsii, löytyykö annettu merkkijono tiedostoista. Tiedostoargumentin voi jättää myös pois, jolloin komennon jälkeen käyttäjältä pyydetään merkkijonosyöte, mistä sitten etsitään annettu merkkijono.
 
 `my-grep merkkijono [file1] [file2]...`
 
 my-zip on meidän versio zip -komennosta. käy läpi tiedoston ja tiivistää tiedostoa niin, että jos merkkejä on useampi peräkkäin, esimerkiksi "aaaa", tiivistetään se numeroon ja merkkiin, esimerkiksi "4a". Argumentiksi annetaan luettava(t) tiedosto(t).
 
 `my-zip file1 [file2] ...`
 
 my-unzip on meidän versio unzip -komennosta toimii my-zipin vastakohtana, eli numero ja kirjain yhdistelmät laajennetaan peräkkäisiksi merkeiksi, esimerkiksi "4a" -> "aaaa".
 
 `my-unzip file1 [file2] ...`

### UNIX SHELL

wish on meidän tekemä yksinkertainen Unix Shell komentokehote. Ohjelman käynnistyessä se ottaa vastaan korkeintaan yhden argumentin, joka on tekstitiedoston nimi, mistä se lukee käskyt. Ohjelmasuoritus loppuu, kun päästään tiedoston loppuun. Jos argumenttia ei anneta, aloittaa sen interaktiivisen tilan, missä käyttäjä voi antaa käskyjä ja ohjelma loppuu vasta käskyllä exit.

Wishimme voi suorittaa ohjelmia. Wishiimme kuuluu myös kolme sisäänrakennettua käskyä: cd, path ja exit. Exit ei ota mitään argumentteja, se vain tyhjentää polkulistan ja vapauttaa muistin, ja lopettaa ohjelmasuorituksen. Cd vaihtaa käsiteltävää työkansiota ja ottaa argumentiksi uuden kansion polun. Path vaihtaa polkua, mistä suoritettavia ohjelmia etsitään, ja ottaa argumentiksi uuden polun. Pathille voi myös olla antamatta polkua, jolloin se luo tyhjän polkulistan, jolloin käskyjä ei voi suorittaa, koska komentokehotteemme ei tiedä, mistä ohjelmaa pitäisi etsiä.

### KERNEL HACKING

Loimme oman systeemikutsun `getcount()`, joka laskee, kuinka monta kertaa tiettyä systeemikutsua on kutsuttu kernelin suorituksen aikana ja palauttaa lukumäärän. 

`int getcount(int x, int y)`

Se pyytää kahta kokonaislukuargumenttia: ensimmäinen `(int x)` on joko 0 tai 1, joka kertoo nollataanko laskuri (0 = ei, 1 = kyllä) ja toinsena argumenttina `(int y)` annetaan laskettavan systeemikutsun ID:n (ID:t löytyvät syscall.h-tiedostosta, esim. sys_read ID on 5, jonka se ottaa oletuksena). Jos toinen argumentti on 0, laskettavaa systeemikutsua ei vaihdeta.
Kansiossa on myös testeissämme käytetty ohjelma, [testi.c](xv6-sys/testi.c). Ohjelmaa voi käyttää xv6 käyttöjärjestelmässä lisäämällä se Makefileen.

Projektin osissa käyetyt lähteet ovat kommentoituna suoraan lähdekoodiin.
Kernel Hacking osan lähteet:
https://stackoverflow.com/questions/21653195/xv6-add-a-system-call-that-counts-system-calls?rq=1

https://medium.com/@viduniwickramarachchi/add-a-new-system-call-in-xv6-5486c2437573
