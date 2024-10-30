class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        auto lis = [&](const vector<int>& arr) {
            vector<int> dp(arr.size(), 1);
            for (int i = 1; i < arr.size(); ++i) {
                for (int j = 0; j < i; ++j) {
                    if (arr[i] > arr[j]) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
            return dp;
        };

        vector<int> lis_lr = lis(nums);
        
        reverse(nums.begin(), nums.end());
        vector<int> lis_rl = lis(nums);
        reverse(lis_rl.begin(), lis_rl.end());
        
        int max_mountain_size = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (lis_lr[i] > 1 && lis_rl[i] > 1) {
                max_mountain_size = max(max_mountain_size, lis_lr[i] + lis_rl[i] - 1);
            }
        }
        
        return n - max_mountain_size;
    }
};
