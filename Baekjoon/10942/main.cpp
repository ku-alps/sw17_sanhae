#include<ios>
int a[2001], n, i, j, d[2001][2];

void f(int t) {
	for (i = 0; i < n - t; i++)
		for (j = 0; i + j < n && i - j >= 0; j++)
			if (a[i - j] == a[i + j + t]) d[i][t]++;
			else break;
}

int main() {
	for (scanf("%d", &n); i <= n; scanf("%d", a + i++));
	f(0); f(1);
	while (~scanf("%d%d", &i, &j))
		printf("%d\n", d[(i + j) / 2 - 1][(i + j) % 2] > (j - i) / 2);
}
