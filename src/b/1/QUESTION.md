# [Soru 1B](https://www.programlamasorulari.tk/b-kategorisi/1B) - Karanlık Cadde Kalmasın

## Bilgilendirme (Briefing)
- Soru İsmi: **Karanlık Cadde Kalmasın**
- Soru Kodu: **1B**
- Hafıza Limiti: **256 mb**
- Süre Limiti: **1 Saniye**
- Soru Puanı: **1200**
- Yanlış Cevap Cezası: **Yanlış deneme başına -200 puan**

## Soru 
*Alperen gece geç saatlerde, sokak lambalarıyla aydınlatılmış, **m** uzunluğunda
düz bir cadde boyunca yürüyor. Koordinat sistemini, caddenin başlangıcı **0** 
noktasına ve sonu **m** noktasına karşılık gelecek şekilde düşünün. **i.** sokak 
lambası **ai** noktasında bulunur. Bir sokak lambası, caddede ondan en fazla **d** 
uzaklıktaki tüm noktaları aydınlatır. (**d** bütün sokak lambaları için ortaktır.)*

*Sokak lambalarının tüm caddeyi aydınlatması için gereken minimum ışık yarıçapı (**d**) kaçtır?*

## Veri Girişi (Input)
    İlk satır iki tam sayı içerir. n, m (1 ≤ n ≤ 1000, 1 ≤ m ≤ 109). Sokak lambası sayısı ve cadde uzunluğu.
    
    Sonraki satır n tane tam sayı içerir. ai (0 ≤ ai ≤ m). Aynı noktada birden fazla sokak lambası olabilir. Sokak lambaları caddenin başında veya sonunda olabilir.
    
## Veri Çıkışı (Output)
    Tüm caddeyi aydınlatmak için gereken minimum ışık yarıçapını (d) yazdırın. 
    
    Mutlak veya göreceli hatası 10⁻9'u aşmazsa cevap doğru kabul edilecektir.

## Çözüm
Sokak lambalarını küçükten büyüğe olacak şekilde sıralayın. Lambaların arasındaki uzaklıklardan en büyüğünü bulun. Buna enBüyükFark diyelim. Bunun dışında caddenin başını ve sonunu da düşünmeniz gerekiyor. İlk lambanın caddenin başına uzaklığına caddeBaşı diyelim. Son lambanın caddenin sonuna uzaklığına da caddeSonu diyelim. 

Cevabımız max(EnBüyükFark / 2, caddeBaşı, caddeSonu) olacaktır.

**Zaman karmaşıklığı:** O(n log n) 

## Çözümler
* [PHP](answer.php)
