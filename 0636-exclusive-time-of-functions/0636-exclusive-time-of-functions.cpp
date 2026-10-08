class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n , 0);
        stack<int> stk;
        int prev_time = 0;

        for(const string& log : logs){
            stringstream ss(log);
            string find_id_str , status , timestamp_str;

            getline(ss , find_id_str , ':');
            getline(ss , status , ':');
            getline(ss , timestamp_str , ':');

            int find_id = stoi(find_id_str);
            int timestamp = stoi(timestamp_str);

            if(status == "start"){
                if(!stk.empty()){
                    res[stk.top()] += timestamp - prev_time;
                }
                stk.push(find_id);
                prev_time = timestamp;
            }else{
                int popped_id = stk.top();
                stk.pop();
                res[popped_id] += timestamp - prev_time + 1;
                prev_time = timestamp + 1;
            }
        }
        return res;
    }
};