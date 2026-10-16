#include <vector>
#include <unordered_map>

using namespace std;

class BIT {
public:
    int size;
    vector<long long> _tree1;
    vector<long long> _tree2;

    BIT(int n) {
        size = n;
        _tree1.assign(n + 2, 0);
        _tree2.assign(n + 2, 0);
    }

    int _lowbit(int index) {
        return index & -index;
    }

    // Public API handles 0-based to 1-based indexing conversion
    void add(int left, int right, int delta) {
        _add(left + 1, delta);
        _add(right + 2, -delta);
    }

    long long query(int left, int right) {
        return _query(right + 1) - _query(left);
    }

private:
    // Standard 1-based RURQ BIT Add
    void _add(int index, int delta) {
        long long val2 = (long long)index * delta;
        while (index <= size) {
            _tree1[index] += delta;
            _tree2[index] += val2; // CRITICAL FIX: Must multiply by the index
            index += _lowbit(index);
        }
    }

    // Standard 1-based RURQ BIT Query
    long long _query(int index) {
        long long res = 0;
        long long original_idx = index;
        while (index > 0) {
            res += (original_idx + 1) * _tree1[index] - _tree2[index];
            index -= _lowbit(index);
        }
        return res;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        long long curr = 0;
        BIT bit(n + 10);
        unordered_map<int, int> seen;
        long long mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            int a = nums[i];
            int j = (seen.count(a) ? seen[a] : -1) + 1;
            
            long long q = bit.query(j, i);
            
            // Contribution transition formula for squared distinct elements
            curr = (curr + q * 2 + (i - j + 1)) % mod;
            if (curr < 0) curr += mod; // Handle negative modulo safety
            
            res = (res + curr) % mod;
            
            bit.add(j, i, 1);
            seen[a] = i;
        }
        return res;
    }
};
