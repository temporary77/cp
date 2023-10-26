#include <bits/stdc++.h>
using namespace std;
/*
int main() {
    int n;
    scanf("%d",&n);
    int arr[n] = {0};
    for (int i = 1; i <= pow(2,n); ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d",arr[j]);
        }
        printf("\n");
        int c = 0;
        for (;;) {
            if (i%int(pow(2,c+1)) != 0) {
                arr[c] = (arr[c]+1)%2;
                break;
            } else {
                ++c;
            }
        }
    }
    return 0;
}*/
/*
int32_t main()
{
  int n;
  cin>>n;
  for(int i=0;i<(1<<n);i++)
  {
    int t=i^(i>>1);
    cout<<bitset<64>(t).to_string().substr(64-n)<<'\n';
  }
}*/



void print(int n,int st) { // this entire function prints the integers out in binary form by using & with like 100, 010, 001 coded in the (1<<i) which is pretty cool
    int i = st-1;
    for (; i >= 0; i--) {
        if (n & (1<<i))cout << 1;
        else cout << 0;
    }
    cout << "\n";
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < pow(2,n); i++) {
        print(i ^ (i >> 1),n); // this brilliantly generates the gray code series, but still in integer form
    }
    return 0;
}
