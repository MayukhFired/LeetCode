class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // int n = s.length();
        // for(int i = 1; i <= n / 2; i++){
        //     if(n % i == 0){
        //         string repeated = "";
        //         for(int j = 0; j < n / i; j++){
        //             repeated += s.substr(0 , i);
        //         }
        //         if(repeated == s){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        string c = s + s;
        return c.substr(1 , c.length() - 2).find(s) != string::npos;
    }
};