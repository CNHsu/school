// 2022/5/10

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // for windows consol only

void Redtext();
void normal();
void WGray();
void WGreen();
void WYellow();
void WR();

// define color, for unix consol 
#define NONE "\033[m"
#define RED "\033[0;32;31m"
#define LIGHT_RED "\033[1;31m"
#define GREEN "\033[0;32;32m"
#define LIGHT_GREEN "\033[1;32m"
#define BLUE "\033[0;32;34m"
#define LIGHT_BLUE "\033[1;34m"
#define DARY_GRAY "\033[1;30m"
#define CYAN "\033[0;36m"
#define LIGHT_CYAN "\033[1;36m"
#define PURPLE "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN "\033[0;33m"
#define YELLOW "\033[1;33m"
#define LIGHT_GRAY "\033[0;37m"
#define WHITE "\033[1;37m"


// you need use [6] inculde string end '\0' to store 5-char string
char str1[5][6]={"Anita","Beryl","Chloc","Doris","Emily"};
char str2[100];
int Error;
int main()
{
int i,j;
unsigned char g,y,r; // r=match, y=not match, g=error

// random
srand(time(NULL));
int a=(rand()%5); // random range
Redtext();
printf("random index = %d",a);
normal();


// chek input
    for(i=0;i<5;i++)
       printf("%s ",str1[i]);
 while(1){
	 
	 printf("\ninput guess text: ");
	 scanf("%s", str2);
	 if(strlen(str2)>5) {
		 Redtext();
		 printf("Input Error!\n");
		 normal();
	 }
	 else {
		 for(i=0,Error=0;i<5;i++) {
			 Error= (!isalpha(str2[i]))|Error;
	    }
		if(Error) {
			Redtext(); 
			printf("Input not aplha\n"); 
			normal();
			}
		else{
			for(j=0,g=y=r=0;j<5;j++)
            for(i=0,Error=1;i<5;i++) {
				if(toupper(str1[a][i])==toupper(str2[j])) {
					if(i==j) {
						r = r | 1<<i; // correct green
						WGreen();
						putch(str2[j]);
						normal();
						Error=0;
					}
					else {
						y=y| 1<<j;        // position error yellow
						WYellow();
						putch(str2[j]);
						normal();
                        Error=0;						
					}
			    }
				else if(Error==1 && i==4){
					g = g | 1<< g;        // all error gray
						WGray();
						putch(str2[j]);
						normal();
                     Error=0;						
				}
			}
		}
		printf("\n answer =%s\n",str1[a]);
		printf(" r=%1x, y=%1x, g=%1x",r,y,g);
		 
	 }	 
	 
	 
}
return 0;
}

//值為xx。x為一位16進位制數，即0~F
//都可以使用，可以隨意組合。

//0~F 分別代表的顏色如下：

//0 = 黑色 8 = 灰色 1 = 淡藍 9 = 藍色
//2 = 淡綠 A = 綠色 3 = 湖藍 B = 淡淺綠
//C = 紅色 4 = 淡紅 5 = 紫色 D = 淡紫
//6 = 黃色 E = 淡黃 7 = 白色 F = 亮白
void Redtext(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 0x0C ); // c:red + 0:white
//    puts("One two three\tfour");
//    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
}
void normal(){
	
 //   SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 0x0C ); // c:red + 0:white
 //   puts("One two three\tfour");
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
}
void WGray(){	
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 0x8F ); // c:red + 0:white
}
void WGreen(){	
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 0xAF ); // c:red + 0:white
}
void WYellow(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 0x60 ); // c:red + 0:white
}
void WR(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 0xCF ); // c:red + 0:white
}