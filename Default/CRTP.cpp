// g++ -std=c++23 main.cpp && ./a.out
// g++ -std=c++17 main.cpp && ./a.out
// https://coliru.stacked-crooked.com/a/2e8deb0a7fb17798
// This file can be also found using the Coliru command line: cat /Archive2/2e/8deb0a7fb17798/main.cpp
// https://www.modernescpp.com/index.php/c23-syntactic-sugar-with-deducing-this/

#include <iostream>

template <typename Derived>
struct CrtpUnified
{
#if defined(__cpp_deducing_this) && __cpp_deducing_this >= 202110L
    void whoami(this auto&& self) {
        self.print();
    }
#else
    void whoami() {
        static_cast<Derived*>(this)->print();
    }
#endif

protected:
    CrtpUnified() = default;
};


struct D1 : public CrtpUnified<D1> {
    void print() {
        std::puts("This is D1..");
    }
};

struct D2 : public CrtpUnified<D2> {
    void print() {
        std::puts("This is D2..");
    }
};

int main() {
    D1 d1; d1.whoami();
    D2 d2; d2.whoami();
}
