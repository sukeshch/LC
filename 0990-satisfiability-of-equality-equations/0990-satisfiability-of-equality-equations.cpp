class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> map(26, -1);
        vector<set<char>> v;
        for(auto eq : equations) {
            if(eq[1] == '=') {
                char x = eq[0], y = eq[3];
                if(map[int(x-'a')] != -1 && map[int(y-'a')] != -1) {
                    if(map[int(x-'a')] == map[int(y-'a')]) continue;
                    v[map[int(x-'a')]].insert(
                        v[map[int(y-'a')]].begin(), 
                        v[map[int(y-'a')]].end()
                    );
                    for(auto c : v[map[int(y-'a')]]) {
                        map[int(c-'a')] = map[int(x-'a')];
                    }
                } else if (map[int(x-'a')] != -1 && map[int(y-'a')] == -1) {
                    v[map[int(x-'a')]].insert(y);
                    map[int(y-'a')] = map[int(x-'a')];
                } else if (map[int(x-'a')] == -1 && map[int(y-'a')] != -1) {
                    v[map[int(y-'a')]].insert(x);
                    map[int(x-'a')] = map[int(y-'a')];
                } else {
                    v.push_back({x,y});
                    map[int(x-'a')] = v.size()-1;
                    map[int(y-'a')] = v.size()-1;
                }
            } 
        }
        for(auto eq : equations) {
            if(eq[1] == '!') {
                char x = eq[0], y = eq[3];
                if(x == y || (map[int(x-'a')] != -1 && map[int(x-'a')] == map[int(y-'a')])) {
                    return false;
                }
            }
        }
        return true;
    }
};