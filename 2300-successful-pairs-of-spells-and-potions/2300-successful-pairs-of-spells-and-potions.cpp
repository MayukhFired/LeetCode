class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        result.resize(spells.size());
        sort(potions.begin() , potions.end());
        for(int i = 0; i < spells.size(); i++){
            long long min_potion = (success + spells[i] - 1) / spells[i];
            int left = 0;
            int right = potions.size();
            while(left < right){
                int mid = left + (right - left) / 2;
                if(potions[mid] >= min_potion){
                    right = mid;
                }else{
                    left = mid + 1;
                }
            }
            result[i] = potions.size() - left;
        }
        return result;
    }
};