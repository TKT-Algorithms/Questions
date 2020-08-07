import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Scanner;

public class Soru_1B {
    public static void main(String[] args) {
        // değişkenler
        Scanner input = new Scanner(System.in);
        String veriAl;
        long sokakUzunlugu, lambaKonum[];
		int lambaSayisi;
        double isikYaricapi = 0;

        int a = 0;

        // verileri alma
        // ilk satır verileri
        veriAl = input.nextLine();
        lambaSayisi = Integer.parseInt(veriAl.split(" ")[0]);
        sokakUzunlugu = Long.parseLong(veriAl.split(" ")[1]);
        lambaKonum = new long[lambaSayisi];

        // ikinci satır verileri
        veriAl = input.nextLine();
        for (int i = 0; i < lambaSayisi; i++) {
        	lambaKonum[i] = Long.parseLong(veriAl.split(" ")[i]);
        }
		Arrays.sort(lambaKonum); // sokak lambalarını konumlarına göre sıraladık

		// lambaKonum[0] - 0 = lambaKonum[0]
		if (lambaKonum[0] > isikYaricapi)
			isikYaricapi = lambaKonum[0];
		// en uzak noktadan en sondaki lambanın konumunun farkı
		if (sokakUzunlugu - lambaKonum[lambaKonum.length - 1] > isikYaricapi)
			isikYaricapi = sokakUzunlugu - lambaKonum[lambaKonum.length - 1];
		// yan yana 2 lamba arası mesafeyi ışık yarıçapıyla kıyaslar
		for (int i = 0; i < lambaKonum.length - 1; i++) {
			if (((double) Math.abs(lambaKonum[i] - lambaKonum[i + 1])) / 2 > isikYaricapi) {
				isikYaricapi = ((double) Math.abs((lambaKonum[i] - lambaKonum[i + 1])) / 2);
			}
		}

		System.out.println(new BigDecimal(isikYaricapi));
	}
}
