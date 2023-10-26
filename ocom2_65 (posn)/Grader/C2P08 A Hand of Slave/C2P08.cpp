#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> vctr;
    char c, d;
    unordered_map<char,int> mp;
    unordered_map<int,char> mprev;
    mp['3'] = 0;
    mp['4'] = 1;
    mp['5'] = 2;
    mp['6'] = 3;
    mp['7'] = 4;
    mp['8'] = 5;
    mp['9'] = 6;
    mp['T'] = 7;
    mp['J'] = 8;
    mp['Q'] = 9;
    mp['K'] = 10;
    mp['A'] = 11;
    mp['2'] = 12;
    mp['C'] = 13;
    mp['D'] = 14;
    mp['H'] = 15;
    mp['S'] = 16;
    mprev[0] = '3';
    mprev[1] = '4';
    mprev[2] = '5';
    mprev[3] = '6';
    mprev[4] = '7';
    mprev[5] = '8';
    mprev[6] = '9';
    mprev[7] = 'T';
    mprev[8] = 'J';
    mprev[9] = 'Q';
    mprev[10] = 'K';
    mprev[11] = 'A';
    mprev[12] = '2';
    mprev[13] = 'C';
    mprev[14] = 'D';
    mprev[15] = 'H';
    mprev[16] = 'S';
    for (int i = 0; i < n; ++i) {
        scanf(" %c %c",&c,&d);
        vctr.push_back({mp[c],mp[d]});
    }
    sort(vctr.begin(),vctr.end());
    for (int i = 0; i < n; ++i) {
        printf("%c %c\n",mprev[vctr[i].first],mprev[vctr[i].second]);
    }
    return 0;
}
