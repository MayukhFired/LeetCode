class Solution {
public:
    int numTrees(int n) {
        vector<int> uniqueTrees(n + 1 , 1);
        for(int nodes = 2; nodes <= n; nodes++){
            int total = 0;
            for(int root = 1; root <= nodes; root++){
                total += uniqueTrees[root - 1] * uniqueTrees[nodes - root];
            }
            uniqueTrees[nodes] = total;
        }
        return uniqueTrees[n];
    }
};