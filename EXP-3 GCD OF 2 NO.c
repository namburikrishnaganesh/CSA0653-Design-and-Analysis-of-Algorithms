#include <stdio.h>  
int main()  
{     
    int num1, num2;
	printf("enter a number : ",num1);
	scanf("%d",&num1); 
	printf("enter a number : ",num2);
	scanf("%d",&num2);
    while (num1 != num2)
	{  
	if (num1 > num2){
	num1 = num1 - num2;
	}
	else
	{
	num2 = num2 - num1;
	}                
    }   
    printf( " GCD of two numbers is %d", num2);  
}  