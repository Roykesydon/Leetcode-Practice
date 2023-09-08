#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> requiredStepToSame;

    int minDistance(string word1, string word2) {
        requiredStepToSame.resize(word1.size() + 1);
        for (int i = 0; i <= word1.size(); i++)
            requiredStepToSame[i].resize(word2.size() + 1);

        for (int i = 0; i <= word1.size(); i++) requiredStepToSame[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) requiredStepToSame[0][j] = j;

        for (int i = 1; i <= word1.size(); i++)
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1])
                    requiredStepToSame[i][j] = requiredStepToSame[i - 1][j - 1];
                else if (word1[i - 1] != word2[j - 1])
                    requiredStepToSame[i][j] =
                        min(requiredStepToSame[i - 1][j - 1],
                            min(requiredStepToSame[i - 1][j],
                                requiredStepToSame[i][j - 1])) +
                        1;
            }

        return requiredStepToSame[word1.size()][word2.size()];
    }
};