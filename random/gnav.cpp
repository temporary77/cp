#include <bits/stdc++.h>
using namespace std;

int board[6][20];
string notes[12] = {"C","C#","D","Eb","E","F","F#","G","G#","A","Bb","B"};
string spacenotes[12] = {"C ","C#","D ","Eb","E ","F ","F#","G ","G#","A ","Bb","B "};
int capo;
bool scales[2][12] = {{1,0,1,0,1,1,0,1,0,1,0,1},{1,0,1,1,0,1,0,1,1,0,1,0}};
bool chords[2][12] = {{1,0,0,0,1,0,0,1,0,0,0,0},{1,0,0,1,0,0,0,1,0,0,0,0}};
int mode;
string key;
string mm;
map<string,int> mmp;

void printboard(string c) {
	int t = 0;
	for (;;) {
		if (notes[t] == c)break;
		++t;
	}
	int k = 0;
	for (;;) {
		if (notes[k] == key)break;
		++k;
	}
	for (int i = 0; i < 20; ++i) {
		if (i < capo) {
			if (i == capo-1) {
				printf("XX[");
				continue;
			}
			printf("XX|");
		} else {
			int ri = i-capo;
			if (ri == 0) {
			printf("%d ]",ri);
			} else if (ri < 10) {
				printf("%d |",ri);
			} else {
				printf("%d|",ri);
			}
		}
	}
	if (mode == 0) {
		printf("\n");
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 20; ++j) {
				if (j < capo) {
					printf("--|");
				} else {
					cout << spacenotes[(board[i][j]+t)%12] << '|';
				}//if (j == 0)printf("| ");
			}
			printf("\n");
		}
	}
	if (mode == 1 || mode == 2) {
		printf("\n");
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 20; ++j) {
				if (j < capo) {
					if (j == capo-1) {
						printf("--[");
						continue;
					}
					printf("--|");
				} else {
					bool det;
					if (mode == 1)det = scales[mmp[mm]][(board[i][j]+t+12-k)%12];
					if (mode == 2)det = chords[mmp[mm]][(board[i][j]+t+12-k)%12];
					if (det == 1) {
						cout << spacenotes[(board[i][j]+t)%12];
					} else {
						printf("--");
					}
					if (j == capo) {
						printf("]");
						continue;
					}
					printf("|");
				}//if (j == 0)printf("| ");
			}
			printf("\n");
		}		
	}
	return;
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	board[0][0] = 4;
	board[1][0] = 11;
	board[2][0] = 7;
	board[3][0] = 2;
	board[4][0] = 9;
	board[5][0] = 4;
	mmp["Maj"] = 0;
	mmp["Min"] = 1;
	int s;
	for (int i = 0; i < 6; ++i) {
		s = board[i][0];
		for (int j = 1; j < 20; ++j) {
			board[i][j] = (s+j)%12;
		}
	}
	capo = 0;
	//printboard("C");
	mode = 1;
	key = "Eb";
	mm = "Maj";
	printboard("C");
 	printf("\n");
 	mode = 1;
	key = "C#";
	mm = "Maj";
	printboard("C");
 	printf("\n");
 	mode = 2;
	key = "G";
	mm = "Min";
	printboard("C");
	return 0;
}
// B BorF# / G#m F# / E Ebm / C#m F# /
