class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>mp;
        // store all the elements with their indices

        for(int i = 0 ; i<nums.size() ; i++)
        {
            mp[nums[i]] = i;
        }

        // second pass : check for complement

        for(int i = 0 ; i<nums.size() ; i++)
        {
            int need = target - nums[i];
            if(mp.find(need)!=mp.end() && mp[need]!=i)
            {
                return {i , mp[need]};
            }
        }

       return {};
    }
};