#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> pow;

    int dfs(int n, int k, bool reverse = false, bool inverse = false) {
        if (n == 1) return int(inverse);

        int length = pow[n] - 1;
        int ans;
        int index = k;

        if (reverse) index = length - k - 1;

        // right
        if (index > length / 2)
            ans = dfs(n - 1, index - length / 2 - 1, true, true);

        // left
        else if (index < length / 2)
            ans = dfs(n - 1, index);

        // middle
        else if (index == length / 2)
            ans = 1;

        if (inverse) ans ^= 1;

        return ans;
    }

   public:
    char findKthBit(int n, int k) {
        k--;
        pow.resize(21);

        int x = 1;
        for (int i = 0; i < pow.size(); i++) {
            pow[i] = x;
            x *= 2;
        }

        return '0' + dfs(n, k);
    }
};