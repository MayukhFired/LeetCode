class Solution {
public:
    int reverseDegree(string s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            count += (i + 1) * (26 - (s[i] - 'a'));
        }
        return count;
    }
};