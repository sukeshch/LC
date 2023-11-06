class Solution {
public:
    bool winnerOfGame(string colors) {
        int acount = 0, bcount = 0;
        int index = 1;
        int cur_count = 1;
        while(index < colors.size()) {
            if(colors[index-1] == colors[index]) {
                cur_count++;
            } else {
                if(cur_count >= 3) {
                    if (colors[index-1] == 'A') {
                        acount += (cur_count - 2);
                    } else {
                        bcount += (cur_count - 2);
                    }
                }
                cur_count = 1;
            }
            index++;
        }
        if(cur_count >= 3) {
            if (colors[index-1] == 'A') {
                acount += (cur_count - 2);
            } else {
                bcount += (cur_count - 2);
            }
        }
        // cout << "acount : " << acount << " bcount : " << bcount << endl; 
        return (acount > bcount);
    }
};