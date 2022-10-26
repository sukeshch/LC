class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> innode(n);
        vector<vector<int>> children(n,vector<int>());
        // find leaf nodes
        for(auto e : edges)
        {
            innode[e[0]]++;
            innode[e[1]]++;
            children[e[0]].push_back(e[1]);
            children[e[1]].push_back(e[0]);
        }
        queue<int> q;
        for(int i=0; i<n; i++)
            if(innode[i] == 1) q.push(i);
        
        int nodesLeft = n;
        while(nodesLeft > 2)
        {
            nodesLeft -= q.size();
            for(int i = 0, sz = q.size(); i < sz; ++i)
            {
                int node = q.front();
                q.pop();
                for(auto v: children[node])
                {
                    innode[v]--;
                    if(innode[v] == 1)
                        q.push(v);
                }
            }
        }
        vector<int> result;
        while(!q.empty())
        {
            result.push_back(q.front()); 
            q.pop();
        }
        return result;
    }
};