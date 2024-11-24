#include <stdio.h>
#include <string.h>

void calculateCRC(char *data, char *divisor, char *remainder) {
    int data_len = strlen(data);
    int divisor_len = strlen(divisor);
    
    char augmented_data[20] = {0};
    strcpy(augmented_data, data);
    for(int i = 0; i < divisor_len - 1; i++) {
        strcat(augmented_data, "0");
    }
    
    char temp[20] = {0};
    strncpy(temp, augmented_data, divisor_len);
    int aug_len = strlen(augmented_data);
    
    for(int i = 0; i < aug_len - divisor_len + 1; i++) {
        if(temp[0] == '1') {
            for(int j = 0; j < divisor_len; j++) {
                temp[j] = (temp[j] == divisor[j]) ? '0' : '1';
            }
        }
        
        for(int j = 0; j < divisor_len - 1; j++) {
            temp[j] = temp[j + 1];
        }
        temp[divisor_len - 1] = augmented_data[i + divisor_len];
    }
    
    strncpy(remainder, temp, divisor_len - 1);
    remainder[divisor_len - 1] = '\0';
}

int main() {
    char data[] = "1001010";
    char divisor[] = "1101";
    char remainder[10];
    char encoded[20];
    
    printf("Data: %s\n", data);
    printf("Divisor: %s\n", divisor);
    
    calculateCRC(data, divisor, remainder);
    
    printf("CRC: %s\n", remainder);
    
    strcpy(encoded, data);
    strcat(encoded, remainder);
    printf("Encoded Data: %s\n", encoded);
    
    return 0;
}