# os-tools
Käyttöjärjestelmät ja systeemiohjelmointi, Syksy 2019, LUT University

Rami Saarivuori

Aarne Savolainen

UNIX UTILITIES

 my-cat on meidän oma versio Unixin cat -konsolikomennosta. Siinä annetaan argumentiksi tiedoston nimi ja käytännössä vain luetaan tiedosto ja tulostetaan konsoliin tulos.
 
 my-grep on meidän oma versio Unixin grep -konsolikomennosta. Siinä annetaan argumentiksi merkkijono ja tiedosto(t). Komento käy läpi tiedostot ja etsii, löytyykö annettu merkkijono tiedostoista. Tiedostoargumentin voi jättää myös pois, jolloin komennon jälkeen käyttäjältä pyydetään merkkijonosyöte, mistä sitten etsitään annettu merkkijono.
 
 my-zip on meidän versio zip -komennosta. käy läpi tiedoston ja tiivistää tiedostoa niin, että jos merkkejä on useampi peräkkäin, esimerkiksi "aaaa", tiivistetään se numeroon ja merkkiin, esimerkiksi "4a". Argumentiksi annetaan luettava(t) tiedosto(t).
 
 my-unzip on meidän versio unzip -komennosta toimii my-zipin vastakohtana, eli numero ja kirjain yhdistelmät laajennetaan peräkkäisiksi merkeiksi, esimerkiksi "4a" -> "aaaa".

UNIX SHELL

wish on meidän tekemä yksinkertainen Unix Shell komentokehote. Ohjelman käynnistyessä se ottaa vastaan korkeintaan yhden argumentin, joka on tekstitiedoston nimi, mistä se lukee käskyt. Ohjelmasuoritus loppuu, kun päästään tiedoston loppuun. Jos argumenttia ei anneta, aloittaa sen interaktiivisen tilan, missä käyttäjä voi antaa käskyjä ja ohjelma loppuu vasta käskyllä exit.
