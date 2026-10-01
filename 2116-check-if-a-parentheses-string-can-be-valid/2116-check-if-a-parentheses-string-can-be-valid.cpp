class Solution {
public:
    bool canBeValid(string s, string locked) {
        // int len = s.size();

        // if(len % 2 == 1){
        //     return false;
        // }

        // stack<int> openBrackets ,unlocked;

        // for(int i = 0; i < len; i++){
        //     if(locked[i] == '0'){
        //         unlocked.push(i);
        //     }else if(s[i] == '('){
        //         openBrackets.push(i);
        //     }else if(s[i] == ')'){
        //         if(!openBrackets.empty()){
        //             openBrackets.pop();
        //         }else if(!unlocked.empty()){
        //             unlocked.pop();
        //         }else{
        //             return false;
        //         }
        //     }
        // }

        // while(!openBrackets.empty() && !unlocked.empty() && openBrackets.top() < unlocked.top()){
        //     openBrackets.pop();
        //     unlocked.pop();
        // }

        // if(!openBrackets.empty()){
        //     return false;
        // }
        // return true;

        int n = s.size();
        if(n % 2 != 0){
            return false;
        }

        int balance = 0;
        for(int i = 0; i < n; i++){
            if(locked[i] == '0' || s[i] == '('){
                balance++;
            }else{
                balance--;
            }
            if(balance < 0){
                return false;
            }
        }

        balance = 0;
        for(int i = n - 1; i >= 0; i--){
            if(locked[i] == '0' || s[i] == ')'){
                balance++;
            }else{
                balance--;
            }
            if(balance < 0){
                return false;
            }
        }
        return true;
    }
};