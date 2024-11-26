class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, e = arr.size()-1;
        
        while(l <= e) {
            int mid = (l+e)/2;
            cout << "mid " << mid << endl;
            
            bool lcomp = (arr[mid-1] < arr[mid]);
            bool rcomp = (arr[mid] < arr[mid+1]);
            
            if(lcomp && !rcomp) return mid;
            
            if(!lcomp) e = mid;
            
            if(rcomp) l = mid + 1;
        }
        cout << l << "::" << e << endl;
        return l;
    }
};