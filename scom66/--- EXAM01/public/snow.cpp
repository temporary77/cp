#include "snow.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> find_pair(int N, int M, vector<int>U, vector<int> V){
    vector<int>ans;
    vector<bool>roadsalt;
    for(int i = 0; i < M; i++)roadsalt.push_back(false);
        for (auto it : roadsalt) {
            if (it) printf("1");
            else printf("0");
        }
    int re = road_salt(roadsalt);
    ans.push_back(0);
    ans.push_back(1);
    return ans;
}