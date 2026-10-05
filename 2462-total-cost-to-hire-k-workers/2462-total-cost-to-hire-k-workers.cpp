class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        priority_queue<pair<int , int> , vector<pair<int , int>> ,  greater<pair<int , int>>> head;
        priority_queue<pair<int , int> , vector<pair<int , int>> ,  greater<pair<int , int>>> tail;

        int i = 0;
        int j = n - 1;
        long long total_cost = 0;

        for(int round = 0; round < k; round++){
            while(head.size() < candidates && i <= j){
                head.push({costs[i] , i});
                i++;
            }

            while(tail.size() < candidates && i <= j){
                tail.push({costs[j] , j});
                j--;
            }

            if(!head.empty() && !tail.empty()){
                if(head.top() < tail.top()){
                    total_cost += head.top().first;
                    head.pop();
                }else{
                    total_cost += tail.top().first;
                    tail.pop();
                }
            }else if(!head.empty()){
                total_cost += head.top().first;
                head.pop();
            }else if(!tail.empty()){
                total_cost += tail.top().first;
                tail.pop();
            }
        }

        return total_cost;
    }
};