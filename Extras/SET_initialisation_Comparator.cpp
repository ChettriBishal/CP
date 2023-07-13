#include <iostream>
#include <set>
 
// Binary predicate
struct comp {
    template<typename T>
    bool operator()(const T &l, const T &r) const {
        return l > r;
    }
};
 
int main()
{
    // The elements are sorted according to the comparison object
    std::set<int, comp> ints = { 10, 20, 30 };
 
    for (auto i: ints) {
        std::cout << i << std::endl;
    }
 
    return 0;
}
