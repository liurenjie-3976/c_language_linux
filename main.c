#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "phone.h"


static char password[] = "yikoupeng";
PHONE *phone_head;// 链表头

int manage_menu(){

    int sel = 0;


	do{
		printf("\033[0;31m+***************************电话号码管理软件*********************+\033[0m\n");
		printf("\033[0;31m|\t\t\t1. 添加					 |\033[0m\n");
		printf("\033[0;31m|\t\t\t2. 删除					 |\033[0m\n");
		printf("\033[0;31m|\t\t\t3. 查找					 |\033[0m\n");
		printf("\033[0;31m|\t\t\t4. 显示所有记录				 |\033[0m\n");
		printf("\033[0;31m|\t\t\t0. 退出					 |\033[0m\n");
		printf("\033[0;31m+****************************************************************+\033[0m\n");

		printf("\033[0;31minput your choice#\033[0m");
		printf("\033[0;33minput your choice#\033[0m");
		scanf("%d",&sel);
        if(sel<0 || sel>4){
            fflush(stdin);// 清空输入缓冲区
            system("clear");
            printf("\t\t\33[0;31m输入错误，请重新输入！\033[0m\n");
            // getchar();
            continue;
        }
        return sel;
		
	}while(1);
}

int management(PHONE *head){
    int sel;
    int fg=0;
	do{

		system("clear");

		sel=manage_menu();

		switch(sel)
		{
			case 1:
				create(head);
				getchar();
				getchar();
				break;
			case 2:
				delete(head);
				getchar();
				getchar();
				break;
			case 3:
				search(head);
				getchar();
				getchar();
			case 4:
				display(head);

				break;

			case 0:
				printf("\t\t\tBye\n");
				allfree(head);
				getchar();
				getchar();
				fg=1;

			default:
				break;

		}
		if(fg==1)
		{
			return 1;
			
		}

	}while(1);
	return 0;


}

int login_menu()
{
    int i=3;
    char name[32] = {0};
	char pass[32] = {0};

    printf("\033[0;96m+=================================================================+\033[0m\n");
	printf("\033[0;96m| 								  |\033[0m\n");
	printf("\033[0;96m| \t\t欢迎来到一口Linux的通讯录 			  |\033[0m\n");
	printf("\033[0;96m| 								  |\033[0m\n");
	printf("\033[0;96m| 			温馨提示：初始密码(yikoupeng)	          |\033[0m\n");
	printf("\033[0;96m| 			关注公众号：一口Linux	                  |\033[0m\n");	
	printf("\033[0;96m+=================================================================+\033[0m\n");

    while(i>0)
    {
        printf("\033[0;31mplease input your password:\033[0m");
        scanf("%s",pass);
        if(strcmp(pass,"yikoupeng")==0)
        {
            
            return 0;
        }
        else
        {
            i--;
            printf("\033[0;31mlogin failed! you have %d times!\033[0m\n",i);
        }
        if(i==0)
        {
            printf("\033[0;31mlogin failed! you have no chance!\033[0m\n");
            return -1;
        }




    }
}

int main(int argc,char **argv){
    int ret;

    init(&phone_head);
    ret=login_menu();

    if(ret==0)
    {
        printf("\033[0;31mlogin success!\033[0m\n");
        getchar();
        getchar();
        management(&phone_head);
    }
    else if(ret==-1)
    {
        printf("\033[0;31mlogin failed!\033[0m\n");
        return (-1);
    }
}
