#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ComparatorTest
{
public:
  int val;
  string str;
  ComparatorTest (int v, string s):val (v), str (s) {}

  bool operator< (const ComparatorTest & p) const
  {
    if (val != p.val) return val < p.val;
    return str < p.str;
  }
  bool operator> (const ComparatorTest & p) const
  {
    if (val != p.val) return val > p.val;
    return str > p.str;
  }
  bool operator==(const ComparatorTest & p) const
  {
    return p.val == val && p.str == str;
  }
};

void print (priority_queue < ComparatorTest, vector < ComparatorTest >,
       std::greater < ComparatorTest >> q)
{
  auto copyq = q;
  cout << "printing Q: \n";
  while (!copyq.empty ())
    {
      cout << copyq.top ().val << " " << copyq.top ().str << "\n";
      copyq.pop ();
    }
  cout << "end printing\n";
}

/*
template <typename T, typename Comparator>
void printPriorityQueueGeneric(std::priority_queue<T, std::vector<T>, Comparator> &q) {
    auto pq = q;
    while (!pq.empty()) {
        std::cout << pq.top().val << " " << pq.top().str << "\n";
        pq.pop();
    }
    std::cout << std::endl;
}
*/

void print (priority_queue < ComparatorTest > q)
{
  auto copyq = q;
  cout << "printing Q: \n";
  while (!copyq.empty ())
    {
      cout << copyq.top ().val << " " << copyq.top ().str << "\n";
      copyq.pop ();
    }
  cout << "end printing\n";
}

int main ()
{
  {
    // priority_queue Comparator using class operator
    // std::less<ComparatorTest> is default; 
    priority_queue < ComparatorTest, vector < ComparatorTest >,
      std::greater < ComparatorTest > >pq;
    pq.push (ComparatorTest (1, "a"));
    print (pq);
    pq.push (ComparatorTest (1, "b"));
    print (pq);
    pq.push (ComparatorTest (2, "b"));
    print (pq);
    pq.push (ComparatorTest (2, "a"));
    print (pq);
  }
//   {
//     // priority_queue Comparator using inline comparator 
//     auto sortRuleLambda = [] (ComparatorTest const& s1, ComparatorTest const& s2) { // calls lhs.operator<(rhs); 
//                                 return s1 < s2; };
//     priority_queue < ComparatorTest, vector<ComparatorTest>, decltype( sortRuleLambda )> pq;
//     pq.push (ComparatorTest (1, "a"));
//     print (pq);
//     pq.push (ComparatorTest (1, "b"));
//     print (pq);
//     pq.push (ComparatorTest (2, "b"));
//     print (pq);
//     pq.push (ComparatorTest (2, "a"));
//     print (pq);
//   }


  return 0;
}
