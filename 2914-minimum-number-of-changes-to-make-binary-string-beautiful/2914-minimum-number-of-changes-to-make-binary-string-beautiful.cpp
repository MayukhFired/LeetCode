class Solution {
public:
    int minChanges(string s) {
    // 1-------------------------------------------------------1
        // char curr_char = s[0];
        // int min_change = 0;
        // int count = 0;

        // for(int ch : s){
        //     if(ch == curr_char){
        //         count++;
        //         continue;
        //     }

        //     if(count % 2 == 0){
        //         count = 1;
        //     }else{
        //         count = 0;
        //         min_change++;
        //     }
        //     curr_char = ch;
        // }
        // return min_change;
    // 1--------------------------------------------------------------1
        int min_change = 0;
        for(int i = 0; i < s.length(); i += 2){
            if(s[i] != s[i + 1]){
                min_change++;
            }
        }
        return min_change;
    }
};