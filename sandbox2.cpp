/*#include<stdio.h>
#include<conio.h>
#include<math.h>
int a[30],count=0;
int place(int pos) {
	int i;
	for (i=1;i<pos;i++) {
		if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
		 return 0;
	}
	return 1;
}
void print_sol(int n) {
	int i,j;
	count++;
	printf("\n");
	for (i=1;i<=n;i++) {
		for (j=1;j<=n;j++) {
			if(a[i]==j)
			 printf("%d", j);
		}
	}
}
void queen(int n) {
	int k=1;
	a[k]=0;
	while(k!=0) {
		a[k]=a[k]+1;
		while((a[k]<=n)&&!place(k))
		 a[k]++;
		if(a[k]<=n) {
			if(k==n)
			 print_sol(n); else {
				k++;
				a[k]=0;
			}
		} else
		 k--;
	}
}
int main() {
	int i,n;
	printf("Enter the number of Queens\n");
	scanf("%d",&n);
	queen(n);
	printf("\n\nTotal Solutions = %d", count);
	getch();
}*/
#include <stdio.h>
int main() {
	int stepSizes[] = {-9, -8, -7, -1, 1, 7, 8, 9};
	unsigned long long queenMaskBySquare[64];
	for(int square = 0; square < 64; square++) {
		queenMaskBySquare[square] = 1ULL << square;
		for(int stepSizeIndex = 0; stepSizeIndex < 8; stepSizeIndex++) {
			int step = stepSizes[stepSizeIndex];
			int attackSquare = square;
			while(1) {
				if(attackSquare + step >= 64) {
					break;
				}
				if(attackSquare + step < 0) {
					break;
				}
				if(attackSquare % 8 - (attackSquare + step) % 8 < -1) {
					break;
				}
				if(attackSquare % 8 - (attackSquare + step) % 8 > 1) {
					break;
				}
				attackSquare += step;
				queenMaskBySquare[square] |= (1ULL << attackSquare);
			}
		}
	}
	unsigned long long queenMaskTotal = 0ULL;
	for(int square1 = 0; square1 < 64; square1++) {
		for(int square2 = square1 + 1; square2 < 64; square2++) {
			for(int square3 = square2 + 1; square3 < 64; square3++) {
				for(int square4 = square3 + 1; square4 < 64; square4++) {
					for(int square5 = square4 + 1; square5 < 64; square5++) {
						queenMaskTotal = queenMaskBySquare[square1] | queenMaskBySquare[square2] | queenMaskBySquare[square3] | queenMaskBySquare[square4] | queenMaskBySquare[square5];
						if(queenMaskTotal == ~0ULL) {
							printf("Found it: %d %d %d %d %d\n", square1, square2, square3, square4, square5);
						}
					}
				}
			}
		}
	}
	return 0;
}
