#include <bits/stdc++.h>
using namespace std;

map<char,set<char>> graph;
map<char,bool> visited;

void recursion(char k) {
	visited[k] = 1;
	for (auto it : graph[k]) {
		if (visited[it] == 0) {
			recursion(it);			
		}
	}
	return;
}

int main() {
	//freopen("test_input.txt","r",stdin);
	char c;
	scanf(" %c",&c);
	string str;
	while (cin >> str) {
		char a = str[0], b = str[1];
		graph[a].insert(b);
		graph[b].insert(a);
	}
	int cnt = 0;
	for (char i = 'A'; i <= c; ++i) {
		if (visited[i] == 0) {
			recursion(i);
			++cnt;
		}
	}
	printf("%d",cnt);
	return 0;
}