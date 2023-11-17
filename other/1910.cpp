#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
   public:
    string removeOccurrences(string s, string part) {
        string tmp = s;
        int tmpPtr = 0;
        int m = part.size();

        for (int i = 0; i < s.size(); i++) {
            tmp[tmpPtr++] = s[i];
            if (tmpPtr >= m && tmp.substr(tmpPtr - m, m) == part) tmpPtr -= m;
        }

        return tmp.substr(0, tmpPtr);
    }
};