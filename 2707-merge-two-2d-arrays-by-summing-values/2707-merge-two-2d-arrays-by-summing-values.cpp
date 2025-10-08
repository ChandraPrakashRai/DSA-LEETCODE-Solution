class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int,int>mp;

        for(int i = 0 ; i< n ; i++)
        {
            int id1  = nums1[i][0];
            int val1  = nums1[i][1];

            mp[id1]+=val1;
        }
        for(int i = 0 ; i< m ; i++)
        {
            int id2  = nums2[i][0];
            int val2  = nums2[i][1];
            mp[id2]+=val2;
        }

    vector<vector<int>>ans;
        for(auto &it: mp)
        {
            ans.push_back({it.first, it.second});
        }

        sort(ans.begin() , ans.end());

        return ans;

       
    }
};