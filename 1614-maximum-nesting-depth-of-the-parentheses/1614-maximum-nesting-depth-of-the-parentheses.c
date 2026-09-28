#define Max(a , b) ((a) > (b) ? (a) : (b))
int maxDepth(char* s) {
    int max_depth = 0;
    int curr_depth = 0;

    for(int i = 0; s[i] != 0; i++){
        if(s[i] == '('){
            curr_depth++;
            max_depth = Max(max_depth , curr_depth);
        }else if(s[i] == ')'){
            curr_depth--;
        }
    }
    return max_depth;
}