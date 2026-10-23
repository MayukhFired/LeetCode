class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // int count = 0;
        // for(int i = 0; i < grid.size(); i++){
        //     for(int j = 0; j < grid[i].size(); j++){
        //         if(grid[i][j] < 0){
        //             count += grid[i].size() - j;
        //             break;
        //         }
        //     }
        // }
        // return count;

        int count = 0;
        int i = grid.size() - 1;
        int j = 0;
        int n = grid[0].size();

        while(i >= 0 && j < n){
            if(grid[i][j] >= 0){
                j++;
            }else{
                count += n - j;
                i--;
            }
        }
        return count;
    }
};