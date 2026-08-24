// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
//   };

//This below code is solved by using BFS

// struct Queue{
//     struct TreeNode** data;
//     int front;
//     int rear;
//     int capacity;
// };

// struct Queue* createqueue(int capacity){
//     struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
//     q->data = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
//     q->front = 0;
//     q->rear = 0;
//     q->capacity = capacity;
//     return q;
// };

// int isempty(struct Queue* q){
//     return q->front == q->rear;
// }

// void enqueue(struct Queue* q , struct TreeNode* node){
//     q->data[q->rear++] = node;
// }

// struct TreeNode* dequeue(struct Queue* q){
//     return q->data[q->front++];
// }

// int maxLevelSum(struct TreeNode* root) {
//     if(!root){
//         return 0;
//     }

//     int max_sum = INT_MIN;
//     int max_level = 1;
//     int current_level = 1;
//     struct Queue* q = createqueue(10000);
//     enqueue(q , root);
//     while(!isempty(q)){
//         int level_size = q->rear - q->front;
//         int level_sum = 0;
//         for(int i = 0; i < level_size; i++){
//             struct TreeNode* node = dequeue(q);
//             level_sum += node->val;
//             if(node->left){
//                 enqueue(q , node->left);
//             }
//             if(node->right){
//                 enqueue(q , node->right);
//             }
//         }
//         if(level_sum > max_sum){
//             max_sum = level_sum;
//             max_level = current_level;
//         }
//         current_level++;
//     }
//     free(q->data);
//     free(q);
//     return max_level;
// }

//Using DFS to solve the problem 
void dfs(struct TreeNode* node , int level , int* level_sums , int* maxDepth){
    if(node == NULL){
        return;
    }
    if(level > *maxDepth){
        *maxDepth = level;
    }

    level_sums[level] += node->val;
    dfs(node->left , level + 1, level_sums , maxDepth);
    dfs(node->right , level + 1 , level_sums , maxDepth);
}
int maxLevelSum(struct TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int* level_sums = (int*)calloc(1000 , sizeof(int));
    int maxDepth = 0;
    dfs(root , 0 , level_sums , &maxDepth);
    int max_sum = INT_MIN;
    int max_level = 1;
    for(int i = 0; i <= maxDepth; i++){
        if(level_sums[i] > max_sum){
            max_sum = level_sums[i];
            max_level = i + 1;
        }
    }
    free(level_sums);
    return max_level;
}