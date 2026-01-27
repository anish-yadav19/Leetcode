class Solution {
public:
    void findBridge(int src, int parent, int&timer, vector<int>&tin, vector<int>&low, unordered_map<int,bool>&visited,unordered_map<int, list<int>>&adj,vector<vector<int>>&ans)
    {
            visited[src] = true;
            tin[src] =low[src] = timer; 
            
            timer++;
            
            for(auto nbr: adj[src])
            {
                if(nbr == parent)
                {
                    continue;;
                }
                if(!visited[nbr])
                {
                    findBridge(nbr,src,timer,tin,low,visited,adj,ans);

                    // low update
                    low[src] = min(low[src], low[nbr]);
                    // check for bridge
                    if(low[nbr]>tin[src])
                    {
                        
                        ans.push_back({nbr,src});
                    }
                }
                else
                {
                    // node is visited and not a parent
                    // low update
                    low[src] = min(low[src], low[nbr]);
                }
            }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        unordered_map<int, list<int>>adj;
        for(int i = 0;i<connections.size();i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
            vector<vector<int>>ans;
            unordered_map<int,bool>visited;
            int timer = 1;
            vector<int>tin(n);
            vector<int>low(n);
            findBridge(0,-1,timer,tin,low,visited,adj,ans);
            return ans;
    }
};