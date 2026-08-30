class Solution {
private:
    void dfs(int city , const vector<vector<int>>& isConnected , vector<bool>& visited){
        visited[city] = true;
        for(int neighbour = 0; neighbour < isConnected.size(); neighbour++){
            if(isConnected[city][neighbour] == 1 && !visited[neighbour]){
                dfs(neighbour , isConnected , visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n , false);
        int provinces = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i , isConnected , visited);
                provinces++;
            }
        }
        return provinces;
    }
};