#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {
	int child;

	mkfifo("EJX162", S_IRUSR | S_IWUSR);

	child = fork();
	if (child < 0) {
		char s[1024];
		int fd;

		fd = open("EJX162", O_RDONLY);
		read(fd, s, sizeof(s));
		printf("%s", s);

		close(fd);
		unlink("EJX162");
	}
	else if (child == 0) {
		int fd;
		}
}

