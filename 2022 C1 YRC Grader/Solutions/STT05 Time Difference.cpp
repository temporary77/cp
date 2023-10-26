#include <bits/stdc++.h>
using namespace std;

struct tme {
    int hour, minute, second;
    tme(): hour(0), minute(0), second(0) {}
    tme(int h, int m, int s): hour(h), minute(m), second(s) {}
    tme timeUntil(const tme &rhs) const {
        tme ans = tme();
        int borrow = 0;
        ans.second = rhs.second - second;
        if(ans.second < 0){
            ans.second += 60;
            borrow = 1;
        } else {
            borrow = 0;
        }
        ans.minute = rhs.minute - minute - borrow;
        if(ans.minute < 0){
            ans.minute += 60;
            borrow = 1;
        } else {
            borrow = 0;
        }
        ans.hour = rhs.hour - hour - borrow;
        return ans;
    }
};

int main(){

    tme a, b;
    scanf("%d%d%d", &a.hour, &a.minute, &a.second);
    scanf("%d%d%d", &b.hour, &b.minute, &b.second);
    tme dif = a.timeUntil(b);
    printf("%d:%d:%d - %d:%d:%d = ", a.hour, a.minute, a.second, b.hour, b.minute, b.second);
    printf("%d:%d:%d", dif.hour, dif.minute, dif.second);

    return 0;
}
