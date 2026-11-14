class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int min_diff = INT_MAX;
        vector<vector<int>> result;

        for(size_t i = 0; i < arr.size() - 1; i++){
            int diff = arr[i + 1] - arr[i];

            if(diff < min_diff){
                min_diff = diff;
                result.clear();
                result.push_back({arr[i] , arr[i + 1]});
            }else if(diff == min_diff){
                result.push_back({arr[i] , arr[i + 1]});
            }
        }
        return result;
    }
};