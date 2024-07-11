class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> num;
        while(n != 0) {
            num.push_back(n % 10);
            n = n / 10;
        }
        vector<int> next(num.size(), -1);
        std::reverse(num.begin(), num.end());
        
        int left = -1;
        int i = 1;
        while(i < num.size()) {
            if(num[i-1] < num[i]) {
                left = i-1;
            }
            i++;
        }
        // right most non (-1)
        if(left == -1) return -1;
        int right = left+1;
        int ct = left + 1;
        while(right < num.size() && num[left] < num[right]) {
            ct = right;
            right++;
        }
        std::cout << "l;r" << left << ":" << ct << endl;
        std::swap(num[left], num[ct]);
        std::reverse(num.begin() + left + 1, num.end());
        for(auto v : num) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
        long long val = 0;
        for(auto v : num) {
            val = 10 * val + v;
        }
        
        return val > INT_MAX ? -1 : val;
    }
};