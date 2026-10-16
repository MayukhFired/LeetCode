bool rotateString(char* s, char* goal) {
    int len_s = strlen(s);
    int len_goal = strlen(goal);

    if(len_s != len_goal){
        return false;
    }

    char* double_s = (char*)malloc((2 * len_s + 1) * sizeof(char));
    if(double_s == NULL){
        return false;
    }

    strcpy(double_s , s);
    strcat(double_s , s);
    bool res = (strstr(double_s , goal) != NULL);
    free(double_s);
    return res;
}