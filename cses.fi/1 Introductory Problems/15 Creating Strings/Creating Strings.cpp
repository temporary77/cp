#include <bits/stdc++.h>
using namespace std;

void recursion(int d, char arr[], int arrsize) {
    if (d == 1) {
        for (int i = 0; i < arrsize; ++i) {
            printf("%c",arr[i]);
        }
        printf("\n");
        return;
    }
    //printf("runnin %d\n",d);
    char c = '\0';
    for (int i = 0; i < d; ++i) {
        if (arr[i+arrsize-d] == c) {
            continue;
        }
        //printf("operatin %d %d\n",i,d);
        c = arr[i+arrsize-d];
        char sndr[arrsize] = {};
        int k = 0;
        //printf("nah\n");
        for (int j = 0; j < arrsize-d; ++j) {
            sndr[j] = arr[j];
        }
        //printf("break %d %d\n",i,d);
        sndr[arrsize-d] = arr[i+arrsize-d];
        for (int j = arrsize-d; j < arrsize-1; ++j) {
            if (sndr[arrsize-d] == arr[j]) {
                k = 1;
            }
            sndr[j+1] = arr[j+k];
        }
        //printf("made it %d %d\n",i,d);
        recursion(d-1,sndr,arrsize);
    }
}

int main() {
    char temp[9] = {};
    int strge[26] = {0};
    long long fac[9] = {1,1,2,6,24,120,720,5040,40320};
    scanf("%s",temp);
    int n = strlen(temp);
    char arr[n];
    for (int i = 0; i < n; ++i) {
        *(arr+i) ^= *(temp+i);
        *(temp+i) ^= *(arr+i);
        *(arr+i) ^= *(temp+i);
    }
    sort(arr,arr+n);
    for (int i = 0; i < n; ++i) {
        ++strge[int(arr[i])-97];
    }
    long long cnt = fac[n];
    for (int i = 0; i < 26; ++i) {
        cnt /= fac[strge[i]];
    }
    printf("%lld\n",cnt);
    recursion(n,arr,n);
    /*for (int i = 0; i < n; ++i) {
        printf("%c",arr[i]);
    }
    printf("%d",n);*/
    return 0;
}

/*void f() {
    string s; cin >> s;
    vector<string> total;

    sort(s.begin(), s.end());

    do {
	total.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << (int)total.size() << '\n';
    for (auto ax : total)
	cout << ax << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    f();

    return 0;
}
*/
