class Solution {
public:
 void solve(vector<int> &s , int start , vector<vector<int>> &v)
    {
        if(start == s.size()-1)
        {
            v.push_back(s);
            return ;
            
        }
        unordered_set<int>mp;
            
        
        for(int i = start ; i<s.size() ; i++)
        {
            
            if(mp.find(s[i])==mp.end())
            {
                mp.insert(s[i]);
                swap(s[i] , s[start]);
                
                solve(s , start+1 , v);
                
                swap(s[start] , s[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& s) {
        vector<vector<int>>v;
        solve(s , 0 , v);
        
        return v;
        
    }
};

