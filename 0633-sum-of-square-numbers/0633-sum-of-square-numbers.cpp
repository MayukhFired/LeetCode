class Solution {
public:
    bool binary_search(int s , int e , int n){
        if(s > e){
            return false;
        }
        long long mid = s + (e - s) / 2;
        if(mid * mid == n){
            return true;
        }else if(mid * mid > n){
            return binary_search(s , mid - 1 , n);
        }
        return binary_search(mid + 1 , e , n);
    }
    bool judgeSquareSum(int c) {
        for(long long a = 0; a * a <= c; a++){
            long long b = c - a * a;
            if(binary_search(0 , b , b)){
                return true;
            }
        }
        return false;
    }
};