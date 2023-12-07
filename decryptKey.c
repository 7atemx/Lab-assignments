/*
* Author:
* Description:
* RSA Decryption using OpenSSL library and Python encode/decode
* */
#include <stdio.h>
#include <string.h>
#include <openssl/bn.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void printBN(char *msg, BIGNUM *tmp){
char *number_str = BN_bn2hex(tmp); // Convert BIGNUM to hex
printf("%s%s\n", msg, number_str); // Print hex
OPENSSL_free(number_str); // Free memory
}
int main(int argc, char *argv[]){
BN_CTX *ctx = BN_CTX_new();

//* Here initialize all needed BIGNUM variables
//* 1- Encryption Key variable
BIGNUM *EkeyVar = BN_new();
//* 2- Decryption Key variable
BIGNUM *DkeyVar = BN_new();
//* 3- product of large prime numbers p and q
BIGNUM *n = BN_new();
//* 4- Totient of (n) Euler's totient function
BIGNUM *phi = BN_new();
//* 5- Encrypted Message variable
BIGNUM *EncMassage = BN_new();
//* 6- Decrypted Ciphertext variable
BIGNUM *DeCyphertext = BN_new();
//* */
// Find Decryption Key (d) using (e) and (Phin):
// 1- Assign value to (e) Encryption Key from hex
BN_hex2bn(&EkeyVar, "010001");
// 2- Assign value to (Phin) Encryption Key from hex
BN_hex2bn(&phi, "E103ABD94892E3E74AFD724BF28E78348D52298BD687C44DEB3A81065A7981A4");
// 3- Calculate the Decryption Key (Private Key) d=e mod(Phi(n))
BN_mod_inverse(DkeyVar, EkeyVar, phi, ctx);
char *CC= malloc(100 * sizeof(char));
printf("\nEnter your Encrypted Message:\n");
// Read the Encrypted Message from the user to variable CC
fgets(CC,100,stdin);
// Assign the input value in variable (CC) to Encrypted Message variable
BN_hex2bn(&EncMassage, CC);
//
//Decrypt ciphertext using D=C^d(mod(n)) ,
//where: (D) is the Decrypted Ciphertext and (C) is the Ciphertext
//*/
// Assign value to (n) product of two large prime numbers from hex
BN_hex2bn(&n, "E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1");
// decrypt Ciphertext using the Private Key
BN_mod_exp(DeCyphertext, EncMassage, DkeyVar, n, ctx);
// Convert Hex string to ASCII letters
char *hex_Deciphertext = BN_bn2hex(DeCyphertext);
char *result = hexStringToAscii(hex_Deciphertext);
printf(*result);
free(result);
printf("\nOriginal Message:\n");
return EXIT_SUCCESS;
}

const char* hexStringToAscii(const char *hexString) {
    size_t len = strlen(hexString);

    // Ensure the hex string has an even number of characters
    if (len % 2 != 0) {
        printf("Error: Hex string must have an even number of characters.\n");
        return NULL;
    }

    // Calculate the length of the resulting ASCII string
    size_t asciiLen = len / 2;

    // Allocate memory for the ASCII string
    char* asciiString = (char*)malloc(asciiLen + 1); // +1 for the null terminator

    if (asciiString == NULL) {
        perror("Error allocating memory");
        return NULL;
    }

    for (size_t i = 0; i < len; i += 2) {
        // Extract two characters from the hex string
        char hexPair[3] = {hexString[i], hexString[i + 1], '\0'};

        // Convert the hex pair to decimal
        int decimalValue = strtol(hexPair, NULL, 16);

        // Set the corresponding ASCII character in the result string
        asciiString[i / 2] = (char)decimalValue;
    }

    // Null-terminate the ASCII string
    asciiString[asciiLen] = '\0';

    return asciiString;
}