class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1 || numRows >= s.length()){
            return s;
        }

        vector<string> rows(min(numRows , (int)s.length()));
        int currRow = 0;
        bool goingdown = false;
        for(char c : s){
            rows[currRow] += c;
            if(currRow == 0 || currRow == numRows - 1){
                goingdown = !goingdown;
            }
            currRow += goingdown ? 1 : -1;
        }
        string result = "";
        for(const string& row : rows){
            result += row;
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna