#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<vector<int>> edge;
    vector<int> indegree;
    queue<int> bfsQueue;
    vector<int> topoSort;

   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses, vector<int>());
        indegree.resize(numCourses, 0);

        for (vector<int> prerequisite : prerequisites) {
            edge[prerequisite[1]].push_back(prerequisite[0]);
            indegree[prerequisite[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0) bfsQueue.push(i);

        while (!bfsQueue.empty()) {
            int courseIndex = bfsQueue.front();
            bfsQueue.pop();
            for(int i : edge[courseIndex]){
                indegree[i]--;
                if(indegree[i]==0){
                    bfsQueue.push(i);
                }
            }
            topoSort.push_back(courseIndex);
        }
        
        return topoSort.size() == numCourses;
    }
};