#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int SayiUret (int dizi[8][6]);
void LotoEkranaYazdir(int dizi[8][6]);
void DosyayaYazdir(int dizi[8][6]);

int main() {
    int dizi[8][6];
        SayiUret(dizi);
        system("pause");
    return 0;
}
int SayiUret ( int dizi[8][6])
{
    srand(time(NULL));
    for (int i = 0; i <8 ; ++i) {
        for (int j = 0; j < 6; ++j) {
            dizi[i][j] = 1 + rand() % 49;
            for (int k = 1; k <=j ; ++k) {
                if (dizi[i][j] == dizi[i][j-k])
                    j--;
            }
        }
    }

        LotoEkranaYazdir(dizi);
}
void LotoEkranaYazdir(int dizi[8][6]) {
    for (int j = 0; j < 6; ++j) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", dizi[0][j], dizi[1][j], dizi[2][j], dizi[3][j], dizi[4][j],
               dizi[5][j], dizi[6][j], dizi[7][j]);
    }
    DosyayaYazdir(dizi);
}
void DosyayaYazdir(int dizi[8][6])
{
    FILE *dosya;
    dosya=fopen("kupon.txt","w");
    for (int j = 0; j < 6; ++j) {
        fprintf(dosya,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", dizi[0][j], dizi[1][j], dizi[2][j], dizi[3][j], dizi[4][j],
               dizi[5][j], dizi[6][j], dizi[7][j]);
    }
    fclose(dosya);
}


