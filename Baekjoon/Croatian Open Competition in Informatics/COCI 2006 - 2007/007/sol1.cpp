#include<ios>

int n, i, j, k, c;
double a[21][21], d[1<<20];

double max(double x, double y) { return x > y ? x : y; }

int main() {
	scanf("%d", &n);

	for (; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &k);
			a[i][j] = k / 100.0;
		}
	}

	for (i = 0; i < n; i++) {
		d[1 << i] = a[0][i];
	}

	for (i = 2; i <= n; i++) {
		for (k = 1; k <= (1 << n); k++) {
			for (j = c = 0; j < n; j++) {
				if (k & (1 << j)) {
					c++;
				}
			}

			if (c == i) {
				for (j = 0; j < n; j++) {
					if (k & (1 << j)) {
						d[k] = max(d[k], d[k - (1 << j)] * a[i - 1][j]);
					}
				}
			}
		}
	}

	printf("%.8lf", d[(1 << n) - 1] * 100);
}
