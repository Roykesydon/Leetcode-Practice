#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> father;
    map<string, int> belong;
    map<string, bool> vis;
    map<int, vector<string>> ownEmail;

    int find(int x) {
        if (father[x] == x) return x;
        return father[x] = find(father[x]);
    }

    void merge(int x, int y) { father[find(x)] = find(y); }

   public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<string>> ans;

        father.resize(n);
        for (int i = 0; i < n; i++) father[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (belong.count(email)) {
                    merge(i, belong[email]);
                } else {
                    belong[email] = i;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int father = find(i);
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (vis.count(email)) continue;
                vis[email] = true;

                ownEmail[father].push_back(email);
            }
        }

        for (auto ownerAndEmail : ownEmail) {
            int owner = ownerAndEmail.first;
            vector<string> emails = ownerAndEmail.second;
            vector<string> tmp;

            tmp.push_back(accounts[owner][0]);
            for (auto email : emails) tmp.push_back(email);

            sort(tmp.begin() + 1, tmp.end());

            ans.push_back(tmp);
        }

        return ans;
    }
};