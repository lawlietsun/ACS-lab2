#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int check_authentication(char * password)
{
	int authorized = 0;
	// char password_buffer[16];
	char * password_buffer;

	password_buffer = (char *) malloc(sizeof(char) * 1);

	strcpy(password_buffer, password);
	if(strcmp(password_buffer,"admin123") == 0)
	{
		authorized = 1;
	}

	return authorized;

}

int main(int argc,char * argv[])
{
	if(argc < 2)
	{
		printf("Usage:%s<password>\n",argv[0]);
	}
	else
	{
		if(check_authentication(argv[1]))
		{
			printf("Access Granted!\n");
		}
		else
		{
			printf("Access Denied!\n");
		}
	}

	return 0;
}
