#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//  PROSEDUR
void Menu();
void Penjumlahan();
void Pengurangan();
void Perkalian();
void Pembagian();
void Modulus();

//  FUNGSI
float hitungPenjumlahan(float bil1, float bil2){
    float hasil = bil1+bil2;
    return hasil;
}

float hitungPengurangan(float bil1, float bil2){
    float hasil = bil1-bil2;
    return hasil;
}

float hitungPerkalian(float bil1, float bil2){
    float hasil = bil1*bil2;
    return hasil;
}

float hitungPembagian(float bil1, float bil2){
    float hasil = bil1/bil2;
    return hasil;
}
int hitungModulus(int bil1, int bil2){
    int hasil = bil1%bil2;
    return hasil;
}

//  MAIN
int main(){
    system("COLOR F0");

    Menu();
    return 0;
}

//  PROSEDUR
int validasiMenu() {
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=49 && angka[i]<=54){ // PEMBATAS PADA ASCII DIMANA 49-54 BERNILAI "1-6"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("INPUT TIDAK SESUAI\n\n");
        printf("Masukan Pilihan Menu : ");
        validasiMenu();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=6){
            return val;
        }else{
            printf("INPUT TIDAK SESUAI\n\n");
            printf("Masukan Pilihan Menu : ");
            validasiMenu();
        }
    }
}

float validasiFloat(){
    int i = 0;
    int salah =0;
    int titik=0;
    char angka[100];
    float val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    if(angka[0]>=48 && angka[0]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

    }else if(angka[0]==45){  // PEMBATAS PADA ASCII DIMANA 45 BERNILAI "-"

    }else{
        salah += 1;
    }

    for(i=1;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

        }else if(angka[i]==46){ // PEMBATAS PADA ASCII DIMANA 45 BERNILAI "."
            titik += 1;
        }else{
            salah += 1;
        }
    }

    if(salah>0 || titik>1){
        printf("HARAP MASUKAN BILLANGAN\n");
        printf("Masukkan input : ");
        validasiFloat();
    }else{
        val = atof(angka);
        return val;
    }
}

int validasiModulus() {
    int i = 0;
    int salah =0;
    char angka[100];
    float val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    if(angka[0]>=48 && angka[0]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

    }else if(angka[0]==45){  // PEMBATAS PADA ASCII DIMANA 45 BERNILAI "-"

    }else{
        salah += 1;
    }

    for(i=1;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("HARAP MASUKAN BILLANGAN\n");
        printf("Masukkan input : ");
        validasiFloat();
    }else{
        val = atoi(angka);
        return val;
    }
}

int validasiPilihan() {
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=49 && angka[i]<=51){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "1-3"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("INPUT TIDAK SESUAI\n\n");
        printf("Masukan Pilihan Menu : ");
        validasiPilihan();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=3){
            return val;
        }else{
            printf("INPUT TIDAK SESUAI\n\n");
            printf("Masukan Pilihan Menu : ");
            validasiPilihan();
        }
    }
}

void Menu(){
    int pilihan;

    printf("================================\n\n");
    printf(" PROGRAM KALKULATOR ARITMATIKA \n\n");
    printf("================================\n");
    printf("\t1. Penjumlahan\n");
    printf("\t2. Pengurangan\n");
    printf("\t3. Perkalian\n");
    printf("\t4. Pembagian\n");
    printf("\t5. Modulus\n");
    printf("\t6. Exit\n");
    printf("================================\n\n");
    printf("Masukan Pilihan Menu : ");
    pilihan = validasiMenu();
    system("cls");
     switch (pilihan){
	    case 1:
	    Penjumlahan();
	    break;
	    case 2:
	    Pengurangan();
	    break;
	    case 3:
	    Perkalian();
	    break;
	    case 4:
	    Pembagian();
	    break;
	    case 5:
	    Modulus();
	    break;
	    default:
        exit(0);
	    break;
	 }
}

