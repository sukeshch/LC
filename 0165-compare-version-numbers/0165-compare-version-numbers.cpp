class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream v1(version1), v2(version2);
        string v1s, v2s; // split strings
        char del = '.';
        while(!v1.eof() && !v2.eof()) {
            getline(v1, v1s, del);
            getline(v2, v2s, del);
            if(stoi(v1s) > stoi(v2s)) {
                return 1;
            } else if (stoi(v1s) < stoi(v2s)) {
                return -1;
            }
            // continue if equal
        }
        
        while(!v1.eof()) {
            getline(v1, v1s, del);
            if(stoi(v1s) != 0) 
                return 1;
        }
        while(!v2.eof()) {
            getline(v2, v2s, del);
            if(stoi(v2s) != 0) 
                return -1;
        }
        return 0;
    }
};