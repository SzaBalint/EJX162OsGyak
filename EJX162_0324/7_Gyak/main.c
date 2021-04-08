#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


int main() {
	int fileHandle = open("EJX162.txt", O_RDWR);
	char s[50];
	if (fileHandle == -1)
	{
		perror("Nem sikerult megnyitni a fajlt!");
		return 1;
	}
	else
		printf("Megnyitottam a fajlt!");

    int olvasott = read(fileHandle, s, sizeof(s));
    s[olvasott]='/0';
    printf("Beolvasott tartalom: \"%s\" \n Byt mennyiseg osszesen \"%i\" \n",s,olvasott);

    lseek(fileHandle,0,SEEK_SET);

    close(fileHandle);
    return 0;

}
