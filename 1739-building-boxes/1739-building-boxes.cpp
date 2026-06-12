class Solution {
public:
    int minimumBoxes(int n) {

        long long k = 0;

        // Find largest complete pyramid
        while ((k + 1) * (k + 2) * (k + 3) / 6 <= n) {
            k++;
        }

        long long used = k * (k + 1) * (k + 2) / 6;

        long long ans = k * (k + 1) / 2;

        long long rem = n - used;

        long long x = 0;

        while (x * (x + 1) / 2 < rem) {
            x++;
        }

        return ans + x;
    }
};