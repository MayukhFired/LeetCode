int compare_seats(const void* a , const void* b){
    int* seat1 = *(int**)a;
    int* seat2 = *(int**)b;
    if(seat1[0] != seat2[0]){
        return seat1[0] - seat2[0];
    }
    return seat1[1] - seat2[1];
}

int maxNumberOfFamilies(int n, int** reservedSeats, int reservedSeatsSize, int* reservedSeatsColSize) {
    qsort(reservedSeats , reservedSeatsSize , sizeof(int*) , compare_seats);
    int left_mask = 0b00001111;
    int middle_mask = 0b00111100;
    int right_mask = 0b11110000;
    int i = 0;
    int  unique_seats = 0;
    int ans = 0;
    while(i < reservedSeatsSize){
        int current_row = reservedSeats[i][0];
        int bitmask = 0;
        unique_seats++;
        while(i < reservedSeatsSize && reservedSeats[i][0] == current_row){
            int col = reservedSeats[i][1];
            if(col >= 2 && col <= 9){
                bitmask |= 1 << (col - 2);
            }
            i++;
        }
        bool left_free = (bitmask & left_mask) == 0;
        bool middle_free = (bitmask & middle_mask) == 0;
        bool right_free = (bitmask & right_mask) == 0;
        if(left_free && right_free){
            ans += 2;
        }else if(left_free || middle_free || right_free){
            ans += 1;
        }
    }
    ans += (n - unique_seats) * 2;
    return ans;
}