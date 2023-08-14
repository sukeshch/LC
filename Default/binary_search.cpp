#include <iostream>
#include <vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1;
    if(nums[low] == target) return low;
    if(nums[high] == target) return high;
    
    while(low < high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        if(nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if(nums[low] == target) return low;
    return -1;
}

int main()  {
  vector<int> input = {-1,0,3,5,9,12};
  int target = 5;
  cout << "Index of target value " << target << " is " << search(input, target) << endl;
}
