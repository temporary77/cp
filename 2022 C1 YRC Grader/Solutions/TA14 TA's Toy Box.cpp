#include <bits/stdc++.h>
using namespace std;

void printChar(int n, char c){
    for(int i = 1; i <= n; ++i){
        cout << c;
    }
}

const int N = 100;

int boxes[N + 5][N + 5], sum[N + 5], mx[N + 5], cnt[N + 5], idx[N + 5];
bool hasStarted[N + 5];

int main(){

    int col;
    scanf("%d", &col);
    int mxSum = 0;
    for(int c = 1; c <= col; ++c){
        int nBoxes;
        scanf("%d", &nBoxes);
        for(int i = nBoxes; i >= 1; --i){
            scanf("%d", &boxes[c][i]);
            mx[c] = max(mx[c], boxes[c][i]);
            sum[c] += boxes[c][i] + 2;
        }
        mxSum = max(mxSum, sum[c]);
    }

    for(int h = mxSum; h >= 1; --h){
        for(int c = 1; c <= col; ++c){
            if(!hasStarted[c] && h > sum[c]){
                printChar(2 * mx[c] + 3, ' ');
                continue;
            }
            if(h == sum[c]){
                hasStarted[c] = true;
                ++idx[c];
                sum[c] -= boxes[c][idx[c]] + 2;
                cnt[c] = 0;
            }
            int cur = boxes[c][idx[c]];
            int i = cur - h + sum[c] + 3;
            printChar(mx[c] - cur, ' ');
            if(i == 1){
                cout << ' ';
                printChar(2 * cur + 1, '_');
                cout << ' ';
            } else if(i == 2){
                cout << '|';
                printChar(cur, ' ');
                cout << '^';
                printChar(cur, ' ');
                cout << '|';
            } else {
                cout << '|';
                printChar(cur - i + 2, ' ');
                cout << '/';
                for(int j = 1; j <= 2 * i - 5; ++j){
                    cout << (char)('A' + cnt[c]);
                    cnt[c] = (cnt[c] + 1) % 26;
                }
                cout << '\\';
                printChar(cur - i + 2, ' ');
                cout << '|';
            }
            printChar(mx[c] - cur, ' ');
        }
        cout << '\n';
    }

    return 0;
}
