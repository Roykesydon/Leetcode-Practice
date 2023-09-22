#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
   private:
    stringstream ss;

   public:
    string reverseWords(string s) {
        vector<string> ans;
        ss.str("");
        ss.clear();
        ss << s;
        while (ss >> s) ans.push_back(s);
        s = "";
        for (int i = ans.size() - 1; i >= 0; i--) {
            s += ((i == ans.size() - 1) ? "" : " ");
            s += ans[i];
        }

        return s;
    }
};