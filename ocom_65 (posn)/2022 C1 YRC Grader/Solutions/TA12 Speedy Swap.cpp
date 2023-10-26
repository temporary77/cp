#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int *arr[N + 5], nNums[N + 5];

int main(){

    int nArrs;
    scanf("%d", &nArrs);

    for(int i = 0; i < nArrs; ++i){
        scanf("%d", &nNums[i]);
        arr[i] = new int[nNums[i]];
        for(int j = 0; j < nNums[i]; ++j){
            scanf("%d", &arr[i][j]);
        }
    }

    int Q;
    scanf("%d", &Q);
    while(Q-- > 0){
        char cmd;
        scanf(" %c", &cmd);
        if(cmd == 'A'){
            int arrIdx;
            scanf("%d", &arrIdx);
            --arrIdx;
            arr[arrIdx] = (int*)realloc(arr[arrIdx], ++nNums[arrIdx] * sizeof(int));
            int numIdx = nNums[arrIdx] - 1;
            scanf("%d", &arr[arrIdx][numIdx]);
        } else if(cmd == 'S'){
            int i, j;
            scanf("%d%d", &i, &j);
            --i; --j;
            int *ptr = arr[i];
            arr[i] = arr[j];
            arr[j] = ptr;
            int tmp = nNums[i];
            nNums[i] = nNums[j];
            nNums[j] = tmp;
        } else if(cmd == 'D'){
            int arrIdx, numIdx;
            scanf("%d%d", &arrIdx, &numIdx);
            --arrIdx; --numIdx;
            if(nNums[arrIdx] <= numIdx){
                printf("Invalid Index\n");
            } else {
                printf("%d\n", arr[arrIdx][numIdx]);
            }
        }
    }

    return 0;
}
