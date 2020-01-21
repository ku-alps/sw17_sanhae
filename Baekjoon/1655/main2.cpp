#include<ios>
int a[20001], n, x, y, c = 1, k = 10000, f, t;

int main() {
	scanf("%d%d", &n, &x);
	printf("%d\n", x);
	a[x += k]++;
	while (~scanf("%d", &y)){
		a[y += k]++;
		t = (x <= y) + f;
		c += --t;
		if (c > a[x] || !c) {
			while (!a[x += t]);
			c = t > 0 ? 1 : a[x];
		}
		f = !f;
		printf("%d\n", x - k);
	}
}
