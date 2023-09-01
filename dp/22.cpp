#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    void dfs(string currentString, int openParenthesesCount,
             int closeParenthesesCount, int n,
             vector<string> &parenthesesPermutation) {
        if (openParenthesesCount + closeParenthesesCount == n * 2) {
            parenthesesPermutation.push_back(currentString);
            return;
        }

        if (openParenthesesCount < n) {
            dfs(currentString + "(", openParenthesesCount + 1,
                closeParenthesesCount, n, parenthesesPermutation);
        }
        if (closeParenthesesCount < openParenthesesCount) {
            dfs(currentString + ")", openParenthesesCount,
                closeParenthesesCount + 1, n, parenthesesPermutation);
        }
    }

   public:
    vector<string> generateParentheses(int n) {
        vector<string> parenthesesPermutation;
        int openParenthesesCount = 0;
        int totalParenthesesCount = 0;

        dfs("", 0, 0, n, parenthesesPermutation);

        return parenthesesPermutation;
    }
};

int main() {
    int n;

    cin >> n;
    // Solution().generateParentheses(n);
    for(auto i:Solution().generateParentheses(n)){
        cout<<i<<'\n';
    }
}