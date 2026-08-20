char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows <= 1 || numRows >= len) {
        return s; 
    }
    char* result = (char*)malloc((len + 1) * sizeof(char));
    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* rowSize = (int*)calloc(numRows , sizeof(int));
    for(int i = 0; i < numRows; i++){
        rows[i] = (char*)malloc((len + 1) * sizeof(char));
    }

    int curr_row = 0;
    int goingDown = 0;
    for(int i = 0; i < len; i++){
        rows[curr_row][rowSize[curr_row]++] = s[i];
        if (curr_row == 0 || curr_row == numRows - 1) {
            goingDown = !goingDown;
        }
        curr_row += goingDown ? 1 : -1;
    }
    int index = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rowSize[i]; j++) {
            result[index++] = rows[i][j];
        }
        free(rows[i]);
    }
    result[index] = '\0';
    free(rows);
    free(rowSize);
    return result;
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna