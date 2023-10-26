#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

int main(){

    int maxX, maxY, maxZ, nTasks;
    scanf("%d%d%d%d", &maxX, &maxY, &maxZ, &nTasks);

    int box = maxX * maxY * maxZ;
    int plane = maxX * maxY;

    bool xisRev, yisRev;
    for(int i = 0; i < nTasks; i += box){
        xisRev = false;
        yisRev = false;
        int stBox = i, edBox = i + box - 1;
        for(int z = i; z <= edBox; z += plane){
            int stPlane = z, edPlane = z + plane - 1;
            int mvRow = 1;
            if(yisRev){
                swap(stPlane, edPlane);
                mvRow = -1;
            }
            for(int y = stPlane; y != edPlane + mvRow; y += mvRow * maxX){
                int stRow = y, edRow = y + mvRow * (maxX - 1);
                int mvPos = mvRow;
                if(yisRev != xisRev){
                    swap(stRow, edRow);
                    mvPos = 0 - mvPos;
                }
                for(int x = stRow; x != edRow + mvPos; x += mvPos){
                    if(x < nTasks){
                        cout << x << ' ';
                    } else {
                        cout << "v ";
                    }
                }
                cout << '\n';
                xisRev = !xisRev;
            }
            yisRev = !yisRev;
            if(maxY % 2 == 0){
                xisRev = !xisRev;
            }
        }
        if(i + box <= nTasks){
            cout << (lli)box * (stBox + edBox) / 2 << '\n';
        } else {
            cout << (lli)(nTasks - stBox) * (stBox + nTasks - 1) / 2 << '\n';
        }
    }

    return 0;
}
