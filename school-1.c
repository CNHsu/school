// ID check 
// study git operation
// branch1
// branch1 modify1
// branch1 modify2
<<<<<<< HEAD
// branch2 merge to
// branch3
// branch3 modify1
// branch4 

=======
// branch2 initial
// branch2 modify1
// branch2 modify2
// branch2-5 
// branch2-5 modify1
// branch2-5 modify2
>>>>>>> branch2-5
#include <stdio.h>
#include <ctype.h>

#define OK 0
#define error_alpha 1
#define error_digit 2
#define error_check 3
#define no_define 2

int main()
{
char dia,di;
int has_error;
int idd[9],idaa;
int inputdi;
int i;
int specialvalue[]={1,9,8,7,6,5,4,3,2,1,1};
int chg[]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
int checkvalue;
char c;
char error_message[4][50]={"ID OK","ID error-first ID not aplha","ID error - not legal","ID error - check fail"};


has_error=no_define;
while(1)
{
	printf("\rInput your ID: ");
	dia=getc(stdin);
	// for first aplha check
	idaa=0;
	if(isalpha(dia)) { // the getc first input is alpha data
					// modified the alpha to A=10,B=11 ...value
		//printf("%c, %d\n\r",dia,dia);
		// modify for alpha calculate a=10, b=11....
		if (dia <97) // upper alpha A=65, B=66...
			// lower aplha a=97,b=98...
			idaa=chg[dia-65]; // A=10,B=11...
		else idaa=chg[dia-97]; // a=10,b=11....
	}
	else {
		// printf("it is not alpha(%c)\n\r",dia);
		has_error=error_alpha; // alpha error
	}

	inputdi=0;
	while( inputdi<9){
		di=getc(stdin);
		if(isdigit(di)) {
			di=di-48; // the ascii value of '0' is 48
			idd[inputdi++]=di;
		}
		else {
			//printf("\n\rwrong number please re-input digital ID number\n\r");
			has_error=error_digit;
			}

	}	

// printf("\n\r%c",toupper(dia));
//for(i=0;i<inputdi;i++) printf("%d",idd[i]);
// check id
	checkvalue=0;
	checkvalue= (idaa/10 *specialvalue[0])%10+ (idaa%10* specialvalue[1])%10;
	for(i=0;i<9;i++)
	{
		checkvalue=checkvalue+ (idd[i]*specialvalue[i+2])%10;
	}
	//printf("ID=%d\n\r",checkvalue);
	//printf("[%d][%d]\n\r",idaa,checkvalue);
	if(checkvalue % 10) {//printf(error_message[has_error]);
 has_error=error_check;
}
	else
	{
printf("\33[2K\r"); // clear a line
printf("%c",toupper(dia));
for(i=0;i<inputdi;i++) printf("%d",idd[i]);
//printf("ID ok\n\r");
has_error=OK; // no error
}
		printf("%s\n\r",error_message[has_error]);
		while ((c = getchar()) != '\n' && c != EOF) { }
	}
return 0;
}