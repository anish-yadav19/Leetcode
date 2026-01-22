//Company Tags                : GOOGLE
   


//Approach-1 (Using Recursion - TLE for C++)
//T.C : In worst case, the function may recursively call itself twice for each character in the pattern (due to *), leading to an exponential number of recursive calls.
        //Hence, time complexity will be approaximately O(2^(max(n, m))). where n , m are lengths of s and p respectively.
//S.C : O(m) - Recursion stack space : where m = length of pattern (maximum depth of recursion tree)
        //NOTE : We are passing substr to isMatch every time and hence they are being copied to x and p so, we will be creating O(2^(max(n, m))) number of substrings.
//Approach-2 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int t[21][21];

    bool solve(int i, int j, string& text, string& pattern) {
        if (j == pattern.length())
            return i == text.length();
            
        if (t[i][j] != -1) {
            return t[i][j];
        }
        
        bool ans = false;

        bool first_match = (i < text.length() &&
                            (pattern[j] == text[i] || pattern[j] == '.'));

        if (j + 1 < pattern.length() && pattern[j + 1] == '*') {
            ans = (solve(i, j + 2, text, pattern) ||
                   (first_match && solve(i + 1, j, text, pattern)));
        } else {
            ans = first_match && solve(i + 1, j + 1, text, pattern);
        }

        return t[i][j] = ans;
    }
    
    bool isMatch(string text, string pattern) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, text, pattern);
    }
};
