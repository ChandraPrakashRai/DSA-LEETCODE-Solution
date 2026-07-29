class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int , int>mp;
        int n = arr.size();
    
    for(int i = 0 ; i<n ; i++)
    {
        int diff = target - arr[i];
        
        if(mp.find(diff)!=mp.end())
        {
            return { i , mp[diff] };
        }
        else
        mp[arr[i]] = i;
    }
    
    return {};
    }
};