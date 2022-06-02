#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    bool isInGrid(int i, int j, int rows, int cols) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) return true;
        return false;
    }

   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = -1;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (obstacleGrid[i][j] == -1) continue;
                if (i == 0 && j == 0) {
                    obstacleGrid[i][j] = 1;
                    continue;
                }

                long long uniquePathInThisGrid = 0;
                if (isInGrid(i - 1, j, rows, cols) &&
                    obstacleGrid[i - 1][j] != -1)
                    uniquePathInThisGrid += obstacleGrid[i - 1][j];
                if (isInGrid(i, j - 1, rows, cols) &&
                    obstacleGrid[i][j - 1] != -1)
                    uniquePathInThisGrid += obstacleGrid[i][j - 1];

                if (uniquePathInThisGrid >= INT32_MAX)
                    obstacleGrid[i][j] = -1;
                else if (uniquePathInThisGrid < INT32_MAX)
                    obstacleGrid[i][j] = int(uniquePathInThisGrid);
            }
        }

        return (obstacleGrid[rows - 1][cols - 1] != -1)
                   ? obstacleGrid[rows - 1][cols - 1]
                   : 0;
    }
};