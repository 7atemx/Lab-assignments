#include <stdlib.h>
#include <stdio.h>

int main(){
	char monthsOfYear[][100] = {"1-January/Muharram", "2-February/Safar", "3-March/Rabi I", "4-April/Rabi II", "5-May/Jumada I", "6-June/Jumada II", 
		"7-July/Rajab", "8-August/Shaaban", "9-September/Ramadan", 
		"10-October/Shawwal", "11-November/Dhu al-Qidah", 
	"12-December/Dhu al-Hijjah"};

	printf("Gregorian/Hijri months:\n");

	for(int i = 0; i < 12; i++){
		printf("%s\n", monthsOfYear[i]);
	}
	exit(0);
}
