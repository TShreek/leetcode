class Solution {
public:
    unordered_map<int,vector<int>> graph;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i =0;i<prerequisites.size();i++){
            int course = prerequisites[i][0];
            int prere = prerequisites[i][1];

            graph[prere].push_back(course);
        }

        int i = 0;
        vector<int> result;
        vector<int> visited(numCourses,0);
        result.reserve(numCourses);

        for(int i =0;i<numCourses;i++){
            if(hasCycle(i, visited,result)) return {};
        }
        reverse(result.begin(),result.end());
        return result;
    }

    bool hasCycle(int course, vector<int>& visited, vector<int>& res){
        if(visited[course] == 1) return true;
        if(visited[course] == 2) return false;

        visited[course] = 1;

        for(auto& neighbour : graph[course]){
            bool cyc = hasCycle(neighbour,visited,res);
            if(cyc) return true;
        }

        res.push_back(course);
        visited[course] = 2;

        return false;
    }
};
