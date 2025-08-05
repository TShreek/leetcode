class Solution {
public:
    unordered_map<int,vector<int>> graph;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.reserve(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int course = prerequisites[i][0];
            int prere = prerequisites[i][1];
            //if(graph[prere].find(course) != graph.end()) return false;
            graph[prere].push_back(course);
        }
        vector<int> visited(numCourses,0);
        for(int i=0; i < numCourses; i++){
            if(hasCycle(visited,i)){
                return false;
            }
        }
        return true;
    }
    bool hasCycle(vector<int>& visited,int course){
        if(visited[course] == 2) return false;
        if(visited[course] == 1) return true;

        visited[course] = 1;
        for(auto& neighbour : graph[course]){
            if(hasCycle(visited,neighbour)){
                return true;
            }
        }
        visited[course] = 2;
        return false;
    }
};
