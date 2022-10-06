#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <string.h>
#define PHI 3.14

//=====================================================================
//  PROSEDUR
void menu();

void luasBangunDatar();
void kelilingBangunDatar();

void lSegitigaSembarang();
void lBelahKetupat();
void lJajargenjang();
void lTrapesium();
void lLingkaran();

void kSegitigaSembarang();
void kBelahKetupat();
void kJajargenjang();
void kTrapesium();
void kLingkaran();
//=====================================================================

//FUNGSI LUAS

float hitungLuasSegitigaSembarang(float sisi1, float sisi2, float sisi3){
	float s = (sisi1+sisi2+sisi3)/2;
    float luas = sqrt(s*(s-sisi1)*(s-sisi2)*(s-sisi3));
	return luas;
}

float hitungLuasBelahKetupat(float diagonal1, float diagonal2){
	float luas = diagonal1*diagonal2/2;
	return luas;
}

float hitungLuasJajargenjang(float alas, float tinggi){
	float luas = alas*tinggi;
	return luas;
}

float hitungLuasTrapesium(float sisi1, float sisi2, float tinggi){
	float luas =(sisi1+sisi2)*tinggi/2;
	return luas;
}

float hitungLuasLingkaran(float jari2){
	float luas = PHI*jari2*jari2;
	return luas;
}

//FUNGSI KELILING

float hitungKelSegitigaSembarang(float sisi1, float sisi2, float sisi3){
	float kel = sisi1+sisi2+sisi3;
	return kel;
}

float hitungKelBelahKetupat(float sisi){
	float kel = 4*sisi;
	return kel;
}

float hitungKelJajargenjang(float sisialas, float sisimiring){
	float kel = 2*(sisialas+sisimiring);
	return kel;
}

float hitungKelTrapesium(float sisi1, float sisi2, float sisi3, float sisi4){
	float kel =sisi1+sisi2+sisi3+sisi4;
	return kel;
}

