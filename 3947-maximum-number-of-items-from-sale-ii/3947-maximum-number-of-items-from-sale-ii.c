int compare(const void* a , const void* b) {
    const int* A = *(const int**)a;
    const int* B = *(const int**)b;
    return (A[1] > B[1]) - (A[1] < B[1]);
}

int maximumSaleItems(int** items, int itemsSize, int* itemsColSize, int budget) {
    qsort(items , itemsSize , sizeof(int*) , compare);
    int mx = 0;
    for(int i = 0; i < itemsSize; i++) {
        mx = fmax(mx , items[i][0]);
    }

    int* freq = (int*)calloc(mx + 1 , sizeof(int));
    for(int i = 0; i < itemsSize; i++) {
        freq[items[i][0]]++;
    }

    for(int i = 1; i <= mx; i++) {
        if(freq[i] > 0) {
            for(int j = i * 2; j <= mx; j += i) {
                freq[i] += freq[j];
            }
        }
    }

    int mn = items[0][1];
    int ans = 0;
    for(int i = 0; i < itemsSize; i++) {
        int factor = items[i][0];
        int price = items[i][1];
        if(price - mn > mn) {
            break;
        }

        int count = freq[factor] - 1;
        int take = budget / price;
        take = fmin(take , count);
        ans += take * 2;
        budget -= take * price;
    }

    ans += budget / mn;
    free(freq);
    return ans;
}