class Solution {
public:
    
    struct Query{
        int qIdx;
        int qVal;
    };
    
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        map<int, vector<Query>> newQs;
        
        vector<int> ans(queries.size(), -1);
        
        for (int idx = 0; idx<queries.size(); idx++) {
            int a = queries[idx][0];
            int b = queries[idx][1];
            
            if (a > b) swap(a,b);
            
            if (heights[a] < heights[b] || a == b) {
                ans[idx] = b;
            }
            else {
                newQs[b].push_back({idx, heights[a]});
            }
        }
        
        // {ht, idx}
        vector<pair<int,int>> st;
        
        int idx = heights.size()-1;
        
        st.push_back({heights.back(), idx});
        idx--;
        
        while(idx >= 0) {
            if(newQs.count(idx)) {
                // address ans at that index
                for (auto [qidx, qval] : newQs[idx]) {
                    // for (auto itr = st.rbegin(); itr != st.rend(); itr++) {
                    //     if (qval < itr->first) {
                    //         ans[qidx] = itr->second;
                    //         break;
                    //     }
                    // }
                    ans[qidx] = search(qval, st);
                }
            }
            
            // monotonic stack
            while (!st.empty() && heights[idx] >= st.back().first) {
                st.pop_back();
            }
            st.push_back({heights[idx], idx});
            
            idx--;
        }
        
        return ans;
    }
    
    int search(int height, vector<pair<int,int>> &monoStack) {
        int left = 0;
        int right = monoStack.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (monoStack[mid].first > height) {
                ans = max(ans, mid);
                left = mid + 1;
            } else
                right = mid - 1;
        }
        if (ans != -1) {
            ans = monoStack[ans].second;
        }
        return ans;
    }
};