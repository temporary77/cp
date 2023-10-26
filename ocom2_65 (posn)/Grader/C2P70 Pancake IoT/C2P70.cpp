#include <bits/stdc++.h>
using namespace std;

int type[101];
bool val[101];
vector<int> proc[101];
vector<int> chld[101];
queue<int> que;
unordered_map<int,tuple<int,int,int>> mux;

void addque(int i) {
    for (auto it : chld[i]) {
        proc[it].push_back(i);
        if ((type[it] == 1 || type[it] == 2 || type[it] == 3) && proc[it].size() == 2) {
            que.push(it);
        } else if (type[it] == 4 && proc[it].size() == 1) {
            que.push(it);
        } else if (type[it] == 5 && proc[it].size() == 3) {
            que.push(it);
        }
    }
    return;
}

int main() {
    cin.tie(nullptr);
    int w, g, q;
    string str;
    scanf("%d%d%d",&w,&g,&q);
    int k;
    int a, b, c;
    for (int i = 0; i < w+g; ++i) {
        scanf("%d",&k);
        cin >> str;
        if (str == "INPUT") {
            type[i] = 0;
            que.push(k);
        } else if (str == "AND") {
            scanf("%d%d",&a,&b);
            type[i] = 1;
            chld[a].push_back(i);
            chld[b].push_back(i);
        } else if (str == "OR") {
            scanf("%d%d",&a,&b);
            type[i] = 2;
            chld[a].push_back(i);
            chld[b].push_back(i);
        } else if (str == "XOR") {
            scanf("%d%d",&a,&b);
            type[i] = 3;
            chld[a].push_back(i);
            chld[b].push_back(i);
        } else if (str == "NOT") {
            scanf("%d",&a);
            type[i] = 4;
            chld[a].push_back(i);
        } else if (str == "MUX") {
            scanf("%d%d%d",&a,&b,&c);
            type[i] = 5;
            mux[i] = {a,b,c};
            chld[a].push_back(i);
            chld[b].push_back(i);
            chld[c].push_back(i);
        }
    }
    for (int t = 0; t < q; ++t) {
        for (int i = 0; i < w; ++i) {
            scanf("%d",&val[i]);
            addque(i);
        }
        for (;!que.empty();) {
            k = que.front();
            if (type[k] == 1) {
                val[k] = val[proc[k][0]]&val[proc[k][1]];
                addque(k);
            } else if (type[k] == 2) {
                val[k] = val[proc[k][0]]|val[proc[k][1]];
                addque(k);
            } else if (type[k] == 3) {
                val[k] = val[proc[k][0]]^val[proc[k][1]];
                addque(k);
            } else if (type[k] == 4) {
                val[k] = !val[proc[k][0]];
                addque(k);
            } else if (type[k] == 5) {
                tuple<int,int,int> tpl = mux[k];
                if (val[get<0>(tpl)] == 0) {
                    val[k] = val[get<1>(tpl)];
                } else {
                    val[k] = val[get<2>(tpl)];
                }
                addque(k);
            }
            que.pop();
        }
        for (int i = w; i < w+g; ++i) {
            printf("%d ",val[i]);
        }
        printf("\n");
        for (int i = w; i < w+g; ++i) {
            proc[i].clear();
        }
    }
    return 0;
}
