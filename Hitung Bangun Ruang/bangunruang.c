#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#define PHI 3.14

//=====================================================================
//  PROSEDUR
void menu();

void volumeBangunRuang();
void luasPermukaanBangunRuang();

void volTabung();
void volBola();
void volLimasSegiempat();
void volPrismaSegitiga();
void volKerucut();

void lPTabung();
void lPBola();
void lPLimasSegiempat();
void lPPrismaSegitiga();
void lPKerucut();
//=====================================================================
//FUNGSI VOLUME

float hitungVolTabung(float jari, float tinggi){
	float vol = PHI*(jari*jari)*tinggi;
	return vol;
}

float hitungVolBola(float jari){
	float vol = 4.0/3.0*PHI*jari*jari*jari;
	return vol;
}

float hitungVolLimasSegiempat(float sisi, float tinggi){
	float vol = 1.0/3.0*(sisi*sisi)*tinggi;
	return vol;
}

float hitungVolPrismaSegitiga(float sisiSegitiga1, float sisiSegitiga2, float sisiSegitiga3, float tinggi){
	float s = (sisiSegitiga1+sisiSegitiga2+sisiSegitiga3)/2.0;
	float vol = (sqrt(s*(s-sisiSegitiga1)*(s-sisiSegitiga2)*(s-sisiSegitiga3)))*tinggi;
	return vol;
}

float hitungVolkerucut(float jari, float tinggi){
	float vol = 1.0/3.0*PHI*jari*jari*tinggi;
	return vol;
}

//FUNGSI LUAS PERMUKAAN

float hitungLPTabung(float jari, float tinggi){
	float luas = (2*PHI*(jari*jari))+(2*PHI*jari*tinggi);
	return luas;
}

float hitungLPBola(float jari){
	float luas = 4*PHI*jari*jari;
	return luas;
}

float hitungLPLimasSegiempat(float sisi, float tinggi){
	float tinggiSegitiga = sqrt(pow(sisi/2,2) + pow(tinggi,2));
	float luas = (sisi*sisi)+(4*(0.5*sisi*tinggiSegitiga));
	return luas;
}

float hitungLPPrismaSegitiga(float tinggi, float sisiSegitiga1, float sisiSegitiga2, float sisiSegitiga3){
	float s = (sisiSegitiga1+sisiSegitiga2+sisiSegitiga3)/2;
	float luas = (tinggi*(sisiSegitiga1+sisiSegitiga2+sisiSegitiga3))+(2*sqrt(s*(s-sisiSegitiga1)*(s-sisiSegitiga2)*(s-sisiSegitiga3)));
	return luas;
}

float hitungLPKerucut(float jari, float tinggi){
	float pelukis = sqrt(pow(jari,2) + pow(tinggi,2));
	float luas = (PHI*(jari*jari))+(PHI*jari*pelukis);
	return luas;
}

//=====================================================================
//MAIN

int main(){
    system("COLOR F0");

    menu();
    return 0;
}

//=====================================================================
//FUNGSI VALIDASI INPUT

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

float validasiBil(){
    int i = 0;
    int salah =0;
    int titik=0;
    char angka[100];
    float val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    if(angka[0]>=48 && angka[0]<=57){ // PEMBATAS PADA ASCII DIMANA 49-51 BERNILAI "0-9"

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
        printf("HARAP MASUKAN BILLANGAN YANG SESUAI\n");
        printf("Masukkan input : ");
        validasiBil();
    }else{
        val = atof(angka);
        return val;
    }
}

//=====================================================================
//PROSEDUR

void menu(){
    int pilihan;

    printf("===========================================================\n\n");
    printf("               PROGRAM MENGHITUNG VOLUME &                \n");
    printf("               LUAS PERMUKAAN BANGUN RUANG                \n\n");
    printf("===========================================================\n\n");
    printf("Daftar Pilihan Menu :\n");
    printf("\t1.Menghitung Volume Bangun Ruang\n");
    printf("\t2.Menghitung Luas Permukaan Bangun Ruang\n");
    printf("\t3.Exit\n");
    printf("-----------------------------------------------------------\n");
    printf("\nMasukan Nomor Menu : ");
    pilihan = validasiPilihan();
    system("cls");

    switch (pilihan){
	    case 1:
	    volumeBangunRuang();
	    break;
	    case 2:
	    luasPermukaanBangunRuang();
	    break;
	    default:
        printf("PROGRAM TELAH BERHENTI\n\n");
	    break;
	 }
}

