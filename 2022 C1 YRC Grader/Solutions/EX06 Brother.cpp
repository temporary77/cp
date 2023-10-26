#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int L = 10;

char arr[N + 5][L + 10];
int cnt[N + 5];

int main(){

    int Q;
    scanf("%d", &Q);
    int n = 0;
    int idx = 0;
    while(Q-- > 0){
        char str[L + 5];
        scanf("%s", str);
        bool found = false;
        for(int i = 1; i <= n; ++i){
            if(strcmp(arr[i], str) == 0){
                found = true;
                ++cnt[i];
                if(cnt[idx] < cnt[i]){
                    idx = i;
                } else if(cnt[idx] == cnt[i]){
                    if(i < idx){
                        idx = i;
                    }
                }
                break;
            }
        }
        if(!found){
            ++n;
            strcpy(arr[n], str);
            cnt[n] = 1;
            if(cnt[idx] < cnt[n]){
                idx = n;
            }
        }
    }
    printf("%s", arr[idx]);

    return 0;
}
