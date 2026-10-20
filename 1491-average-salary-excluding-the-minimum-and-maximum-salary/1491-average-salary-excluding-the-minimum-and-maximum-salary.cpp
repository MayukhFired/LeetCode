#define Max(a , b) ((a) > (b) ? (a) : (b))
#define Min(a , b) ((a) < (b) ? (a) : (b))

class Solution {
public:
    double average(vector<int>& salary) {
        // FIXED: Swap the initial values so they can be correctly overridden
        long long minimum = INT_MAX; 
        long long maximum = INT_MIN;
        long long sum = 0;

        for(int i = 0; i < salary.size(); i++){
            maximum = Max(maximum , salary[i]);
            minimum = Min(minimum , salary[i]);
            sum += salary[i];
        }

        // Subtract the min and max from total sum, then divide by the remaining count
        return (double)(sum - maximum - minimum) / (salary.size() - 2);
    }
};
