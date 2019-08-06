#include<ios>
#include<algorithm>

struct pp {
	int x, y, c;
	bool operator <(pp &p) { return c < p.c; }
};

int v, e, i, x, y, z, mn, p[10001];
struct pp pa[100001];

int find(int t) {
	return (t - p[t]) ? p[t] = find(p[t]) : t;
}

int main() {
	scanf("%d%d", &v, &e);
	for (; i < e; i++) {
		scanf("%d%d%d", &x, &y, &z);
		pa[i] = { x, y, z };
	}
	std::sort(pa, pa + e);
	while (v--)p[v + 1] = v + 1;
	for (i = 0; i < e; i++)
		if ((x = find(pa[i].x)) - (y = find(pa[i].y))) {
			p[x] = y;
			mn += pa[i].c;
		}

	printf("%d", mn);
}
