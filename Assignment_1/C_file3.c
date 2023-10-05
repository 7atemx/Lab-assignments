#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	char Name[100];
	char Age[3];
	char address[30];
	printf("What is your name: ");
	fgets(Name, 100, stdin);
	Name[strlen(Name)-1] = '\0';
	printf("your age: ");
	scanf("%s", &Age);
	printf("Your address: ");
	scanf("%s", &address);

	printf("Name: %s   ", Name);
	printf("Age: %s   ", Age);
	printf("Address: %s\n", address);
}
