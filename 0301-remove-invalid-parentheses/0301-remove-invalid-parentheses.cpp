class Solution {
    unordered_set<string>valid_set;
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

    void dfs(const string& s , int index , int rem_left , int rem_right , int balance , string current_str){
        if(index == s.length()){
            if(rem_left == 0 && rem_right == 0 && balance == 0){
                valid_set.insert(current_str);
            }
            return;
        }

        if(balance < 0){
            return;
        }

        char c = s[index];

        if(c == '(' && rem_left > 0){
            dfs(s , index + 1 , rem_left - 1 , rem_right , balance , current_str);
        }else if(c == ')' && rem_right > 0){
            dfs(s , index + 1 , rem_left , rem_right - 1 , balance , current_str);
        }

        if(c == '('){
            dfs(s , index + 1 , rem_left , rem_right , balance + 1 , current_str + c);
        }else if(c == ')'){
            dfs(s , index + 1 , rem_left , rem_right , balance - 1 , current_str + c);
        }else{
            dfs(s , index + 1 , rem_left , rem_right , balance , current_str + c);
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

        int rem_left = 0;
        int rem_right = 0;

        for(char c : s){
            if(c == '('){
                rem_left++;
            }else if(c == ')'){
                if(rem_left > 0){
                    rem_left--;
                }else{
                    rem_right++;
                }
            }
        }
        valid_set.clear();
        dfs(s , 0 , rem_left , rem_right , 0 , "");

        return vector<string>(valid_set.begin() , valid_set.end());
    }
};