class Solution {
public:
    void solve(vector<vector<int>>&result ,vector<int>arr , vector<int>&curr , int n , int k , int index)
    {
        if(curr.size()==k && n==0)
        {
            result.push_back(curr);
            return;
        }

        if(curr.size()>k || n<0)
        return;

        for(int i = index ; i<arr.size() ;i++ )
        {
            
                curr.push_back(arr[i]);
                solve(result , arr , curr , n-arr[i] ,k , i+1);
                curr.pop_back();
            
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr= {1,2,3,4,5,6,7,8,9}; 
         vector<int>curr ;
        vector<vector<int>>result ;

        solve(result , arr , curr , n , k , 0 );
        return result;
    }
};