class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_set<int>st;

    vector<int>arr;
        for(int i =0 ; i<n1 ; i++)
        {
            for(int j =0 ; j<n2 ; j++)
            {
                if(nums1[i]==nums2[j])
                {
                    if(!st.count(nums1[i]))
                    {
                    arr.push_back(nums1[i]);
                    st.insert(nums1[i]);
                    }
                    
                }
            }
        }
       return arr;
    }
};