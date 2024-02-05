#include <bits/stdc++.h>
using namespace std;

vector<char> letters = {'U','A','C','G'};
map<string,string> mp;

string codon(string c) {
	if (c[0] == 'U') {
		if (c[1] == 'U') {
			if (c[2] == 'U' || c[2] == 'C') {
				return "Phe";
			} else if (c[2] == 'A' || c[2] == 'G') {
				return "Leu";
			}
		} else if (c[1] == 'C') {
			return "Ser";
		} else if (c[1] == 'A') {
			if (c[2] == 'U' || c[2] == 'C') {
				return "Tyr";
			} else if (c[2] == 'A' || c[2] == 'G') {
				return "Stop";
			}
		} else if (c[1] == 'G') {
			if (c[2] == 'U' || c[2] == 'C') {
				return "Cys";
			} else if (c[2] == 'A') {
				return "Stop";
			} else if (c[2] == 'G') {
				return "Trp";
			}
		}
	} else if (c[0] == 'C') {
		if (c[1] == 'U') {
			return "Leu";
		} else if (c[1] == 'C') {
			return "Pro";
		} else if (c[1] == 'A') {
			if (c[2] == 'U' || c[2] == 'C') {
				return "His";
			} else if (c[2] == 'A' || c[2] == 'G') {
				return "Gln";
			}
		} else if (c[1] == 'G') {
			return "Arg";
		}
	} else if (c[0] == 'A') {
		if (c[1] == 'U') {
			if (c[2] == 'U' || c[2] == 'C' || c[2] == 'A') {
				return "Ile";
			} else if (c[2] == 'A' || c[2] == 'G') {
				return "Met";
			}
		} else if (c[1] == 'C') {
			return "Thr";
		} else if (c[1] == 'A') {
			if (c[2] == 'U' || c[2] == 'C') {
				return "Asn";
			} else if (c[2] == 'A' || c[2] == 'G') {
				return "Lys";
			}
		} else if (c[1] == 'G') {
			if (c[2] == 'U' || c[2] == 'C') {
				return "Ser";
			} else if (c[2] == 'A' || c[2] == 'G') {
				return "Arg";
			}
		}
	} else if (c[0] == 'G') {
		if (c[1] == 'U') {
			return "Val";
		} else if (c[1] == 'C') {
			return "Ala";
		} else if (c[1] == 'A') {
			if (c[2] == 'U' || c[2] == 'C') {
				return "Asp";
			} else if (c[2] == 'A' || c[2] == 'G') {
				return "Glu";
			}
		} else if (c[1] == 'G') {
			return "Gly";
		}
	}
	return "XXX";
}

string polypeptide(bool start, bool stop, string str) {
	string c = string(str.begin(),str.begin()+3);
	int i = 0;
	if (start) {
		for (; i < str.size(); ++i) {
			if (c == "AUG")break;
			c.erase(c.begin());
			c.push_back(str[i+3]);
		}
	} 
	string res = "";
	for (int j = i; j+2 < str.size(); j += 3) {
		string cdn = string(str.begin()+j,str.begin()+j+3);
		res += codon(cdn);
		if (codon(cdn) == "Stop" && stop)break;
		res += ' ';
	}
	return res;
}

int main() {
	cin.tie(NULL);
	string str;
	cin >> str;
	cout << polypeptide(false,true,str) << '\n';
	cin >> str;
	cout << polypeptide(false,true,str) << '\n';
	cin >> str;
	cout << polypeptide(false,true,str) << '\n';
	cin >> str;
	cout << polypeptide(false,true,str) << '\n';
	cin >> str;
	cout << polypeptide(false,true,str) << '\n';
	return 0;
}