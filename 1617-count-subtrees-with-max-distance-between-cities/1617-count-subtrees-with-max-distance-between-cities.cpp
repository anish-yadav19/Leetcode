class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(
        int n,
        vector<vector<int>>& edges) {

        vector<vector<int>> dist(
            n, vector<int>(n, 1e9));

        for(int i = 0; i < n; i++)
            dist[i][i] = 0;

        vector<vector<int>> g(n);

        for(auto &e : edges) {

            int u = e[0] - 1;
            int v = e[1] - 1;

            dist[u][v] = 1;
            dist[v][u] = 1;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    dist[i][j] =
                        min(dist[i][j],
                            dist[i][k] + dist[k][j]);

        vector<int> ans(n - 1);

        int totalMasks = 1 << n;

        for(int mask = 1; mask < totalMasks; mask++) {

            int nodes = __builtin_popcount(mask);

            if(nodes < 2)
                continue;

            int edgeCnt = 0;

            for(auto &e : edges) {

                int u = e[0] - 1;
                int v = e[1] - 1;

                if((mask & (1 << u)) &&
                   (mask & (1 << v)))
                    edgeCnt++;
            }

            if(edgeCnt != nodes - 1)
                continue;

            int diameter = 0;

            for(int i = 0; i < n; i++) {

                if(!(mask & (1 << i)))
                    continue;

                for(int j = i + 1; j < n; j++) {

                    if(!(mask & (1 << j)))
                        continue;

                    diameter =
                        max(diameter,
                            dist[i][j]);
                }
            }

            ans[diameter - 1]++;
        }

        return ans;
    }
};