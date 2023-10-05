#include <stdlib.h>
#include <stdio.h>

int main(){
	int num[3];
	printf("Enter Values of A,B and C: \nA:");
	scanf("%d", &num[0]);
	printf("B:");
	scanf("%d", &num[1]);
	printf("C:");
	scanf("%d", &num[2]);
	int max = num[0];
	int min = num[0];
	float avg = ((float)(num[0]+num[1]+num[2]))/3;
	for(int i = 0; i < 3 ; i++){
	if(num[i] > max){max = num[i];}
	if(num[i] < min){min = num[i];}
	}
	printf("Values of A:%d   B:%d   C:%d, Maximum number is:%d, Minimum number is:%d , Average is:%1.2f\n", num[0], num[1], num[2], max, min, avg);
}
