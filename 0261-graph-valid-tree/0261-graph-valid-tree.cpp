class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() == 0) return n == 1;
        
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n, vector<int>());
        
        int visited_count = 0;
        for(auto e : edges) {
            indeg[e[0]]++;
            indeg[e[1]]++; 
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        stack<int> st;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++) {
            if(indeg[i] == 1) {
                visited[i] = true;
                st.push(i);
            } 
            if(indeg[i] == 0) // count vertices not in graph
                visited_count++;
        }
        if(visited_count > 0) return false; 
        
        {
            // checking for disconnected components
            int count = 0;
            vector<bool> v(n, false);
            // find first non-zero edge index
            int index = 0;
            while(index < n && indeg[index] == 0) index++;
            
            stack<int> stc;
            stc.push(index);
            v[index] = true;
            while(!stc.empty()) {
                auto top = stc.top();
                stc.pop();
                count++;
                for(int j = 0; j < adj[top].size(); j++) {
                    if(!v[adj[top][j]]) {
                        v[adj[top][j]] = true;
                        stc.push(adj[top][j]);
                    }
                }
            }
            
            if(count + visited_count != n) // disconnected componets detected
                return false;
        }
        
        bool progress = true;
        while(!st.empty() && progress) {
            progress = false;
            for(int i=0, sz=st.size(); i < sz; i++) {
                auto top = st.top();
                st.pop();
                progress = true;
                visited_count++;
                for(int j=0; j<adj[top].size(); j++) {
                    if( !visited[adj[top][j]] ) {
                        visited[adj[top][j]] = true;
                        indeg[adj[top][j]]--;
                        if(indeg[adj[top][j]] == 1) {
                            st.push(adj[top][j]);
                        }
                    }
                }
            }
        }
        if(visited_count >= n-1) return true;
        return false;
    }
};