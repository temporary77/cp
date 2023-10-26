#include <bits/stdc++.h>
using namespace std;

map<string,int> months;

struct date {
	int d;
	string m;
	int y;
	string event1;
	bool operator < (const date &rhs) {
		if (y != rhs.y) {
			return y < rhs.y;
		} else if (m != rhs.m) {
			return months[m] < months[rhs.m];
		} else {
			return d < rhs.d;
		}
	}
	bool operator > (const date &rhs) {
		if (y != rhs.y) {
			return y > rhs.y;
		} else if (m != rhs.m) {
			return months[m] > months[rhs.m];
		} else {
			return d > rhs.d;
		}
	}
	bool operator == (const date &rhs) {
		return (y == rhs.y && m == rhs.m && d == rhs.d);
	}
};


vector<date> vctr;

bool binarysearch(int l, int r, date x, int mode) {
	if (l > r)return 0;
	int mid = l+(r-l)/2;
	if (vctr[mid] == x) { 
		cout << "key: " << x.d << "/" << x.m << "/" << x.y << " found " << vctr[mid].event1 << endl;
		return 1;
	}
	if (mode == 1) {
		cout << "[" << mid << "]: " << vctr[mid].d << "/" << vctr[mid].m << "/" << vctr[mid].y << endl;		
	}
	if (vctr[mid] > x) {
		return binarysearch(l,mid-1,x,mode);
	}
	return binarysearch(mid+1,r,x,mode);
}

int main() {
	//freopen("test_input2.txt","r",stdin);
	months["Jan"] = 0;
	months["Feb"] = 1;
	months["Mar"] = 2;
	months["Apr"] = 3;
	months["May"] = 4;
	months["Jun"] = 5;
	months["Jul"] = 6;
	months["Aug"] = 7;
	months["Sep"] = 8;
	months["Oct"] = 9;
	months["Nov"] = 10;
	months["Dec"] = 11;
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i) {
		int d, y;
		string month1, event1;
		cin >> d >> month1 >> y >> event1;
		vctr.push_back({d,month1,y,event1});
	}
	sort(vctr.begin(),vctr.end());
	int m;
	scanf("%d",&m);
	for (int i = 0; i < m; ++i) {
		int mde, d, y;
		string m;
		cin >> mde >> d >> m >> y;
		if (!binarysearch(0,n-1,{d,m,y,""},mde)) {
			cout << "key: " << d << "/" << m << "/" << y << " not found" << endl;
		}
	}
	return 0;
}