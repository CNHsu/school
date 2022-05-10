// 2022/5/10

#include <stdio.h>
// define color
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
int g,y,r; // r=match, y=not match, g=error

// random
srand(time(NULL));
int a=(rand()%5); // random range

// chek input
    for(i=0;i<5;i++)
    printf("%s ",str1[i]);
 while(1){
	 printf("\ninput guess text: ");
	 scanf("%s", str2);
	 if(strlen(str2)>5) printf("\033[0;32;31mInput Error!\n");
	 else {
		 for(i=0,Error=0;i<5;i++) {
			 Error=isaplha(str2[i])|Error;
	    }
		if(Error) printf(RED"Input not aplha\n");
		else{
			for(j=0,g=y=r=0;j<5;j++)
            for(i=0;i<5;i++) {
				if(str1[a][i]==str2[j]) {
					if(i==j) r = r | 1<<i;
					else y=y| 1<<j;
			    }
				else g = g | 1<< g;
			}
		}
		printf("answoer =%s\n",str1[a]);
		printf(" r=%x, y=%x, g=%x",r,y,g);
		 
	 }	 
	 
	 
}

return 0;
}