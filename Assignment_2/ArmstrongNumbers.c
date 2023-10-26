#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int numDigits(int input);
int Calculation(int number);
int main(int argc, char* argv[]){
    printf("Enter a number: ");
    int number, ArmstrongCount = 0, counter = 0;
    number = atoi(argv[1]);
    if(number >= 89) {number = 0;}
    while(ArmstrongCount < number ){
        if(Calculation(counter) == counter){
            ArmstrongCount++;
            printf("%d-%d\n", ArmstrongCount, counter);
        }
        counter++;
    }
    return 0;
}
int Calculation(int number){
    int n, count, remainder, sum=0, temp;
    temp=number;
    n=numDigits(number);
    for (temp; number!=0; number){
        remainder=number%10;
        /// start of C code (use GCC)
        count=n;
            while(count>1){

                remainder*=number%10;
                count--;

            }
        sum+=remainder; // end of C code (use GCC) ///
        //sum+=(int)pow((double)remainder,3.0); // C++ code (use G++)
        number=number/10;
    }
    return sum;
}
int numDigits(int input){
    int count=0;
    while(input>0){
        count++;
        input=input/10;

    }
    return count;

}
