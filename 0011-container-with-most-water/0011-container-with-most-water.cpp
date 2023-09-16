class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int start = 0, end = N-1;
        int ans = 0;
        while(start < end) {
            ans = max(ans, 
                     (end-start) * min(height[start], height[end])
                     );
            
            if(height[start] > height[end]) {
                end--;
            } else start++;
            
        }
        return ans;
    }
};