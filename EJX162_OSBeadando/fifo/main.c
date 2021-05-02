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

 int fd;
 int db;
    if(child == 0){
        int fd;
        fd = open("myfifo",O_RDONLY);
        read(fd,&db,sizeof(int));

      close(fd);
    }
    else{
      printf("futa szulo:");
      scanf("%d",&db);
      int fd;
      fd = open("myfifo",O_WRONLY);
      write(fd,&db,sizeof(int));
      printf("a szam: %d",db);

      close(fd);
    }
    return 0;
}