// Sub Menu Volume
void volumeBangunRuang(){
  	int pilihan;

    printf("===========================================================\n\n");
    printf("               PROGRAM MENGHITUNG VOLUME &                 \n");
    printf("               LUAS PERMUKAAN BANGUN RUANG                 \n");;
    printf("-----------------------------------------------------------\n");
    printf("                  PENGHITUNGAN VOLUME                      \n");
    printf("===========================================================\n");
    printf("Pilih Bangun Ruang Dibawah \n");
    printf("\t1.Tabung\n");
    printf("\t2.Bola\n");
    printf("\t3.Limas Segiempat\n");
    printf("\t4.Prisma Segitiga\n");
    printf("\t5.Kerucut\n");
    printf("\t6.Back\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Nomor Menu : ");
    pilihan = validasiMenu();
    system("cls");

    switch (pilihan){
	    case 1:
	    volTabung();
	    break;
	    case 2:
	    volBola();
	    break;
	    case 3:
	   	volLimasSegiempat();
	    break;
	    case 4:
	    volPrismaSegitiga();
	    break;
	    case 5:
	    volKerucut();
	    break;
	    default:
	    menu();
	    break;
	 }

}

// Volume tabung
void volTabung(){
	float jari;
	float tinggi;
	float vol;
	int pilihan;

    printf("===========================================================\n\n");
    printf("               PROGRAM MENGHITUNG VOLUME                   \n");
    printf("-----------------------------------------------------------\n");
    printf("                   Hitung Volume Tabung                    \n");
    printf("===========================================================\n\n");
    printf("Masukan Panjang Jari-Jari Alas (cm) : ");
    jari = validasiBil();
    printf("Masukan Tinggi (cm) : ");
    tinggi = validasiBil();
    printf("-----------------------------------------------------------\n\n");
    vol = hitungVolTabung(jari, tinggi);
    printf("Volume Tabung adalah : %.2f cm3\n",vol);

    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    volTabung();
	    break;
	    case 2:
	    volumeBangunRuang();
	    break;
	    default:
	    menu();
	    break;
	 }
}

// Volume Bola
void volBola(){
    float jari;
    float vol;
    int pilihan;

    printf("===========================================================\n\n");
    printf("               PROGRAM MENGHITUNG VOLUME                   \n");
    printf("-----------------------------------------------------------\n");
    printf("                   Hitung Volume Bola                      \n");
    printf("===========================================================\n\n");
    printf("Masukan Panjang Jari-Jari (cm) : ");
    jari = validasiBil();
    printf("-----------------------------------------------------------\n\n");
    vol = hitungVolBola(jari);
    printf("Volume Bola adalah : %.2f cm3\n",vol);

    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU \n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    volBola();
	    break;
	    case 2:
	    volumeBangunRuang();
	    break;
	    default:
	    menu();
	    break;
	 }
}

// Validasi Limas Segiempat
void volLimasSegiempat(){
	float tinggi;
	float sisi;
	float vol;
	int pilihan;

    printf("===========================================================\n\n");
    printf("               PROGRAM MENGHITUNG VOLUME                   \n");
    printf("-----------------------------------------------------------\n");
    printf("               Hitung Volume Limas Segiempat               \n");
    printf("===========================================================\n\n");
    printf("Masukan Panjang Sisi Alas (cm) : ");
    sisi = validasiBil();
    printf("Masukan Tinggi (cm) : ");
    tinggi = validasiBil();
    printf("-----------------------------------------------------------\n\n");
    vol = hitungVolLimasSegiempat( sisi, tinggi);
    printf("Volume Limas Segiempat adalah : %.2f cm3\n",vol);

    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU \n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    volLimasSegiempat();
	    break;
	    case 2:
	    volumeBangunRuang();
	    break;
	    default:
	    menu();
	    break;
	 }
}

