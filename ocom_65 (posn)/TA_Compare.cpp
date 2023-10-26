#include <bits/stdc++.h>
using namespace std;

struct banana {
    int a, b, c;
    bool operator < (const banana &rhs) const {
        if (a != rhs.a) {
            return a > rhs.a;
        } else if (b != rhs.b) {
            return b > rhs.b;
        } else {
            return c < rhs.c;
        }
    }
    bool operator <= (const banana &rhs) const {
        if (a != rhs.a) {
            return a > rhs.a;
        } else if (b != rhs.b) {
            return b > rhs.b;
        } else {
            return c <= rhs.c;
        }
    }
};

int partition1(banana arr[], int start, int end1) {
    banana pivot = arr[start];
    int cnt = 0;
    for (int i = start+1; i <= end1; ++i) {
        if (arr[start+1] < pivot) {
            cnt++;
        }
    }
    int pivoti = start+cnt;
    swap(arr[start],arr[pivoti]);
    int i = start, j = end1;
    while (i < pivoti && pivoti < j) {
        while (arr[i] <= pivot) {
            ++i;
        }
        while (pivot <= arr[j]) {
            --j;
        }
        if (i < pivoti && j > pivoti) {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivoti;
}

void quicksort(banana arr[], int start, int end1) {
    if (start >= end1) {
        return;
    }
    int p = partition1(arr,start,end1);
    quicksort(arr,start,p-1);
    quicksort(arr,p+1,end1);
}

int main() {
    int n;
    scanf("%d",&n);
    banana arr[n];
    for (int i = 0; i < n; ++i) {
        char c;
        int mode = 0;
        int result = 0;
        for (;;) {
            scanf(" %c",&c);
            if (c == '(') {
                mode++;
            } else if (c == ')') {
                mode++;
                if (mode == 2) {
                    arr[i].a = result;
                    result = 0;
                } else if (mode == 4) {
                    arr[i].b = result;
                    result = 0;
                } else if (mode == 6) {
                    arr[i].c = result;
                    result = 0;
                    break;
                }
            } else if ((c >= 48 && c <= 57) || (c >= 65 && c <= 70)) {
                if (mode == 1) {
                    result *= 16;
                    if (c >= 65 && c <= 70) {
                        c -= 7;
                    }
                    result += int(c)-48;
                } else if (mode == 3) {
                    result *= 10;
                    result += int(c)-48;
                } else if (mode == 5) {
                    result *= 2;
                    result += int(c)-48;
                }
            }
        }
    }
    quicksort(arr,0,n-1);
    for (int i = 0; i < n; ++i) {
        printf("%d %d %d\n",arr[i].a,arr[i].b,arr[i].c);
    }

    return 0;
}
