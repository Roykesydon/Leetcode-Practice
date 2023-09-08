#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    void dfs(int depth, vector<int>& currentBoard, int& boardSize,
             vector<vector<string>>& ans) {
        if (depth == boardSize) {
            vector<string> oneAns;
            string tmp;
            for (int i = 0; i < currentBoard.size(); i++) {
                tmp = "";

                for (int j = 0; j < currentBoard[i]; j++) tmp += ".";
                tmp += "Q";
                for (int j = currentBoard[i] + 1; j < boardSize; j++)
                    tmp += ".";

                oneAns.push_back(tmp);
            }

            ans.push_back(oneAns);

            return;
        }

        for (int i = 0; i < boardSize; i++) {
            // check validation
            bool flag = true;
            for (int j = 0; j < depth; j++) {
                if (currentBoard[j] == i ||
                    abs(j - depth) == abs(i - currentBoard[j])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                currentBoard.push_back(i);
                dfs(depth + 1, currentBoard, boardSize, ans);
                currentBoard.pop_back();
            }
        }
    }

   public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> currentBoard;

        ans.clear();

        dfs(0, currentBoard, n, ans);

        return ans;
    }
};