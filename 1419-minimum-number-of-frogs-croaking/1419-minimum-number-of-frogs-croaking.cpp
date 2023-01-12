class Solution {
public:
    int minNumberOfFrogs(string input) {
        if(input.size() % 5 != 0)
            return -1;
        string sound = "croak";
        map<char, int> sound_map;
        for(int i=0; i<sound.size(); i++) 
            sound_map[sound[i]] = i;
        
        vector<stack<int>> vmp(5);
        int num_frogs = 0, max_frogs = 0, frog_ids = 0;
        
        for(auto c : input) {
            if(sound_map[c] == 0) {
                vmp[sound_map[c]].push(frog_ids);
                num_frogs++;
                frog_ids++;
                max_frogs = max(max_frogs, num_frogs);        
            }
            else if(sound_map[c] == (sound.size()-1))
            {
                if(vmp[sound_map[c]-1].empty()) return -1;
                vmp[sound_map[c]-1].pop();
                num_frogs--;
            } else {
                if(vmp[sound_map[c]-1].empty()) return -1;
                vmp[sound_map[c]].push(vmp[sound_map[c]-1].top());
                vmp[sound_map[c]-1].pop();
            }
        }
        for(auto ss : vmp)
            if(!ss.empty()) return -1;
        
        return max_frogs;
    }
};