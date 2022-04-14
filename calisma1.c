#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_MODE          (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main (int argc, char *argv[]){
	if(argc!=2)
	{
	printf("bir dosya ismi vermelisiniz.\n");
	exit(-1);
	}
	int n;
	int fd=open(argv[1],O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
	printf("Dosya belirteci: %d\n",fd);
	if(fd<)
	{
		printf("Dosya açma hatası");
		exit(-2);
	}
	char buf[19] = "Bu benim ilk yazım."
	if(n = write(fd,buf,sizeof(buf)-1)<0)
	{
		printf("Yazma Hatasi\n");
		exit(-3);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);

	printf("dosya belirteci: %d\n",fd);
	char buf2[10];
	while ((n = read(fd,buf2,sizeof(buf2)))>0)

}
