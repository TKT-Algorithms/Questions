# [Soru 1A](https://www.programlamasorulari.tk/a-kategorisi/1A) - Şanslı Sayılar

## Bilgilendirme (Briefing)
- Soru İsmi: **Şanslı Sayılar**
- Soru Kodu: **1A**
- Hafıza Limiti: **256 mb**
- Süre Limiti: **1 Saniye**
- Soru Puanı: **Isınma sorusu (Puan Yok)**
- Yanlış Cevap Cezası: **Yanlış deneme başına 0 puan**

## Soru 
*Eğer bir sayının basamaklarında sadece 4 ve 7 varsa, o sayı şanslı sayıdır. 
Örnek olarak; 47, 744, 4 sayıları şanslı sayılardır fakat 5, 17, 467 sayıları 
şanslı sayılar değildir.* 

*Eğer bir sayı şanslı bir sayıya kalansız olarak bölünebiliyorsa o sayı yarı şanslı sayıdır.*

*Verilen sayının yarı şanslı olup olmadığını bulmanız gerekiyor.*

## Veri Girişi (Input)
    N tam sayısı n (1 ≤ n ≤ 1000)
    
## Veri Çıkışı (Output)
    Verilen sayı yarı şanslı ise "YES", değilse "NO" yazdırınız. (Tırnak işaretleri olmadan)
    
## Çözüm
Döngü ile 1'den n'e kadar olan sayıları şanslı sayı olup olmamalarına göre kontrol ederek, eğer şanslı sayı ise n sayısının o sayıya kalansız bölünüp bölünmediğini kontrol edebilirsiniz. Cevap, eğer en az bir tanesi bölünüyorsa "Yes", hiçbiri bölünmüyorsa "No" olacak.

Başka bir çözüm yöntemi olarak ise kendiniz bütün şanslı sayıları bir diziye koyup tek tek n sayısının o sayılara kalansız bölünüp bölünmediğini deneyebilirsiniz.

**Zaman karmaşıklığı:** O(n)

## Çözümler
* [PHP](php_answer.php)
* [Go](go_answer.cpp)
* [Rust](rust_answer.rs)
* [C++](cpp_answer.cpp)
* [C](c_answer.c)
