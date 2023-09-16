class Solution {
public:
    int maxArea(vector<int>& height) {
        int N = height.size();
        int start = 0, end = N-1;
        int ans = 0;
        while(start < end) {
            
            if(height[start] > height[end]) {
                ans = max(ans, 
                     (end-start) * height[end]
                     );
                end--;
            } else {
                ans = max(ans, 
                     (end-start) * height[start]
                     );
                start++;
            }
        }
        return ans;
    }
};