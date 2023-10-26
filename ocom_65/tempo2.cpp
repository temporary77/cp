#include <bits/stdc++.h>
using namespace std;

void printChar(char c, int n){
    while(n-- > 0){
        cout << c;
    }
}

const int N = 100;

int curr[N + 5], cnt[N + 5], box[N + 5][N + 5], sta[N + 5], nBox[N + 5], mxBox[N + 5], sumBox[N + 5];

int main(){

    int nCol;
    scanf("%d", &nCol);
    int mxHeight = 0;
    for(int i = 1; i <= nCol; ++i){
        scanf("%d", &nBox[i]);
        for(int j = 1; j <= nBox[i]; ++j){
            scanf("%d", &box[i][j]);
            mxBox[i] = max(mxBox[i], box[i][j]);
            sumBox[i] += box[i][j] + 2;
        }
        reverse(box[i] + 1, box[i] + nBox[i] + 1);
        mxHeight = max(mxHeight, sumBox[i]);
    }

    for(int h = mxHeight; h >= 1; --h){
        for(int i = 1; i <= nCol; ++i){
            if(h == sumBox[i]){
                ++sta[i];
                sumBox[i] -= box[i][sta[i]] + 2;
                cnt[i] = 0;
                curr[i] = 1;
            }
            int currBox = box[i][sta[i]];
            if(sta[i] == 0){
                printChar(' ', mxBox[i] * 2 + 3);
                continue;
            }
            printChar(' ', mxBox[i] - currBox);
            if(curr[i] == 1){
                cout << ' ';
                printChar('_', 2 * currBox + 1);
                cout << ' ';
            } else if(curr[i] == 2){
                cout << '|';
                printChar(' ', currBox);
                cout << '^';
                printChar(' ', currBox);
                cout << '|';
            } else {
                cout << '|';
                printChar(' ', currBox - curr[i] + 2);
                cout << '/';
                for(int j = 1; j <= 2 * curr[i] - 5; ++j){
                    cout << (char)('A' + cnt[i]);
                    cnt[i] = (cnt[i] + 1) % 26;
                }
                cout << '\\';
                printChar(' ', currBox - curr[i] + 2);
                cout << '|';
            }
            printChar(' ', mxBox[i] - currBox);
            ++curr[i];
        }
        cout << '\n';
    }

    return 0;
}
