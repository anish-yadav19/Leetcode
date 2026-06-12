class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {

        int n = arr.size();
        int g = gcd(n, k);

        long long ans = 0;

        for (int start = 0; start < g; start++) {

            vector<int> cycle;

            int idx = start;

            do {
                cycle.push_back(arr[idx]);
                idx = (idx + k) % n;
            } while (idx != start);

            sort(cycle.begin(), cycle.end());

            long long median = cycle[cycle.size() / 2];

            for (long long x : cycle)
                ans += llabs(x - median);
        }

        return ans;
    }
};