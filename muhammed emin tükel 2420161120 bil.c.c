// MUHAMMED EMÝN TÜKEL
// 2420161120
// https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=WJ1SkNVVaB


#include <stdio.h>

//ekrana yazdirma fonksiyonu 
void dizi_yazdir(int dizi[], int bas_ind, int son_ind) {
	int i;
	for (i = bas_ind; i <= son_ind; i++) { // i=bas indis(sütun). i son indise(sütun) gelince i yi diðer elemana geçir.
		printf(" %d", dizi[i]);
	}
	printf("\n");
}

void arayaeklemeli_sirala(int dizi[], int BOYUT) { //araya eklemeli siralama
	int i, j; //i ve j adýnda iki deðiþken tanýmladýk.
	int anahtar; //anahtar deðiþkenini tanýmladýk.

	for (i = 1; i <= BOYUT - 1; i++) { //i=1, dögü boyut yani indisten 1 eksik olana kadar devam edicek, i yi 1 arttýrarak.
		anahtar = dizi[i];

		for (j = i - 1; j >= 0 && anahtar < dizi[j]; j--) { //
			dizi[j + 1] = dizi[j];  //j'yi yani satýrý 1 alta indir
		}
		dizi[j + 1] = anahtar; // indisi 1 arttýrarak anahtarý belirledik.
		printf("iter.%d: ", i); // ekrana çýktý verir
		dizi_yazdir(dizi, 0, BOYUT - 1); //yzdýðýmýz bütün sayýlarý yazar.
	}
}

int ikili_arama(int dizi[], int BOYUT, int aranan) {
	int sol = 0;
	int sag = BOYUT - 1;
	int orta;

	while (sol <= sag) {
		orta = (sol + sag) / 2;

		if (dizi[orta] == aranan) {
			return orta;   //aradýðýnýz bulundu
		}
		else if (aranan < dizi[orta]) {
			sag = orta - 1;
		}
		else {
			sol = orta + 1;
		}
	}
	return -1;  //aradýgýnýz bulunamadý
}

int main() {
	int A[] = {24, 20, 16, 11,200,41 , 34, 81, 54, 32};
	int N = sizeof(A) / sizeof(A[0]);
	int aranan;
	int sonuc;

	printf("Orijinal dizi:\n");
	dizi_yazdir(A, 0, N - 1);

	printf("\nAraya Eklemeli Siralama Adimlari:\n");
	arayaeklemeli_sirala(A, N);

	printf("\nSiralanmis dizi:\n");
	dizi_yazdir(A, 0, N - 1);

	printf("\nAramak istediginiz sayiyi giriniz: ");
	scanf("%d", &aranan);

	sonuc = ikili_arama(A, N, aranan);

	if (sonuc != -1) {
		printf("Aradiginiz sayi %d, dizide %d. indiste bulundu.\n", aranan, sonuc);
	}
	else {
		printf("Aradiginiz sayi %d, dizide bulunamadi.\n", aranan);
	}

	return 0;
}

