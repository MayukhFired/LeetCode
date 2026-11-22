class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        int last_a = -1;
        int first_b = n;

        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                last_a = max(last_a , i);
            }else{
                first_b = min(first_b , i);
            }
        }
        return last_a < first_b;
    }
};