void Penjumlahan(){
	float bil1, bil2;
	float hasil;
	int pilihan;

    printf("================================\n\n");
    printf("        PROGRAM PENJUMLAHAN    \n\n");
    printf("================================\n\n");
    printf("Masukkan bilangan pertama : ");
    bil1 = validasiFloat();
    printf("\nMasukkan bilangan kedua   : ");
    bil2 = validasiFloat();
    printf("--------------------------------\n");
    printf("\nOperasi Penjumlahan\n");
    printf("\t%.2f \n", bil1);
    printf("\t%.2f \n", bil2);
    printf("    ---------- + \n");
    hasil = hitungPenjumlahan(bil1, bil2);
    printf("      = %.2f\n\n", hasil);

    printf("\n\n================================\n");
    printf("1.Ulangi   2.Kembali   3.Exit\n");
    printf("--------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    Penjumlahan();
	    break;
	    case 2:
	    Menu();
	    break;
	    default:
	    exit(0);
	    break;
	 }
}

void Pengurangan(){
	float bil1, bil2;
	float hasil;
	int pilihan;

    printf("================================\n\n");
    printf("       PROGRAM PENGURANGAN    \n\n");
    printf("================================\n\n");
    printf("Masukkan bilangan pertama : ");
    bil1 = validasiFloat();
    printf("\nMasukkan bilangan kedua   : ");
    bil2 = validasiFloat();
    printf("--------------------------------\n");
    printf("\nOperasi Pengurangan\n");
    printf("\t%.2f \n", bil1);
    printf("\t%.2f \n", bil2);
    printf("    ---------- - \n");
    hasil = hitungPengurangan(bil1, bil2);
    printf("      = %.2f\n\n", hasil);

    printf("\n\n================================\n");
    printf("1.Ulangi   2.Kembali   3.Exit\n");
    printf("--------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    Pengurangan();
	    break;
	    case 2:
	    Menu();
	    break;
	    default:
	    exit(0);
	    break;
	 }
}

void Perkalian(){
    float bil1, bil2;
	float hasil;
	int pilihan;

    printf("================================\n\n");
    printf("          PROGRAM PEKALIAN      \n\n");
    printf("================================\n\n");
    printf("Masukkan bilangan pertama : ");
    bil1 = validasiFloat();
    printf("\nMasukkan bilangan kedua   : ");
    bil2 = validasiFloat();
    printf("--------------------------------\n");
    printf("\nOperasi Perkalian\n");
    printf("\t%.2f \n", bil1);
    printf("\t%.2f \n", bil2);
    printf("    ---------- x \n");
    hasil = hitungPerkalian(bil1, bil2);
    printf("      = %.2f\n\n", hasil);

    printf("\n\n================================\n");
    printf("1.Ulangi   2.Kembali   3.Exit\n");
    printf("--------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    Perkalian();
	    break;
	    case 2:
	    Menu();
	    break;
	    default:
	    exit(0);
	    break;
	 }
}

void Pembagian(){
    float bil1, bil2;
	float hasil;
	int pilihan;

    printf("================================\n\n");
    printf("         PROGRAM PEMBAGIAN      \n\n");
    printf("================================\n\n");
    printf("Masukkan bilangan pertama : ");
    bil1 = validasiFloat();
    printf("\nMasukkan bilangan kedua   : ");
    bil2 = validasiFloat();
    printf("--------------------------------\n");
    printf("\nOperasi Pembagian\n\n");
    printf("\t%.2f \n", bil1);
    printf("\t%.2f \n", bil2);
    printf("    ---------- : \n");
    hasil = hitungPembagian(bil1, bil2);
    printf("      = %.2f\n\n", hasil);

    printf("\n\n================================\n");
    printf("1.Ulangi   2.Kembali   3.Exit\n");
    printf("--------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    Pembagian();
	    break;
	    case 2:
	    Menu();
	    break;
	    default:
	    exit(0);
	    break;
	 }
}

void Modulus(){
    int bil1, bil2;
	int hasil;
	int pilihan;

    printf("================================\n\n");
    printf("         PROGRAM MODULUS        \n\n");
    printf("================================\n\n");
    printf("Masukkan bilangan pertama : ");
    bil1 = validasiModulus();
    printf("\nMasukkan bilangan kedua   : ");
    bil2 = validasiModulus();
    printf("--------------------------------\n");
    printf("\nOperasi Modulus\n\n");
    printf("\t%d \n", bil1);
    printf("\t%d \n", bil2);
    printf("    ---------- %% \n");
    hasil = hitungModulus(bil1, bil2);
    printf("      = %d\n\n", hasil);

    printf("\n\n================================\n");
    printf("1.Ulangi   2.Kembali   3.Exit\n");
    printf("--------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    Modulus();
	    break;
	    case 2:
	    Menu();
	    break;
	    default:
	    exit(0);
	    break;
	 }
}
