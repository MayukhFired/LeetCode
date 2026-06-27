char* longestCommonPrefix(char** strs, int strsSize) {
    // Handle base case
    if (strsSize == 0 || strs == NULL) {
        char *empty = (char*)malloc(1);
        empty[0] = '\0';
        return empty;
    }

    char *compare = (char*)malloc(201 * sizeof(char));
    
    // Start by assuming the prefix is the entire first word
    int min_len = strlen(strs[0]); 

    // Loop through the rest of the words safely (up to strsSize)
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        
        // Count matches, but don't exceed the existing prefix length
        while (j < min_len && strs[0][j] == strs[i][j]) {
            j++;
        }
        
        // Shrink the prefix length to the smallest match found so far
        min_len = j; 
    }

    // Now copy the finalized prefix into your allocated memory
    for (int k = 0; k < min_len; k++) {
        compare[k] = strs[0][k];
    }
    
    compare[min_len] = '\0'; // Crucial: Null-terminate the string!
    return compare;
}
