class Solution {
    // 2-------------------------------1
    // unordered_set<string>valid_set;
    // 2-------------------------------1
    vector<string>ans;
private:
// 1-------------------------------------------------------------------1
    // bool isValid(const string& s){
    //     int balance = 0;
    //     for(char c : s){
    //         if(c == '('){
    //             balance++;
    //         }else if(c == ')'){
    //             balance--;
    //             if(balance < 0){
    //                 return false;
    //             }
    //         }
    //     }
    //     return balance == 0;
    // }
// 1--------------------------------------------------------------------1

// 3------------------------------------------------------------------------------------------------------------3
    // void dfs(const string& s , int index , int rem_left , int rem_right , int balance , string current_str){
    //     if(index == s.length()){
    //         if(rem_left == 0 && rem_right == 0 && balance == 0){
    //             valid_set.insert(current_str);
    //         }
    //         return;
    //     }

    //     if(balance < 0){
    //         return;
    //     }

    //     char c = s[index];

    //     if(c == '(' && rem_left > 0){
    //         dfs(s , index + 1 , rem_left - 1 , rem_right , balance , current_str);
    //     }else if(c == ')' && rem_right > 0){
    //         dfs(s , index + 1 , rem_left , rem_right - 1 , balance , current_str);
    //     }

    //     if(c == '('){
    //         dfs(s , index + 1 , rem_left , rem_right , balance + 1 , current_str + c);
    //     }else if(c == ')'){
    //         dfs(s , index + 1 , rem_left , rem_right , balance - 1 , current_str + c);
    //     }else{
    //         dfs(s , index + 1 , rem_left , rem_right , balance , current_str + c);
    //     }
    // }
// 3----------------------------------------------------------------------------------------------------------3

    void dfs(string s , int start , int last , int open , int close){
        int balance = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == open) balance++;
            if(s[i] == close) balance--;
            if(balance >= 0) continue;

            for(int j = last; j <= i; j++){
                if(s[j] == close && (j == last || s[j - 1] != close)){
                    dfs(s.substr(0 , j) + s.substr(j + 1) , i , j , open , close);
                }
            }
            return;
        }

        reverse(s.begin() , s.end());
        if(open == '('){
            dfs(s , 0 , 0 , ')' , '(');
        }else{
            ans.push_back(s);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
    // 1-----------------------------------------------------------------1
        // if(s.empty()){
        //     return {""};
        // }

        // vector<string> result;
        // queue<string> q;
        // unordered_set<string> visited;

        // q.push(s);
        // visited.insert(s);
        // bool found = false;

        // while(!q.empty()){
        //     int level_size = q.size();
        //     vector<string> level_solutions;

        //     for(int i = 0; i < level_size; i++){
        //         string current = q.front();
        //         q.pop();

        //         if(isValid(current)){
        //             level_solutions.push_back(current);
        //             found = true;
        //         }

        //         if(found) continue;

        //         for(size_t j = 0; j < current.length(); j++){
        //             if(current[j] != '(' && current[j] != ')'){
        //                 continue;
        //             }

        //             string next_state = current.substr(0 , j) + current.substr(j + 1);
        //             if(visited.find(next_state) == visited.end()){
        //                 visited.insert(next_state);
        //                 q.push(next_state);
        //             }
        //         }
        //     }
        //     if(found){
        //         return level_solutions;
        //     }
        // }
        // return result.empty() ? vector<string> {""} : result;
    // 1---------------------------------------------------------------------------------1

    // 2--------------------------------------------------------------------2
        // int rem_left = 0, rem_right = 0;

        // // Calculate minimum unmatched parentheses to remove
        // for (char c : s) {
        //     if (c == '(') {
        //         rem_left++;
        //     } else if (c == ')') {
        //         if (rem_left > 0) rem_left--;
        //         else rem_right++;
        //     }
        // }

        // valid_set.clear();
        // dfs(s, 0, rem_left, rem_right, 0, "");
        
        // return std::vector<std::string>(valid_set.begin(), valid_set.end());
    // 2----------------------------------------------------------------------2

        dfs(s , 0 , 0 , '(' , ')');
        return ans;
    }
};