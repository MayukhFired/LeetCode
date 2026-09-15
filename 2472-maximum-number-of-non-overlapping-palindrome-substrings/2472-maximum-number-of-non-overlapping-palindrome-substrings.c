bool isPalindrome(char* s , int left , int right){
    while(left < right){
        if(s[left++] != s[right--]){
            return false;
        }
    }
    return true;
}
int maxPalindromes(char* s, int k) {
    int n = strlen(s);
    int count = 0;
    for(int i = 0; i <= n - k; i++){
        if(isPalindrome(s , i , i + k - 1)){
            count++;
            i += k - 1;
        }else if(isPalindrome(s , i , i + k)){
            count++;
            i += k;
        }
    }
    return count;
}