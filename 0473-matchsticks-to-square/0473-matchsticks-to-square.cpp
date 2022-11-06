class Solution {
public:
    long long sums[4] = {0};
    long side_length;
    map<long, bool> cache;
    
    bool dfs(vector<int>& ms, int index, std::bitset<19> bb, int numsides)
    {   
        if(sums[numsides] == side_length) {
            bb[numsides + 16] = 1;
            return dfs(ms, index+1, bb, numsides+1);
        }
        if(numsides == 3) return true;
        
        if(cache.count((long)bb.to_ulong()) > 0)
            return cache[(long)bb.to_ulong()];
        
        bool ret = false;
        // for(int i=0; i<4; i++)
        for(int i=0; i<ms.size(); i++)
        {
            if(bb[i] == 0) // not taken
            {
                if(sums[numsides] + ms[i] > side_length) continue;
                sums[numsides] += ms[i];
                bb[i] = 1;
                ret |= dfs(ms, i+1, bb, numsides);
                bb[i] = 0;
                if(ret)
                    break;
                sums[numsides] -= ms[i];    
            }
        }
        cache[(long)bb.to_ulong()] = ret;
        return ret;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        long long sum = 0;
        if(matchsticks.size() < 4) return false;
        for(auto ms: matchsticks)
            sum+=ms;
        if(sum % 4 != 0) return false;
        side_length = sum/4;
        std::sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());
        std::bitset<19> bb{0};
        return dfs(matchsticks, 0, bb, 0);
    }
};