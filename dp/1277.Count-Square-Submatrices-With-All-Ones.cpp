#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
   public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (i && j && matrix[i][j])
                    matrix[i][j] +=
                        min(matrix[i - 1][j],
                            min(matrix[i][j - 1], matrix[i - 1][j - 1]));
                ans += matrix[i][j];
            }

        return ans;
    }
};