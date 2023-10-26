#include <bits/stdc++.h>
using namespace std;
char arr[48];
bool map1[9][9] = {{1,1,1,1,1,1,1,1,1},
                   {1,0,0,0,0,0,0,0,1},
                   {1,0,0,0,0,0,0,0,1},
                   {1,0,0,0,0,0,0,0,1},
                   {1,0,0,0,0,0,0,0,1},
                   {1,0,0,0,0,0,0,0,1},
                   {1,0,0,0,0,0,0,0,1},
                   {1,0,0,0,0,0,0,0,1},
                   {1,1,1,1,1,1,1,1,1}};
int cnt = 0;

int vibecheck(int x, int y) {
    if (map1[x][y] == 1)return 0;
    int neighbors = int(map1[x-1][y])+int(map1[x+1][y])+int(map1[x][y-1])+int(map1[x][y+1]);
    if (neighbors == 3) {
        return 5;
    } else if (neighbors == 4) {
        return 1;
    } else {
        return 0;
    }
}

char check(int x, int y) {
    int L = vibecheck(x-1,y);
    int R = vibecheck(x+1,y);
    int U = vibecheck(x,y-1);
    int D = vibecheck(x,y+1);
    if (x-y == -5)return '?';
    if ((L == 1) || (R == 1) || (U == 1) || (D == 1) || ((L+R+U+D >= 10))) {
        return 'X';
    }
    if (L == 5)return 'L';
    if (R == 5)return 'R';
    if (U == 5)return 'U';
    if (D == 5)return 'D';
    return '?';
}

void recursion(int m, int x, int y) {
    if (x == 1 && y == 7) {
        if (m == 48) {
            ++cnt;
            //printf(">>>>>>>>> %d\n",cnt);
        }
        return;
    }
    map1[x][y] = 1;
    char move1 = check(x,y);
    if (arr[m] != '?' && move1 != 'X') {
        move1 = arr[m];
    }
    if (move1 == 'X') {
        map1[x][y] = 0;
        return;
    }
    /*if (m >= 47) {
        printf("%d %d %c\n",x,y,move1);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                printf("%d",int(map1[j][i]));
            }
            printf("\n");
        }
        printf("------------------------------------");
    };*/
    //printf("%d %d %d\n",m,x,y);
    if (((move1 == 'L') || (move1 == '?')) && x >= 2) {
        if (map1[x-1][y] == 0) {
            recursion(m+1,x-1,y);
        }
    }
    if (((move1 == 'R') || (move1 == '?')) && x <= 6) {
        if (map1[x+1][y] == 0) {
            recursion(m+1,x+1,y);
        }
    }
    if (((move1 == 'D') || (move1 == '?')) && y <= 6) {
        if (map1[x][y+1] == 0) {
            recursion(m+1,x,y+1);
        }
    }
    if (((move1 == 'U') || (move1 == '?')) && y >= 2) {
        if (map1[x][y-1] == 0) {
            recursion(m+1,x,y-1);
        }
    }
    map1[x][y] = 0;
    return;
}

int main() {
    scanf("%s",arr);
    recursion(0,1,1);
    printf("%d",cnt);
    return 0;
}
