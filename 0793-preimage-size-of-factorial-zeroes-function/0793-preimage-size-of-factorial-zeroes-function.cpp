class Solution {
public:

    long long trailingZeros(long long n) {

        long long ans = 0;

        while (n) {
            n /= 5;
            ans += n;
        }

        return ans;
    }

    int preimageSizeFZF(int k) {

        long long left = 0;
        long long right = 5LL * k + 5;

        while (left < right) {

            long long mid = left + (right - left) / 2;

            if (trailingZeros(mid) < k)
                left = mid + 1;
            else
                right = mid;
        }

        return trailingZeros(left) == k ? 5 : 0;
    }
};