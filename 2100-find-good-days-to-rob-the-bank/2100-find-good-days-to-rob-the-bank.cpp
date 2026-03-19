class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> left(n, 0), right(n, 0);
        
        // Step 1: non-increasing before i
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i-1])
                left[i] = left[i-1] + 1;
        }
        
        // Step 2: non-decreasing after i
        for (int i = n-2; i >= 0; i--) {
            if (security[i] <= security[i+1])
                right[i] = right[i+1] + 1;
        }
        
        // Step 3: find good days
        vector<int> ans;
        for (int i = time; i < n - time; i++) {
            if (left[i] >= time && right[i] >= time)
                ans.push_back(i);
        }
        
        return ans;
    }
};