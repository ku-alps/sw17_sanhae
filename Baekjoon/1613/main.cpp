#include<ios>
int n, k, x, y;
bool a[401][401];

int main() {
	for (scanf("%d%d", &n, &k); k--; ) {
		scanf("%d%d", &x, &y);
		a[x][y] = 1;
	}

	for (k = 1; k <= n; k++)
		for (x = 1; x <= n; x++)
			for (y = 1; y <= n; y++)
				a[x][y] |= a[x][k] & a[k][y];

	for (scanf("%*d"); ~scanf("%d%d", &x, &y);)
		printf("%d\n", a[x][y] ? -1 : a[y][x]);
}
