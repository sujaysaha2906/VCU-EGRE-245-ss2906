#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBITS (sizeof(unsigned) * 8)

// char *bitsToStr(unsigned x) {
//     // Allocate space for all bits + null terminator
//     char *s = malloc(NUMBITS + 1);
//     if (s == NULL) {
//         return NULL;
//     }

//     // Extract bits from MSB → LSB
//     for (int i = 0; i < NUMBITS; i++) {
//         unsigned bit = (x >> (NUMBITS - 1 - i)) & 1;
//         s[i] = bit ? '1' : '0';
//     }

//     s[NUMBITS] = '\0'; // Null-terminate string
//     return s;
// }

char *bitsToStr(unsigned x) {
    char *s = malloc(NUMBITS + 1);
    if (s == NULL) return NULL;

    unsigned temp = x;

    // Fill from the end (LSB to MSB)
    for (int i = NUMBITS - 1; i >= 0; i--) {
        s[i] = (temp % 2) ? '1' : '0';  // extract LSB using mod
        temp /= 2;                      // shift right using division
    }

    s[NUMBITS] = '\0';
    return s;
}

int main() {
    unsigned x;

    printf("Enter an unsigned integer: ");
    scanf("%u", &x);

    char *binary = bitsToStr(x);

    if (binary != NULL) {
        printf("Binary representation: %s\n", binary);
        free(binary);
    } else {
        printf("Memory allocation failed!\n");
    }

    return 0;
}