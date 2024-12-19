class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int curr_ptr = 0, visited_ptr = 0;
        
        vector<bool> visited(arr.size(), false);
        
        int max_chunks = 0;
        
        while(curr_ptr < arr.size()) {
            visited[arr[curr_ptr]] = true;
            
            while(visited_ptr < arr.size() && visited[visited_ptr]) {
                visited_ptr++;
            }
            
            if(visited_ptr > curr_ptr) {
                max_chunks++;
            }
            curr_ptr++;
        }
        
        return max_chunks;
    }
};