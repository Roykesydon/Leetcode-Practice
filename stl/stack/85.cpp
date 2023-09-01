#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> continuousOneAbove;
    int maximalRectangle(vector<vector<char>>& matrix) {
        int answer = 0;

        continuousOneAbove.resize(matrix.size());
        for (int i = 0; i < matrix.size(); i++)
            continuousOneAbove[i].resize(matrix[0].size(), 0);
            
        for (int i = 0; i < continuousOneAbove.size(); i++)
            for (int j = 0; j < continuousOneAbove[0].size(); j++)
                if (matrix[i][j] == '1')
                    continuousOneAbove[i][j] =
                        (i != 0) ? continuousOneAbove[i - 1][j] + 1 : 1;

        for (int i = 0; i < continuousOneAbove.size(); i++) {
            stack<pair<int, int>> histogram;  // pair <height, index>
            for (int j = 0; j < continuousOneAbove[i].size(); j++) {
                if (histogram.empty() ||
                    histogram.top().first < continuousOneAbove[i][j]) {
                    histogram.push({continuousOneAbove[i][j], j});
                    continue;
                }

                int leftIndex = -1;
                while (!histogram.empty() &&
                       histogram.top().first >= continuousOneAbove[i][j]) {
                    int endPosition = j - 1;
                    answer = max(
                        answer, histogram.top().first *
                                    (endPosition - histogram.top().second + 1));
                    leftIndex = histogram.top().second;
                    histogram.pop();
                }

                histogram.push({continuousOneAbove[i][j], leftIndex});
            }

            // calculate the remained histogram in stack
            if (!histogram.empty()) {
                int endPosition = continuousOneAbove[i].size() - 1;
                while (!histogram.empty()) {
                    answer = max(
                        answer, histogram.top().first *
                                    (endPosition - histogram.top().second + 1));
                    histogram.pop();
                }
            }
        }

        return answer;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> input;
    input.resize(n);
    for (int i = 0; i < n; i++) input[i].resize(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> input[i][j];

    cout << Solution().maximalRectangle(input) << '\n';
}