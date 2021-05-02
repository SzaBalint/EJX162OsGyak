#include <stdio.h>
#include <stdlib.h>

int main()
{
    int db;

    FILE *fp;
    FILE * fd;
    fd= fopen("kimenet.txt","w");
    fp = fopen("bemenet.txt","r");
    fscanf(fp,"%d",&db);
    printf("%d\n",db);
    int tomb[db];
    int tomb2[db];
    for(int i = 0;i<db;i++){
         fscanf(fp,"%d %d",&tomb[i],&tomb2[i]);
    }
    int *p;
    p = &tomb[0];
    int *p2;
    p2 = &tomb2[0];
    for(int i =0;i<db;i++){
         printf("%d %d\n",*(p+i),*(p2+i));

    }
    int m;
    for (int i =0;i<db;i++){
    if(tomb[i] < tomb2[i])
    {
        m=tomb[i];
        tomb[i]=tomb2[i];
        tomb2[i]=m;
    }

        m=tomb2[i];
    while(tomb[i]%m != 0 || tomb2[i]%m != 0)
    {
        m = m-1;
    }
    printf("%d  %d  %d\n", tomb2[i], tomb[i], m);
    fprintf(fd,"%d %d %d\n",tomb2[i], tomb[i], m);
    }
    fclose(fd);
    fclose(fp);



    return 0;
}
