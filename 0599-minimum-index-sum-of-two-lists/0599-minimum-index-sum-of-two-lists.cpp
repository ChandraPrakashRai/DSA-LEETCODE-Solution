class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        for(int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;          // store index of each item in list1
        }

        int best = INT_MAX;
        vector<string> ans;

        for(int j = 0; j < list2.size(); j++) {
            string s = list2[j];

            if(mp.count(s)) {          // common string found
                int total = j + mp[s]; // index sum

                if(total < best) {     // new minimum
                    best = total;
                    ans = {s};
                }
                else if(total == best) { // same minimum → push
                    ans.push_back(s);
                }
            }
        }

        return ans;
    }
};
