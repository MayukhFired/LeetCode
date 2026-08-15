char* predictPartyVictory(char* senate) {
    int n = strlen(senate);
    int* radiant = (int*)malloc(n * sizeof(int));
    int* dire = (int*)malloc(n * sizeof(int));
    int r_front = 0;
    int r_rear = 0;
    int d_front = 0;
    int d_rear = 0;
    for(int i = 0 ; i < n ; i++){
        if(senate[i] == 'R'){
            radiant[r_rear++] = i;
        }else{
            dire[d_rear++] = i;
        }
    }

    int max_cap = n * 2;
    radiant = (int*)realloc(radiant , sizeof(int) * max_cap);
    dire = (int*)realloc(dire , sizeof(int) * max_cap);
    while(r_front < r_rear && d_front < d_rear){
        int r_idx = radiant[r_front++];
        int d_idx = dire[d_front++];
        if(r_idx < d_idx){
            radiant[r_rear++] = r_idx + n;
        }else{
            dire[d_rear++] = d_idx + n;
        }
    }
    free(radiant);
    free(dire);
    return (r_front < r_rear) ? "Radiant" : "Dire";
}