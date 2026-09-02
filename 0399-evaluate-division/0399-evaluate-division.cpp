class Solution {
private:
    double dfs(const string& curr , const string& target , unordered_map<string , unordered_map<string , double>>& graph , unordered_set<string>& visited){
        if(graph.find(curr) == graph.end() || graph.find(target) == graph.end()){
            return -1.0;
        }
        if(curr == target){
            return 1.0;
        }

        visited.insert(curr);
        for(const auto& [neighbour , weight] : graph[curr]){
            if(visited.find(neighbour) == visited.end()){
                double product = dfs(neighbour , target , graph , visited);
                if(product != -1.0){
                    return weight * product;
                }
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string , unordered_map<string , double>> graph;
        for(size_t i = 0; i < equations.size(); i++){
            string src = equations[i][0];
            string dst = equations[i][1];
            double val = values[i];
            graph[src][dst] = val;
            graph[dst][src] = 1.0 / val;
        }
        vector<double> results;
        for(const auto& query : queries){
            unordered_set<string> visited;
            results.push_back(dfs(query[0] , query[1] , graph , visited));
        }

        return results;
    }
};