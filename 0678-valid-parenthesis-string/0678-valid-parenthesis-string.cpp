class Solution {
private:
    bool isvalid(int index , int openCount , const string& s , vector<vector<int>>& memo){
        if(index == s.size()){
            return (openCount == 0);
        }

        if(memo[index][openCount] != -1){
            return memo[index][openCount];
        }

        bool valid = false;

        if(s[index] == '*'){
            valid |= isvalid(index + 1 , openCount + 1 , s , memo);
            if(openCount){
                valid |= isvalid(index + 1 , openCount - 1 , s , memo);
            }
            valid |= isvalid(index + 1 , openCount , s , memo);
        }else{
            if(s[index] == '('){
                valid = isvalid(index + 1 , openCount + 1 , s , memo);
            }else if(openCount){
                valid = isvalid(index + 1 , openCount - 1 , s , memo);
            }
        }
        return memo[index][openCount] = valid;
    }
public:
    bool checkValidString(string s) {
        vector<vector<int>> memo(s.size() , vector<int> (s.size() , -1));
        return isvalid(0 , 0 , s , memo);
    }
};