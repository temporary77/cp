#include "rescue.h"
#include <cstdio>
#include "rescue.cpp"

static std::vector<int> X;
static std::vector<int> Y;
static int N,Q;

int main()
{
  int tmp;

  tmp = scanf("%d %d", &N, &Q);
  for(int i=0; i<N; i++) {
    int x,y;
    tmp = scanf("%d %d",&x,&y);
    X.push_back(x);
    Y.push_back(y);
  }
  init_rescue(N,Q,X,Y);

  for(int i=0; i<Q; i++) {
    int k,r;
    tmp = scanf("%d",&k);
    if(k==1) {
      int a,b,c,d;
      tmp = scanf("%d %d %d %d",&a,&b,&c,&d);
      printf("%d\n", answer_query(a,b,c,d));
    } else {
      tmp = scanf("%d",&r);
      cancel_request(r);
    }
  }
}
