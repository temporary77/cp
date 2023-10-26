#include "spectrophotometer.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

static std::vector<int> lasers;
static int N;
static int swap_count;
int suc = 0;
int wa = 0;
int mxcnt = 0;

int n;

void printlasers() {
    printf("\n");
    for (int i = 2*n; i < 3*n; ++i) {
        printf("%d ",lasers[i]);
    }   
    printf("\n");
    for (int i = n; i < 2*n; ++i) {
        printf("%d ",lasers[i]);
    }   
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ",lasers[i]);
    }   
    printf("\n");
}

void fail(std::string reason) {
  std::cout << reason << std::endl;
  exit(0);
}

void success() {
  std::cout << "correct answer" << std::endl;
  std::cout << swap_count << std::endl;
  mxcnt = max(mxcnt,swap_count);
  ++suc;
  //exit(0);
}

bool call_swap(int a, int b) {
    //printf("mf swapping %d %d\n",a,b);
  if (a < 0 || a >= 3 * N || b < 0 || b >= 3 * N || a == b) {
    fail("invalid swap parameters");
  }
  swap_count++;
  std::swap(lasers[a], lasers[b]);
  //printf("%d",swap_count);
  //printlasers();
  return lasers[a] == lasers[b];
}

/*
0 unknown
1 is red
2 is green
3 is blue
4 1 or 2
5 1 or 3
6 2 or 3
*/


