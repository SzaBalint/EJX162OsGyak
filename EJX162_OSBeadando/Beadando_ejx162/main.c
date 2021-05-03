#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{

 mkfifo("myfifo", 0777);
 pid_t child = fork();

 int db;
 int fd;


    if(child == 0){
        int fd;
        fd = open("myfifo",O_RDONLY);
        read(fd,&db,sizeof(int));

        int tomb[db];
        int tomb2[db];
        for( int i =0;i<db;i++){
           read(fd,&tomb[i],sizeof(tomb[i]));
        }
        for( int i =0;i<db;i++){
           read(fd,&tomb2[i],sizeof(tomb2[i]));
        }

        int *p,*p2;

        p2 = &tomb2[0];
        p=&tomb[0];

        printf("\n%d\n",db);
        for(int i = 0; i<db;i++){
          printf("%d %d\n",*(p+i),*(p2+i));
        }
         FILE * ki;
         ki = fopen("kimenet.txt","w");

            int m;
    for (int i =0;i<db;i++){
    if(tomb[i] < tomb2[i]){
        m=tomb[i];
        tomb[i]=tomb2[i];
        tomb2[i]=m;
        }

        m=tomb2[i];
        while(tomb[i]%m != 0 || tomb2[i]%m != 0){
            m = m-1;
        }
      printf("%d  %d  %d\n", tomb2[i], tomb[i], m);
      fprintf(ki,"%d %d %d\n",tomb2[i], tomb[i], m);
    }
    fclose(ki);

    close(fd);

    }
    else{
      printf("Fut a szulo!");

      int fd;
      fd = open("myfifo",O_WRONLY);

      FILE *be;
      be = fopen("bemenet.txt","r");

      fscanf(be,"%d",&db);

      int tomb[db];
      int tomb2[db];

      for(int i = 0; i<db;i++){
        fscanf(be,"%d %d",&tomb[i],&tomb2[i]);
      }

      fclose(be);

      write(fd,&db,sizeof(int));

      for( int i =0;i<db;i++){
        write(fd,&tomb[i],sizeof(tomb[i]));
      }

      for( int i =0;i<db;i++){
        write(fd,&tomb2[i],sizeof(tomb2[i]));
      }

      close(fd);
    }
    return 0;
}
