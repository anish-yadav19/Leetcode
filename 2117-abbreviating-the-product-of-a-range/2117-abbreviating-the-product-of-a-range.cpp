class Solution {
public:
    string abbreviateProduct(int left, int right) {

        long double logSum = 0;

        long long cnt2 = 0, cnt5 = 0;

        long long suffix = 1;

        const long long MOD = 100000;

        for (int x = left; x <= right; x++) {

            logSum += log10((long double)x);

            int t = x;

            while (t % 2 == 0) {
                cnt2++;
                t /= 2;
            }

            while (t % 5 == 0) {
                cnt5++;
                t /= 5;
            }

            suffix = (suffix * t) % MOD;
        }

        long long zeros = min(cnt2, cnt5);

        cnt2 -= zeros;
        cnt5 -= zeros;

        while (cnt2--)
            suffix = (suffix * 2) % MOD;

        while (cnt5--)
            suffix = (suffix * 5) % MOD;

        long double frac = logSum - floor(logSum);

        long long prefix =
            (long long)(pow(10.0L, frac + 4));

        string suf = to_string(suffix);

        while (suf.size() < 5)
            suf = "0" + suf;

        long long digits =
            (long long)floor(logSum) + 1 - zeros;

        if (digits <= 10) {

            long double prod = 1;

            for (int i = left; i <= right; i++) {
                prod *= i;

                while ((long long)prod % 10 == 0)
                    prod /= 10;

                while (prod > 1e12)
                    prod /= 10;
            }

            string s =
                to_string((long long)prod);

            return s + "e" + to_string(zeros);
        }

        return to_string(prefix) +
               "..." +
               suf +
               "e" +
               to_string(zeros);
    }
};