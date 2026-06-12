class Solution {
public:
    int n;
    vector<vector<int>> adj;
    vector<vector<int>> dp;
    vector<int> nums;

    bool isSquare(int x) {
        int r = sqrt(x);
        return r * r == x;
    }

    int solve(int mask, int last) {

        if(mask == (1 << n) - 1)
            return 1;

        if(dp[mask][last] != -1)
            return dp[mask][last];

        int ans = 0;

        for(int nxt = 0; nxt < n; nxt++) {

            if(mask & (1 << nxt))
                continue;

            if(!adj[last][nxt])
                continue;

            if(nxt > 0 &&
               nums[nxt] == nums[nxt - 1] &&
               !(mask & (1 << (nxt - 1))))
                continue;

            ans += solve(mask | (1 << nxt), nxt);
        }

        return dp[mask][last] = ans;
    }

    int numSquarefulPerms(vector<int>& A) {

        nums = A;
        sort(nums.begin(), nums.end());

        n = nums.size();

        adj.assign(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && isSquare(nums[i] + nums[j]))
                    adj[i][j] = 1;
            }
        }

        dp.assign(1 << n, vector<int>(n, -1));

        int ans = 0;

        for(int i = 0; i < n; i++) {

            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            ans += solve(1 << i, i);
        }

        return ans;
    }
};