class Solution {
public:
    vector<vector<int>> adj_;
    vector<bool> visited_;
    
    void bfs(int node) {
        queue<int> q;
        
        q.push(node);
        visited_[node] = true;
        
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            for(auto c : adj_[top]) {
                if(!visited_[c]) {
                    visited_[c] = true;
                    q.push(c);
                }
            }
        }
    }
    
    void dfs(int node) {
        stack<int> st;
        
        st.push(node);
        visited_[node] = true;
        
        while(!st.empty()) {
            auto top = st.top();
            st.pop();
            for(auto c : adj_[top]) {
                if(!visited_[c]) {
                    visited_[c] = true;
                    st.push(c);
                }
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        adj_ = vector<vector<int>>(n, vector<int>());
        visited_ = vector<bool>(n);
        
        for(auto edge : edges) {
            adj_[edge[0]].push_back(edge[1]);
            adj_[edge[1]].push_back(edge[0]);
        }
        
        int components = 0;
        for(int i=0; i<n; i++) {
            if(!visited_[i]) {
                dfs(i);
                components++;
            }
        }
        return components; 
    }
};