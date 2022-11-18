class Solution {
public:
    template<class T>
    void printArr(vector<T> arr)
    {
        for(auto v : arr)
            cout << v << " ";
        cout << endl;
    }
    void rotate(vector<int>& nums, int k) {
        int count = 0, n = nums.size();
        k = k % n; // avoid multi rotations
        int current = 0;
        while(count < n) {
            int prev = nums[current], next = 0, ct = 0;
            while((current + ct * k + k)%n != current) {
                int temp = nums[(current + ct * k + k)%n];                    
                nums[(current + ct * k + k)%n] = prev;
                prev = temp;
                ct++;
                count++;
            }
            nums[current] = prev;
            count++;
            current++;
        }
        // for(int i=0; i<n-k; i+=2)
        //     swap(nums[i/2], nums[n-1-k-i/2]);
        // // printArr(nums);
        // for(int start = n-k, i=0; i+start<n; i+=2)
        //     swap(nums[start + i/2], nums[n-1-i/2]);
        // // printArr(nums);
        // reverse(nums.begin(), nums.end());
    }
};