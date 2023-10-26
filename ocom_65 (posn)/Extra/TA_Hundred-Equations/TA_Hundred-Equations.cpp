#include <bits/stdc++.h>
using namespace std;

void matrix(double **arr, int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            printf("% 6.2lf|",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

int main() {
    int n, scnd, indx, rslt, mode;
    char c;
    bool neg;
    scanf("%d",&n);
    double *arr[n+1];
    for (int i = 0; i <= n; ++i) {
        arr[i] = new double [n+1];
    }
    for (int i = 1; i <= n; ++i) {
        scnd = 0;
        indx = 0;
        rslt = 0;
        neg = 0;
        mode = 0;
        for (;;) {
            scanf("%c",&c);
            if (c >= 48 && c <= 57) {
                if (mode == 0) {
                    scnd *= 10;
                    scnd += int(c-48);
                } else if (mode == 1) {
                    indx *= 10;
                    indx += int(c-48);
                } else if (mode == 2 || mode == 3) {
                    rslt *= 10;
                    rslt += int(c-48);
                }
            } else if (c == 'x') {
                mode = 1;
                if (scnd == 0) {
                    scnd = 1;
                }
            } else if (c == '+') {
                mode = 0;
                if (neg == 0) {
                    arr[i][indx] = scnd;
                } else {
                    arr[i][indx] = scnd*-1;
                }
                scnd = 0;
                indx = 0;
                neg = 0;
            } else if (c == '-') {
                if (mode == 1) {
                    mode = 0;
                } else if (mode == 2) {
                    mode = 3;
                }
                if (neg == 0) {
                    arr[i][indx] = scnd;
                } else {
                    arr[i][indx] = scnd*-1;
                }
                scnd = 0;
                indx = 0;
                neg = 1;
            } else if (c == '=') {
                mode = 2;
                if (neg == 0) {
                    arr[i][indx] = scnd;
                } else {
                    arr[i][indx] = scnd*-1;
                }
            } else if (c == '\n') {
                if (mode == 2) {
                    arr[i][0] = rslt;
                    break;
                } else if (mode == 3) {
                    arr[i][0] = -1*rslt;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (arr[i][i] == 0) {
            for (int j = i+1; j <= n; ++j) {
                if (arr[j][i] != 0) {
                    swap(arr[i],arr[j]);
                }
                break;
            }
            if (arr[i][i] == 0) {
                continue;
            }
        }
        for (int j = i+1; j <= n; ++j) {
            double d = arr[j][i]/arr[i][i];
            arr[j][i] = 0;
            arr[j][0] -= arr[i][0]*d;
            for (int k = i+1; k <= n; ++k) {
                arr[j][k] -= arr[i][k]*d;
            }
        }
    }
    for (int i = n; i >= 1; --i) {
        if (arr[i][i] == 0) {
            continue;
        }
        arr[i][0] /= arr[i][i];
        arr[i][i] = 1;
        for (int j = i-1; j >= 1; --j) {
            arr[j][0] -= arr[i][0]*arr[j][i];
            arr[j][i] = 0;
        }
    }
    bool toggle = 0;
    for (int i = 1; i <= n; ++i) {
        if (arr[i][i] == 0) {
            if (arr[i][0] != 0) {
                printf("No Solutions");
                return 0;
            } else {
                toggle = 1;
            }
        }
    }
    if (toggle == 1) {
        printf("Many Solutions");
        return 0;
    }
    double sols[n+1] = {};
    for (int i = n; i >= 1; --i) {
        sols[i] = arr[i][0];
        for (int j = i+1; j <= n; ++j) {
            sols[i] -= arr[i][j]*sols[j];
        }
        sols[i] /= arr[i][i];
    }
    for (int i = 1; i <= n; ++i) {
        printf("x%d: %.10lf\n",i,sols[i]);
    }
    return 0;
}
