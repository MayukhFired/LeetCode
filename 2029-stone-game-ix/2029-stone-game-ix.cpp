class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c0 = 0;
        int c1 = 0;
        int c2 = 0;
        for(int i = 0; i < stones.size(); i++){
            int r = stones[i] % 3;
            if(r == 0) c0++;
            if(r == 1) c1++;
            if(r == 2) c2++;
        }
        if(c0 % 2 == 0){
            return c1 > 0 and c2 > 0;
        }
        return abs(c1 - c2) > 2;
    }
};