#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  // Star Pattern#1
  int sisi;
  cout << "Masukkan sisi : ";
  cin >> sisi;
  for (int i = 1; i <= sisi; i++) {
    for (int j = 1; j <= sisi; j++) {
      cout << "*";
    }
    cout << endl;
  }


  // Star Pattern#2
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      if ((i == 1 || i == 5) || (j == 1 || j == 5)) {
        cout << "*";
      }
      else {
        cout << " ";
      }
    }
    cout << endl;
  }


  // Star Pattern#3
  int input;

  cout << "Jumlah Baris Bintang = ";
  cin >> input;

  for (int i = 1; i <= input; i++) {
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    cout << endl;
  }


  // Star Pattern#4
  for (int i = 1; i <= 5; i++)
  {
    for (int j = 1; j < i; j++)
    {
      cout << " ";
    }
    for (int k = 5; k >= i; k--)
    {
      cout << "*";
    }
    cout << endl;
  }
  for (int l = 1; l < 5; l++)
  {
    for (int m = 5-1; m > l; m--)
    {
      cout << " ";
    }
    for (int n = 0; n <= l; n++)
    {
      cout << "*";
    }
    cout << endl;
  }


  // Star Pattern#5
  int input;

  cout << "Input = ";
  cin >> input;

  cout << "Output = " << endl;
  for (int i = 1, k = 0; i <= input; i++, k = 0) {
    k = 0;
    for (int j = 0; j <= input-i; j++) {
      cout << " ";
    }
    while(k != 2*i-1) {
      cout << "*";
      k++;
    }
    cout << endl;
  }
  

  // Number pattern #1
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= i; j++)
    {
        cout << j << " "; 
    }
    cout << endl;
  }

  Number pattern #2
  int input, r = 1;
    
    cout << "Input = ";
    cin >> input;

    for (int i = input; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << r; 
        }
        cout << endl;
        r++;
    }

  
  // Number pattern #3
  int kali = 1;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cout << j * kali << " "; 
        }
        cout << endl;
        kali++;
    }

  
  // Number pattern #4
  int j, r = 4;
    for (int i = 1; i < 5; i++) {
        for (j = 1; j <= i; j++)
        {
             cout << j; 
        }
        cout << endl;
    }
    for (int k = 4; k >= 1; k--) {
        for (int l = 1; l <= k; l++) {
            cout << r; 
        }
        cout << endl;
        r--;
    }

  
  // Number pattern #5
  int kali = 10;
    for (int i = 10; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << j * kali; 
        }
        cout << endl;
        kali--;
    }
  
  
  return 0;
}
