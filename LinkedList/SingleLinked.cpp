  #include<iostream.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node *simpul;
struct node
{
  char Isi;
  simpul Next;
};
//======================
//==Prototype Function==
//======================
void Sisip_Depan(simpul &L, char elemen);
void Sisip_Belakang(simpul &L, char elemen);
void Sisip_Tengah1(simpul &L, char elemen1, char elemen2);
void Sisip_Tengah2(simpul &L, char elemen1, char elemen2);
void Hapus_Depan(simpul &L);
void Hapus_Belakang(simpul &L);
void Hapus_Tengah(simpul &L, char elemen);
void Cetak(simpul L);

//=================
//==Function Main==
//=================
main()
{
  char huruf, huruf2;
  simpul L = NULL;  //Pastikan bahwa L kosong
  cout<<"==OPERASI PADA SINGLE LINKED LIST=="<<endl<<endl;
  //===============
  //==Sisip Depan==
  //===============
  cout<<"Penyisipan Simpul Di Depan"<<endl<<endl;
  cout<<"Masukkan Huruf :"; cin>>huruf;
  Sisip_Depan(L, huruf);
  cout<<"Masukkan Huruf :"; cin>>huruf;
  Sisip_Depan(L, huruf);
  cout<<"Masukkan Huruf :"; cin>>huruf;
  Sisip_Depan(L, huruf);
  cout<<"Masukkan Huruf :"; cin>>huruf;
  Sisip_Depan(L, huruf);
  Cetak(L);
  //======================
  //====Sisip Belakang====
  //======================
  //==Hapus Simpul Depan==
  //======================
  cout<<endl<<endl<<"Setelah Hapus Simpul Depan "<<;
  Hapus_Depan(L);
  Cetak(L);
  //=========================
  //==Hapus Simpul Belakang==
  //=========================
  cout<<endl<<endl<<"Setelah Hapus Simpul Belakang "<<endl;
  Hapus_Belakang(L);
  Cetak(L);
  //=======================
  //==Hapus Simpul TENGAH==
  //=======================
  cout<<"\n\nMasukkan Huruf Tengah Yang Akan Dihapus :";
  cin>>huruf;
  Hapus_Tengah(L,huruf);
  Cetak(L);
  getch();
}

//**********************************
//**FUNCTION SISIP SIMPUL DI DEPAN**
//**********************************
void Sisip_Depan(simpul &L, char elemen)
{
  simpul baru;  // = new simpul;
  baru = (simpul) malloc(sizeof(simpul));
  baru->Isi = elemen;
  baru->Next = NULL;
  if(L == NULL)
    L=baru;
  else
  {
    baru->Next = L;
    L=baru;
  }
}

//*************************************************
//**FUNCTION SISIP SIMPUL SETELAH SIMPUL TERTENTU**
//*************************************************
void Sisip_Tengah1(simpul &L, char elemen1, char elemen2)
{
  simpul bantu, baru;
  baru = (simpul) malloc(sizeof(simpul));
  baru->Isi = elemen1;
  baru->Next = NULL;
  if(L == NULL)
    cout<<"List Kosong............"<<endl;
  else
  {
    bantu = L;
    while(bantu->Isi != elemen2) bantu=bantu->Next;
    baru->Next = bantu->Next;
    bantu->Next = baru;
  }
}

//*************************************************
//**FUNCTION SISIP SIMPUL SEBELUM SIMPUL TERTENTU**
//*************************************************
void Sisip_Tengah2(simpul &L, char elemen1, char elemen2)
{
  simpul bantu, baru;
  baru = (simpul) malloc(sizeof(simpul));
  baru->Isi = elemen1;
  baru->Next = NULL;
  if(L == NULL)
    cout<<"List Kosong .........."<<endl;
  else
  {
    bantu = L;
    while(bantu->Next->Isi != elemen2) bantu-bantu->Next;
    baru->Next = bantu->Next;
    bantu->Next = baru;
  }
}

//*************************************
//**FUNCTION SISIP SIMPUL DI BELAKANG**
//*************************************
void Sisip_Belakang(simpul &L, char elemen)
{
  simpul bantu, baru;
  baru = (simpul) malloc(sizeof(simpul));
  baru->Isi = elemen;
  baru->Next = NULL;
  if(L == NULL)
    L=baru;
  else
  {
    bantu=L;
    while(bantu->Next != NULL)
      bantu=bantu->Next;
    bantu->Next=baru;
  }
}
//*************************************
//**FUNCTION MENCETAK ISI LINKED LIST**
//*************************************
void Cetak(simpul L)
{
  simpul bantu;
  if(L=NULL)
    cout<<"Linked List Kosong ......"<<endl;
  else
  {
    bantu=L;
    cout<<"Isi Linked List : ";
    while (bantu->Next != NULL)
    {
      cout<<bantu->Isi<<"-->";
      bantu=bantu->Next;
    }
    cout<<bantu->Isi;
  }
}

//*******************************
//**FUNCTION HAPUS SIMPUL DEPAN**
//*******************************
void Hapus_Depan(simpul &L)
{
  simpul Hapus;
  if(L==NULL)
    cout<<"Linked List Kosong ...........";
  else
  {
    Hapus = L;
    L = L->Next;
    Hapus->Next = NULL;
    free(Hapus);
  }
}

//**********************************
//**FUNCTION HAPUS SIMPUL BELAKANG**
//**********************************
void Hapus_Belakang(simpul &L)
{
  simpul bantu, hapus;
  if(L==NULL)
    cout<<"Linked List Kosong ............";
  else
  {
    bantu = L;
    while(bantu->Next->Next != NULL) bantu=bantu->Next;
    hapus = bantu->Next;
    bantu->Next = NULL;
    free(hapus);
  }
}

//***********************************
//**FUNCTION HAPUS SIMPUL DI TENGAH**
//***********************************
void Hapus_Tengah(simpul &L, char elemen)
{
  simpul bantu, hapus;
  if(L==NULL)
    cout<<"Linked List Kosong ............";
  else
  {
    bantu = L;
    while(bantu->Next->Isi != elemen) bantu=bantu->Next;
    hapus = bantu->Next;
    bantu->Next = bantu->Next->Next;
    hapus->Next = NULL;
    free(hapus);
  }
}  //=====================eof=====================
