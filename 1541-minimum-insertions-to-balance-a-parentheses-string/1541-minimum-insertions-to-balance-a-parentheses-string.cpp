class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int leftCount = 0;
        int len = s.length();
        int index = 0;

        while(index < len){
            char c = s[index];
            if(c == '('){
                leftCount++;
                index++;
            }else{
                if(leftCount > 0){
                    leftCount--;
                }else{
                    insertions++;
                }
                if(index < len - 1 && s[index + 1] == ')'){
                    index += 2;
                }else{
                    insertions++;
                    index++;
                }
            }
        }
        insertions += leftCount * 2;
        return insertions;
    }
};