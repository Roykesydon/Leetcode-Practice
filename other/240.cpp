#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    int n, m;

    bool isInMatrix(pair<int, int> pos) {
        return (pos.first >= 0 && pos.second >= 0 && pos.first < n &&
                pos.second < m);
    }

   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        n = matrix.size();
        m = matrix[0].size();

        pair<int, int> pos = make_pair(0, m - 1);

        while (isInMatrix(pos)) {
            int currentValue = matrix[pos.first][pos.second];
            if(currentValue == target)
                return true;

            if(currentValue>target)
                pos.second -= 1;

            if(currentValue<target)
                pos.first += 1;
        }

        return false;
    }
};