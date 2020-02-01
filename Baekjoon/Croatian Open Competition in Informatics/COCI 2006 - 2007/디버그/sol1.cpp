//https://www.acmicpc.net/problem/3057

#include<ios>

int r, c, k, i, j, m = 1;
bool a[301][301];

bool f(int x, int y, int t) {
	if (t < 2) return 1;

	if (f(x + 1, y + 1, t - 2)) {
		for (int p = x; p < x + t; p++)
			if (a[2 * x + t - 1 - p][y + t - 1] != a[p][y])
				return 0;
        
		for (int q = y; q < y + t; q++)
			if (a[x + t - 1][2 * y + t - 1 - q] != a[x][q])
				return 0;
        
		if (t > m) m = t;
        
		return 1;
	}
	return 0;
}

int main() {
	scanf("%d%d", &r, &c);
	for (; i < r; i++)
		for (j = 0; j < c; j++)
			scanf("%1d", &a[i][j]);
    
	for (k = r > c ? r : c; k > m; k--)
		for (i = 0; i + k <= r; i++)
			for (j = 0; j + k <= c; j++)
				if (f(i, j, k)) {
					printf("%d", k);
					exit(0);
				}

	printf("%d", m == 1? -1 : m);
}
