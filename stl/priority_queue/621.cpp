#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   private:
    priority_queue<pair<int, char>> pq;
    unordered_map<char, int> count;

   public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<pair<int, char>> tmp;
        int cycleCount = 0;
        int completeCircle = 0;

        for (char task : tasks) count[task]++;

        for (auto i : count) pq.push({i.second, i.first});

        while (!pq.empty()) {
            auto u = pq.top();
            pq.pop();
            cycleCount++;
            u.first--;
            if (u.first != 0) tmp.push_back(u);

            if (cycleCount == n + 1 || (pq.empty() && tmp.size())) {
                completeCircle++;
                cycleCount = 0;
                for (auto i : tmp) pq.push(i);
                tmp.clear();
            }
        }

        return completeCircle * (n + 1) + cycleCount;
    }
};