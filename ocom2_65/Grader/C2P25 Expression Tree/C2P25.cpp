#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("test_input2.txt","r",stdin);
	int n, mode;
	scanf("%d",&n);
	map<string,int> mp;
	for (int i = 0; i < n; ++i) {
		int k;
		scanf("%d",&k);
		mp[to_string(char(i+65))] = k;
	}
	scanf("%d%d",&n,&mode);
	if (mode == 0) {
		for (int i = 0; i < n; ++i) {
			stack<string> stck;
			string str;
			cin >> str;
			for (;!str.empty();) {
				char c = str[0];
				if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
					string b = stck.top();
					stck.pop();
					string a = stck.top();
					stck.pop();
					string str2 = "(" + a;
					str2 += c;
					str2 += b;
					str2 += ")";
					stck.push(str2);
				} else {
					stck.push(to_string(mp[to_string(c)]));
				}
				str.erase(str.begin());
			}
			cout << stck.top() << endl;
		}
	} else if (mode == 1) {
		for (int i = 0; i < n; ++i) {
			stack<double> stck;
			string str;
			cin >> str;
			for (;!str.empty();) {
				char c = str[0];
				if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
					double b = stck.top();
					stck.pop();
					double a = stck.top();
					stck.pop();
					double x;
					if (c == '+')x = a+b;
					if (c == '-')x = a-b;
					if (c == '*')x = a*b;
					if (c == '/')x = a/b;
					if (c == '^')x = pow(a,b);
					stck.push(x);
				} else {
					stck.push(mp[to_string(c)]);
				}
				str.erase(str.begin());
			}
			printf("%.2lf\n",stck.top());
		}
	}
	return 0;
}