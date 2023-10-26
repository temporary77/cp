#include <bits/stdc++.h>
using namespace std;

int main(){

    int row, col;
    scanf("%d%d", &row, &col);

    bool diffIsAlpha = true;
    int alphaCnt = 0, numCnt = 0;
    int diffChain = 0, sumChain = col + 1;
    for(int i = 1; i <= row; ++i){
        if(i + 1 == sumChain){
            sumChain += col - 1;
            diffChain += col - 1;
            diffIsAlpha = !diffIsAlpha;
        }
        for(int j = 1; j <= col; ++j){
            if(i - j == diffChain && i + j == sumChain){
                cout << (char)('A' + alphaCnt);
            } else if(i - j == diffChain){
                if(diffIsAlpha){
                    cout << (char)('A' + alphaCnt);
                } else {
                    cout << numCnt;
                }
            } else if(i + j == sumChain){
                if(!diffIsAlpha){
                    cout << (char)('A' + alphaCnt);
                } else {
                    cout << numCnt;
                }
            } else {
                cout << ' ';
            }
        }
        numCnt = (numCnt + 1) % 10;
        alphaCnt = (alphaCnt + 1) % 26;
        cout << '\n';
    }

    return 0;
}
