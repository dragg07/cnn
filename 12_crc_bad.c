#include <stdio.h>
#include <string.h>

int checkCRC(char *received_data, char *divisor) {
    int data_len = strlen(received_data);
    int divisor_len = strlen(divisor);

    char temp[20] = {0};
    strncpy(temp, received_data, divisor_len);

    for(int i = 0; i < data_len - divisor_len + 1; i++) {
        if(temp[0] == '1') {
            for(int j = 0; j < divisor_len; j++) {
                temp[j] = (temp[j] == divisor[j]) ? '0' : '1';
            }
        }
        
        for(int j = 0; j < divisor_len - 1; j++) {
            temp[j] = temp[j + 1];
        }
        temp[divisor_len - 1] = received_data[i + divisor_len];
    }
    
    for(int i = 0; i < divisor_len - 1; i++) {
        if(temp[i] != '0') return 0;
    }
    return 1; 
}

int main() {
    char received_data[] = "1001010001";
    char divisor[] = "1101";
    
    printf("Received Data: %s\n", received_data);
    printf("Divisor: %s\n", divisor);
    
    if(checkCRC(received_data, divisor)) {
        printf("CRC Check: GOOD - No errors detected\n");
    } else {
        printf("CRC Check: BAD - Errors detected\n");
    }
    
    return 0;
}