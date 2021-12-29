#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int8_t  write_buff[1024];
int8_t read_buff[1024];
int fd;
int main();
char option;

printf("Welcome to the demo of character Driver\n");

fd=open("/dev/chardeviceQue2.c", O_RDWR);
if(fd<0)
	{
	printf("cannot open device file... \n");
	return 0;
	}

while(1){
	printf("****Please Enter Your Choice****\n");
	printf("1.Write\n2.Read\n,3.Exit");
	scanf("%c",&option);
	printf("Your choice is %c\n");

switch(option){
	
	case 1: 
	
	printf("Enter string to write into the driver\n");
	scanf("%[^\t\n]s",write_buff);
	printf("Data written\n");
	write(fd,write_buff,strlen(write_buff)+1);
	printf("DONE\n");
	break;
	
	case 2:

	printf("Data is Reading\n");
	read(fd,read_buff,1024);
	printf("Done... \n\n");
	printf("Data = %s \n\n",read_buff);
	break;

	case 3;

	close(fd);
	exit(1);
	break;

	default:

	printf("Entre correct choise");
	break;
	}
}
close(fd);
}

