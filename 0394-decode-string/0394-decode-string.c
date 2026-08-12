char* decodeString(char* s) {
    int s_len = strlen(s);
    
    // Stack capacity initialization
    int stack_capacity = 64;
    int stack_top = -1;
    
    int* count_stack = (int*)malloc(stack_capacity * sizeof(int));
    char** str_stack = (char**)malloc(stack_capacity * sizeof(char*));
    
    // Current state buffers
    int current_num = 0;
    int curr_capacity = 128;
    int curr_len = 0;
    char* current_str = (char*)malloc(curr_capacity * sizeof(char));
    current_str[0] = '\0';
    
    for (int i = 0; i < s_len; i++) {
        char ch = s[i];
        
        if (isdigit(ch)) {
            current_num = current_num * 10 + (ch - '0');
        } 
        else if (ch == '[') {
            // Resize stacks if full
            if (stack_top + 1 >= stack_capacity) {
                stack_capacity *= 2;
                count_stack = (int*)realloc(count_stack, stack_capacity * sizeof(int));
                str_stack = (char**)realloc(str_stack, stack_capacity * sizeof(char*));
            }
            
            // Push current state to stacks
            stack_top++;
            count_stack[stack_top] = current_num;
            str_stack[stack_top] = current_str;
            
            // Reset for inside bracket content
            current_num = 0;
            curr_capacity = 128;
            curr_len = 0;
            current_str = (char*)malloc(curr_capacity * sizeof(char));
            current_str[0] = '\0';
        } 
        else if (ch == ']') {
            int k = count_stack[stack_top];
            char* prev_str = str_stack[stack_top];
            stack_top--;
            
            int prev_len = strlen(prev_str);
            int new_len = prev_len + (curr_len * k);
            
            // Allocate space for combined string
            char* combined_str = (char*)malloc((new_len + 1) * sizeof(char));
            strcpy(combined_str, prev_str);
            
            // Repeat current_str k times onto combined_str
            for (int r = 0; r < k; r++) {
                strcat(combined_str, current_str);
            }
            
            // Free consumed buffers
            free(prev_str);
            free(current_str);
            
            // Update current state
            current_str = combined_str;
            curr_len = new_len;
            curr_capacity = new_len + 1;
        } 
        else {
            // Ensure capacity for appending letter
            if (curr_len + 2 > curr_capacity) {
                curr_capacity *= 2;
                current_str = (char*)realloc(current_str, curr_capacity * sizeof(char));
            }
            current_str[curr_len++] = ch;
            current_str[curr_len] = '\0';
        }
    }
    
    // Cleanup stacks
    free(count_stack);
    free(str_stack);
    
    return current_str;
}