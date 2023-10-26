#include <bits/stdc++.h>
using namespace std;

const int N = 200;
const int L = 2500;
const double AN = -1e-6;
const double AP = 1e-6;

double *mat[N + 5], ans[N + 5];
char eq[L + 5];

bool isZero(const double &x){
    return AN <= x && x <= AP;
}

int main(){

    freopen("09.in", "r", stdin);
    freopen("test.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        mat[i] = new double[n + 2];
        for(int j = 1; j <= n + 1; ++j){
            mat[i][j] = 0;
        }
        scanf(" %[^\n]", eq);
        int neg = 1;
        for(char *tok = strtok(eq, " "); tok != NULL; tok = strtok(NULL, " ")){
            if(tok[0] == '+' || tok[0] == '='){
                neg = 1;
                continue;
            } else if(tok[0] == '-'){
                neg = -1;
                continue;
            }
            char *ptr = strchr(tok, 'x');
            if(ptr == NULL){
                mat[i][n + 1] = neg * atoi(tok);
                continue;
            }
            int idx = ptr - tok;
            int ith = atoi(tok + idx + 1);
            if(idx == 0){
                mat[i][ith] = neg * 1;
            } else {
                char cof[5];
                strncpy(cof, tok, idx);
                cof[idx] = '\0';
                mat[i][ith] = neg * atoi(cof);
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        if(isZero(mat[i][i])){
            bool found = false;
            for(int j = i + 1; j <= n; ++j){
                if(!isZero(mat[j][i])){
                    swap(mat[i], mat[j]);
                    found = true;
                    break;
                }
            }
            if(!found){
                continue;
            }
        }
        for(int j = i + 1; j <= n; ++j){
            if(isZero(mat[j][i])){
                continue;
            }
            double coef = mat[j][i] / mat[i][i];
            mat[j][i] = 0;
            for(int k = i + 1; k <= n + 1; ++k){
                mat[j][k] -= coef * mat[i][k];
            }
        }
    }
    for(int i = n; i >= 1; --i){
        if(isZero(mat[i][i])){
            continue;
        }
        for(int j = i - 1; j >= 1; --j){
            if(isZero(mat[j][i])){
                continue;
            }
            double coef = mat[j][i] / mat[i][i];
            mat[j][i] = 0;
            mat[j][n + 1] -= coef * mat[i][n + 1];
        }
    }

    bool hasNo = false;
    bool hasMany = false;
    for(int i = n; i >= 1; --i){
        if(isZero(mat[i][i])){
            bool isAllZero = true;
            for(int j = i + 1; j <= n; ++j){
                if(!isZero(mat[i][j])){
                    isAllZero = false;
                    break;
                }
            }
            if(isAllZero && isZero(mat[i][n + 1])){
                hasMany = true;
            } else {
                hasNo = true;
            }
        }
        ans[i] = mat[i][n + 1] / mat[i][i];
    }
    if(hasNo){
        cout << "No Solutions\n";
        return 0;
    }
    if(hasMany){
        cout << "Many Solutions\n";
        return 0;
    }
    for(int i = 1; i <= n; ++i){
        printf("x%d: %.10lf\n", i, ans[i]);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
