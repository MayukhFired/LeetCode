#include <stdio.h>
#include <stdlib.h>

// Helper tool to sort numbers from smallest to largest
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // Step 1: Sort the array
    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 16; 
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));
    *returnSize = 0;

    // Step 2: Loop through each number to use as the first element
    for (int i = 0; i < numsSize - 2; i++) {
        
        // Stop early: If the smallest number is above 0, sum can never be 0
        if (nums[i] > 0) break;

        // Skip duplicate anchors so we don't get duplicate results
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Set up the two sliding pointers
        int left = i + 1;
        int right = numsSize - 1;

        // Step 3: Slide the pointers toward each other
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                // Double array capacity if we run out of room
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                // Store the successful triplet
                result[*returnSize] = (int*)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Skip duplicate numbers for left and right pointers
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                // Move both pointers inward to look for new combinations
                left++;
                right--;
            } 
            else if (sum < 0) {
                left++;  // Sum too small, move to a bigger number
            } 
            else {
                right--; // Sum too big, move to a smaller number
            }
        }
    }

    return result;
}
