class Solution {
public:
    void DFS(vector<vector<int>>& isConnected, vector<bool>&visited)
    {
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), 0);
        int provinces = 0;
        for(int i=0; i<isConnected.size(); i++) {
            if(!visited[i]) {
                queue<int> st;
                st.push(i);
                visited[i] = true;
                while(!st.empty()) {
                    for(int sz = st.size(); sz>0; sz--) {
                        int top = st.front();
                        st.pop();
                        for(int k=0; k<isConnected.size(); k++) {
                            if(isConnected[top][k] && !visited[k]) {
                                visited[k] = true;
                                st.push(k);
                            }
                        }
                    }
                }
                provinces++;
            }
        }
        return provinces;
    }
};