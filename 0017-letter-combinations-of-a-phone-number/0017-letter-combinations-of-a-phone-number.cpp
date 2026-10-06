class Solution {
private:
    const vector<string> phone_map = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};

    void backtrack(const string& digits , int index , string& current , vector<string>& result){
        if(index == digits.length()){
            result.push_back(current);
            return;
        }

        string letters = phone_map[digits[index] - '0'];
        for(char letter : letters){
            current.push_back(letter);
            backtrack(digits , index + 1 , current , result);
            current.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()){
            return result;
        }

        string current = "";
        backtrack(digits , 0 , current , result);
        return result;
    }
};