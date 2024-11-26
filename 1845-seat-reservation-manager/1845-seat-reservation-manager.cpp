class SeatManager {
    int SIZE_;
    int curr;
    set<int> st;
public:
    SeatManager(int n) : SIZE_(n) {
        curr = 1;
        for (int i=1; i<=n; i++)
            st.insert(i);
    }
    
    int reserve() {
        int res = *st.begin();
        st.erase(res);
        return res;
        // int res = -1;
        // if (st.empty()) {
        //     res = curr;
        //     curr++;
        // }
        // else {
        //     res = *st.begin();
        //     st.erase(res);
        // }
        // std::cout << "reserve " << curr << " curr ";
        // for(auto v : st) {
        //     cout << v << ", ";
        // }
        // cout << endl;
        // return res;
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
        // st.insert(seatNumber);
        // std::cout << "unreserve " << curr << " curr ";
        // for(auto v : st) {
        //     cout << v << ", ";
        // }
        // cout << endl;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */