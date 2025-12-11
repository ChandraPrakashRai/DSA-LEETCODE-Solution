class Solution {
public:
    // Signature matches callers that pass (n, buildings)
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> row; // row_y -> list of x's
        unordered_map<int, vector<int>> col; // col_x -> list of y's

        for (auto &b : buildings) {
            int x = b[0], y = b[1];
            row[y].push_back(x);
            col[x].push_back(y);
        }

        for (auto &p : row) sort(p.second.begin(), p.second.end());
        for (auto &p : col) sort(p.second.begin(), p.second.end());

        int covered = 0;
        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            auto &rx = row[y];
            auto itRow = lower_bound(rx.begin(), rx.end(), x);
            bool hasLeft  = (itRow != rx.begin());
            bool hasRight = (itRow + 1 != rx.end());
            if (!hasLeft || !hasRight) continue;

            auto &cy = col[x];
            auto itCol = lower_bound(cy.begin(), cy.end(), y);
            bool hasDown = (itCol != cy.begin());
            bool hasUp   = (itCol + 1 != cy.end());
            if (!hasDown || !hasUp) continue;

            covered++;
        }
        return covered;
    }
};