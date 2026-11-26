class Solution {
public:
    bool canAliceWin(int n) {
    // 1--------------------------------------------1
        // int k = (21 - sqrt(441 - 8 * n)) / 2;
        // return k % 2 == 1;
    // 1--------------------------------------------1
        int take = 10, k = 0;
        while (n >= take) {
            n -= take;
            take--;
            k++;
        }
        return k % 2 == 1;
    }
};