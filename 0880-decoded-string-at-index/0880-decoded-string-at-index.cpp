class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0;

        // Find decoded length
        for (char ch : s) {
            if (isdigit(ch))
                size *= (ch - '0');
            else
                size++;
        }

        // Reverse traversal
        for (int i = s.size() - 1; i >= 0; i--) {
            k %= size;

            if (k == 0 && isalpha(s[i]))
                return string(1, s[i]);

            if (isdigit(s[i]))
                size /= (s[i] - '0');
            else
                size--;
        }

        return "";
    }
};