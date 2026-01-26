class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp;  
        // col -> row -> values

        queue<pair<TreeNode*, pair<int,int>>> q;  
        // node -> {row, col}

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto [node, rc] = q.front();
            q.pop();

            int row = rc.first;
            int col = rc.second;

            mp[col][row].push_back(node->val);

            if (node->left)
                q.push({node->left, {row + 1, col - 1}});

            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }

        vector<vector<int>> ans;

        for (auto &c : mp) {
            vector<int> temp;

            for (auto &r : c.second) {
                sort(r.second.begin(), r.second.end());  // IMPORTANT
                temp.insert(temp.end(), r.second.begin(), r.second.end());
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
