class Solution {
    //1------------------------------------------------------------------------------------------1
// private:
    // bool isvalid(int index , int openCount , const string& s , vector<vector<int>>& memo){
    //     if(index == s.size()){
    //         return (openCount == 0);
    //     }

    //     if(memo[index][openCount] != -1){
    //         return memo[index][openCount];
    //     }

    //     bool valid = false;

    //     if(s[index] == '*'){
    //         valid |= isvalid(index + 1 , openCount + 1 , s , memo);
    //         if(openCount){
    //             valid |= isvalid(index + 1 , openCount - 1 , s , memo);
    //         }
    //         valid |= isvalid(index + 1 , openCount , s , memo);
    //     }else{
    //         if(s[index] == '('){
    //             valid = isvalid(index + 1 , openCount + 1 , s , memo);
    //         }else if(openCount){
    //             valid = isvalid(index + 1 , openCount - 1 , s , memo);
    //         }
    //     }
    //     return memo[index][openCount] = valid;
    // }

    //1----------------------------------------------------------------------------------1
public:
    bool checkValidString(string s) {
        // 1-----------------------------------------------------------------1
        // vector<vector<int>> memo(s.size() , vector<int> (s.size() , -1));
        // return isvalid(0 , 0 , s , memo);
        // 1-----------------------------------------------------------------1

        int max_add = 0;
        int min_add = 0;

        for(char ch : s){
            if(ch == '('){
                max_add++;
                min_add++;
            }else if(ch == ')'){
                max_add--;
                min_add--;
            }else if(ch == '*'){
                max_add++;
                min_add--;
            }

            if(max_add < 0){
                return false;
            }

            if(min_add < 0){
                min_add = 0;
            }
        }
        return min_add == 0;
    }
};