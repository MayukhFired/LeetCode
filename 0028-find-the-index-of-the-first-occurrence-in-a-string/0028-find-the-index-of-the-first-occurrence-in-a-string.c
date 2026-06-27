int strStr(char* haystack, char* needle) {
    char *pointer = strstr(haystack , needle);

    if(pointer != NULL){
        return pointer - haystack;
    }

    return -1;
}