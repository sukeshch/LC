class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        
        for(auto nums : nums) {
            vector<int> temp;
            while(nums != 0) {
                temp.push_back(nums % 10);
                nums /= 10;
            }
            for(int i = temp.size()-1; i>=0; i--) {
                result.push_back(temp[i]);
            }
        }
        // std::reverse(result.begin(), result.end());
        return result;
    }
};