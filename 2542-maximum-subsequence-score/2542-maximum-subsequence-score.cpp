class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int ,int>> pairs(n);

        for(int i = 0; i < n; i++){
            pairs[i] = {nums2[i] , nums1[i]};
        }

        sort(pairs.rbegin() , pairs.rend());

        priority_queue<int , vector<int> , greater<int>> minHeap;

        long long curr_sum = 0;
        long long max_score = 0;

        for(int i = 0; i < n;i++){
            int n2 = pairs[i].first;
            int n1 = pairs[i].second;

            minHeap.push(n1);
            curr_sum += n1;

            if(minHeap.size() > k){
                curr_sum -= minHeap.top();
                minHeap.pop();
            }

            if(minHeap.size() == k){
                max_score = max(max_score , curr_sum * n2);
            }

        }

        return max_score;
    }
};