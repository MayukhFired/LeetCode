static int min(int a , int b){
    return a < b ? a : b;
}

static int max(int a , int b){
    return a > b ? a : b;
}

static int calculate(const char* day , const int* prefix_sum){
    int month = (day[0] - '0') * 10 + day[1] - '0';
    int date = (day[3] - '0') * 10 + day[4] - '0';
    return prefix_sum[month - 1] + date;
}

int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
    int datesofMonths[12] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
    int prefix_sum[13];
    prefix_sum[0] = 0;
    for(int i = 0; i < 12; i++){
        prefix_sum[i + 1] = prefix_sum[i] + datesofMonths[i];
    }

    int AlliceArriveDay = calculate(arriveAlice , prefix_sum);
    int AlliceLeaveDay = calculate(leaveAlice , prefix_sum);
    int BobArriveDay = calculate(arriveBob , prefix_sum);
    int BobleaveDay = calculate(leaveBob , prefix_sum);

    return max(0 , min(AlliceLeaveDay , BobleaveDay) - max(AlliceArriveDay , BobArriveDay) + 1);
}