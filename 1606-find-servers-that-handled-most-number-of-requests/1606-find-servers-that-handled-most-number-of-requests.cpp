class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for(int i = 0; i < k; i++){
            available.insert(i);
        }

        priority_queue<pair<long long , int> , vector<pair<long long , int>> , greater<pair<long long , int>>> busy;
        vector<int> count(k , 0);

        for(int i = 0; i < arrival.size(); i++){
            int time = arrival[i];

            while(!busy.empty() && busy.top().first <= time){
                available.insert(busy.top().second);
                busy.pop();
            }

            if(available.empty()){
                continue;
            }

            int target = i % k;
            auto it = available.lower_bound(target);

            if(it == available.end()){
                it = available.begin();
            }

            int server_id = *it;
            available.erase(it);
            busy.push({time + load[i] , server_id});
            count[server_id]++;
        }

        int max_handled = *max_element(count.begin() , count.end());

        vector<int> res;
        for(int i = 0; i < k; i++){
            if(count[i] == max_handled){
                res.push_back(i);
            }
        }
        return res;
    }
};