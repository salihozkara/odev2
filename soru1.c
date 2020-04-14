#include <stdio.h>
#include <stdlib.h>

int karakterSay()
{
    int karakterSayisi=0;
    FILE *dosya;
    dosya=fopen("text.txt","r");
    if(!dosya)
    {
        printf("dosya bulunamadi.\n");
        system("pause");
        exit(1);
    }
    while(1){
        if(fgetc(dosya) != EOF)
            karakterSayisi++;
        else
            break;
    }
    fclose(dosya);
    return karakterSayisi;
}
void sesliHarfSay()
{
    char sesliHarf[]={'a','e','i','o','u'};
    int karakterSayisi,toplam=0;
    FILE *dosya;
    dosya=fopen("text.txt","r");
    karakterSayisi=karakterSay();
    char dizi[karakterSayisi];
    for (int k = 0; k <karakterSayisi ; ++k) {
        fscanf(dosya,"%c",&dizi[k]);
    }
    fclose(dosya);
    for (int i = 0; i <5 ; ++i) {
        for (int j = 0; j <karakterSayisi ; ++j) {
            if(sesliHarf[i]==dizi[j])
                toplam++;
        }
    }
    printf("toplam sesli harf=%d\n",toplam);
    system("pause");
}
int main() {
    sesliHarfSay();
    return 0;
}