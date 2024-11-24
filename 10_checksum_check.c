#include <stdio.h>
#include <string.h>

int binToDecimal(char* bin, int start, int length) {
    int decimal = 0;
    for(int i = start; i < start + length; i++) {
        decimal = decimal * 2 + (bin[i] - '0');
    }
    return decimal;
}

void decimalToBin4bit(int decimal, char* result) {
    for(int i = 3; i >= 0; i--) {
        result[i] = (decimal & 1) + '0';
        decimal >>= 1;
    }
    result[4] = '\0';
}

void calculateChecksum(char* data, int length, char* checksum) {
    int sum = 0;
    
    for(int i = 0; i < length; i += 4) {
        sum += binToDecimal(data, i, 4);
    }
    
    sum = sum & 0xF;
    sum = (~sum) & 0xF;
    decimalToBin4bit(sum, checksum);
}

int verifyChecksum(char* data, int length) {
    int sum = 0;
    
    for(int i = 0; i < length; i += 4) {
        sum += binToDecimal(data, i, 4);
    }
    
    return (sum & 0xF) == 0xF;
}

int main() {
    char data[] = "110110110111";
    int dataLength = strlen(data);
    char checksum[5];
    
    calculateChecksum(data, dataLength, checksum);
    
    printf("Original data: %s\n", data);
    printf("Calculated checksum: %s\n", checksum);
    
    char complete[20];
    strcpy(complete, data);
    strcat(complete, checksum);
    
    printf("Verification result: %s\n", 
           verifyChecksum(complete, strlen(complete)) ? "Valid" : "Invalid");
    
    return 0;
}