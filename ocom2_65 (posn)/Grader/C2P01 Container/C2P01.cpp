#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    multiset<int> mltst;
    for (int i = 0; i < str.size(); ++i) {
        int c = int(str[i]-'A');
        auto it = mltst.upper_bound(c-1);
        if (it == mltst.end()) {
            mltst.insert(c);
            continue;
        }
        mltst.erase(it);
        mltst.insert(c);
    }
    printf("%lu",mltst.size());
}