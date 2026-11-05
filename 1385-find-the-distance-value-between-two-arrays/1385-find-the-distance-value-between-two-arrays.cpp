class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    // 1-------------------------------------------------------------1
        // int count = 0;
        // for(int i = 0; i < arr1.size(); i++){
        //     bool ok = true;
        //     for(int j = 0; j < arr2.size(); j++){
        //         ok = ok && (abs(arr1[i] - arr2[j]) > d);
        //     }
        //     count += ok ? 1 : 0;
        // }
        // return count;
    // 1---------------------------------------------------------------1
        int count = 0;
        sort(arr2.begin() , arr2.end());
        for(int i = 0; i < arr1.size(); i++){
            int x = arr1[i];
            int left = 0;
            int right = arr2.size();
            while(left < right){
                int mid = left + (right - left) / 2;
                if(arr2[mid] < x){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
            int p = left;
            bool ok = true;
            if(p < arr2.size()){
                ok = ok && (arr2[p] - x > d); 
            }
            if(p - 1 >= 0 && p - 1 < arr2.size()){
                ok = ok && (x - arr2[p - 1] > d);
            }
            count += ok ? 1 : 0;
        }
        return count;
    }
};