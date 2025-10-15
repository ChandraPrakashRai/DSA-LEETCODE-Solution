class Solution {
public:
    string defangIPaddr(string address) {
        int s = address.size();
        string str = "";
        for(int i = 0 ; i<s ; i++)
        {
            if(address[i]=='.')
            {
                    str= str+ "[.]";
            }
            else
            str = str + address[i];
        }
        return str;
    }
};