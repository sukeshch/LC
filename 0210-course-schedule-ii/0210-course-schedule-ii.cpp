class Solution {
public:
    typedef int Course;
    typedef vector<int> Prereqs;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        unordered_map<Course, Prereqs> cp;
        vector<int> indegree(numCourses);
        for(auto cpq : prerequisites)
        {
            cp[cpq[1]].push_back(cpq[0]);
            indegree[cpq[0]] ++;
        }
        vector<int> order;
        queue<int> q;
        vector<int> result;
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i); // result.push_back(i);
        }
        int count = 0;
        while(!q.empty())
        {
            for(int i=0, sz = q.size(); i<sz; i++)
            {
                int t = q.front();
                q.pop();
                result.push_back(t);
                for(auto c : cp[t])
                {
                    indegree[c]--;
                    count++;
                    if(indegree[c] == 0)
                        q.push(c); // result.push_back(c);
                }
            }
        }
        if(count == prerequisites.size())
        {
            return result;
        }
        return {};
    }
};