#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<vector<int>> aboveOnes;
    stack<pair<int, int>> monotonicStack;

   public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        aboveOnes.resize(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') aboveOnes[i][j] = 1;
                if (i && aboveOnes[i][j]) aboveOnes[i][j] += aboveOnes[i - 1][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sameHeightIndex = j;
                while (!monotonicStack.empty() &&
                       monotonicStack.top().second > aboveOnes[i][j]) {
                    pair<int, int> stackTop = monotonicStack.top();
                    monotonicStack.pop();

                    ans = max(ans, (j - stackTop.first) * stackTop.second);
                    sameHeightIndex = stackTop.first;
                }

                if (monotonicStack.empty() && aboveOnes[i][j]) {
                    monotonicStack.push({sameHeightIndex, aboveOnes[i][j]});
                }

                if (!monotonicStack.empty() &&
                    monotonicStack.top().second < aboveOnes[i][j]) {
                    monotonicStack.push({sameHeightIndex, aboveOnes[i][j]});
                }
            }

            while (!monotonicStack.empty()) {
                pair<int, int> stackTop = monotonicStack.top();
                monotonicStack.pop();

                ans = max(ans, (m - stackTop.first) * stackTop.second);
            }
        }

        return ans;
    }
};