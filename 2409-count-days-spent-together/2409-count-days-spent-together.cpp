class Solution {
private:
    static int calculate(const string& day , const vector<int>& prefix_sum){
        int month = (day[0] - '0') * 10 + day[1] - '0';
        int date = (day[3] - '0') * 10 + day[4] - '0';
        return prefix_sum[month - 1] + date;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> DaysofMonths = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
        vector<int> prefix_sum(1 , 0);
        for(int date : DaysofMonths){
            prefix_sum.emplace_back(prefix_sum.back() + date);
        }

        int AlliceArriveDay = calculate(arriveAlice , prefix_sum);
        int AlliceLeaveDay = calculate(leaveAlice , prefix_sum);
        int BobArriveDay = calculate(arriveBob , prefix_sum);
        int BobLeaveDay = calculate(leaveBob , prefix_sum);

        return max(0 , min(AlliceLeaveDay , BobLeaveDay) - max(AlliceArriveDay , BobArriveDay) + 1);
    }
};