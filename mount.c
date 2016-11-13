#include <sys/mount.h>
#include <stdio.h>
#include <errno.h>

void callmount()
{

if (mount("/dev/sdb1", "/mnt", "vfat", MS_NOATIME, NULL)) {
    if (errno == EBUSY) {
        printf("Mountpoint busy");
    } else {
        printf("Mount error: %s",strerror(errno));//, strerror(errno));
    }
} else {
    printf("Mount successful");
}
}

void calluMount()
{

if(umount("/mnt"))
	{

	if(errno==EBUSY) {
			printf("mountpoint Busy|n");
		}
}
		else {
					printf("umount point success");
		}
	}



void FindDev()
{
	system("dmesg");
}

int main()
{
int opt;
printf("please Enter ur choice \n");
printf("1.mount\n2.Umount \n3.FindDev\n");
scanf("%d",&opt);
switch (opt)
{
	case 1:
		callmount();
		break;
	case 2:
		calluMount();
		break;
	case 3 :
		FindDev();
	break;
	default:
		printf("unable to mount or unmount Device ");
		break;
}

return 0;
}


