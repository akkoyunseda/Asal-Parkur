# include <stdio.h>
# include <stdlib.h>

int AasalMi(int a, int b, int c, int s);
void sonuc(int x, FILE *P);

int main()
{
    printf("log.txt dosyasina bakiniz.\n");
    FILE *fp;
    fp = fopen("log.txt","w");

    if(fp == NULL)
    {
        printf("log.txt dosyasi acilmadi!\n");
        exit(1);
    }

    fprintf(fp, "Yarisma basladi!!\n");
    fprintf(fp, "Yarismaci HP = 100\n");

    int parkur_uz;
    srand(time(NULL));
    parkur_uz = 49+rand()%51;


    int v=0;
    int j=5;

    int engel;
    srand(time(NULL));
    engel = 2+rand()%3;
    int dizi[engel];
    int hp[engel];
    int metre;
    int i,m;

    for(i=0; i<engel; i++)
    {
        srand(time(NULL));
        metre = j+rand()%(parkur_uz-j);
        dizi[i] = metre;
        j = metre;
    }
    int temp;
    for(i=0; i<engel-1; i++)
    {
        for(int j=0; j<engel-i-1; j++)
        {
            if(dizi[j] > dizi[j+1])
            {
                temp = dizi[j];
                dizi[j] = dizi[j+1];
                dizi[j+1] = temp;
            }
        }
    }
    for(i=0; i<engel; i++)
    {
        if(dizi[i] == dizi[i+1])
        {
            srand(time(NULL));
            dizi[i+1] = (dizi[i]+1) + rand()%(parkur_uz-dizi[i]);
        }

    }


    for(i=0; i<engel; i++)
    {

        hp[0] = 100;
        fprintf(fp,"Yarismaci %d. metreye kadar bir engelle karsilasmadi.\n", dizi[i]);
        fprintf(fp, "%d. metrede bir engel var.",dizi[i]);
        if(AasalMi(hp[i],hp[i+1],dizi[i],m) == 1)
        {
             fprintf(fp, "%d ile %d aralarinda asal degildir.\n",hp[i],dizi[i]);
                hp[i+1] = hp[i];
        }
        else
        {
            fprintf(fp,"%d ile %d aralarinda asaldir.\n",hp[i],dizi[i]);
            hp[i+1] = hp[i] - dizi[i];
        }
        fprintf(fp,"Yarismaci HP = %d\n",hp[i+1]);
        v++;
    }

    sonuc(hp[v],fp);

    return 0;
}

int AasalMi(int a, int b, int c,int s)
{
    int i, ks, bs;


    if(a<c)
    {
        ks = a;
        bs = c;
    }
    else
    {
        ks = c;
        bs = a;
    }
    for(i=2; i<=ks; i++)
    {
        if(bs%i==0 && ks%i==0)
        {
           s=1;
           return 1;
        }
    }

}

void sonuc(int x, FILE *p)
{
    if(x>0)
    {
        fprintf(p, "Tebrikler!! Yarismayi %d HP ile biridiniz!!\n",x);
    }
    else
        fprintf(p, "Uzgunum!! Malesef yarismayi tamamlayamadiniz, elendiniz.\n");
}
