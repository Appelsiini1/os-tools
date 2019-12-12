# os-tools
***Käyttöjärjestelmät ja systeemiohjelmointi, Syksy 2019, LUT University***

*Rami Saarivuori*

*Aarne Savolainen*

### 1. UNIX UTILITIES

`mycat file1 [file2] ... `

 [my-cat](my-cat.c) on meidän oma versio Unixin cat -konsolikomennosta. Siinä annetaan argumentiksi tiedoston nimi ja käytännössä vain luetaan tiedosto ja tulostetaan konsoliin tulos.

`my-grep merkkijono [file1] [file2]...`

 [my-grep](my-grep.c) on meidän oma versio Unixin grep -konsolikomennosta. Siinä annetaan argumentiksi merkkijono ja tiedosto(t). Komento käy läpi tiedostot ja etsii, löytyykö annettu merkkijono tiedostoista. Tiedostoargumentin voi jättää myös pois, jolloin komennon jälkeen käyttäjältä pyydetään merkkijonosyöte, mistä sitten etsitään annettu merkkijono.

`my-zip file1 [file2] ...`

 [my-zip](my-zip.c) on meidän versio zip -komennosta. käy läpi tiedoston ja tiivistää tiedostoa niin, että jos merkkejä on useampi peräkkäin, esimerkiksi "aaaa", tiivistetään se numeroon ja merkkiin, esimerkiksi "4a". Argumentiksi annetaan luettava(t) tiedosto(t).
 
`my-unzip file1 [file2] ...`

 [my-unzip](my-unzip.c) on meidän versio unzip -komennosta toimii my-zipin vastakohtana, eli numero ja kirjain yhdistelmät laajennetaan peräkkäisiksi merkeiksi, esimerkiksi "4a" -> "aaaa".
 

### 2. UNIX SHELL

`wish [command] (> file)`

[wish](wish.c) on tekemämme yksinkertainen Unix Shell komentokehote. Ohjelman käynnistyessä se ottaa vastaan korkeintaan yhden argumentin, tekstitiedoston nimen, josta se lukee suoritettavat käskyt. Ohjelmasuoritus loppuu, kun päästään tiedoston loppuun. Jos argumenttia ei anneta, aloittaa sen interaktiivisen tilan, missä käyttäjä voi antaa käskyjä ja ohjelma loppuu vasta käskyllä `exit`.

Wishimme voi suorittaa ohjelmia. Wishiimme kuuluu myös kolme sisäänrakennettua käskyä: `cd`, `path` ja `exit`. 

`exit` ei ota mitään argumentteja, se vain tyhjentää polkulistan, vapauttaa muistin ja lopettaa ohjelman suorituksen. 

`cd` vaihtaa käsiteltävää työkansiota ja ottaa argumentiksi uuden kansion polun. 

`path` vaihtaa polkua, mistä suoritettavia ohjelmia etsitään, ja ottaa argumentiksi uuden polun. `path`-komennolle voi myös olla antamatta polkua, jolloin se tyhjentää polkulistan. Tällöin käskyjä ei voi suorittaa, koska komentokehotteemme ei tiedä, mistä ohjelmaa pitäisi etsiä.

Muut kuin sisäänrakennetut käskyt yritetään suorittaa `path`-komennolla annetuista poluista. Oletuksena etsitään kansiosta `/bin/`. Komennoille voi antaa normaaliin tapaan argumentteja. Tulostuksen voi ohjata tiedostoon käyttämällä `>` merkkiä ja kirjoittamalla kohdetiedoston nimen merkin jälkeen.

### 3. KERNEL HACKING

Loimme oman systeemikutsun `getcount()`, joka laskee, kuinka monta kertaa tiettyä systeemikutsua on kutsuttu kernelin suorituksen aikana ja palauttaa lukumäärän. 

`int getcount(int x, int y)`

Se pyytää kahta kokonaislukuargumenttia: ensimmäinen `(int x)` on joko 0 tai 1, joka kertoo nollataanko laskuri (0 = ei, 1 = kyllä) ja toisena argumenttina `(int y)` annetaan laskettavan systeemikutsun ID:n (ID:t löytyvät syscall.h-tiedostosta, esim. sys_read ID on 5, jonka se ottaa oletuksena). Jos toinen argumentti on 0, laskettavaa systeemikutsua ei vaihdeta.
Kansiossa on myös testeissämme käytetty ohjelma, [testi.c](xv6-sys/testi.c). Ohjelmaa voi käyttää xv6 käyttöjärjestelmässä lisäämällä se Makefileen.

Projektin osissa käyetyt lähteet ovat kommentoituna suoraan lähdekoodiin.
Kernel Hacking osan lähteet:
https://stackoverflow.com/questions/21653195/xv6-add-a-system-call-that-counts-system-calls?rq=1

https://medium.com/@viduniwickramarachchi/add-a-new-system-call-in-xv6-5486c2437573
