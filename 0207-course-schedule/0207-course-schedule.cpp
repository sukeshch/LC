class Solution {
public:
    int N;
    vector<vector<int>> adj_;
    vector<int> indeg_;
    
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        N = numCourses;
        adj_ = vector<vector<int>>(N, vector<int>());
        indeg_ = vector<int>(N, 0);
        
        for(auto pre : prereq) {
            // prereq --> course
            adj_[pre[1]].push_back(pre[0]);
            // indeg[course] + 1
            indeg_[pre[0]]++;
        }
        
        vector<bool> visited(N, false);
        int reachable_nodes = 0;
        
        queue<int> q; // zero indegree nodes
        
        for(int i=0; i<N; i++) {
            if(indeg_[i] == 0) {
                if (adj_[i].size() == 0)
                    reachable_nodes++;
                else {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
        
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            reachable_nodes++;
            for(auto n : adj_[top]) {
                indeg_[n]--;
                if(!visited[n] && indeg_[n] == 0) {
                    visited[n] = 1;
                    q.push(n);
                }
            }
        }
        
        return reachable_nodes == N;
    }
};