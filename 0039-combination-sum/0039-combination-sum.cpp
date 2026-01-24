class Solution {
public:

    void solve(vector<int>& candidates, int target , vector<vector<int>>& result , vector<int>& curr , int index){
        if(target==0)
        {
            result.push_back(curr);
            return;
        }

        if(index<0)
        return;

        if(candidates[index]<=target)
        {
             curr.push_back(candidates[index]);
        solve(candidates , target-candidates[index] ,result , curr , index);
        curr.pop_back();
        }

        solve(candidates , target , result , curr , index-1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result ;
        vector<int>curr ;
        solve(candidates , target , result , curr ,candidates.size()-1 );

        return result;
        
    }
};