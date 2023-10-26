#include "volunteers.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;

void setup_battalion(int N, int M, int Q, std::vector<std::vector<int>> H) {
	for (int i = 0; i < N; ++i) {
		vctr.push_back(H[i][0]);
	}
	return;
}

int count_volunteers(int L, int R) {
	vector<int> vctr2;
	--L;
	--R;
	for (int i = L; i <= R; ++i) {
		auto it = upper_bound(vctr2.begin(),vctr2.end(),vctr[i]);
		if (it == vctr2.end()) {
			vctr2.push_back(vctr[i]);
		} else {
			*it = vctr[i];
		}
	}
	return vctr2.size();
}