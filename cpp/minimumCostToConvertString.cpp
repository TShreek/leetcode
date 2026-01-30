class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

    // declare variables for reuse
     const long long INF = 1e18;
     int n = 26;

    // declare a vector of vector of long longs to store large numbers, initialize n vectors storing value = infinity
     vector<vector<long long>> dist(n, vector<long long>(n,INF));   

    // set dist = 0 for each node to itself
    for(int i =0; i<n;i++){
        dist[i][i]=0;
    }

    // set initial weights for all oriignal to changed for cost price
    for(int i=0; i < original.size(); i++){
        int u = original[i] - 'a';
        int v = changed[i] - 'a';
        dist[u][v] = min(dist[u][v], (long long)cost[i]);
    }

    // Floydd-warshall algorithm - takes O(n^3) time
    for(int i =0;i < n;i++){
        for(int j=0; j< n; j++){
            for(int k = 0;k < n;k++){
                if(dist[k][j] > dist[k][i] + dist[i][j]){
                    dist[k][j] = dist[k][i] + dist[i][j];
                }
            }
        }
    }
    long long ans = 0;

    // calculate answer
    
    for(int i = 0; i< source.size(); i++){
        int u = source[i] - 'a';
        int v = target[i] - 'a';
        if(dist[u][v] == INF){
            return -1;
        }
        else{
            ans += dist[u][v];
        }
    }

    return ans;
    
    }
};
