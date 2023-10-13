#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool isValidSerialization(string preorder) {
        if(preorder == "#")
            return true;

        vector<string> nodes;
        int cnt = 0;

        preorder += ",";
        int l = 0;
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] == ',') {
                nodes.push_back(preorder.substr(l, i - l));
                l = i + 1;
            }
        }
        // nodes.push_back(preorder.substr(l, preorder.size() - l));
        // for(auto i:nodes)
        //     cout<<i<<"---\n";

        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == "#") {
                cnt--;
                if (cnt < 0) return false;
                if (cnt == 0) {
                    if (i == nodes.size() - 1) return true;
                    return false;
                }
            } else {
                if (!i)
                    cnt += 2;
                else
                    cnt++;
            }
        }

        return cnt == 0;
    }
};