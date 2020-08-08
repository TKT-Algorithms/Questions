# [Soru 1E](https://www.programlamasorulari.tk/e-kategorisi/1E) - StockTicTacToeFish

## Bilgilendirme (Briefing)
- Soru İsmi: **StockTicTacToeFish**
- Soru Kodu: **1E**
- Hafıza Limiti: **256 mb**
- Süre Limiti: **Her hareketin en fazla 5 saniye sürmesi gerekiyor.**
- Soru Puanı: **2500**
- Yanlış Cevap Cezası: **Yanlış deneme başına -350 puan**

## Soru 
*Tic Tac Toe oyunu ve bu oyunu oynayan yapay zeka algoritması yazmanız gerekiyor.*

## Kurallar
 * Oyuna "X" başlar.
 * Oyun tahtasında satırlar için {a, b, c}, sütunlar için {1, 2, 3} kullanılacak. (Örnek: b2)
 * Oyun tahtası için 2 boyutlu char dizisi kullanılacak.
 * Oyun tahtası her hamleden sonra yazdırılacak.
 * Her hamleden önce kimin hamlesi olduğu ve o hamleyi yapacak kişinin kullanacağı karakter yazdırılacak.
 * Yazdığınız AI'a testler uygulanacak. Kaybettiği her %1 oyun için 200 puan düşürülecek. Eğer bu %10'u geçerse soru yanlış sayılır.
 
## Ek Görevler
 1. Yanlış bir giriş yapıldığında girdiği şeyi düzeltip tekrar girmesini söyler. **(50 puan)**
 1. Kullanıcı büyük-küçük harf farketmeksizin giriş yapabilir. X yerine x, b2 yerine B2 gibi. **(50 puan)**
 1. Oyuncunun istediği karakteri seçmesine izin verir ve yapay zeka karakter farketmeksizin çalışır. **(200 puan)**
 1. Yapay zeka kazanması ya da berabere kalması için kullanacağı stratejilerden en kısasını seçer. **(200 puan)**
 
## Örnek
![Tic Tac Toe Örnek](https://i.hizliresim.com/MA9uI5.png)
 
## Çözüm
Bu soruyu çözmek için bir karar ağacı kullanabilirsiniz. Bunun için de Minimax Algoritması oldukça işimize yarıyor.

En basit olarak Minimax Algoritması, ihtimaller havuzu içinden en iyi ve en kötü senaryoları değerlendiren bir karar verme algoritmasıdır.  

> https://wikipedia.org/wiki/Minimax  

**Zaman karmaşıklığı:** O(bM) b = mümkün olan hareketler, m = ağacın maksimum derinliği 

## Çözümler
* [PHP](php_answer.php)
* [Python](python_answer.py)
* [CPP](cpp_answer.cpp)
