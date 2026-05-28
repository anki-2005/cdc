class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return arr[a] < arr[b]; });

        for (int i : idx) {
            for (int x = 1; x <= d && i + x < n; x++) {
                if (arr[i + x] >= arr[i]) break;
                dp[i] = max(dp[i], dp[i + x] + 1);
            }
            for (int x = 1; x <= d && i - x >= 0; x++) {
                if (arr[i - x] >= arr[i]) break;
                dp[i] = max(dp[i], dp[i - x] + 1);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};