void sort_lasers(int N) {
    // printf("QUERY\n");
      // for (int i = 0; i < 3 * N; i++) {
      //   std::cout << lasers[i] << " ";
      // }
      // std::cout << std::endl;
    n = N;
  // printlasers();
    if (N == 1)return;
    bool check;
    int rdx = 0, gdx = n, bdx = 2*n;
    for (;;) {
        check = call_swap(rdx,gdx);
        if (check) {
            ++rdx;
        } else {
            break;
        }
    }
    ++rdx;
    ++gdx;
    ++bdx;
    int r = 0, g = n, u = 2*n;
    int uval;
        // printf("ITS %d also %d %d %d and %d %d %d\n",uval,r,g,u,rdx,gdx,bdx);
    check = call_swap(u,r);
    swap(u,r);
    if (check) {
        uval = 1;
    } else {
        check = call_swap(u,g);
        swap(u,g);
        if (check) {
            uval = 2;
        } else {
            uval = 3;
        }
    }
    int frst;
    for (;;) {
        //if (rdx == n || gdx == 2*n || bdx == 3*n)break;
      // for (int i = 0; i < 3 * N; i++) {
      //   std::cout << lasers[i] << " ";
      // }
      // std::cout << std::endl;
        // printf("ITS %d also %d %d %d and %d %d %d\n",uval,r,g,u,rdx,gdx,bdx);
    // printf("%d %d %d %d %d %d %d\n",r,g,u,rdx,gdx,bdx,uval);
        if (uval == 1) {
            check = call_swap(u,rdx);
            ++rdx;
            if (rdx == n) {
                frst = 1;
                break;
            }
            if (check) {
                uval = 1;
            } else {
                check = call_swap(u,g);
                swap(u,g);
                if (check) {
                    uval = 2;
                } else {
                    uval = 3;
                }
            }
        } else if (uval == 2) {
            check = call_swap(u,gdx);
            ++gdx;
            if (gdx == 2*n) {
                frst = 2;
                break;
            }
            if (check) {
                uval = 2;
            } else {
                check = call_swap(u,r);
                swap(u,r);
                if (check) {
                    uval = 1;
                } else {
                    uval = 3;
                }
            }
        } else if (uval == 3) {
            if (bdx == 3*n) {
                frst = 3;
                break;
            }
            check = call_swap(u,bdx);
            ++bdx;
            if (check) {
                uval = 3;
            } else {
                check = call_swap(u,r);
                swap(u,r);
                if (check) {
                    uval = 1;
                } else {
                    uval = 2;
                }
            }
        }
    }
    int other1, other2, other3;
    int x, xval;
    int y, yval;
    if (frst == 1) {
        check = call_swap(u,g);
        swap(g,u);
        x = u;
        if (check) {
            xval = 2;
        } else {
            xval = 3;
        }
        y = g;
        yval = 2;
    } else if (frst == 2) {
        check = call_swap(u,r);
        swap(r,u);
        x = u;
        if (check) {
            xval = 1;
        } else {
            xval = 3;
        }
        y = r;
        yval = 1;
    } else if (frst == 3) {
        x = g;
        xval = 2;
        y = r;
        yval = 1;
        other1 = 2;
        other2 = 1;
    }
    // printf("%d %d %d %d ------- %d\n",x,xval,y,yval,frst);
    for (;;) {
       //  printf("%d %d %d <<<\n",rdx,gdx,bdx);
        if (!(rdx == n ^ gdx == 2*n ^ bdx == 3*n))break;
        if (xval == 1) {
            check = call_swap(x,rdx);
            ++rdx;
            if (check) {
                xval = 1;
            } else {
                xval = yval;
            }
        } else if (xval == 2) {
            check = call_swap(x,gdx);
            ++gdx;
            if (check) {
                xval = 2;
            } else {
                xval = yval;
            }
        } else if (xval == 3) {
            check = call_swap(x,bdx);
            ++bdx;
            if (check) {
                xval = 3;
            } else {
                xval = yval;
            }
        }
    }
    printf("OOOOOOOOOOOOOOOOOOOOO %d %d %d %d\n",x,xval,y,yval);
    // if (yval == 1) {
    //     if (y != 0) {
    //         call_swap(0,y);
    //     }
    // } else if (yval == 2) {
    //     if (y != n) {
    //         call_swap(n,y);
    //     }
    // }
    // int x = g;
    // int xval = 2;
    // for (;;) {
    //     if (xval == 1) {
    //         check = call_swap(x,rdx);
    //         ++rdx;
    //         if (check) {
    //             xval = 1;
    //         } else {
    //             xval = 2;
    //         }
    //     } else if (xval == 2) {
    //         if (gdx == 2*n)break;
    //         check = call_swap(x,gdx);
    //         ++gdx;
    //         if (check) {
    //             xval = 2;
    //         } else {
    //             xval = 1;
    //         }
    //     }
    // }
    // if (r == n) {
    //     call_swap(r,x);
    //     swap(r,x);
    // }
    //printf("%d %d %d %d %d %d %d\n",r,g,u,rdx,gdx,bdx,uval);
      for (int i = 0; i < 3 * N; i++) {
        std::cout << lasers[i] << " ";
      }
      std::cout << std::endl;

    return;
}

int main() {
  std::cin >> N;
  for (int t = 0; t < 1000; ++t) {
    lasers.clear();
    swap_count = 0;
  std::map<int, int> tcount;
  for (int i = 0; i < 3 * N; i++) {
    int col;
    std::cin >> col;
    tcount[col]++;
    lasers.push_back(col);
  }
  swap_count = 0;
  sort_lasers(N);
  std::map<int, int> last;
  bool grade = 1;
  for (auto t : tcount)
    last[t.first] = -1;
  for (int i = 0; i < 3 * N; i++) {
    if (last[lasers[i]] == -1) {
      last[lasers[i]] = i;
    } else if (last[lasers[i]] == i - 1) {
      last[lasers[i]] = i;
    } else {
      std::cout << "wrong answer" << std::endl;
      for (int i = 0; i < 3 * N; i++) {
        std::cout << lasers[i] << " ";
      }
      std::cout << std::endl;
      grade = 0;
      break;
// exit(0);
    }
  }
  if (grade)success();
}
printf("%d %d %d\n",suc,wa,mxcnt);
  return 0;
}