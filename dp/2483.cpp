#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> prefixY;

    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalY = 0;
        pair<int, int> ans;
        prefixY.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if (customers[i - 1] == 'Y') {
                prefixY[i] = 1;
                totalY++;
            }

            prefixY[i] += prefixY[i - 1];
        }

        // close at 0th hour
        ans = make_pair(0, totalY);

        for (int i = 1; i <= n; i++) {
            // if close at here
            int suffixY = totalY - prefixY[i];
            int prefixN = i - prefixY[i];
            if (prefixN + suffixY < ans.second) {
                ans = make_pair(i, prefixN + suffixY);
            }
        }

        return ans.first;
    }
};