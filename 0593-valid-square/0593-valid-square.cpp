class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        bool maySq = false;
        if((p1[0] + p2[0] == p3[0] + p4[0]) && (p1[1] + p2[1] == p3[1] + p4[1])) {
            maySq = true;
        }
        if((p1[0] + p3[0] == p2[0] + p4[0]) && (p1[1] + p3[1] == p2[1] + p4[1])) {
            maySq = true;
            swap(p2, p3);
        }
        if((p1[0] + p4[0] == p2[0] + p3[0]) && (p1[1] + p4[1] == p2[1] + p3[1])) {
            maySq = true;
            swap(p2, p4);
        }
        if(!maySq || p1 == p2) return false;
        // p1 - p2 are diagonals
        // p3 - p4 are diagonals
        // take p1, p3 and find p2, p4

        vector<int> v3 = { p1[0] + (p3[1]-p1[1]), p1[1] + (p1[0]-p3[0])};
        vector<int> v4 = { p3[0] + (p3[1]-p1[1]), p3[1] + (p1[0]-p3[0])};
        if((v3 == p2 && v4 == p4) || (v3 == p4 && v4 == p2)) return true;
        
        v3 = { p1[0] - (p3[1]-p1[1]), p1[1] - (p1[0]-p3[0])};
        v4 = { p3[0] - (p3[1]-p1[1]), p3[1] - (p1[0]-p3[0])};
        if((v3 == p2 && v4 == p4) || (v3 == p4 && v4 == p2)) return true;
        return false;
    }
};