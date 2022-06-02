#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
   public:

    pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    pair<int, int> endPoint;

    int totalSquareNeedWalk = 0;
    int rows;
    int cols;

    bool inGrid(int i, int j) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) return true;
        return false;
    }

    ll dfs(int x, int y, int step, vector<vector<int>>& grid) {
        if (x == endPoint.first && y == endPoint.second) {
            if (step == totalSquareNeedWalk)
                return 1;
            else
                return 0;
        }

        ll uniquePath = 0;

        grid[x][y] = -1;
        for (int i = 0; i < 4; i++) {
            int newPositionX = x + dir[i].first;
            int newPositionY = y + dir[i].second;

            if (inGrid(newPositionX, newPositionY) &&
                grid[newPositionX][newPositionY] != -1)
                uniquePath += dfs(newPositionX, newPositionY, step + 1, grid);
        }
        grid[x][y] = 0;

        return uniquePath;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();


        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != -1) totalSquareNeedWalk++;
                if (grid[i][j] == 2) endPoint = {i, j};
            }

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (grid[i][j] == 1) return dfs(i, j, 1, grid);

        return -1;
    }
};

int main() {
    vector<vector<int>> grid;
    int n, m;
    cin >> n >> m;

    grid.resize(n);
    for (int i = 0; i < n; i++) grid[i].resize(m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> grid[i][j];

    cout << Solution().uniquePathsIII(grid) << '\n';
}