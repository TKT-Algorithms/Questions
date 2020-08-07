# [Soru 1C](https://www.programlamasorulari.tk/c-kategorisi/1C) - Krallığın Boyacısı

## Bilgilendirme (Briefing)
- Soru İsmi: **Krallığın Boyacısı**
- Soru Kodu: **1C**
- Hafıza Limiti: **1024 mb**
- Süre Limiti: **2 Saniye**
- Soru Puanı: **1500**
- Yanlış Cevap Cezası: **Yanlış deneme başına -250 puan**

## Soru 
*Yüzyıllar önce odasından sıkılan ve boyatmak isteyen bir kral varmış. Bir sürü boyacı odayı boyamayı denemiş ama kral 
hiçbirinden hoşlanmamış. Bu yüzden bir yarışma başlatmış. Odasını boyayanlardan en beğendiğine hem altın ödülü verecek, 
hem de onu krallığın boyacısı yapacakmış.*

*Alper bu yarışmayı duyunca hemen işi gücü bırakıp krallığa gitmiş ve başvurmuş. Ödülü çok istiyormuş. Sırası gelene 
kadar ne yapacağını düşünmüş.*

*Sırası geldiğinde aklında bir fikir varmış. Onu yapmaya karar vermiş ve kralın beğeneceğine eminmiş. Hemen boyamaya 
başlamış. Her bir duvara kralın hayatı boyunca yaşadığı önemli anlardan parçalar eklemiş. Bu şaheseri yapması birkaç 
gün sürmüş fakat kral son halini gördüğünde çok hayran kalmış ve onu krallığın boyacısı yapmış. Altın ödülünü de vermeyi 
ihmal etmemiş. Ona hazineye girmesini, tam olarak X adet kırmızı altın kutusu ve Y adet **mavi** altın kutusu almasını söylemiş.* 

*Hazinede **A** adet **k1**, **k2**, **k3**, **... kA**  ağırlığında kırmızı altın kutusu,  **B** adet **m1**, **m2**, **m3**, **... mB** ağırlığında mavi altın
kutusu ve **C** adet **r1**, **r2**, **r3**, **... rC**   ağırlığında renksiz altın kutusu varmış.* 

*Kutuları seçmeden önce renksiz kutuları boyamasının mümkün olduğu aklına gelmiş. Renksiz kutuyu kırmızıya boyarsa 
kırmızı, maviye boyarsa mavi olarak sayılacakmış.*

*Alper **0 ya da daha fazla** kutu boyayarak toplam ağırlıkları **maksimum** olacak şekilde kutuları seçmiş.*

*Alper'in seçtiği kutuların toplam ağırlığı kaçtır?*

## Veri Girişi (Input)
    İlk satır beş tam sayı içerir. X, Y, A, B, C (1 ≤ X ≤ A ≤ 105, 1 ≤ Y ≤ B ≤ 105, 1 ≤ C ≤ 105). Alması gereken kırmızı altın kutusu sayısı, alması gereken mavi altın kutusu sayısı, hazinedeki kırmızı altın kutusu sayısı, hazinedeki mavi altın kutusu sayısı ve hazinedeki renksiz altın kutusu sayısı.
    
    İkinci satır A adet tam sayı içerir. k1, k2, k3, ... kA  (1 ≤ ki ≤ 109). Kırmızı altın kutularının ağırlıkları.
    
    Üçüncü satır B adet tam sayı içerir. m1, m2, m3, ... mB (1 ≤ mi ≤ 109). Mavi altın kutularının ağırlıkları.
    
    Dördüncü satır C adet tam sayı içerir. r1, r2, r3, ... rC (1 ≤ ri ≤ 109). Renksiz altın kutularının ağırlıkları.
    
## Veri Çıkışı (Output)
    Alper'in seçtiği kutuların toplam ağırlığı.
   
## Çözüm
X adet kırmızı altın kutusundan daha fazla kırmızı altın kutusu seçilemeyeceği için, en ağır X kırmızı altın kutusu dışındaki diğer kutuları hesaplamamızın dışında tutabiliriz. Aynı şekilde Y adet mavi altın kutusundan daha fazla mavi altın kutusu seçilemeyeceği için, en ağır Y mavi altın kutusu dışındaki diğer kutuları hesaplamamızın dışında tutabiliriz.

Bu işlemi yaptıktan sonra, kalan kutulardan nasıl X+Y kadar kutu seçersek seçelim doğru boyama işlemlerini yaparak X kırmızı ve Y mavi kutu seçebiliriz.

Bu yüzden kalan kutulardan en ağır X+Y kutuyu seçersek toplam ağırlıkları maksimum olacak şekilde kutuları seçmiş oluruz.

**Zaman karmaşıklığı:** O(n log n) 

## Çözümler
*Henüz çözüm yok*
