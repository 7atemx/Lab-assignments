#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Global variables representing the lowercase English alphabet
char alphabets[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                        'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
    char password[5]; // Password array to store generated passwords
    
    int i[4] = {0, 0, 0, 0}; // Array to store indices for each position in the password

int main(int argc, char *argv[]) {
    password[4] = '\0';
    for(int ind0 = 0; ind0 < 26; ind0++) {
        i[0] = ind0;
        repitionDetect(0);
        ind0 = i[0];
        // Check if the second position is within bounds
        if(i[0] < 26) {
        password[0] = alphabets[i[0]];
        for(int ind1 = 0; ind1 < 26; ind1++) {
            i[1] = ind1;
            repitionDetect(1);
            ind1 = i[1];
            if(i[1] < 26) {
            password[1] = alphabets[i[1]];
            for(int ind2 = 0; ind2 < 26; ind2++) {
                i[2] = ind2;
                repitionDetect(2);
                ind2 = i[2];
                if(i[2] < 26) {
                password[2] = alphabets[i[2]];
                for(int ind3 = 0; ind3 < 26; ind3++) {
                    i[3] = ind3;
                    repitionDetect(3);
                    ind3 = i[3];
                    if(i[3] < 26) {
                    password[3] = alphabets[i[3]];
                    printf("%s\n", password);
                    }
                }
                }
            }
            }
        }
        }
    }
}

// Function to detect and resolve repetition in the password
void repitionDetect(int pointer) {
    if(pointer == 0)
                password[pointer] = alphabets[i[0]];
            else{
                int c = 0;
                while(c < 4) {
                    if(c == pointer) {
                        c++;
                        continue;
                    }
                    if(i[c] == i[pointer]) {
                        i[pointer]++;
                        c = 0; // Reset the loop to check for repetition
                    }
                    c++;
                }
            }
}