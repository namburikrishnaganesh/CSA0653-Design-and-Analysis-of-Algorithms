#include<stdio.h>
int main()
{
	int num,originalNum,remainder,n=0;
	float result = 0.0;
	printf("enter an integer : ");
	scanf("%d",&num);
	originalNum = num;
	for(originalNum=num;originalNum !=0; ++n){
		originalNum /= 10;
	}
	for(originalNum=num;originalNum !=0;originalNum /= 10){
	remainder = originalNum % 10;
	result += pow(remainder, n);
	}
	if((int)result==num)
	printf("%d is an armstrong number",num);
	else
	printf("%d is not an armstrong number",num);
	return 0;
}