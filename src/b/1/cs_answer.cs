using System;

namespace algoritma1B
{
    class Program
    {
        static void Main(string[] args)
        {
            int lambaSayisi = 0, caddeUzunlugu = 0;
            double gecici, sonuc = 0;
            string[] _cevap1 = new string[2];
            string cevap1 = Console.ReadLine();
            _cevap1 = cevap1.Split(' ');
            lambaSayisi = int.Parse(_cevap1[0]);
            caddeUzunlugu = int.Parse(_cevap1[1]);
            int[] lambaKonumlari = new int[lambaSayisi];
            string cevap2 = Console.ReadLine();
            lambaKonumlari = Array.ConvertAll(cevap2.Split(' '),sayi => int.Parse(sayi));
            Array.Sort(lambaKonumlari);
            for (int i = 0; i < lambaSayisi-1; i++)
            {   
                gecici = lambaKonumlari[i+1]-lambaKonumlari[i];
                if (gecici/2 > sonuc)
                {
                    sonuc = gecici/2;
                }
            }
            if (lambaKonumlari[0]-0 > sonuc)
            {
                sonuc = lambaKonumlari[0]-0;
            }
            if (caddeUzunlugu-lambaKonumlari[lambaSayisi-1] >sonuc)
            {
                sonuc = caddeUzunlugu - lambaKonumlari[lambaSayisi-1];
            }
            Console.WriteLine(sonuc);
        }
    }
}
