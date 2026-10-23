char nextGreatestLetter(char* letters, int lettersSize, char target) {
    // for(int i = 0; i < lettersSize; i++){
    //     if(letters[i] > target){
    //         return letters[i];
    //     }
    // }
    // return letters[0];

    int left = 0;
    int right = lettersSize - 1;
    int ch = letters[0];

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(letters[mid] > target){
            ch = letters[mid];
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return ch;
}