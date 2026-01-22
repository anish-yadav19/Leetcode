/*
    Company Tags                : Amazon, Microsoft
*/

//Approach-2 (Using BFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> result;
        
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void bfs(vector<vector<int>>& land, int i, int j, int& r2, int& c2) {
        queue<pair<int, int>> que;
        que.push({i, j});
        
        while(!que.empty()) {
            
            pair<int, int> p = que.front();
            que.pop();
            
            r2 = max(r2, p.first);
            c2 = max(c2, p.second);
            
            for(auto &dir : directions) {
                int i_ = p.first  + dir[0];
                int j_ = p.second + dir[1];
                
                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && land[i_][j_] == 1) {
                    land[i_][j_] = 0; //visited
                    que.push({i_, j_});
                }
            }
            
        }
        
        
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(land[i][j] == 1) {
                    int r1 = i;
                    int c1 = j;
                    int r2 = -1;
                    int c2 = -1;
                    
                    bfs(land, i, j, r2, c2);
                    result.push_back({r1, c1, r2, c2});
                }
                
            }
        }
        
        return result;
    }
};
