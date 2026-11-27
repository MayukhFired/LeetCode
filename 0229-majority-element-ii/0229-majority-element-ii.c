/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    int cand1 = 0;
    int cand2 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for(int i = 0; i < numsSize; i++) {
        if(cand1 == nums[i]) {
            cnt1++;
        }else if(cand2 == nums[i]) {
            cnt2++;
        }else if(cnt1 == 0) {
            cand1 = nums[i];
            cnt1 = 1;
        }else if(cnt2 == 0) {
            cand2 = nums[i];
            cnt2 = 1;
        }else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = cnt2 = 0;
    int* ans = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;

    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == cand1) {
            cnt1++;
        }else if(nums[i] == cand2) {
            cnt2++;
        }
    }

    if(cnt1 > numsSize / 3) {
        ans[(*returnSize)++] = cand1;
    }
    if(cnt2 > numsSize / 3) {
        ans[(*returnSize)++] = cand2;
    }

    return ans;
}