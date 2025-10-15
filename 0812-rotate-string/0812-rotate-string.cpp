class Solution {
public:
    bool rotateString(string s, string goal) {
        int sz = s.size();
        int gz = goal.size();
        if(sz!=gz)  return false;

        for(int i = 0 ; i<sz ; i++)
        {
            // rotate
            rotate(s.begin() , s.begin()+1 , s.end());

            // check
            if(s==goal)
            return true;
        }

        return false;
    }
};