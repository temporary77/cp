#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d%d%d",&a,&b,&c);
	set<int> posc;
	vector<int> posbc;
	for (int i = 1; i*i < c; ++i) {
		posc.insert(i);
		posc.insert(-1*i);
	}
	for (auto i : posc) {
		if (b%i == 0) {
			posbc.push_back(i);
		}
	}
	set<tuple<int,int,int>> yzset;
	set<pair<int,int>> xset;
	int x, y, z;
	/*for (auto it: posbc) {
		printf("%d ",it);
	}*/
	for (auto it = posbc.begin(); it != posbc.end(); ++it) {
		for (auto it2 = it+1; it2 != posbc.end(); ++it2) {
			y = *it;
			z = *it2;
			if (b%(y*z) != 0)continue;
			yzset.insert({y*z,y,z});
		}
	}
	for (auto it = posbc.begin(); it != posbc.end(); ++it) {
		x = *it;
		xset.insert({b/x,x});
	}
	/*for (auto it: yzset) {
		printf("yz %d %d %d\n",get<0>(it),get<1>(it),get<2>(it));
	}
	for (auto it: xset) {
		printf("x %d %d\n",it.first,it.second);
	}*/
	auto xit = xset.begin();
	auto yzit = yzset.begin();
	int xval, yzval;
	tuple<int,int,int> tpl;
	bool check = 0;
	for (;xit != xset.end() && yzit != yzset.end();) {
		xval = xit->first;
		yzval = get<0>(*yzit);
		if (xval == yzval) {
			x = xit->second;
			y = get<1>(*yzit);
			z = get<2>(*yzit);
			//printf("c %d %d %d %d\n",xit->first,x,y,z);
			if (x == y || y == z || z == x || x+y+z != a || x*x+y*y+z*z != c) {
				++yzit;
				continue;
			}
			if (x > y)swap(x,y);
			if (y > z)swap(y,z);
			if (x > y)swap(x,y);
			tpl = {x,y,z};
			check = 1;
			break;
		} else if (xval > yzval) {
			++yzit;
		} else if (xval < yzval) {
			++xit;
		}
	}
	if (!check) {
		printf("No solution.");
		return 0;
	}
	printf("%d %d %d",get<0>(tpl),get<1>(tpl),get<2>(tpl));
	return 0;
}