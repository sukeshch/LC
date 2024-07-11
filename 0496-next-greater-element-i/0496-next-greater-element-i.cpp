#define PRINT_VEC(vec) for(auto v : vec) std::cout << v << " "; 

class Solution {
public:
    template <typename T>
    void printvec(std::vector<T> t) {
        for(auto v : t) {
            std::cout << v << ", ";
        }
        std::cout << std::endl;
    }
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // find next greater per element
        vector<int> next2(nums2.size(), -1);
        stack<int> st;
        st.push( 0 ); /* push index */
        for(auto i = 1; i < nums2.size(); i++) {            
            while (!st.empty() && nums2[st.top()] < nums2[i] ) { 
                next2[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        /* val(1) --> index */
        unordered_map<int, int> mp;
        for(int i=0; i < nums2.size(); i++) {
            mp[nums2[i]] = next2[i];
        }
        
        std::vector<int> result(nums1.size(), -1);
        for(int i=0; i < nums1.size(); i++) {
            if (mp[nums1[i]] != -1) {
                result[i] = nums2[mp[nums1[i]]];
            }
        }
        
        return result;
    }
};