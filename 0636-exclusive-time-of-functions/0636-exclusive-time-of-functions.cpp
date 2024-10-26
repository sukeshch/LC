class Solution {
public:
    tuple<int, string, int> parse(string log, string delimiter) {
        std::vector<std::string> res;
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        
        while ((pos_end = log.find(delimiter, pos_start)) != std::string::npos) {
            std::string token = log.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(log.substr(pos_start));
        
        return {stoi(res[0]), res[1], stoi(res[2])};
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        
        // {f : timestamp}
        stack<tuple<int, int, int>> st;
        
        for (auto log : logs) {
            auto [f, action, ts] = parse(log, ":");
            if (action == "end") {
                auto [f1, ts1, s] = st.top(); 
                // cout << (ts - ts1 + 1) << " :: sum :- " << sum << endl;
                result[f1] += (ts - ts1 + 1) - s;
                st.pop();
                if (!st.empty()) {
                    auto [f2, ts2, s] = st.top();
                    st.pop();
                    st.push({f2, ts2, s + ((ts - ts1 + 1))});
                }
            } else {
                st.push({f, ts, 0});
            }
        }
        
        return result;
    }
};



/*
0 1 2 3 4 5  6  7 
s   s.    e s e e

*/