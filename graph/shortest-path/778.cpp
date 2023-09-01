#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   private:
    class Node {
       public:
        int x;
        int y;

        Node(int x_, int y_) {
            x = x_;
            y = y_;
        }
    };

    class DijkstraCompare {
       public:
        bool operator()(pair<int, Node> a, pair<int, Node> b) {
            return a.first > b.first;
        }
    };

    priority_queue<pair<int, Node>, vector<pair<int, Node>>, DijkstraCompare>
        pq;
    vector<vector<int>> dis;
    vector<vector<bool>> vis;

    bool isInGrid(int x, int y, int n) {
        if (x >= 0 && x < n && y >= 0 && y < n) return true;
        return false;
    }

   public:
    int swimInWater(vector<vector<int>>& grid) {
        int INF = 1e9;

        int n = grid.size();
        int dirX[] = {1, -1, 0, 0};
        int dirY[] = {0, 0, 1, -1};

        dis.resize(n, vector<int>(n, 1e9));
        vis.resize(n, vector<bool>(n, false));
        pq.push({0, Node(0, 0)});
        dis[0][0] = 0;

        while (!pq.empty()) {
            auto curNode = pq.top();
            pq.pop();
            int curX = curNode.second.x;
            int curY = curNode.second.y;

            if (vis[curX][curY]) continue;
            vis[curX][curY] = true;

            for (int i = 0; i < 4; i++) {
                int toX = curX + dirX[i];
                int toY = curY + dirY[i];

                // check in grid
                if (!isInGrid(toX, toY, n)) continue;

                if (dis[toX][toY] > max(dis[curX][curY], grid[curX][curY])) {
                    dis[toX][toY] = max(dis[curX][curY], grid[curX][curY]);
                    pq.push({dis[toX][toY], Node(toX, toY)});
                }
            }
        }

        return max(dis[n - 1][n - 1], grid[n - 1][n - 1]);
    }
};