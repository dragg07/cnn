#include <stdio.h>
#include <string.h>
#include <math.h>

int ctoi(char c) {
    return c - '0';
}

int calculateParityBits(int dataLength) {
    int r = 0;
    while(pow(2, r) < dataLength + r + 1) {
        r++;
    }
    return r;
}

void hammingEncode(char *data) {
    int dataLength = strlen(data);
    int r = calculateParityBits(dataLength);
    int encodedLength = dataLength + r;

    int encoded[32] = {0};
    int dataIndex = 0;
    
    for(int i = 1; i <= encodedLength; i++) {
        if((i & (i - 1)) != 0) {
            encoded[i] = ctoi(data[dataIndex++]);
        }
    }

    for(int i = 0; i < r; i++) {
        int parityPos = pow(2, i);
        int parityBit = 0;

        for(int j = parityPos; j <= encodedLength; j++) {
            if(j & parityPos) {
                parityBit ^= encoded[j];
            }
        }
        
        encoded[parityPos] = parityBit;
    }
    
    printf("Original data: %s\n", data);
    printf("Encoded data: ");
    for(int i = 1; i <= encodedLength; i++) {
        printf("%d", encoded[i]);
    }
    printf("\n");
}

int main() {
    char data[] = "1001101";
    hammingEncode(data);
    return 0;
}