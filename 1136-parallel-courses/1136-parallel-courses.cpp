class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        unordered_map<int, vector<int>> cp;
        vector<int> ideg(n+1);
        for(auto r : relations)
        {
            cp[r[0]].push_back(r[1]);
            ideg[r[1]]++;
        }
        
        queue<int> q;
        for(int i=1; i<n; i++)
        {
            if(ideg[i] == 0)
                q.push(i);
        }
        int count = 0, depth = 0;
        while(!q.empty()) {
            for(int i=0, sz = q.size(); i<sz; i++) {
                int t = q.front();
                q.pop();
                for(auto c : cp[t])
                {
                    ideg[c]--;
                    count ++;
                    if(ideg[c] == 0)
                        q.push(c);
                }
            }
            depth++;
        }
        if(count == relations.size()) return depth;
        return -1;
    }
};