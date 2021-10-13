#include <iostream>
using namespace std; 
int main() {
    
  int a; 
  cout << "=====Program mengecek Angka=====" << endl; 
  cout << "Pilih angka 1, 2, 3, 4, atau 5: ";
  cin >> a; 
  
  switch (a) {
      
    case 1:
      cout << "\nIni adalah angka 1" << endl; 
      break;
      
    case 2:
      cout << "\nIni adalah angka 2" << endl; 
      break;
      
    case 3:
      cout << "\nIni adalah angka 3" << endl; 
      break;
      
    case 4: 
      cout << "\nIni adalah angka 4" << endl;
      break; 
      
    case 5: 
      cout << "\nIni adalah angka 5" << endl; 
      break;
      
    default:
      cout << "\nAnda tidak memasukkannya sesuai keterangan. Silahkan coba lagi" << endl; 
  }

  return 0; 
}
