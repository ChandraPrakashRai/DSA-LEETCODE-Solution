class Solution {
public:
    static const long long MOD = 1000000007LL;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int pref_min = complexity[0];
        for (int i = 1; i < n; ++i) {
            if (pref_min >= complexity[i]) return 0;
            pref_min = min(pref_min, complexity[i]);
        }
        long long ans = 1;
        for (int x = 2; x < n; ++x) ans = (ans * x) % MOD;
        return (int)ans;
    }
};
