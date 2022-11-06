class Solution {
public:
    long long sums[4];
    long side_length;
    
    bool dfs(vector<int>& ms, int index)
    {
        if(index == ms.size()) 
            return sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == sums[3];
        for(int i=0; i<4; i++)
        {
            if(sums[i] + ms[index] > side_length) continue;
            sums[i] += ms[index];
            if(dfs(ms, index+1))
                return true;
            sums[i] -= ms[index];
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        long long sum = 0;
        if(matchsticks.size() < 4) return false;
        for(auto ms: matchsticks)
            sum+=ms;
        if(sum % 4 != 0) return false;
        side_length = sum/4;
        std::sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());
        return dfs(matchsticks, 0);
    }
};