class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> result;
        result.push(asteroids[0]);
        int id = 1;
        while(id < asteroids.size()) {
            if(result.size() && 
               (result.top() > 0 && asteroids[id] < 0))
            {
                int current = asteroids[id];
                while(result.size() 
                      && (result.top() > 0 && current < 0) ) {
                    if(result.top() + current == 0) {
                        current = 0;
                        result.pop();
                    }
                    else {
                        current = abs(result.top()) > abs(current) ? result.top() : current;
                        result.pop();
                    }
                }
                if(current)
                    result.push(current);
            } else {
                result.push(asteroids[id]);
            }
            id++;
        }
        vector<int> r(result.size());
        id = result.size()-1;
        while(!result.empty()) {
            r[id] = result.top();
            result.pop();
            id--;
        }
        return r;
    }
};