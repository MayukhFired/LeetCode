typedef struct{
    int data[200];
    int top;
} Stack;

void initStack(Stack *s){
    s->top = -1;
}

void stackPush(Stack *s , int x){
    s->data[++(s->top)] = x;
}

int stackPop(Stack *s){
    return s->data[(s->top)--];
}

int stackPeek(Stack *s){
    return s->data[s->top];
}

bool stackEmpty(Stack *s){
    return s->top == -1;
}


typedef struct {
    Stack s1;
    Stack s2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    initStack(&(queue->s1));
    initStack(&(queue->s2));
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(&(obj->s1) , x);
}

int myQueuePop(MyQueue* obj) {
    if(stackEmpty(&(obj->s2))){
        while(!stackEmpty(&(obj->s1))){
            stackPush(&(obj->s2) , stackPop(&(obj->s1)));
        }
    }
    return stackPop(&(obj->s2));
}

int myQueuePeek(MyQueue* obj) {
    if(stackEmpty(&(obj->s2))){
        while(!stackEmpty(&(obj->s1))){
            stackPush(&(obj->s2) , stackPop(&(obj->s1)));
        }
    }
    return stackPeek(&(obj->s2));
}

bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(&(obj->s1)) && stackEmpty(&(obj->s2));
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/