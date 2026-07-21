#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxActiveSectionsAfterTrade(char* s) {
    int total_ones = 0;
    int len = strlen(s);
    
    // Allocate space for zero group lengths dynamically or use a safe upper bound
    int* zero_groups = (int*)malloc(sizeof(int) * (len + 1));
    int group_count = 0;
    int current_zeros = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '1') {
            total_ones++;
            if (current_zeros > 0) {
                zero_groups[group_count++] = current_zeros;
                current_zeros = 0;
            }
        } else {
            current_zeros++;
        }
    }
    if (current_zeros > 0) {
        zero_groups[group_count++] = current_zeros;
    }

    int max_gain = 0;
    // A trade is only possible if there are at least 2 zero groups separated by an internal '1'
    if (group_count >= 2) {
        for (int i = 0; i < group_count - 1; i++) {
            max_gain = MAX(max_gain, zero_groups[i] + zero_groups[i + 1]);
        }
    }

    free(zero_groups);
    return total_ones + max_gain;
}
