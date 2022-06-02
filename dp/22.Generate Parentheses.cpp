#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    void dfs(string currentString, int openParenthesisCount,
             int closeParenthesisCount, int n,
             vector<string> &parenthesisPermutation) {
        if (openParenthesisCount + closeParenthesisCount == n * 2) {
            parenthesisPermutation.push_back(currentString);
            return;
        }

        if (openParenthesisCount < n) {
            dfs(currentString + "(", openParenthesisCount + 1,
                closeParenthesisCount, n, parenthesisPermutation);
        }
        if (closeParenthesisCount < openParenthesisCount) {
            dfs(currentString + ")", openParenthesisCount,
                closeParenthesisCount + 1, n, parenthesisPermutation);
        }
    }

   public:
    vector<string> generateParenthesis(int n) {
        vector<string> parenthesisPermutation;
        int openParenthesisCount = 0;
        int totalParenthesisCount = 0;

        dfs("", 0, 0, n, parenthesisPermutation);

        return parenthesisPermutation;
    }
};

int main() {
    int n;

    cin >> n;
    // Solution().generateParenthesis(n);
    for(auto i:Solution().generateParenthesis(n)){
        cout<<i<<'\n';
    }
}