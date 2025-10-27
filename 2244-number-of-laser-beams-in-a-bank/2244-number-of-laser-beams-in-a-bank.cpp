class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        //  no of floor nikal lo 
        int n = bank.size();

        int prevDevices = 0 ;
        int result = 0;

        for(int i = 0 ; i<n ; i++)
        {
            int currDevices = 0 ;

            for(char &ch : bank[i])
            {
        
                if(ch == '1')
                {
                    currDevices+=1;
                }
            }
            

            result+= (currDevices * prevDevices);

            if(currDevices!=0)
            {
                    prevDevices =  currDevices ;
            }
          
        }

        return result;
        
    }
};