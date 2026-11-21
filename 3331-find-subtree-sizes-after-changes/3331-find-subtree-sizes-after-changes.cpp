class Solution {
public:
    vector<int> ans;
    void dfs(int u , vector<vector<int>>& adj , string& s , vector<int>& p , vector<int>& last){
        int c = s[u] - 'a';
        int old = last[c];

        if(u && old != -1){
            p[u] = old;
        }
        last[c] = u;

        for(int v : adj[u]){
            dfs(v , adj , s , p , last);
        }
        last[c] = old;
    }
    int calculate(int u , vector<vector<int>>& tree){
        ans[u] = 1;
        for(int v : tree[u]){
            ans[u] += calculate(v , tree);
        }
        return ans[u];
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n) , tree(n);

        for(int i = 1; i < n; i++){
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26 , -1);
        dfs(0 , adj , s , parent , last);

        for(int i = 1; i < n; i++){
            tree[parent[i]].push_back(i);
        }

        ans.resize(n);
        calculate(0 , tree);
        return ans;
    }
};