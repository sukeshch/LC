class Solution {
public:
    typedef int Course;
    typedef vector<int> Prereq;

    bool isCycleDFS(map<Course, Prereq> &cp, vector<bool> &visited, vector<bool> &checked, int current)
    {
        if(checked[current]) return false;
        if(visited[current]) return true;
        visited[current] = true;
        bool ret = false;
        for(int i=0; i<cp[current].size(); i++)
        {
            ret = isCycleDFS(cp, visited, checked, cp[current][i]);
            if(ret) break;
        }
        visited[current] = false;
        checked[current] = true;
        return ret;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<Course, Prereq> cp;
        for(auto p: prerequisites)
        {
            cp[p[0]].push_back(p[1]);
        }
        vector<bool> visited(numCourses), checked(numCourses);
        for(auto v : cp)
        {
            if(isCycleDFS(cp, visited, checked, v.first))
                return false;
        }
        return true; 
    }
};