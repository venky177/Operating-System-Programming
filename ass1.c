

#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

void callDevice()
  {
		char buff[256];
		char ptr[256];
		const  char *chart="newDir/";

		printf("Please Enter path for directory to which u want to crate");
		scanf("%s",ptr);
		strcpy(buff,ptr);
	 	if(buff[strlen(buff)-1]=='/')
		  {
			strcpy(buff+strlen(buff),chart);
			mkdir(buff,S_IRWXU|S_IRWXG|S_IRWXO);
		  }
		else
		  {
			printf("sorry unable to crate");
		  }

  }

void removeDir()
  {
                char buff[256];
                char ptr[256];

        	 printf("Please Enter path for directory to which u want to delete ");
                scanf("%s",ptr);
                strcpy(buff,ptr);
                   rmdir(buff);

  }

void changeDir()
  {
                char buff[256];
                char ptr[256];

	        printf("Please Enter path for directory to which u want to change ");
                scanf("%s",ptr);
                strcpy(buff,ptr);
                chdir(buff);
		system("ls  >out.txt");
                system("stat out.txt");

  }

int main()
  {
    int opt;
printf("please Enter ur choice \n");
printf("\n1.crateDirectory \n2.RemoveDirectory\n3.ChangeDirectory");
scanf("%d",&opt);
switch (opt)
{
	case 1:
		callDevice();
		break;
	case 2:
		removeDir();
		break;
	case 3:
		 changeDir();
		break;
	default:
		printf("unable to mount or unmount Device ");
		break;
}

return 0;
}


