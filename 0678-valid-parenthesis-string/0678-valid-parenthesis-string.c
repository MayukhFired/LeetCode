
// 1---------------------------------------------------------------------------------1
// bool isValid(int index , int openCount , const char* s , int len , int** memo){
//     if(index == len){
//         return (openCount == 0);
//     }

//     if(memo[index][openCount] != -1){
//         return memo[index][openCount];
//     }

//     bool valid = false;

//     if(s[index] == '*'){
//         valid |= isValid(index + 1 , openCount + 1 , s , len , memo);
//         if(openCount > 0){
//             valid |= isValid(index + 1 , openCount - 1 , s , len , memo);
//         }
//         valid |= isValid(index + 1 , openCount , s , len , memo);
//     }else{
//         if(s[index] == '('){
//             valid |= isValid(index + 1 , openCount + 1 , s , len , memo);
//         }else if(openCount > 0){
//             valid |= isValid(index + 1 , openCount - 1 , s , len , memo);
//         }
//     }
//     return memo[index][openCount] = valid;
// }
//  1-------------------------------------------------------------------------------1

bool checkValidString(char* s) {
    // 1-----------------------------------------------------------1
    // int len = strlen(s);
    // if(len == 0){
    //     return true;
    // }

    // int** memo = (int**)malloc(len * sizeof(int*));
    // for(int i = 0; i < len; i++){
    //     memo[i] = (int*)malloc((len + 1 ) * sizeof(int));
    //     memset(memo[i] , -1 , (len + 1) * sizeof(int));
    // }

    // bool res = isValid(0 , 0 , s , len , memo);

    // for(int i = 0; i < len; i++){
    //     free(memo[i]);
    // }

    // free(memo);
    // return res;
    // 1-------------------------------------------------------------1

    // 2-------------------------------------------------------------2
    // int n = strlen(s);
    // int* stack = (int*)malloc(n * sizeof(int));
    // int* star = (int*)malloc(n * sizeof(int));
    // int top = -1;
    // int starttop = -1;

    // for(int i = 0; i < n; i++){
    //     char ch = s[i];
    //     if(ch == '('){
    //         stack[++top] = i;
    //     }else if(ch == '*'){
    //         star[++starttop] = i;
    //     }else{
    //         if(top >= 0){
    //             top--;
    //         }else if(starttop >= 0){
    //             starttop--;
    //         }else{
    //             free(stack);
    //             free(star);
    //             return false;
    //         }
    //     }
    // }

    // while(top >= 0 && starttop >= 0){
    //     if(stack[top] > star[starttop]){
    //         free(stack);
    //         free(star);
    //         return false;
    //     }
    //     top--;
    //     starttop--;
    // }

    // free(stack);
    // free(star);
    // return top == -1;
    // 2--------------------------------------------------------2

    int min_open = 0;
    int max_open = 0;

    for(int i = 0; i < strlen(s); i++){
        char curr = s[i];
        if(curr == '('){
            min_open++;
            max_open++;
        }else if(curr == ')'){
            min_open--;
            max_open--;
        }else if(curr == '*'){
            min_open--;
            max_open++;
        }

        if(max_open < 0){
            return false;
        }

        if(min_open < 0){
            min_open = 0;
        }
    }

    return min_open == 0;
}