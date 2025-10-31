class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
                unordered_map<int,int>mp;
        vector<int>ans;

        for(int num: nums)
        {
            mp[num]++;
        }

        // iterate over in map
        for(auto &it: mp)
        {
            if(it.second==1)
            ans.push_back(it.first);
        }

        return ans;

    }
};