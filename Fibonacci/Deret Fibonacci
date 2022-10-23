#include <stdio.h>

void menu()
{
    system("clear || cls");
    puts("+===============================================+");
    puts("|\t\tPROGRAM DERET FIBONACCI\t\t|");
    puts("+===============================================+");

    puts("| Menu Program : \t\t\t\t|");
    puts("| [1] Fibonacci Rekursif\t\t\t|");
    puts("| [2] Fibonacci Iteratif\t\t\t|");
    puts("| [3] Keluar Program\t\t\t\t|");
    puts("+===============================================+");
}

int fiboRekursif(int bilangan)
{
    if (bilangan == 0 || bilangan == 1)
    {
        return bilangan;
    }
    return fiboRekursif(bilangan - 2) + fiboRekursif(bilangan - 1);
}

void deretFiboRekursif(int jumlah_deret)
{
    for (int i = 0; i < jumlah_deret; i++)
    {
        printf("%d ", fiboRekursif(i));
    }
    printf("\n");
}

void deretFiboIteratif(int jumlah_deret)
{
    int bilangan1 = 0, bilangan2 = 1;
    int tampung;
    for (int i = 0; i < jumlah_deret; i++)
    {
        if (i == 0 || i == 1)
        {
            printf("%d ", i);
        }
        else
        {
            tampung = bilangan1 + bilangan2;
            bilangan1 = bilangan2;
            bilangan2 = tampung;
            printf("%d ", tampung);
        }
    }
    printf("\n");
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

int validasi(int *var, char nama[100])
{
    if (scanf("%d", var) != 1)
    {
        clean();
        printf("Hanya masukkan angka!, masukkan ulang %s! : ", nama);
        validasi(var, nama);
    }
    return 1;
}

int main()
{
    char ulangi;
    int pilihan, jumlah_deret;
    do
    {
        menu();
        printf("Masukkan pilihanmu : ");
        validasi(&pilihan, "pilihan [1-3]");
        if (pilihan >= 1 && pilihan <= 2)
        {
            printf("Masukkan jumlah deret yang diinginkan : ");
            validasi(&jumlah_deret, "jumlah deret");
            if (pilihan == 1)
            {
                deretFiboRekursif(jumlah_deret);
            }
            else
            {
                deretFiboIteratif(jumlah_deret);
            }
        }
        else if (pilihan == 3)
        {
            printf("Terimakasih!");
            return 0;
        }
        else
        {
            printf("Hanya masukkan angka 1 - 3!\n");
        }
        clean();
        printf("Ingin Mengulangi ? : [y/n] ");
        scanf("%c", &ulangi);
    } while (ulangi == 'y' || ulangi == 'Y');
    printf("Terimakasih!");

    return 0;
}
