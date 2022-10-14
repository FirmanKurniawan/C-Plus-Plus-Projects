#include <iostream> 

void factorialization(int num) {
    long factorial = 1;

    if(num > 1) {
        for(int i = 1; i <= num; i++) {
            factorial *= i; 
        }
        std::cout << factorial << "\n"; 
    } else if(num == 0 || num == 1) {
        std::cout << 1 << "\n"; 
    } else {
        std::cout << "Tidak ada operasi faktorial pada bilangan negatif!" << "\n";  
    }
}

int main() {
    int input; 
    
    std::cout << "Factorialization" << "\n"; 
    std::cout << "Silahkan masukkan angka yang ingin difaktorialkan: "; 
    std::cin >> input; 
    
    std::cout << "\nHasilnya: "; 
    factorialization(input);
    
    return 0;
}
