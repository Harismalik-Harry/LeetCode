class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); ++i) {
            int root = sqrt(nums[i]);
            
            if (root * root == nums[i] && numMap.find(root) != numMap.end()) {
                numMap[nums[i]] = numMap[root] + 1;
            } else {
                numMap[nums[i]] = 1;
            }
        }

        int maxi = 0;

        for (auto it = numMap.begin(); it != numMap.end(); ++it) {
            if (maxi < it->second) {
                maxi = it->second;
            }
        }

        return maxi >= 2 ? maxi : -1;
    }
};
