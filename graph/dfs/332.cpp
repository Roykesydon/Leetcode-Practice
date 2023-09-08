#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
   private:
    map<string, multiset<string>> edge;
    vector<string> ans;

    void dfs(string name) {
        while (edge[name].size()) {
            string toNode = *edge[name].begin();
            edge[name].erase(edge[name].begin());
            dfs(toNode);
        }

        ans.push_back(name);
    }

   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto i : tickets) {
            edge[i[0]].insert(i[1]);
        }
        dfs("JFK");

        reverse(ans.begin(), ans.end());
        return ans;
    }
};