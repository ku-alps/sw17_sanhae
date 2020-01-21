#include<ios>
int a[20001], n, x, xi, ci, l, r, k = 10000, f;

int main() {
	scanf("%d%d", &n, &xi);
	printf("%d\n", xi);
	a[xi += k]++;
	while (--n) {
		scanf("%d", &x);
		a[x += k]++;
		f = !f;
		if (xi < x) {
			if (l - r) { l++; ci++; }
			else { r++; }
		}
		else if (x < xi) {
			if (l - r) { l++; }
			else { r++; ci--; }
		}
		else {
			if (l - r) { l++; ci++; }
			else { r++; }
		}

		if (ci >= a[xi]) {
			while (!a[++xi]);
			ci = 0;
		}else if (ci < 0) {
			while (!a[--xi]);
			ci = a[xi] - 1;
		}
		printf("%d\n", xi - k);
	}
}
