class Solution {
public:
    void get(const string& s , int start , int len , int* sum , int* count){
        *sum = 0;
        *count = 0;
        for(int i = start; i < start + len; i++){
            if(s[i] == '?'){
                (*count)++;
            }else{
                *sum += (s[i] - '0');
            }
        }
    }
    
    bool sumGame(string num) {
        int n = num.length();
        int half = n / 2;
        int n0 , n1 , q0 , q1;
        get(num , 0 , half , &n0 , &q0);
        get(num , half , half , &n1 , &q1);
        return ((q0 + q1) % 2 == 1) || (n0 - n1 != (q1 - q0) * 9 / 2);
    }
};