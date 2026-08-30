class Solution {
private:
    void dfs(int city , const vector< vector <pair <int , int>>>& adj , vector<bool>& visited , int& change_count){
        visited[city] = true;
        for(const auto& edge : adj[city]){
            int neighbour = edge.first;
            int cost = edge.second;

            if(!visited[neighbour]){
                change_count += cost;
                dfs(neighbour , adj , visited , change_count);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int , int>>> adj(n);
        for(const auto& conn : connections){
            adj[conn[0]].push_back({conn[1] , 1});
            adj[conn[1]].push_back({conn[0] , 0});
        }

        vector<bool> visited(n , false);
        int change_count = 0;
        dfs(0 , adj , visited , change_count);
        return change_count;
    }
};