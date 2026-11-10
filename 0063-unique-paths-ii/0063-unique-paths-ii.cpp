#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        // Quick edge case check for an empty grid
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size(); // Fixed typo: obstacleGird -> obstacleGrid
        
        std::vector<int> dp(n, 0);       // Added std:: namespace prefix
        
        // Base case: If the starting cell is blocked, we can't move anywhere
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[n - 1];
    }
};
