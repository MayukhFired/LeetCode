class Solution {
public:
    int reverseDegree(string s) {
        int count = 0;
        for(int i = 1; i <= s.length(); i++){
            count += i * (26 - (s[i - 1] - 'a'));
        }
        return count;
    }
};