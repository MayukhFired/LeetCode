int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    int result = 0;

    while(s[i] == ' '){
        i++;
    }

    if(s[i] == '-' || s[i] == '+'){
        if(s[i] == '-'){
            sign = -1;
        }else{
            sign = 1;
        }
        i++;
    }

    while(s[i] >= '0' && s[i] <= '9'){
        int digit = s[i] - '0';

        if(result > (INT_MAX - digit) / 10){
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = (result * 10) + digit;
        i++;
    }

    return (int)(result * sign);
}