#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    int n;
    void solve(int index, long long l1, long long l2, vector<int>& tmp, vector<int>& ans,
               string& num) {
        if (index == n && tmp.size() >= 3) {
            ans = tmp;
            return;
        }

        long long numInt = 0;
        for (int i = index; i < n; i++) {
            numInt *= 10;
            numInt += num[i] - '0';
            if(numInt > INT32_MAX)
                break;

            tmp.push_back(numInt);
            if (l2 == -1) {
                if (l1 == -1) {
                    solve(i + 1, numInt, -1, tmp, ans, num);
                } else {
                    solve(i + 1, l1, numInt, tmp, ans, num);
                }
            } else {
                if (l1+l2 < INT32_MAX &&numInt == l1 + l2) {
                    solve(i + 1, l2, numInt, tmp, ans, num);
                }
            }
            tmp.pop_back();

            if ((i == index && num[i] == '0') || ans.size()) {
                break;
            }
        }
    }

   public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;
        vector<int> tmp;

        n = num.size();
        solve(0, -1, -1, tmp, ans, num);
        return ans;
    }
};