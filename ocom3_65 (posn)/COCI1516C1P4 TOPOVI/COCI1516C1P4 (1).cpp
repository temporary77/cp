#include <bits/stdc++.h>
using namespace std;

#define int long long
#define int2 int

map<int,int> mpr, mpc; // power of key r/c
map<pair<int,int>,int> mpx; // power at pos x,y
map<int,int> mr, mc; // number of key power r/c in all
int rrr = 0, ccc = 0; // number of r/c that has above 0 power
long long n;
long long cnt = 0;

void change(int pos, int x, char rc) {
	if (rc == 'r') {
		--mr[mpr[pos]];
		//printf("%d del\n",mpr[pos]);
		if (mc.find(mpr[pos]) != mc.end()) {
			cnt -= n-mc[mpr[pos]];
			//printf("subtract %d\n",n-mc[mpr[pos]]);
		} else {
			cnt -= n;
			//printf("subtract %d\n",n);
		}
		if (mr[mpr[pos]] == 0)mr.erase(mpr[pos]);
		mpr[pos] ^= x;
		++mr[mpr[pos]];
		//printf("%d add\n",mpr[pos]);
		if (mc.find(mpr[pos]) != mc.end()) {
			cnt += n-mc[mpr[pos]];
			//printf("add %d\n",n-mc[mpr[pos]]);
		} else {
			cnt += n;
			//printf("add %d\n",n);
		}
		//printf("--- %lld\n",cnt);		
	} else {
		--mc[mpc[pos]];
		//printf("%d del\n",mpc[pos]);
		if (mr.find(mpc[pos]) != mr.end()) {
			cnt -= n-mr[mpc[pos]];
			//printf("subtract %d\n",n-mr[mpc[pos]]);
		} else {
			cnt -= n;
			//printf("subtract %d\n",n);
		}
		if (mc[mpc[pos]] == 0)mc.erase(mpc[pos]);
		//printf("%d with %d to ",mpc[pos],x);
		mpc[pos] ^= x;
		//printf("%d\n",mpc[pos]);
		++mc[mpc[pos]];
		//printf("%d add\n",mpc[pos]);
		if (mr.find(mpc[pos]) != mr.end()) {
			cnt += n-mr[mpc[pos]];
			//printf("add %d\n",n-mr[mpc[pos]]);
		} else {
			cnt += n;
			//printf("add %d\n",n);
		}
		//printf("--- %lld\n",cnt);
	}
	return;
}

void printmap() {
	printf("vvvvvvvvvvvvvvvvvvvvvv\n");
	for (auto it : mr) {
		printf("%lld ",it.first);
	}
	printf("\n");
	for (auto it : mr) {
		printf("%lld ",it.second);
	}
	printf("\n");
	for (auto it : mc) {
		printf("%lld ",it.first);
	}
	printf("\n");
	for (auto it : mc) {
		printf("%lld ",it.second);
	}
	printf("\n--------------------\n");
}

signed main() {
	//freopen("test_input.txt","r",stdin);
	int k, p;
	scanf("%lld%lld%lld",&n,&k,&p);
	int r, c, x;
	for (int i = 0; i < k; ++i) {
		scanf("%lld%lld%lld",&r,&c,&x);
		mpr[r] ^= x;
		mpc[c] ^= x;
		mpx[{r,c}] = x;
	}
	/*for (auto it : mpr) {
		printf("%lld ",it.second);
	}
	printf("\n");
	for (auto it : mpc) {
		printf("%lld ",it.second);
	}
	printf("\n");*/
	for (auto it = mpr.begin(); it != mpr.end(); ++it) {
		if (it->second == 0) {

		} else {
			++mr[it->second];
			++rrr;
		}
	}
	for (auto it = mpc.begin(); it != mpc.end(); ++it) {
		if (it->second == 0) {

		} else {
			++mc[it->second];
			++ccc;
		}
	}
	if (n-rrr > 0)mr[0] = n-rrr;
	if (n-ccc > 0)mc[0] = n-ccc;
	//printmap();
	auto it1 = mr.begin(), it2 = mc.begin();
	int pr = 0, pc = 0;
	for (;it1 != mr.end() && it2 != mc.end();) {
		if (it1->first == it2->first) {
			pr += it1->second;
			pc += it2->second;
			cnt += (it1->second)*(n-pc);
			cnt += (it2->second)*(n-pr);
			++it1;
			++it2;
		} else if (it1->first < it2->first) {
			cnt += (it1->second)*(n-pc);
			pr += it1->second;
			++it1;
		} else {
			cnt += (it2->second)*(n-pr);
			pc += it2->second;
			++it2;
		}
	}
	//printf("%lld << \n",cnt);
	int r1, c1, r2, c2;
	for (int i = 0; i < p; ++i) {
		scanf("%lld%lld%lld%lld",&r1,&c1,&r2,&c2);
		x = mpx[{r1,c1}];
		change(r1,x,'r');
		//printmap();
		change(r2,x,'r');
		//printmap();
		change(c1,x,'c');
		//printmap();
		change(c2,x,'c');
		//printmap();
		mpx.erase({r1,c1});
		mpx[{r2,c2}] = x;
		printf("%lld\n",cnt);
	}
	return 0;
}


/*

10
01

10
10

01
10



*/