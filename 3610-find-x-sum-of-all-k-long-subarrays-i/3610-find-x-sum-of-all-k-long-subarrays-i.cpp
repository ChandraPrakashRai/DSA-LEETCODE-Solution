class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        long long windowSum = 0;
        unordered_map<int,int> cnt;
        multiset<pair<int,int>> top; // (freq, value) for top x
        multiset<pair<int,int>> bot; // rest

        auto update = [&](int num, int delta) {
            int old = cnt[num];
            if (old > 0) {
                // remove old entry from one of the sets
                auto it_bot = bot.find({old, num});
                if (it_bot != bot.end()) {
                    bot.erase(it_bot);
                } else {
                    auto it_top = top.find({old, num});
                    top.erase(it_top);
                    windowSum -= (long long)num * old;
                }
            }
            int now = old + delta;
            if (now > 0) {
                cnt[num] = now;
                bot.insert({now, num});
            } else {
                cnt.erase(num);
            }
        };

        for (int i = 0; i < n; i++) {
            update(nums[i], +1);
            if (i >= k) {
                update(nums[i - k], -1);
            }

            // ensure top has x elements if possible
            while (!bot.empty() && (int)top.size() < x) {
                auto it = prev(bot.end());
                auto p = *it;
                bot.erase(it);
                top.insert(p);
                windowSum += (long long)p.second * p.first;
            }

            // ensure correctness: swap if bot has better candidate
            while (!bot.empty() && !top.empty() && *prev(bot.end()) > *top.begin()) {
                auto pb = *prev(bot.end());
                auto pt = *top.begin();
                bot.erase(prev(bot.end()));
                top.erase(top.begin());
                // move pt → bot, pb → top
                bot.insert(pt);
                top.insert(pb);
                windowSum += (long long)pb.second * pb.first;
                windowSum -= (long long)pt.second * pt.first;
            }

            if (i >= k - 1) {
                ans.push_back((int)windowSum);
            }
        }

        return ans;
    }
};
