#include<ios>
#include<algorithm>
#include<math.h>

struct pp {
	int f, t;
	float c;
	bool operator <(pp &p) { return c < p.c; }
};

int v, i, j, k, p[101];
struct pp pa[5000];
float x, y, mn, px[101][2];

float len(int a, int b) {
	return sqrt(pow((px[a][0]-px[b][0]), 2) + pow((px[a][1] - px[b][1]), 2));
}

int find(int t) {
	return (t - p[t]) ? p[t] = find(p[t]) : t;
}

int main() {
	scanf("%d", &v);
	for (; i < v; i++) {
		scanf("%f%f", px[i], px[i] + 1);
		for (j = 0; j < i; j++) {
			pa[k++] = {i, j, len(i, j)};
		}
	}
	std::sort(pa, pa + k);
	while (v--)p[v + 1] = v + 1;
	for (i = 0; i < k; i++)
		if ((x = find(pa[i].f)) - (y = find(pa[i].t))) {
			p[(int)x] = y;
			mn += pa[i].c;
		}

	printf("%f", mn);
}
