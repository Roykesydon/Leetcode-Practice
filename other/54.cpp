#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int n, m;

    vector<vector<bool>> vis;

    bool dontNeedChangeDir(int x, int y, int dir) {
        int nextX = x + dx[dir];
        int nextY = y + dy[dir];

        return nextX >= 0 && nextX < n && nextY >= 0 && nextY < m &&
               !vis[nextX][nextY];
    }

   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int x, y;
        int dir = 0;

        vis.resize(n, vector<bool>(m, false));
        x = 0;
        y = 0;

        vector<int> ans;

        while (ans.size() != n * m) {
            ans.push_back(matrix[x][y]);

            vis[x][y] = 1;

            if (ans.size() == n * m) break;

            if (!dontNeedChangeDir(x, y, dir)) {
                dir = (dir + 1) % 4;
            }
            x += dx[dir];
            y += dy[dir];
        }

        return ans;
    }
};