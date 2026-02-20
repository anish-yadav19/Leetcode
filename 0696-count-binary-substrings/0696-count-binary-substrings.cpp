class Solution {
public:
    int countBinarySubstrings(string s) 
    {
        int result = 0;
        int prevc = 0;
        int curc = 1;
        for(int i = 1;i<s.length();i++)
        {
            if(s[i]==s[i-1])
            {
                curc++;
            }
            else
            {
                result += min(curc,prevc);
                prevc= curc;
                curc = 1;
            }
        }
        return result + min(curc,prevc);
    }
};