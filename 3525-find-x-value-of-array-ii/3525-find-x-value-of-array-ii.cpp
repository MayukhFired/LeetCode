struct SegmentTreeNode{
    int prod;
    vector<int> remain;

    SegmentTreeNode(int k){
        prod = 1;
        remain.assign(k , 0);
    }
};

class SegmentTree {
private:
    int n;
    int k;
    vector<SegmentTreeNode> tree;

    void merge(const SegmentTreeNode& left , const SegmentTreeNode& right , SegmentTreeNode& res){
        res.prod = (1LL * left.prod * right.prod) % k;

        for(int i = 0; i < k; i++){
            res.remain[i] = left.remain[i];
        }

        for(int i = 0; i < k; i++){
            if(right.remain[i] > 0){
                int target_mod = (1LL * left.prod * i) % k;
                res.remain[target_mod] += right.remain[i];
            }
        }
    }

    void build(const vector<int>& nums , int curr , int left , int right){
        if(left == right){
            int val = nums[left] % k;
            tree[curr].remain[val] = 1;
            tree[curr].prod = val;
            return;
        }
        int mid = left + (right - left) / 2;
        build(nums , 2 * curr + 1 , left , mid);
        build(nums , 2 * curr + 2 , mid + 1 , right);
        merge(tree[2 * curr + 1] , tree[2 * curr + 2] , tree[curr]);
    }

    void update(int curr , int low , int high , int index , int val){
        if(low == high){
            int target_val = val % k;
            fill(tree[curr].remain.begin() , tree[curr].remain.end() , 0);
            tree[curr].remain[target_val] = 1;
            tree[curr].prod = target_val;
            return;
        }

        int mid = low + (high - low) / 2;
        if(index <= mid){
            update(2 * curr + 1 , low , mid , index , val);
        }else{
            update(2 * curr + 2 , mid + 1 , high , index , val);
        }
        merge(tree[2 * curr + 1] , tree[2 * curr + 2] , tree[curr]);
    }

    void query(int curr , int low , int high , int ql , int qr , SegmentTreeNode& res){
        if(ql <= low && high <= qr){
            res = tree[curr];
            return;
        }
        int mid = low + (high - low) / 2;
        if(qr <= mid){
            return query(2 * curr + 1 , low , mid , ql , qr , res);
        }
        if(ql > mid){
            return query(2 * curr + 2 , mid + 1 , high , ql , qr , res);
        }

        SegmentTreeNode left_res(k) , right_res(k);
        query(2 * curr + 1 , low , mid , ql , mid , left_res);
        query(2 * curr + 2 , mid + 1 , high , mid + 1 , qr , right_res);
        merge(left_res , right_res , res);
    }

public:
    SegmentTree(const vector<int>& nums , int k_val){
        n = nums.size();
        k = k_val;
        tree.assign(4 * n , SegmentTreeNode(k_val));
        if(nums.size() > 0){
            build(nums , 0 , 0 , n - 1);
        }
    }

    void update(int idx , int val){
        update(0 , 0 , n - 1 , idx , val);
    }

    SegmentTreeNode query(int ql , int qr){
        SegmentTreeNode res(k);
        query(0 , 0 , n - 1 , ql , qr , res);
        return res;
    }
};

class Solution{
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree st(nums , k);
        vector<int> ans;
        ans.reserve(queries.size());

        for(const auto& q : queries){
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];
            st.update(idx , val);

            if(start >= n){
                ans.push_back(0);
            }else{
                SegmentTreeNode res_node = st.query(start , n - 1);
                ans.push_back(res_node.remain[x]);
            }
        }
        return ans;
    }
};