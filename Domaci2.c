//Drugi domaci iz programiranja
#include <stdio.h>
struct radnici{
   char ime[250];
   int satDolaska[30], minDolaska[30], sekDolaska[30], satOdlaska[30], minOdlaska[30], sekOdlaska[30], razlikaSat[30], razlikaMin[30], razlikaSek[30];
}niz[5];
void unos(struct radnici niz[], int n, int *pn);
int main (){
   int n,dani, exit,i,j;
   do {
      loop: printf ("Unesite koliko ima radnih dana u sedmici vasa firma: ");
      scanf ("%d", &dani);
      if (dani<=0 || dani >7)
         goto loop;
      petlja1:printf ("Unesite broj radnika vase firme (maksimalno 5): ");
      scanf ("%d", &n);
      if (n<=0 || n >5)
         goto petlja1;
      struct radnici niz[5];
      unos(niz,n, &dani);
      float sum[10],sumSati[10];
      for (i=0; i<n; i++){
         printf ("\n--------------------------------------\n");
         for (j=0; j<dani; j++){
            printf ("%s  je radio %d. dana ---->\t %.2dh %.2d m %.2ds \n", niz[i].ime, j+1, niz[i].razlikaSat[j], niz[i].razlikaMin[j], niz[i].razlikaSek[j]);
            sum[i]+= (niz[i].razlikaSat[j])*3600 + (niz[i].razlikaMin[j])*60 + niz[i].razlikaSek[j];
            sumSati[i]=sum[i]/3600;
         }
         printf ("%s je u toku sedmice ukupno radio | %.2f | sati. \n",niz[i].ime, sumSati[i]);
         printf ("\n--------------------------------------\n");
      }
       printf ("Za gasenje programa upisite nulu, za ponovno pokretanje upisite bilo koji broj:  ");
       scanf ("%d", &exit);
    } while(exit!=0);
return 0;
}
void unos(struct radnici niz[], int n, int *pn){
      int i,j;
      for(i=0;i<n;i++){
         printf ("Unesi ime %d. radnika: ", i+1);
         scanf (" %250[^\n]", niz[i].ime);
         for (j=0;j<*pn;j++){
            petlja: printf ("\nUnesi u koliko je  %s dosao na posao %d. dana u sedmici (hh mm ss): ", niz[i].ime, j+1);
            scanf ("%d%d%d", &niz[i].satDolaska[j], &niz[i].minDolaska[j], &niz[i].sekDolaska[j]);

            if (niz[i].satDolaska[j] < 0 || niz[i].satDolaska[j] > 24 || niz[i].minDolaska[j] < 0 || niz[i].minDolaska[j] > 60 || niz[i].sekDolaska[j] < 0 || niz[i].sekDolaska[j] > 60)
            goto petlja;
            petlja33: printf ("\nUnesi u koliko je  %s otisao sa posla %d. dana (hh mm ss): ", niz[i].ime, j+1);
            scanf ("%d%d%d", &niz[i].satOdlaska[j], &niz[i].minOdlaska[j], &niz[i].sekOdlaska[j]);
            if (niz[i].satOdlaska[j] < 0 || niz[i].satOdlaska[j] > 24 || niz[i].minOdlaska[j] < 0 || niz[i].minOdlaska[j] > 60 || niz[i].sekOdlaska[j] < 0 || niz[i].sekOdlaska[j] > 60)
            goto petlja33;
            niz[i].razlikaSat[j]=niz[i].satOdlaska[j] - niz[i].satDolaska[j];
            niz[i].razlikaMin[j]=niz[i].minOdlaska[j] - niz[i].minDolaska[j];
            niz[i].razlikaSek[j]=niz[i].sekOdlaska[j] - niz[i].sekDolaska[j];
            if(niz[i].razlikaMin[j]<0){
                niz[i].razlikaMin[j]=60+niz[i].razlikaMin[j];
                niz[i].razlikaSat[j]--;
            }
            if(niz[i].razlikaSek[j]<0){
                niz[i].razlikaSek[j]=60+niz[i].razlikaSek[j];
                niz[i].razlikaMin[j]--;
            }
            if (niz[i].razlikaSek[j]<0 || niz[i].razlikaMin[j]<0 || niz[i].razlikaSat[j]<0){
               printf ("Uneli ste nemoguce podatke (upisite ponovo) \n");
               goto petlja;
            }
         }
      }
}
//Student: Kalač Ilhan 429/16