// Volume Prsma Segitiga
void volPrismaSegitiga(){
	float sisiSegitiga1;
	float sisiSegitiga2;
	float sisiSegitiga3;
	float tinggi;
	float vol;
	int pilihan;

    printf("===========================================================\n\n");
    printf("               PROGRAM MENGHITUNG VOLUME                   \n");
    printf("-----------------------------------------------------------\n");
    printf("                Hitung Volume Prisma Segitiga              \n");
    printf("===========================================================\n\n");
    printf("Masukan Panjang Sisi 1 Segitiga (cm) : ");
    sisiSegitiga1 = validasiBil();
    printf("Masukan Panjang Sisi 2 Segitiga (cm) : ");
    sisiSegitiga2 = validasiBil();
    printf("Masukan Panjang Sisi 3 Segitiga (cm) : ");
    sisiSegitiga3 = validasiBil();
    printf("Masukan Tinggi (cm) : ");
    tinggi = validasiBil();
    printf("-----------------------------------------------------------\n\n");
    vol = hitungVolPrismaSegitiga(sisiSegitiga1, sisiSegitiga2, sisiSegitiga3, tinggi);
    printf("Volume Prisma Segitiga adalah : %.2f cm3\n",vol);

    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU \n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    volPrismaSegitiga();
	    break;
	    case 2:
	    volumeBangunRuang();
	    break;
	    default:
	    menu();
	    break;
	 }
}

// Volume Kerucut
void volKerucut(){
	float jari;
	float tinggi;
	float vol;
	int pilihan;

    printf("===========================================================\n\n");
    printf("               PROGRAM MENGHITUNG VOLUME                   \n");
    printf("-----------------------------------------------------------\n");
    printf("                   Hitung Volume Kerucut                   \n");
    printf("===========================================================\n\n");
    printf("Masukan Panjang Jari-Jari (cm) : ");
    jari = validasiBil();
    printf("Masukan Tinggi (cm) : ");
    tinggi = validasiBil();
    printf("-----------------------------------------------------------\n\n");
    vol = hitungVolkerucut( jari, tinggi);
    printf("Volume Kerucut adalah : %.2f cm3\n",vol);

    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU \n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    volKerucut();
	    break;
	    case 2:
	    volumeBangunRuang();
	    break;
	    default:
	    menu();
	    break;
	 }
}

// Sub Menu Luas Permukaan
void luasPermukaanBangunRuang(){
  	int pilihan;

  	printf("===========================================================\n\n");
    printf("               PROGRAM MENGHITUNG VOLUME &                 \n");
    printf("               LUAS PERMUKAAN BANGUN RUANG                 \n\n");
    printf("-----------------------------------------------------------\n");
    printf("                 PERHITUNGAN LUAS PERMUKAAN                \n");
    printf("===========================================================\n\n");
    printf("Pilih Bangun Ruang Dibawah :\n");
    printf("\t1.Tabung\n");
    printf("\t2.Bola\n");
    printf("\t3.Limas Segiempat\n");
    printf("\t4.Prisma Segitiga\n");
    printf("\t5.Kerucut\n");
    printf("\t6.Back\n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Nomor Menu : ");
    pilihan = validasiMenu();
    system("cls");

    switch (pilihan){
	    case 1:
	    lPTabung();
	    break;
	    case 2:
	    lPBola();
	    break;
	    case 3:
	    lPLimasSegiempat();
	    break;
	    case 4:
	    lPPrismaSegitiga();
	    break;
	    case 5:
	    lPKerucut();
	    break;
	    default:
	    menu();
	    break;
	 }
}

void lPTabung(){
    float jari;
	float tinggi;
	float luas;
	int pilihan;

    printf("===========================================================\n\n");
    printf("            PROGRAM MENGHITUNG LUAS PERMUKAAN              \n");
    printf("-----------------------------------------------------------\n");
    printf("               Hitung Luas Permukaan Tabung                \n");
    printf("===========================================================\n\n");
    printf("Masukan Panjang Jari-jari (cm) : ");
    jari = validasiBil();
    printf("Masukan Tinggi (cm) : ");
    tinggi = validasiBil();
    luas = hitungLPTabung(jari, tinggi);
    printf("Luas Permukaan Tabung adalah : %.2f cm2\n",luas);

    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU \n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    lPTabung();
	    break;
	    case 2:
	    luasPermukaanBangunRuang();
	    break;
	    default:
	    menu();
	    break;
	 }
}

