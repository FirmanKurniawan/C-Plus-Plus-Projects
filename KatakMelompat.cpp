#include <conio.h>

#include <iostream>

//using namespace std; ini saya matiin karena saya make borland

main(){

	int koordinat, lompatKanan, lompatKiri, ulang, hasilAkhir = 0;

	cout << "Masukan Koordinat Katak : ";

	cin >> koordinat;

	cout << "Masukan Panjang Lompatan Katak ke Kanan : ";

	cin >> lompatKanan;

	cout << "Masukan Panjang Lompatan Katak ke Kiri : ";

	cin >> lompatKiri;

	

	if(koordinat >= 0){ // koordinat lebih dari 0 (gak minus)

		if(koordinat % 2 == 0){  // koordinat genap

			ulang = lompatKanan * lompatKiri;

		}else{

			ulang = lompatKanan * 2;  // koordinat ganjil

		}

	}else {  // kalo koordinat minus

		if(koordinat % 3 == 0){

			ulang = lompatKiri * 2;  // koordinat minus tapi kelipatan 3

		}else{

			ulang = lompatKanan * lompatKiri; // koordinat minus aja

		}

	}

   hasilAkhir += koordinat; // set titik koordinat awal

	for(int i = 1; i <= ulang; i++){ // perulangan sebanyak k, dimulai dari 1 karena yang ke-0 nya itu nilai koordinat awalnya.

		if(i % 2 == 1){ // ini kalo si i ganjil, tambah pake panjang lompat kanan.

			hasilAkhir += lompatKanan;

		}else{ // ini kalo si i genap, tambah pake lompat kiri.

			hasilAkhir -= lompatKiri;

		}

	}

	

	cout << "Koordinat Katak Sekarang : " << hasilAkhir;

	

	getch();

}
