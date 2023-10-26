#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("test_input.txt","r",stdin);
	int t, q, k;
	scanf("%d%d",&t,&q);
	vector<int> vctr;
	for (int i = 0; i < t; ++i) {
		int cnt = 0;
		for (int j = 0; j < q; ++j) {
			scanf("%d",&k);
			vctr.push_back(k);		
		}
		auto sit = vctr.begin();
		for (int j = 1; j < q; ++j) {
			auto it = max_element(sit,vctr.end());
			if (it == sit) {
				++sit;
				continue;
			}
			if (it == vctr.end()-1) {
				reverse(sit,vctr.end());
				++cnt;
				++sit;
				continue;
			}
			reverse(it,vctr.end());
			reverse(sit,vctr.end());
			cnt += 2;
			++sit;
			/*for (auto transit = vctr.begin(); transit != vctr.end(); ++transit) {
				printf("%d ",*transit);
			}
			printf("\n%d \n",cnt);*/
		}
		printf("%d\n",cnt);
		vctr.clear();
	}
	return 0;
}