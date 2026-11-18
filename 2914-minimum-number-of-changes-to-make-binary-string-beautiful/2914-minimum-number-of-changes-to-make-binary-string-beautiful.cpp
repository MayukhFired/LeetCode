class Solution {
public:
    int minChanges(string s) {
        char curr_char = s[0];
        int min_change = 0;
        int count = 0;

        for(int ch : s){
            if(ch == curr_char){
                count++;
                continue;
            }

            if(count % 2 == 0){
                count = 1;
            }else{
                count = 0;
                min_change++;
            }
            curr_char = ch;
        }
        return min_change;
    }
};