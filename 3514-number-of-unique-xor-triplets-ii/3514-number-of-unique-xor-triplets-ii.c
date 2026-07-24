#define Max_Val 131702
int uniqueXorTriplets(int* nums, int numsSize) {
    int* freq = (int*)calloc(Max_Val , sizeof(int));
    for(int i = 0; i < numsSize; i++){
        freq[nums[i]]++;
    }

    char* possible_pairs = (char*)calloc(Max_Val , sizeof(char));
    for(int i = 0; i < numsSize; i++){
        for(int j = i; j < numsSize; j++){
            possible_pairs[nums[i] ^ nums[j]] = 1;
        }
    }

    char* unique_triplets = (char*)calloc(Max_Val , sizeof(char));
    int count = 0;
    for(int v = 0; v < Max_Val; v++){
        if(!possible_pairs[v]) continue;
        for(int k = 0; k < numsSize; k++){
            int triplet_Xor = v ^ nums[k];
            if(!unique_triplets[triplet_Xor]){
                unique_triplets[triplet_Xor] = 1;
                count++;
            }
        }
    }

    free(freq);
    free(possible_pairs);
    free(unique_triplets);
    return count;
}