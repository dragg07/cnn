#include <stdio.h>
#include <string.h>

void generateHamming(char data[], char hamming[], int dataLength) {
    int r = 1;
    while ((1 << r) < (dataLength + r + 1)) {
        r++;
    }
    
    int hammingLength = dataLength + r;
    
    for (int i = 0; i < hammingLength; i++) {
        hamming[i] = 'x';
    }
    hamming[hammingLength] = '\0';
    
    int dataIndex = 0;
    for (int i = 0; i < hammingLength; i++) {
        if ((i + 1) & (i)) {
            hamming[i] = data[dataIndex++];
        }
    }
    
    for (int i = 0; i < r; i++) {
        int parityPos = (1 << i) - 1;
        int parity = 0;
        
        for (int j = parityPos; j < hammingLength; j++) {
            if ((j + 1) & (1 << i)) {
                if (hamming[j] == '1') {
                    parity ^= 1;
                }
            }
        }
        
        hamming[parityPos] = parity + '0';
    }
}

int main() {
    char data[] = "10010100101";
    int dataLength = strlen(data);
    char hamming[20];
    
    generateHamming(data, hamming, dataLength);
    
    printf("Original data: %s\n", data);
    printf("Hamming code: %s\n", hamming);
    
    return 0;
}