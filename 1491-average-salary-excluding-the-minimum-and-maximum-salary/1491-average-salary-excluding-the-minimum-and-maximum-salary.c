#define Max(a , b) ((a) > (b) ? (a) : (b))
#define Min(a , b) ((a) < (b) ? (a) : (b))
double average(int* salary, int salarySize) {
    long long maximum = INT_MIN;
    long long minimum = INT_MAX;
    long long sum = 0;

    for(int i = 0; i < salarySize; i++){
        maximum = Max(maximum , salary[i]);
        minimum = Min(minimum , salary[i]);
        sum += salary[i];
    }

    return (double)(sum - maximum - minimum) / (salarySize - 2);
}