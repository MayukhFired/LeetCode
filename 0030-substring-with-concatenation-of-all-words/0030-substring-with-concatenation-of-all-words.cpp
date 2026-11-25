class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.empty() || words.empty()){
            return ans;
        }

        int n = s.length();
        int wordCount = words.size();
        int wordLen = words[0].size();
        int totalLen = wordCount * wordLen;

        if(n < totalLen){
            return ans;
        }

        unordered_map<string , int> wordMap;
        for(const string& word: words) {
            wordMap[word]++;
        }

        for(int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;
            unordered_map<string , int> seen;

            for(int right = i; right <= n - wordLen; right += wordLen) {
                string currWord = s.substr(right , wordLen);

                if(wordMap.count(currWord)) {
                    seen[currWord]++;
                    count++;

                    while(seen[currWord] > wordMap[currWord]) {
                        string leftWord = s.substr(left , wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }

                    if(count == wordCount) {
                        ans.push_back(left);
                        string leftWord = s.substr(left , wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                }else{
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return ans;
    }
};