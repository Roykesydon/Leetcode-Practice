#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    class Node {
       public:
        Node* next[26];
        vector<string> suggests;

        Node() {
            for (int i = 0; i < 26; i++) next[i] = nullptr;
        }
    };

    void addProduct(Node* root, string productName) {
        Node* ptr = root;

        for (char ch : productName) {
            if (ptr->next[ch - 'a'] == nullptr)
                ptr->next[ch - 'a'] = new Node();

            ptr = ptr->next[ch - 'a'];

            if (ptr->suggests.size() < 3) {
                ptr->suggests.push_back(productName);
            }
        }
    }

    void dfs(vector<vector<string>>& ans, Node* curPtr, int index,
             string target) {
        if (index == target.size()) return;

        if (curPtr->next[target[index] - 'a'] == nullptr) {
            for (int i = index; i < target.size(); i++) ans[i] = {};
            return;
        } else {
            curPtr = curPtr->next[target[index] - 'a'];
            ans[index] = curPtr->suggests;
            dfs(ans, curPtr, index + 1, target);
        }
    }

   public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
        vector<vector<string>> ans;
        ans.resize(searchWord.size());

        // sort products
        sort(products.begin(), products.end());

        // build trie
        Node* root = new Node();

        for (string productName : products) addProduct(root, productName);

        // search reversed ans;
        dfs(ans, root, 0, searchWord);

        return ans;
    }
};