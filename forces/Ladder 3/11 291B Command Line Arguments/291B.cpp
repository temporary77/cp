#include <bits/stdc++.h>
using namespace std;

char str[100005];

int main() {
	scanf("%[^\n]s",str);
	bool inblock = 0;
	bool inmodule = 0;
	for (int i = 0; i < 100005; ++i) {
		if (str[i] == '\0') {
			if (inmodule || inblock) {
				printf(">\n");
			}
			return 0;
		}
		if (str[i] == '"') {
			if (!inblock) {
				printf("<");
			} else {
				printf(">\n");
			}
			inblock ^= 1;
		} else if (inblock) {
			printf("%c",str[i]);
		} else {
			if (!inmodule) {
				if (str[i] == ' ')continue;
				printf("<%c",str[i]);
				inmodule = 1;
			} else {
				if (str[i] == ' ') {
					printf(">\n");
					inmodule = 0;
				} else {
					printf("%c",str[i]);
				}
			}
		}
	}
	return 0;
}