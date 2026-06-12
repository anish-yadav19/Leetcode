class Solution {
public:
    unordered_map<int,int> mp;
    int sz;

    Solution(int n, vector<int>& blacklist) {

        sz = n - blacklist.size();

        unordered_set<int> black(
            blacklist.begin(),
            blacklist.end()
        );

        int last = n - 1;

        for(int b : blacklist) {

            if(b >= sz)
                continue;

            while(black.count(last))
                last--;

            mp[b] = last;
            last--;
        }
    }

    int pick() {

        int x = rand() % sz;

        if(mp.count(x))
            return mp[x];

        return x;
    }
};