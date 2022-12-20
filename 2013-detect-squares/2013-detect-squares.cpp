class DetectSquares {
public:
    DetectSquares() {
        points_on_x_ = vector<map<pair<int,int>, int>>(1005);
    }
    
    void add(vector<int> point) {
        points_on_x_[point[0]][{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int result = 0;
        int x = point[0];
        // cout << "point " << point[0] << "," << point[1] << endl;
        for(auto p : points_on_x_[x] ) {
            if(p.first.first == point[0] && p.first.second == point[1]) continue;
            result += p.second * checkSquare(point, {p.first.first, p.first.second});
            // cout << points_on_x_[x].size() << " loop result " << result << endl;
        }
        // cout << "count result " << result << endl;
        return result;
    }
private:
    int checkSquare(vector<int> a, vector<int> b)
    {
        int diff = a[1] - b[1];
        int newx = a[0] + diff;
        int res = 0;
        if( newx <= 1000 && newx >=0 &&  
            !points_on_x_[newx].empty() && 
            points_on_x_[newx].count({newx, a[1]}) != 0 && 
            points_on_x_[newx].count({newx, b[1]}) != 0) {
            res += points_on_x_[newx][{newx, a[1]}] * points_on_x_[newx][{newx, b[1]}];
        }
        newx = a[0] - diff;
        if( newx <= 1000 && newx >=0 && 
            !points_on_x_[newx].empty() && 
            points_on_x_[newx].count({newx, a[1]}) != 0 && 
            points_on_x_[newx].count({newx, b[1]}) != 0) {
            res += points_on_x_[newx][{newx, a[1]}] * points_on_x_[newx][{newx, b[1]}];
        }
        return res;
    }
    vector<map<pair<int,int>, int>> points_on_x_;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */