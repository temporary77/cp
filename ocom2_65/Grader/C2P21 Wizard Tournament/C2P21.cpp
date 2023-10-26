#include <bits/stdc++.h>
using namespace std;

struct guy {
	string n;
	int val;
	int ele;
	bool operator < (const guy &rhs) {
		if (val != rhs.val) {
			return val < rhs.val;
		} else {
			if (ele == 0) {
				return 1 > (rhs.ele+1)%3;
			} else if (ele == 1) {
				return 1 > rhs.ele;
			} else {
				return 1 > (rhs.ele+2)%3;
			}
		}
	}
	bool operator > (const guy &rhs) {
		if (val != rhs.val) {
			return val > rhs.val;
		} else {
			if (ele == 0) {
				return 1 < (rhs.ele+1)%3;
			} else if (ele == 1) {
				return 1 < rhs.ele;
			} else {
				return 1 < (rhs.ele+2)%3;
			}
		}
	}
};

map<string,int> mp = {{"fire",0},{"wood",1},{"water",2}};
map<int,string> hamburger = {{0,"fire"},{1,"wood"},{2,"water"}};

int main() {
	vector<guy> vctr;
	//freopen("test_input2.txt","r",stdin);
	int n;// = 100;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		int m;// = rand()%199+2;
		scanf("%d",&m);
		string name, ele;
		int val;
		for (int j = 0; j < m; ++j) {
			cin >> name >> val >> ele;
			//name = char(j+65);
			//val = rand()%500+1;
			//ele = hamburger[rand()%3];
			vctr.push_back({name,val,mp[ele]});
		}
		int idx = 0;
		for (;vctr.size() > 2;) {
			if (vctr[idx] < vctr[idx+1]) {
				vctr.erase(vctr.begin()+idx);
			} else {
				vctr.erase(vctr.begin()+idx+1);
			}
			++idx;
			if (idx >= vctr.size()-1)idx = 0;
			/*for (int k = 0; k < vctr.size(); ++k) {
				cout << vctr[k].n << " " << vctr[k].val << " " << hamburger[vctr[k].ele] << endl;
			}
			printf("-------------\n");*/
		}
		if (vctr[idx] < vctr[idx+1]) {
			idx = 1;
		} else {
			idx = 0;
		}
		//cout << "balling" << idx << endl;
		cout << vctr[idx].n << " " << vctr[idx].val << " " << hamburger[vctr[idx].ele] << " vs " << vctr[(idx+1)%2].n << " " << vctr[(idx+1)%2].val << " " << hamburger[vctr[(idx+1)%2].ele] << endl;
		vctr.clear();
	}
	//printf("done and dusted");
	return 0;
}