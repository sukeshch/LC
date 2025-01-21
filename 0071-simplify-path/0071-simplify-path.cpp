class Solution {
public:
    string simplifyPath(string path) {
        deque<string> dq;
        // dq.push_front("/");
        int index = 0;
        while (index < path.size()) {
            if (path[index] == '/') {
                index++;
                continue;
            }
            string temp = "";
            while (index < path.size() && path[index] != '/') {
                temp += path[index];
                index++;
            }

            if (temp == "..") {
                if(!dq.empty())
                    dq.pop_back();
            } else if (temp != ".") {
                dq.push_back(temp);
            }
        }
        string result = "";
        while (!dq.empty()) {
            if(dq.front() != "/") {
                result += "/";
                result += dq.front();
            }
            dq.pop_front();
        }
        if(result.empty())
            result = "/";
        return result;
    }
};