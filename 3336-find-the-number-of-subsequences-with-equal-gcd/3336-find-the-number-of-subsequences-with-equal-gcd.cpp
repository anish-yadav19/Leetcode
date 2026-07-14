/*
//Approach-1 (Recursion + Memoization)
//T.C : O(n * M * M), M = max element 
//S.C : O(n * M * M), M = max element
class Solution {
    int MOD = 1e9 + 7;
    int t[201][201][201];
public:
    int solve(vector<int> &nums,int i, int first, int second){
        if (i == nums.size()) {
            bool bothNonEmpty = (first != 0 && second != 0);
            bool gcdsMatch    = (first == second);
            return (bothNonEmpty && gcdsMatch) ? 1 : 0;
        }
        
        if(t[i][first][second] != -1) 
            return t[i][first][second];
        
        // Skip this index entirely
        int skip = solve(nums, i + 1, first, second);

        // Include this index in seq1
        int take1 = solve(nums, i + 1, __gcd(first, nums[i]), second);

        // Include this index in seq2
        int take2 = solve(nums, i + 1, first, __gcd(second, nums[i]));
        
        // Summing up all the possibilites
        return t[i][first][second] = (0LL + skip + take1 + take2) % MOD;
    }
    
    int subsequencePairCount(vector<int>& nums) {
        memset(t, -1, sizeof(t));
        return solve(nums, 0, 0, 0);
    }
};

*/

//Approach-2 (Bottom Up)
//T.C : O(n * M * M), M = max element 
//S.C : O(n * M * M), M = max element
class Solution {
    int MOD = 1e9 + 7;
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        int maxEl = -1;
        for (int x : nums) 
            maxEl = max(maxEl, x);
        
        int dp[n+1][maxEl+1][maxEl+1];

        // Base case
        for (int first = 0; first <= maxEl; first++) {
            for (int second = 0; second <= maxEl; second++) {
                bool bothNonEmpty = (first != 0 && second != 0);
                bool gcdsMatch    = (first == second);
                dp[n][first][second] = (bothNonEmpty && gcdsMatch) ? 1 : 0;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int first = maxEl; first >= 0; first--) {
                for (int second = maxEl; second >= 0; second--) {

                    // Skip this index entirely
                    int skip  = dp[i + 1][first][second]; //solve(i+1, first, second);

                    // Include this index in seq1
                    int take1 = dp[i + 1][__gcd(first, nums[i])][second]; 

                    // Include this index in seq2
                    int take2 = dp[i + 1][first][__gcd(second, nums[i])];

                    dp[i][first][second] = (0LL + skip + take1 + take2) % MOD;
                }
            }
        }
 
        return dp[0][0][0]; //return solve(nums, 0, 0, 0);
    }
};

