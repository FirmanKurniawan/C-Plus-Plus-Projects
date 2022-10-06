#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//=====================================================================
//  DEKLARASI PROSEDUR
void menu();
void zodiak();

//=====================================================================
//  VALIDASI
int validasiTanggal(){
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 48-57 BERNILAI "0-9"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("INPUT TIDAK SESUAI\n");
        printf("Masukkan input Tanggal : ");
        validasiTanggal();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=31){
            return val;
        }else{
            printf("INPUT TIDAK SESUAI\n");
            printf("Masukkan input Tanggal : ");
            validasiTanggal();
        }
    }
}

int validasiBulan(){
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 48-57 BERNILAI "0-9"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("INPUT TIDAK SESUAI\n");
        printf("Masukkan input Bulan : ");
        validasiBulan();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=12){
            return val;
        }else{
            printf("INPUT TIDAK SESUAI\n");
            printf("Masukkan input Bulan : ");
            validasiBulan();
        }
    }
}

int validasiTahun(){
    int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 48-57 BERNILAI "0-9"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("INPUT TIDAK SESUAI\n");
        printf("Masukkan input Tahun : ");
        validasiTahun();
    }else{
        val = atoi(angka);
        if(val>=1700 && val<=2021){
            return val;
        }else{
            printf("INPUT TIDAK SESUAI\n");
            printf("Masukkan input Tahun : ");
            validasiTahun();
        }
    }
}

int validasiPilihan(){
	int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 48-57 BERNILAI "0-9"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("INPUT TIDAK SESUAI\n");
        printf("Masukkan input kembali : ");
        validasiPilihan();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=3){
            return val;
        }else{
            printf("INPUT TIDAK SESUAI\n");
            printf("Masukkan input kembali : ");
            validasiPilihan();
        }
    }
}

int validasiMenu(){
	int i = 0;
    int salah =0;
    char angka[100];
    int val;
    int array;

    scanf("%s", &angka);
    array=strlen(angka);

    for(i=0;i<array; i++){
        if(angka[i]>=48 && angka[i]<=57){ // PEMBATAS PADA ASCII DIMANA 48-57 BERNILAI "0-9"

        }else{
            salah += 1;
        }
    }

    if(salah>0){
        printf("INPUT TIDAK SESUAI\n");
        printf("Masukkan input kembali : ");
        validasiMenu();
    }else{
        val = atoi(angka);
        if(val>=1 && val<=2){
            return val;
        }else{
            printf("INPUT TIDAK SESUAI\n");
            printf("Masukkan input kembali : ");
            validasiMenu();
        }
    }
}

//=====================================================================
//MAIN
int main(){
    system("COLOR F0");
    menu();
    system("pause");
    return 0;
}

//=====================================================================
// MENU
void menu(){
    int pilihan;

    printf("==============================================\n\n");
	printf("                PROGRAM ZODIAK                \n\n");
	printf("==============================================\n");
    printf("\t 1. Mulai            \n");
	printf("\t 2. Keluar Program   \n");
	printf("==============================================\n\n");
	printf("Masukan Nomor Menu Yang Anda Inginkan : ");
    pilihan = validasiMenu();
    system("cls");

	if(pilihan==1){
        zodiak();
    }else{
        exit(0);
    }
}


// ZODIAK
void zodiak(){
	int tanggal;
	int bulan;
	int pilih;
	int tahun;

    printf("==============================================\n\n");
	printf("                PROGRAM ZODIAK                \n\n");
	printf("==============================================\n\n");
    printf("               Daftar Bulan             \n");
    printf("---------------------------------------------\n");
    printf("     [1] Januari       [7] Juli         \n");
    printf("     [2] Februari      [8] Agustus      \n");
    printf("     [3] Maret         [9] September    \n");
    printf("     [4] April         [10] Oktober     \n");
    printf("     [5] Mei           [11] November    \n");
    printf("     [6] Juni          [12] Desember    \n");
    printf("=============================================\n");
    printf("Masukkan Tanggal Lahir Anda (1-31): ");
    tanggal=validasiTanggal();
    printf("Masukkan Bulan Lahir Anda (1-12)  : ");
    bulan=validasiBulan();
    printf("Masukkan Tahun Lahir Anda : ");
    tahun=validasiTahun();
    printf("----------------------------------------------\n");

    if((tahun%400==0||tahun%4==0)&&(bulan==2&&tanggal==29)){
        printf("\t\t Zodiak Anda adalah Pisces\n");
    }else{
        if((tanggal>=21 && tanggal<=31 && bulan==3)||(tanggal>=1 && tanggal<=19 &&bulan==4)){
            printf("\t Zodiak Anda adalah Aries\n");
        }else if ((tanggal>=20&&tanggal<=30&&bulan==4)||(tanggal>=1&&tanggal<=20&&bulan==5)){
            printf("\t Zodiak Anda adalah Taurus\n");
        }else if((tanggal>=21&&tanggal<=31&&bulan==5)||(tanggal>=1&&tanggal<=20&&bulan==6)){
            printf("\t Zodiak Anda adalah Gemini\n");
        }else if((tanggal>=21&&tanggal<=30&&bulan==6)||(tanggal>=1&&tanggal<=22&&bulan==7)){
            printf("\t Zodiak Anda adalah Cancer\n");
        }else if((tanggal>=23&&tanggal<=31&&bulan==7)||(tanggal>=1&&tanggal<=22&&bulan==8)){
            printf("\t Zodiak Anda adalah Leo\n");
        }else if((tanggal>=23&&tanggal<=31&&bulan==8)||(tanggal>=1&&tanggal<=22&&bulan==9)){
            printf("\t Zodiak Anda adalah Virgo\n");
        }else if((tanggal>=23&&tanggal<=30&&bulan==9)||(tanggal>=1&&tanggal<=22&&bulan==10)){
            printf("\t Zodiak Anda adalah Libra\n");
        }else if((tanggal>=23&&tanggal<=31&&bulan==10)||(tanggal>=1&&tanggal<=21&&bulan==11)){
            printf("\t Zodiak Anda adalah Scorpio\n");
        }else if((tanggal>=22&&tanggal<=30&&bulan==11)||(tanggal>=1&&tanggal<=21&&bulan==12)){
            printf("\t Zodiak Anda adalah Sagitarius\n");
        }else if((tanggal>=22&&tanggal<=31&&bulan==12)||(tanggal>=1&&tanggal<=19&&bulan==1)){
            printf("\t Zodiak Anda adalah Capricon\n");
        }else if((tanggal>=20&&tanggal<=31&&bulan==1)||(tanggal>=1&&tanggal<=18&&bulan==2)){
            printf("\t Zodiak Anda adalah Aquarius\n");
        }else if((tanggal>=19&&tanggal<=28&&bulan==2)||(tanggal>=1&&tanggal<=20&&bulan==3)){
            printf("\t Zodiak Anda adalah Pisces\n");
        }else{
            printf("Pilihan anda tidak tersedia\n");
            printf("Zodiak tidak ditemukan\n");
			}
		}

    printf("\n==============================================\n");
    printf("     1.Ulangi      2.Kembali       3.Exit\n");
    printf("----------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilih = validasiPilihan();
    system("cls");

	switch(pilih){
	    case 1:
        zodiak();
	    break;
	    case 2:
	    menu();
	    break;
	    default:
	    exit(0);
	    break;
    }
}
