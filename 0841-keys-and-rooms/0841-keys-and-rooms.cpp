class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size() , false);
        vector<int> stack;
        stack.push_back(0);
        int visitedCount = 0;
        while(!stack.empty()){
            int curr = stack.back();
            stack.pop_back();
            if(!visited[curr]){
                visited[curr] = true;
                visitedCount++;
                for(int key : rooms[curr]){
                    if(!visited[key]){
                        stack.push_back(key);
                    }
                }
            }
        }
        return visitedCount == rooms.size();
    }
};