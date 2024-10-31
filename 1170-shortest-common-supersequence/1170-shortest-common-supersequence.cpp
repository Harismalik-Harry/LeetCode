class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int i = m, j = n;
        string lcs;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                lcs.push_back(str1[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        reverse(lcs.begin(), lcs.end());

        string scs;
        i = 0, j = 0;
        for (auto &ch : lcs) {
            while (i < m && str1[i] != ch) {
                scs.push_back(str1[i++]);
            }
            while (j < n && str2[j] != ch) {
                scs.push_back(str2[j++]);
            }
            scs.push_back(ch);
            i++;
            j++;
        }

        while (i < m) {
            scs.push_back(str1[i++]);
        }
        while (j < n) {
            scs.push_back(str2[j++]);
        }

        return scs;
    }
};