void lPBola(){
    float jari;
    float luas;
	int pilihan;

    printf("===========================================================\n\n");
    printf("            PROGRAM MENGHITUNG LUAS PERMUKAAN              \n");
    printf("-----------------------------------------------------------\n");
    printf("                Hitung Luas Permukaan Bola                 \n");
    printf("===========================================================\n");
    printf("Masukan Panjang Jari-jari (cm) : ");
    jari = validasiBil();

    luas = hitungLPBola(jari);
    printf("Luas Permukaan Bola adalah : %.2f cm2\n",luas);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU \n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    lPBola();
	    break;
	    case 2:
	    luasPermukaanBangunRuang();
	    break;
	    default:
	    menu();
	    break;
	 }
}

void lPLimasSegiempat(){
    float sisi;
	float tinggi;
	float luas;
	int pilihan;

    printf("===========================================================\n\n");
    printf("            PROGRAM MENGHITUNG LUAS PERMUKAAN              \n");
    printf("-----------------------------------------------------------\n");
    printf("           Hitung Luas Permukaan Limas Segiempat           \n");
    printf("===========================================================\n\n");
    printf("Masukan Panjang Sisi Alas (cm) : ");
    sisi = validasiBil();
    printf("Masukan Tinggi (cm) : ");
    tinggi = validasiBil();

    luas = hitungLPLimasSegiempat( sisi, tinggi);
    printf("Luas Permukaan Limas Segiempat adalah : %.2f cm2\n",luas);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU \n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    lPLimasSegiempat();
	    break;
	    case 2:
	    luasPermukaanBangunRuang();
	    break;
	    default:
	    menu();
	    break;
	 }
}

void lPPrismaSegitiga(){
    float tinggi;
	float sisiSegitiga1;
	float sisiSegitiga2;
	float sisiSegitiga3;
	float luas;
	int pilihan;

    printf("===========================================================\n\n");
    printf("            PROGRAM MENGHITUNG LUAS PERMUKAAN              \n");
    printf("-----------------------------------------------------------\n");
    printf("            Hitung Luas Permukaan Prisma Segitiga          \n");
    printf("===========================================================\n\n");
    printf("Masukan Tinggi (cm) : ");
    tinggi = validasiBil();
    printf("Masukan Panjang Sisi a Segitiga (cm) : ");
    sisiSegitiga1 = validasiBil();
    printf("Masukan Panjang Sisi b Segitiga (cm) : ");
    sisiSegitiga2 = validasiBil();
    printf("Masukan Panjang Sisi c Segitiga (cm) : ");
    sisiSegitiga3 = validasiBil();
    luas = hitungLPPrismaSegitiga(tinggi, sisiSegitiga1, sisiSegitiga2, sisiSegitiga3);
    printf("Luas Permukaan Prisma Segitiga adalah : %.2f cm2\n",luas);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU \n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    lPPrismaSegitiga();
	    break;
	    case 2:
	    luasPermukaanBangunRuang();
	    break;
	    default:
	    menu();
	    break;
	 }
}

void lPKerucut(){
    float jari;
	float tinggi;
	float luas;
	int pilihan;

    printf("===========================================================\n\n");
    printf("            PROGRAM MENGHITUNG LUAS PERMUKAAN              \n");
    printf("-----------------------------------------------------------\n");
    printf("              Hitung Luas Permukaan Kerucut                \n");
    printf("===========================================================\n\n");
    printf("Masukan Panjang Jari-jari (cm) : ");
    jari = validasiBil();
    printf("Masukan Tinggi (cm) : ");
    tinggi = validasiBil();

    luas = hitungLPKerucut( jari, tinggi);
    printf("Luas Permukaan Kerucut adalah : %.2f cm2\n",luas);
    printf("\n\n===========================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU \n");
    printf("-----------------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    lPKerucut();
	    break;
	    case 2:
	    luasPermukaanBangunRuang();
	    break;
	    default:
	    menu();
	    break;
	 }
}
