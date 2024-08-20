#include <iostream>
#include <vector>
#include <map>

struct Pos {
    int row; 
    int col;
    
    friend std::ostream& operator<<(std::ostream& os, const Pos& pos) {
        os << "(" << pos.row << ", " << pos.col << ")" << std::endl;
        return os;
    }
    
    Pos operator+(const Pos& pos) {
        return {this->row + pos.row, this->col + pos.col};
    }
    
    bool operator==(const Pos& pos) {
        return (pos.row == row) && (pos.col == col);
    }
    
    bool operator<(const Pos& pos) const{
        return this->row < pos.row || this->col < pos.col;
    }
};

std::vector<Pos> dirs{{0,1},{0,-1},{1,0},{-1,0}};

std::map<Pos, bool> visited;

// void DFS(Pos pos) {
//     if(visited[pos]) {
//         return;
//     }
//     Pos curr = pos;
//     for(auto d : dirs) {
//         curr = pos + d;
//         if(!visited[curr]) {
//             DFS(pos+d);
//         }
//         else {
//         }
//     }
// }

int main() {
    
    // DFS({0,0});
    
    Pos pos{0,1}, pos1{1,0};
    visited.insert(std::make_pair(pos, true));
    if(pos == pos1) {
        std::cout << "equal\n";
    } else {
        std::cout << "not equal\n";
    }
    
    return 0;
}
