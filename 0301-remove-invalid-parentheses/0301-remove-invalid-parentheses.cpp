class Solution {
private:
    bool isValid(const string& s){
        int balance = 0;
        for(char c : s){
            if(c == '('){
                balance++;
            }else if(c == ')'){
                balance--;
                if(balance < 0){
                    return false;
                }
            }
        }
        return balance == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        if(s.empty()){
            return {""};
        }

        vector<string> result;
        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);
        bool found = false;

        while(!q.empty()){
            int level_size = q.size();
            vector<string> level_solutions;

            for(int i = 0; i < level_size; i++){
                string current = q.front();
                q.pop();

                if(isValid(current)){
                    level_solutions.push_back(current);
                    found = true;
                }

                if(found) continue;

                for(size_t j = 0; j < current.length(); j++){
                    if(current[j] != '(' && current[j] != ')'){
                        continue;
                    }

                    string next_state = current.substr(0 , j) + current.substr(j + 1);
                    if(visited.find(next_state) == visited.end()){
                        visited.insert(next_state);
                        q.push(next_state);
                    }
                }
            }
            if(found){
                return level_solutions;
            }
        }
        return result.empty() ? vector<string> {""} : result;
    }
};