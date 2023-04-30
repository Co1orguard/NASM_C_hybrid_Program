#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>


int is_palindrome(char*, int);
void palindrome_check();
int addstr(char*, char*);
int factstr(char*);
void Option1();
int fact(int);
void Option2();
void Option3();
void Option4();


int main() {

	int input = 0;
	
	do  {
	// print out menu
	printf("1) Add two numbers together\n");
	printf("2) Test if a string is a palindrome (C->ASM)\n");
	printf("3) Print the factorial of a number\n");
	printf("4) Test if a string is a palindrome (ASM->C)\n");
	printf("5) Exit the program\n");
	// print message and query user input
	printf("Select an option: ");	
	scanf("%d", &input);
	printf("\n");
	

	// execute selected option
	if(input == 1){
		//add two numbers
		Option1();
	}
	
	else if(input == 2){
		// detect palindrome (C->ASM)
		Option2();
	}

	else if(input == 3){
		// calculate factorial
		Option3();
	}
	else if(input == 4){
		// detect palindrome (ASM->C) 
		Option4();
	}

	} while(input != 5);
	
	printf("Exiting..\n");

	return 0;
}


int fact(int a){

	int result = a;
	int i = a-1;
	while(i != 0){
	result = result*i;
	i = i-1;
	} 
	
	return result;

}


int C_palindrome(char* input){
	
	int i,j;
	
	int length = strlen(input) -2;
	
	for(i=0, j=length; i <= length/2; i++, j--){
		
		if (input[i] != input[j]){
			printf("Is not a palindrome\n");
			printf("\n");
			return 0;
		}
	}
	
	printf("Is a palindrome\n");
	printf("\n");
	return 0;
}


void Option1(){

	// declare local variables	
	char a[1024];
        char b[1024];
        int out = 0;

	// query user input
        printf("Enter first number: ");
	scanf("%s", a);
	printf("Enter second number: ");
        scanf("%s", b);


	// call ASM addstr function on user input
        out = addstr(a,b);

	// output the returned sum from addstr
        printf("The sum and is: %d\n", out);
        printf("\n");

}

void Option2(){
        char a[1024];

        printf("Enter a string: ");
        scanf("%s", a);

        int size = strlen(a);

        bool flag = is_palindrome(a, size);

        if(flag == 1){
                printf("Is a palindrome\n");
        }
        else{
                printf("Is not a palindrome\n");
        }
        printf("\n");
}


void Option3(){
        char a[1024];
	int out = 0;

        // query user input
        printf("Enter number: ");
        scanf("%s", a);
	
        // call ASM addstr function on user input
        out = factstr(a);

        // output the returned sum from addstr
        printf("%s factorial is: %d\n",a,out);
        printf("\n");
	
}


void Option4(){

	palindrome_check();
	
}
