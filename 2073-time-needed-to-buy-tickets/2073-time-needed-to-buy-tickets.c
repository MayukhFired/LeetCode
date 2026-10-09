#define min(a , b) ((a) < (b) ? (a) : (b))
int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int ans = 0;
    for(int i = 0; i < ticketsSize; i++){
        ans += min(tickets[k] - (i > k) ,tickets[i]);
    }
    return ans;
}