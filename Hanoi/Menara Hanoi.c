#include <stdio.h>
#include <math.h>

char tower[3] = {'A', 'B', 'C'};

void hanoiRekursif(int jumlah_cakram, int from, int middle, int to)
{
    if (jumlah_cakram > 0)
    {
        hanoiRekursif(jumlah_cakram - 1, from, to, middle);
        printf("Memindahkan piringan dari %c ke %c\n", tower[from], tower[to]);
        hanoiRekursif(jumlah_cakram - 1, middle, from, to);
    }
}

void hanoiIteratif(int total_langkah)
{
    for (int i = 1; i < total_langkah; i++)
    {
        printf("Pindahkan piringan dari %c ke %c\n", tower[(i - (i & -i)) % 3], tower[(i + (i & -i)) % 3]);
    }
}

void clean()
{
    /*
        berfungsi untuk mengosongkan karakter-karakter yang tersimpan 
        di dalam buffer sampai ketemu karakter newline (â€˜\nâ€™).
    */
    while (getchar() != '\n')
        ;
}

int validasi(int *var, char nama[100], int size)
{
    if (scanf("%d", var) != 1)
    {
        clean();
        printf("Hanya masukkan angka!, masukkan ulang %s! : ", nama);
        validasi(var, nama, size);
    }
    else if (*var > size)
    {
        clean();
        printf("Angkanya melebihi batas size (%d)!, masukkan ulang %s! : ", size, nama);
        validasi(var, nama, size);
    }
    else if (*var < 1)
    {
        clean();
        printf("Jangan masukkan angka negatif!, masukkan ulang %s! : ", nama);
        validasi(var, nama, size);
    }
    return 1;
}

int main()
{
    int jumlah_cakram, menu, total_langkah;
    char ulangi;
    do
    {
        system("cls || clear");
        puts("+=======================================================================+");
        puts("|\t\tProgram memindahkan Cakram pada Menara Hanoi\t\t|");
        puts("+=======================================================================+");
        puts("|\t\t\t\tMENU PROGRAM\t \t\t\t|");
        puts("+=======================================================================+");
        puts("| 1. Menara Hanoi Iteratif\t\t\t\t\t\t|");
        puts("| 2. Menara Hanoi Rekursif\t\t\t\t\t\t|");
        puts("| 3. Keluar Program\t\t\t\t\t\t\t|");
        puts("+=======================================================================+");
        printf("Masukkan Pilihan mu : ");
        validasi(&menu, "menu", 3);
        if (menu == 3)
        {
            puts("Terimakasih!");
            return 0;
        }
        clean();
        printf("Masukkan jumlah cakram : ");
        validasi(&jumlah_cakram, "jumlah cakram", 50);
        system("cls || clear");
        total_langkah = (int)pow(2, jumlah_cakram);
        if (menu == 1)
        {
            puts("[METODE ITERATIF]");
            hanoiIteratif(total_langkah);
        }
        else if (menu == 2)
        {
            puts("[METODE REKURSIF]");
            hanoiRekursif(jumlah_cakram, 0, 1, 2);
        }

        printf("Jumlah langkah minimum yang dibutuhkan adalah %d\n\n", total_langkah - 1);
        clean();
        printf("Ingin Mengulangi ? : [y/n] ");
        scanf("%c", &ulangi);
    } while (ulangi == 'y' || ulangi == 'Y');
    printf("Terimakasih!\n");

    return 0;
}
