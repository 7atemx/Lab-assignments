#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct student{
	char name[20];
	int grade;
};

int main(int argc, char *argv[]){
	char names[][20] = {"Ahmed", "Mohammad", "Saleh", "Omar", "Wael", "Abdullah", "Abdul alrahman", "Khaled", "Anas", "Amged"};
	struct student stu[10];
	time_t t1;
	srand((unsigned)time (&t1));
	for(int i = 0; i < 10; i++){
		strcpy(stu[i].name, names[i]);
		stu[i].grade = rand() % 100 + 1;
	}
	for(int i = 0; i < 10 ; i++){
		printf("Student Name: %s   ,student grade: %d\n", stu[i].name, stu[i].grade);
	}
	exit(0);
}
