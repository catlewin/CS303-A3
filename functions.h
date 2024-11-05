#include <vector>
using namespace std;

template<class T>
int mod_linear_search(const vector<T>& items, const T& target, int pos_last) { //Last occurrence of target
    if (pos_last == -1)
        return -1;
    if (target == items[pos_last])
        return pos_last;
    else
        return mod_linear_search(items, target, pos_last - 1);
};
