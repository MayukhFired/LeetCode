class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int k = 0;
        int N = nums1.size() + nums2.size();
        int r[N];

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                r[k++] = nums1[i++];
            }else{
                r[k++] = nums2[j++];
            }
        }

        while(i < nums1.size()){
            r[k++] = nums1[i++];
        }

        while(j < nums2.size()){
            r[k++] = nums2[j++];
        }

        float median;
        if(N % 2 != 0){
            median = r[N / 2];
        }else{
            median = (r[(N - 1) / 2] + r[N / 2]) / 2.0;
        }
        return median;
    }
};