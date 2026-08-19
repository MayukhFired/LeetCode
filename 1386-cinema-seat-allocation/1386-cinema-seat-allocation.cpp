class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int left_mask = 0b00001111;
        int middle_mask = 0b00111100;
        int right_mask = 0b11110000;
        unordered_map <int , int> occupied;
        for(const vector<int>& seat: reservedSeats){
            if(seat[1] >= 2 && seat[1] <= 9){
                occupied[seat[0]] |= (1 <<(seat[1] - 2));
            }
        }
        int ans = (n - occupied.size()) * 2;
        for(auto& [row , bitmask] : occupied){
            bool left_free = (bitmask & left_mask) == 0;
            bool middle_free = (bitmask & middle_mask) == 0;
            bool right_free = (bitmask & right_mask) == 0;
            if(left_free && right_free){
                ans += 2;
            }else if(left_free || middle_free || right_free){
                ans += 1;
            }
        }
        return ans;
    }
};