class Solution {
public:
    void BFS(vector<vector<int>>& isConnected, vector<bool> &visited, int i)
    {
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while(!q.empty()) {
            for(int sz = q.size(); sz>0; sz--) {
                int top = q.front();
                q.pop();
                for(int k=0; k<isConnected.size(); k++) {
                    if(isConnected[top][k] && !visited[k]) {
                        visited[k] = true;
                        q.push(k);
                    }
                }
            }
        }
    }
    
    void DFS(vector<vector<int>>& isConnected, vector<bool> &visited, int i){
        stack<int> st; 
        st.push(i);
        while(!st.empty()) {
            int top = st.top();
            st.pop();
            if(!visited[top]) {
                visited[top] = true;
            }
            for(int i=0; i<isConnected.size(); i++) {
                if((i != top) && isConnected[top][i] == 1 && !visited[i]) {
                    st.push(i);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), 0);
        int provinces = 0;
        for(int i=0; i<isConnected.size(); i++) {
            if(!visited[i]) {
                BFS(isConnected, visited, i);
                // DFS(isConnected, visited, i);
                provinces++;
            }
        }
        return provinces;
    }
};