//https://www.acmicpc.net/problem/3054

#include<ios>
#include<string.h>
#include<cmath>
char s[16];
int n, x, y, i = 2, j, k, a[5][61];

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (; j < n; i += 4, j++) {
		for (k = 0; k < 8; k++) {
			x = 2 + "43210123"[k] - '2', y = i + "23432101"[k] - '2';
			a[x][y] = j % 3 != 2 && a[x][y] != 2 ? 1 : 2;
		}
		a[2][i] = s[j];
	}
	
	for (i = 0; i < 5; i++) {
		for (j = 0; j <= 4 * n; j++) {
			printf("%c", a[i][j] > 2 ? a[i][j] : ".#*"[a[i][j]]);
		}
		printf("\n");
	}
}
