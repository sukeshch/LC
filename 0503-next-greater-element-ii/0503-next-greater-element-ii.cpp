class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int sz = nums.size();
        vector<int> result(sz, -1);
        
        // find max index 
        auto it = std::max_element(nums.begin(), nums.end());

        int index = std::distance(nums.begin(), it);
        // std::cout << "max_index : " << index << " " << *it << endl;
        
        stack<int> st;
        st.push((index+1)%sz);
        for(int i=((index+2)%sz), count = 0; count < sz; count++, i = (i+1)%sz) {
            while(!st.empty() && 
                  nums[st.top()] < nums[i]) {
                result[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        
        
        return result;
    }
};