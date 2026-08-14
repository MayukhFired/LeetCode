class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 1){
            return false;
        }else if(num == 1){
            return true;
        }
        long long high = num;
        long long low = 0;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long square = mid * mid;
            if(square == num){
                return true;
            }else if(square > num){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return false;
    }
};