float hitungKelLingkaran(float jari2){
    float kel = 2*PHI*jari2;
	return kel;
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
//MENU
void menu(){
    int pilihan;

    printf("=================================================\n\n");
    printf("             PROGRAM MENGHITUNG LUAS &           \n");
    printf("               KELILING BANGUN DATAR             \n\n");
    printf("=================================================\n\n");
    printf("Daftar Pilihan Menu :\n\n");
    printf("\t1.Hitung Luas Bangun Datar\n");
    printf("\t2.Hitung Keliling Bangun Datar\n");
    printf("\t3.Exit\n");
    printf("-------------------------------------------------\n");
    printf("\nMasukan Nomor Menu : ");
    pilihan = validasiPilihan();
    printf("\n");
    system("cls");

    switch (pilihan){
	    case 1:
	    luasBangunDatar();
	    break;
	    case 2:
	    kelilingBangunDatar();
	    break;
	    default:
        printf("PROGRAM TELAH BERHENTI\n\n");
	    break;
	 }
}

//Sub Menu Luas
void luasBangunDatar(){
	int pilihan;

    printf("=================================================\n\n");
    printf("             PROGRAM MENGHITUNG LUAS &           \n");
    printf("               KELILING BANGUN DATAR             \n\n");
    printf("-------------------------------------------------\n");
    printf("                 PENGHITUNGAN LUAS               \n");
    printf("=================================================\n\n");
    printf("Pilih Bangun Datar Dibawah\n");
    printf("\t1.Segitiga Sembarang\n");
    printf("\t2.Belah Ketupat\n");
    printf("\t3.Jajargenjang\n");
    printf("\t4.Trapesium\n");
    printf("\t5.Lingkaran\n");
    printf("\t6.Kembali\n");
    printf("-------------------------------------------------\n");
    printf("Masukan Nomor Menu : ");
    pilihan = validasiMenu();
    system("cls");

    switch (pilihan){
	    case 1:
	    lSegitigaSembarang();
	    break;
	    case 2:
	    lBelahKetupat();
	    break;
	    case 3:
	    lJajargenjang();
	    break;
	    case 4:
	    lTrapesium();
	    break;
	    case 5:
	    lLingkaran();
	    break;
	    default:
	    menu();
	    break;
	 }
}

// Luas Segitiga Sembarang
void lSegitigaSembarang(){
    int pilihan;
    float a,b,c,s,luas;

    printf("=================================================\n\n");
    printf("       PROGRAM MENGHITUNG LUAS BANGUN DATAR      \n\n");
    printf("-------------------------------------------------\n");
    printf("         Hitung Luas Segitiga Sembarang          \n");
    printf("=================================================\n\n");

    printf("Masukan Panjang Sisi a (cm) : ");
    a = validasiBil();
    printf("Masukan Panjang Sisi b (cm) : ");
    b = validasiBil();
    printf("Masukan Panjang Sisi c (cm) : ");
    c = validasiBil();

    if (a!=b && a!=c && b!=c && b!=a)
    {
        //Kalau Input bener
        luas =  hitungLuasSegitigaSembarang(a,b,c);
        printf("Luas Segitiga Sembarang adalah : %.2f cm2\n",luas);
    } else
    {
        //Kalau Input ada yg sama
        system("cls");
        printf("SISI TIDAK BOLEH SAMA \n");
        printf("Ulangi Masukkan angka \n");
        lSegitigaSembarang();
    }

    printf("\n\n=================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    lSegitigaSembarang();
	    break;
	    case 2:
	    luasBangunDatar();
	    break;
	    default:
	    menu();
	    break;
	 }
}

// Luas Belah Ketupat
void lBelahKetupat(){
	int pilihan;
    float da,db,luas;

    printf("=================================================\n\n");
    printf("       PROGRAM MENGHITUNG LUAS BANGUN DATAR      \n\n");;
    printf("-------------------------------------------------\n");
    printf("            Hitung Luas Belah Ketupat            \n");
    printf("=================================================\n\n");
    printf("Masukan Panjang d1 (cm) : ");
    da = validasiBil();
    printf("Masukan Panjang d2 (cm) : ");
    db = validasiBil();

    luas = hitungLuasBelahKetupat(da,db);
    printf("Luas Belah Ketupat adalah : %.2f cm2\n",luas);

    printf("\n\n=================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    lBelahKetupat();
	    break;
	    case 2:
	    luasBangunDatar();
	    break;
	    default:
	    menu();
	    break;
    }
}

// Luas Jajargenjang
void lJajargenjang(){
    int pilihan;
    float a,t,luas;

    printf("=================================================\n\n");
    printf("       PROGRAM MENGHITUNG LUAS BANGUN DATAR      \n\n");
    printf("-------------------------------------------------\n");
    printf("            Hitung Luas Jajargenjang             \n");
    printf("=================================================\n\n");
    printf("Masukan Panjang Alas (cm) : ");
    a = validasiBil();
    printf("Masukan Tinggi (cm) : ");
    t = validasiBil();

    luas = hitungLuasJajargenjang(a,t);
    printf("Luas Jajargenjang adalah : %.2f cm2\n",luas);

    printf("\n\n=================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    lJajargenjang();
	    break;
	    case 2:
	    luasBangunDatar();
	    break;
	    default:
	    menu();
	    break;
    }
}

// Luas Trapesium
void lTrapesium(){
    int pilihan;
    float a,b,t,luas;

    printf("=================================================\n\n");
    printf("       PROGRAM MENGHITUNG LUAS BANGUN DATAR      \n\n");
    printf("-------------------------------------------------\n");
    printf("             Hitung Luas Trapesium               \n");
    printf("=================================================\n\n");
    printf("Masukan Panjang Sisi Atas (cm)  : ");
    a = validasiBil();
    printf("Masukan Panjang Sisi Bawah (cm) : ");
    b = validasiBil();
    printf("Masukan tinggi (cm) : ");
    t = validasiBil();

    if (a!=b && b!=a)
    {
        // Kalau Input bener
        luas = hitungLuasTrapesium(a,b,t);
        printf("Luas Trapesium adalah : %.2f cm2\n",luas);

    } else
    {
        // Kalau input ada yg sama
        system("cls");
        printf("ANGKA UNTUK TINGGI DAN ALAS TIDAK BOLEH SAMA\n");
        printf("Ulangi Masukkan angka \n");
        lTrapesium();
    }

    printf("\n\n=================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    lTrapesium();
	    break;
	    case 2:
	    luasBangunDatar();
	    break;
	    default:
	    menu();
	    break;
    }
}

// Luas Lingkaran
void lLingkaran(){
    int pilihan;
    float r,luas;

    printf("=================================================\n\n");
    printf("       PROGRAM MENGHITUNG LUAS BANGUN DATAR      \n\n");
    printf("-------------------------------------------------\n");
    printf("             Hitung Luas Lingkaran               \n");
    printf("=================================================\n\n");
    printf("Masukan Panjang Jari-jari (cm) : ");
    r = validasiBil();

    luas = hitungLuasLingkaran(r);
    printf("Luas Lingkaran adalah : %.2f cm2\n",luas);

    printf("\n\n=================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    lLingkaran();
	    break;
	    case 2:
	    luasBangunDatar();
	    break;
	    default:
	    menu();
	    break;
    }
}

// Sub Menu Keliling
void kelilingBangunDatar(){
	int pilihan;

    printf("=================================================\n\n");
    printf("             PROGRAM MENGHITUNG LUAS &           \n");
    printf("               KELILING BANGUN DATAR             \n\n");
    printf("-------------------------------------------------\n");
    printf("               PENGHITUNGAN KELILING             \n");
    printf("=================================================\n\n");
    printf("Pilih Bangun Datar Dibawah\n");
    printf("\t1.Segitiga Sembarang\n");
    printf("\t2.Belah Ketupat\n");
    printf("\t3.Jajargenjang\n");
    printf("\t4.Trapesium\n");
    printf("\t5.Lingkaran\n");
    printf("\t6.Kembali\n");
    printf("-------------------------------------------------\n");
    printf("Masukan Nomor Menu : ");
    pilihan = validasiMenu();
    system("cls");

    switch (pilihan){
	    case 1:
	    kSegitigaSembarang();
	    break;
        case 2:
	    kBelahKetupat();
	    break;
	    case 3:
	    kJajargenjang();
	    break;
	    case 4:
	    kTrapesium();
	    break;
	    case 5:
	    kLingkaran();
	    break;
	    default:
	    menu();
	    break;
    }
}

// Keliling Segitiga Sembarang
void kSegitigaSembarang(){
	int pilihan;
    float a,b,c,kel;

    printf("=================================================\n\n");
    printf("    PROGRAM MENGHITUNG KELILING BANGUN DATAR     \n\n");
    printf("-------------------------------------------------\n");
    printf("       Hitung Keliling Segitiga Sembarang        \n");
    printf("=================================================\n\n");

    printf("Masukan Panjang Sisi a (cm) : ");
    a = validasiBil();
    printf("Masukan Panjang Sisi b (cm) : ");
    b = validasiBil();
    printf("Masukan Panjang Sisi c (cm) : ");
    c = validasiBil();

    if (a!=b && a!=c && b!=c && b!=a){
        //Kalau Input bener
        kel = hitungKelSegitigaSembarang(a,b,c);
        printf("Keliling Segitiga Sembarang adalah : %.2f cm2\n",kel);
    }else{
        //Kalau Input ada yg sama
        system("cls");
        printf("SISI TIDAK BOLEH SAMA \n");
        printf("Ulangi Masukkan angka \n");
        kSegitigaSembarang();
    }

    printf("\n\n=================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    kSegitigaSembarang();
	    break;
	    case 2:
	    kelilingBangunDatar();
	    break;
	    default:
	    menu();
	    break;
    }
}

// Keliling Belah Ketupat
void kBelahKetupat(){
    int pilihan;
    float s,kel;

    printf("=================================================\n\n");
    printf("    PROGRAM MENGHITUNG KELILING BANGUN DATAR     \n\n");
    printf("-------------------------------------------------\n");
    printf("          Hitung Keliling Belah Ketupat          \n");
    printf("=================================================\n\n");
    printf(" Masukan Panjang Sisi (cm) :  ");
    s = validasiBil();
    kel = hitungKelBelahKetupat(s);
    printf("Keliling Belah Ketupat adalah : %.2f cm\n",kel);

    printf("\n\n=================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    kBelahKetupat();
	    break;
	    case 2:
	    kelilingBangunDatar();
	    break;
	    default:
	    menu();
	    break;
    }
}

// Keliling Jajargenjang
void kJajargenjang(){
    int pilihan;
    float a,b,kel;

    printf("=================================================\n\n");
    printf("    PROGRAM MENGHITUNG KELILING BANGUN DATAR     \n\n");
    printf("-------------------------------------------------\n");
    printf("          Hitung Keliling Jajargenjang           \n");
    printf("=================================================\n\n");
    printf("Masukan Panjang Alas (cm) : ");
    a = validasiBil();
    printf("Masukan Panjang Sisi Miring (cm) : ");
    b = validasiBil();
    kel = hitungKelJajargenjang(a,b);
    printf("Keliling Jajargenjang adalah : %.2f cm\n",kel);

    printf("\n\n=================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    kJajargenjang();
	    break;
	    case 2:
	    kelilingBangunDatar();
	    break;
	    default:
	    menu();
	    break;
    }
}

// Keliling Trapesium
void kTrapesium(){
	int pilihan;
    float a,b,c,d,kel;

    printf("=================================================\n\n");
    printf("    PROGRAM MENGHITUNG KELILING BANGUN DATAR     \n\n");
    printf("-------------------------------------------------\n");
    printf("            Hitung Keliling Trapesium            \n");
    printf("=================================================\n\n");
    printf("Masukan Panjang Sisi Atas (cm) : ");
    a = validasiBil();
    printf("Masukan Panjang Sisi Bawah (cm) : ");
    b = validasiBil();
    printf("Masukan Panjang Sisi Samping A (cm) : ");
    c = validasiBil();
    printf("Masukan Panjang Sisi Samping B (cm) : ");
    d = validasiBil();

    if (a!=b){
        //Kalau Input bener
        kel = hitungKelTrapesium(a,b,c,d);
        printf("Keliling Trapesium adalah : %.2f cm2\n",kel);

    } else{
        //Kalau Input ada yang sama
        system("cls");
        printf("SISI TIDAK BOLEH SAMA\n");
        printf("Ulangi Masukkan angka \n");
        kTrapesium();
    }

    printf("\n\n=================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    kTrapesium();
	    break;
	    case 2:
	    kelilingBangunDatar();
	    break;
	    default:
	    menu();
	    break;
    }
}

// Keliling Lingkaran
void kLingkaran(){
    int pilihan;
    float r,kel;

    printf("=================================================\n\n");
    printf("    PROGRAM MENGHITUNG KELILING BANGUN DATAR     \n\n");
    printf("-------------------------------------------------\n");
    printf("           Hitung Keliling Lingkaran             \n");
    printf("=================================================\n\n");
    printf("Masukan Panjang Jari-jari (cm) : ");
    r = validasiBil();
    kel = hitungKelLingkaran(r);
    printf("Keliling Lingkaran adalah : %.2f cm\n",kel);

    printf("\n\n=================================================\n");
    printf("          1.Ulangi      2.Kembali       3.MENU\n");
    printf("-------------------------------------------------\n");
    printf("Masukan Pilihan Anda : ");
    pilihan = validasiPilihan();
    system("cls");

	switch(pilihan){
	    case 1:
	    kLingkaran();
	    break;
	    case 2:
	    kelilingBangunDatar();
	    break;
	    default:
	    menu();
	    break;
    }
}
