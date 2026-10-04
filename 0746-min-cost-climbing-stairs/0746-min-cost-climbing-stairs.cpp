class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first = 0;
        int second = 0;

        for(int c : cost){
            int next = c + min(first , second);
            first = second;
            second = next;
        }

        return min(first , second);
    }
};