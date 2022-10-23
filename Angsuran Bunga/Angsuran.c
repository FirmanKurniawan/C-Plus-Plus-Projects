#include <stdio.h>

void hitungBunga(int pokok_pinjaman, float besar_bunga, int lama_pinjaman)
{
    double angsuran_pokok;
    double total_bunga = 0;
    double total_angsuran = 0;
    puts("++------------------------------------------------------------------------++");
    puts("|| Bulan \t  Bunga \tAngsuran Pokok \t\tAngsuran Perbulan ||");
    puts("++------------------------------------------------------------------------++");

    for (int i = 1; i <= lama_pinjaman; i++)
    {
        angsuran_pokok = pokok_pinjaman / lama_pinjaman;
        double bunga = (pokok_pinjaman - ((i - 1) * angsuran_pokok)) * besar_bunga / 12;
        total_bunga += bunga;
        total_angsuran += angsuran_pokok + bunga;
        printf("||  %d \t\t Rp. %.2f \t   Rp. %.2f \t    Rp. %.2f  ||\n", i, bunga, angsuran_pokok, angsuran_pokok + bunga);
    }
    puts("++------------------------------------------------------------------------++");
    printf("|| Total Bunga \t\t\t\t\t Rp. %.2f \t\t  ||", total_bunga);
    printf("\n|| Total Angsuran \t\t\t\t Rp. %.2f \t  ||\n", total_angsuran);
    puts("++------------------------------------------------------------------------++");
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

int validasi(float *var, char nama[100])
{
    if (scanf("%f", var) != 1)
    {
        clean();
        printf("Hanya masukkan angka!, masukkan ulang %s! : ", nama);
        validasi(var, nama);
    }
    return 1;
}

int main()
{
    float pokok_pinjaman, lama_pinjaman, besar_bunga;
    char ulangi;
    do
    {
        system("clear || cls");
        puts("+=======================================================================+");
        puts("|\t\t\tProgram Perhitungan Angsuran\t\t\t|");
        puts("+=======================================================================+");
        printf("Jumlah Pinjaman : ");
        validasi(&pokok_pinjaman, "pokok pinjaman");
        printf("Besar Bunga (%%) : ");
        validasi(&besar_bunga, "besar bunga");
        printf("Pokok Lama Peminjaman (Bulan) : ");
        validasi(&lama_pinjaman, "lama peminjaman");
        hitungBunga(pokok_pinjaman, (float)besar_bunga / 100, lama_pinjaman);
        clean();
        printf("Ingin Mengulangi ? : [y/n] ");
        scanf("%c", &ulangi);
    } while (ulangi == 'y' || ulangi == 'Y');
    printf("Terimakasih!\n");

    return 0;
}
