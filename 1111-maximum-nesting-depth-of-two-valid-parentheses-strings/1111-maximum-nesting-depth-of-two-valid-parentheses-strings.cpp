class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int count = 0;
        int maxCount = 0;

        for(int i = 0; i < seq.size(); i++){
            if(seq[i] == '('){
                count++;
            }else if(seq[i] == ')'){
                count--;
            }
            maxCount = max(maxCount , count);
        }

        vector<int> ans(seq.size() , 0);
        bool run = false;
        int part = maxCount / 2;

        for(int i = 0; i < seq.size(); i++){
            if(seq[i] == '('){
                count++;
            }else if(seq[i] == ')'){
                count--;
            }

            if(!run && count > part){
                ans[i] = 1;
                run = true;
            }else if(run && count >= part){
                ans[i] = 1;
                if(count == part){
                    run = false;
                }
            }
        }
        return ans;
    }
};