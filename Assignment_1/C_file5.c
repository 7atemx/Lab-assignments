#include <stdlib.h>
#include <stdio.h>

	int main(int argc, char *argv[]){
	char *h = argv[1];
	int s = atoi(h) * 60;
	printf("Number of seconds of %s hours: %d\n", argv[1], s);
	exit(0);
}
