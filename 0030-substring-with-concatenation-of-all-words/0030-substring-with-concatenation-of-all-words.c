/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int getWordId(const char* slice , char** uniqueWords , int uniqueCount , int wordLen) {
    for(int i = 0; i < uniqueCount; i++) {
        if(strncmp(slice , uniqueWords[i] , wordLen) == 0) {
            return i;
        }
    }
    return -1;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    *returnSize = 0;
    if(!s || !words || wordsSize == 0) {
        return NULL;
    }

    int n = strlen(s);
    int word_len = strlen(words[0]);
    int total_len = wordsSize * word_len;

    if(n < total_len) {
        return NULL;
    }

    char** uniqueWords = (char**)malloc(wordsSize * sizeof(char*));
    int* targetFreq = (int*)calloc(wordsSize , sizeof(int));
    int uniqueCount = 0;

    for(int i = 0; i < wordsSize; i++) {
        int id = getWordId(words[i] , uniqueWords , uniqueCount , word_len);
        if(id == -1) {
            uniqueWords[uniqueCount] = words[i];
            targetFreq[uniqueCount] = 1;
            uniqueCount++;
        }else{
            targetFreq[id]++;
        }
    }

    int* ans = (int*)malloc((n - total_len + 1) * sizeof(int));
    int* seen = (int*)malloc(uniqueCount * sizeof(int));

    for(int i = 0; i < word_len; i++) {
        int left = i;
        int count = 0;
        memset(seen , 0 , uniqueCount * sizeof(int));
        for(int right = i; right <= n - word_len; right += word_len) {
            int id = getWordId(s + right , uniqueWords , uniqueCount , word_len);
            if(id != -1) {
                seen[id]++;
                count++;

                while(seen[id] > targetFreq[id]) {
                    int leftId = getWordId(s + left , uniqueWords , uniqueCount , word_len);
                    seen[leftId]--;
                    count--;
                    left += word_len;
                }

                if(count == wordsSize) {
                    ans[(*returnSize)++] = left;
                    int leftId = getWordId(s + left , uniqueWords , uniqueCount , word_len);
                    seen[leftId]--;
                    count--;
                    left += word_len;
                } 
            }else{
                memset(seen , 0 , uniqueCount * sizeof(int));
                count = 0;
                left = right + word_len;
            }
        }
    }

    free(seen);
    free(targetFreq);
    free(uniqueWords);

    return ans;
}