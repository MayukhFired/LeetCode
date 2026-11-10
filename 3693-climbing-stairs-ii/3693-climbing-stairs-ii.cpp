class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int a = 0; 
        int b = 0;
        int c = 0;

        for(int i = 0; i < n; i++){
            int n = min({a + 9 , b + 4 , c + 1}) + costs[i];
            a = b;
            b = c;
            c = n;
        }
        return c;
    }
};