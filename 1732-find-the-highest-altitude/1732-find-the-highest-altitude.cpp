class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr_alt = 0;
        int max_alt = 0;

        for(int g : gain){
            curr_alt += g;
            if(max_alt < curr_alt){
                max_alt = curr_alt;
            }
        }
        return max_alt;
    }
};