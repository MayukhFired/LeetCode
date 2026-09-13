class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int , int>> nonzeros1;
        vector<pair<int , int>> nonzeros2;

        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                if(img1[r][c] == 1){
                    nonzeros1.push_back({r , c});
                }
                if(img2[r][c] == 1){
                    nonzeros2.push_back({r , c});
                }
            }
        }

        map<pair<int , int> , int> vectorCounts;
        int maxOverlap = 0;

        for(auto& p1 : nonzeros1){
            for(auto& p2 : nonzeros2){
                pair<int , int> vec = {p2.first - p1.first , p2.second - p1.second};
                vectorCounts[vec]++;
                maxOverlap = max(maxOverlap , vectorCounts[vec]);
            }
        }
        return maxOverlap;
    }
};