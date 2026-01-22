/*
    Company Tags                : Amazon, Microsoft
*/

//Approach-3 (Brute Force Greedy)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        
        vector<vector<int>> result;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(land[i][j] == 0) continue;
                
                //find the right most column of the current group
                int c1 = j;
                while(c1 < n && land[i][c1] == 1) {
                    c1++;
                }
                
                //find the bottom most row of the current group
                int r1 = i;
                while(r1 < m && land[r1][j] == 1) {
                    r1++;
                }
                
                c1 = c1 == 0 ?  c1 : c1-1;
                r1 = r1 == 0 ?  r1 : r1-1;
                
                result.push_back({i, j, r1, c1});
                
                
                //mark all the inbetween 1s to 0s
                for(int k = i; k <= r1; k++) {
                    for(int l = j; l <= c1; l++) {
                        land[k][l] = 0; //visited
                    }
                }
                
                
            }
        }
        
        return result;
        
        
    }
};