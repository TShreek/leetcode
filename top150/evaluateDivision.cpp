class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string start, string end, unordered_set<string>& visited){
        if(graph.find(start) == graph.end()) return -1.0;
        if(start == end) return 1.0;

        visited.insert(start);

        for(auto& neighbour : graph[start]){
            string next = neighbour.first;
            double weight = neighbour.second;

            if(visited.count(next)) continue;

            double result = dfs(next, end, visited);
            if(result != -1.0) return result * weight;
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            graph[a].push_back({b , val});
            graph[b].push_back({ a , 1.0/val});
        }

        vector<double> result;
        for(auto& query : queries){
            string start = query[0];
            string end = query[1];

            unordered_set<string> visited;
            double val = dfs(start,end,visited);
            result.push_back(val);
        }
        return result;
    }
};
