#include <stdio.h>
#include <string.h>

int countOnes(char *data) {
    int count = 0;
    for(int i = 0; data[i] != '\0'; i++) {
        if(data[i] == '1') {
            count++;
        }
    }
    return count;
}

char* addParityBit(char *data, char parity_type) {
    static char result[32];
    int ones = countOnes(data);
    
    strcpy(result, data);
    
    if(parity_type == 'E' || parity_type == 'e') {
        if(ones % 2 == 0) {
            strcat(result, "0");
        } else {
            strcat(result, "1");
        }
    }

    else if(parity_type == 'O' || parity_type == 'o') {
        if(ones % 2 == 0) {
            strcat(result, "1"); 
        } else {
            strcat(result, "0");
        }
    }
    
    return result;
}

int main() {
    char data[100];
    printf("Enter binary data: ");
    scanf("%s", data);
    char parity_type;
    
    printf("Enter parity type (E for Even, O for Odd): ");
    scanf(" %c", &parity_type);
    
    char *encoded_data = addParityBit(data, parity_type);
    
    printf("\nOriginal data: %s\n", data);
    printf("Number of 1's in data: %d\n", countOnes(data));
    printf("Encoded data with %s parity: %s\n", 
           (parity_type == 'E' || parity_type == 'e') ? "even" : "odd",
           encoded_data);
    printf("Number of 1's in encoded data: %d\n", countOnes(encoded_data));
    
    return 0;
}