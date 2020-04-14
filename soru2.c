#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int SayiUret (int dizi[8][6]);
void LotoEkranaYazdir(int dizi[8][6]);
void DosyayaYazdir(int dizi[8][6]);
void siralama(int dizi[8][6]);

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
    siralama(dizi);
    DosyayaYazdir(dizi);
}
void LotoEkranaYazdir(int dizi[8][6]) {
    FILE *dosya;
    dosya=fopen("kupon.txt","r");
    for (int j = 0; j < 6; ++j) {
        fscanf(dosya,"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", &dizi[0][j], &dizi[1][j], &dizi[2][j], &dizi[3][j], &dizi[4][j],
               &dizi[5][j], &dizi[6][j], &dizi[7][j]);
    }
    for (int j = 0; j < 6; ++j) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", dizi[0][j], dizi[1][j], dizi[2][j], dizi[3][j], dizi[4][j],
               dizi[5][j], dizi[6][j], dizi[7][j]);
    }
    fclose(dosya);
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
    LotoEkranaYazdir(dizi);
}
void siralama(int dizi[8][6]) {
    for (int j = 0; j <8 ; ++j) {
        for (int k = 0; k < 6; ++k) {
            for (int i = 0; i < 5; ++i) {
                int tut;
                if (dizi[j][i] > dizi[j][i + 1]) {
                    tut = dizi[j][i];
                    dizi[j][i] = dizi[j][i + 1];
                    dizi[j][i + 1] = tut;
                }
            }
        }
    }
}


