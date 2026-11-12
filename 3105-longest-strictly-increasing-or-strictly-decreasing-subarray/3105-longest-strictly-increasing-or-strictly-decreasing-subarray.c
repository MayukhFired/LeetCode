#define Max(a , b) ((a) > (b) ? (a) : (b))
int longestMonotonicSubarray(int* nums, int numsSize) {
// 1------------------------------------------------------------------------------------1
    // int max_length = 1;
    // for(int start = 0; start < numsSize; start++){
    //     int curr_length = 1;
    //     for(int pos = start + 1; pos < numsSize; pos++){
    //         if(nums[pos] > nums[pos - 1]){
    //             curr_length++;
    //         }else{
    //             break;
    //         }
    //     }
    //     max_length = Max(max_length , curr_length);
    // }

    // for(int start = 0; start < numsSize; start++){
    //     int curr_length = 1;
    //     for(int pos = start + 1; pos < numsSize; pos++){
    //         if(nums[pos] < nums[pos - 1]){
    //             curr_length++;
    //         }else{
    //             break;
    //         }
    //     }
    //     max_length = Max(max_length , curr_length);
    // }

    // return max_length;
// 1--------------------------------------------------------------------------------------------1
    int max_length = 1;
    int inc = 1;
    int dec = 1;

    for(int pos = 0; pos < numsSize - 1; pos++){
        if(nums[pos + 1] > nums[pos]){
            inc++;
            dec = 1;
        }else if(nums[pos + 1] < nums[pos]){
            dec++;
            inc = 1;
        }else{
            inc = 1;
            dec = 1;
        }
        max_length = Max(max_length , Max(inc , dec));
    }

    return max_length;
}