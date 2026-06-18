class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }

    int maxNiceDivisors(int primeFactors) {
        if (primeFactors <= 3)
            return primeFactors;

        if (primeFactors % 3 == 0)
            return power(3, primeFactors / 3);

        if (primeFactors % 3 == 1)
            return (power(3, (primeFactors - 4) / 3) * 4) % MOD;

        return (power(3, primeFactors / 3) * 2) % MOD;
    }
};