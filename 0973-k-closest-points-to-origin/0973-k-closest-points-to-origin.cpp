class Solution {
public:
    std::pair<vector<int>,vector<int>> getsplit(
        vector<int> points,
        vector<int> &distances, 
        int targetdist) {
        vector<int> closest, farther;
        
        for(int i=0; i < points.size(); i++) {
            if(distances[points[i]] <= targetdist)
                closest.push_back(points[i]);
            else 
                farther.push_back(points[i]);
        }
        
        return {closest, farther};
    } 
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result;
        
        vector<int> distances(points.size(), 0);
        int low = INT_MAX, high = -1;
        vector<int> rem_points;
        
        for(int i=0; i<points.size(); i++) {
            rem_points.push_back(i);
            distances[i] = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            low = min(low, distances[i]);
            high = max(high, distances[i]);
        }
        
        // binary search 
        // butiful
        while(k) {
            int mid = (low + high) / 2;
            auto [cl, fr] = getsplit(rem_points, distances, mid);
            if (cl.size() > k) {
                rem_points = cl;
                high = mid;
            } else {
                k -= cl.size();
                
                for(auto r : cl) {
                    result.push_back(points[r]);
                }
                rem_points = fr;
                low = mid;
            }
        }
        
        return result;
    }
};