class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>arr(26,0);

        int n = sentence.size();

        for(int i =0 ; i< n ; i++)
        {
           arr[sentence[i]-'a'] = 1  ;
        }

        for(int i =0 ; i< arr.size() ; i++)
        {
            if(arr[i]==0)
            return false;
        }
        return true;
    }
};