#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FILE_MODE          (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("bir dosya ismi veriniz.\n");
		exit(-1);
	}
	char buf[27] = "Bu dosya yeni olusturuldu.\n";
	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, FILE_MODE);
	if(fd <0)
	{
		printf("dosya açma hatasi \n");
		exit(-2);
	}
	int n;
	if(n = write(fd,buf,sizeof(buf)-1)<0)
	{
		printf("yazma hatasi. \n");
		exit(-3);
	}
	close(fd);
	char buf2[25] = "\ndosyanin ikinci satiri.\n";
 	fd =  open(argv[1], O_WRONLY | O_APPEND, FILE_MODE );
	if(n = write(fd,buf2,sizeof(buf2)-1)<0)
	{
		printf("yazma hatasi 2.\n");
		exit(-4);
	}
	close(fd);
}
