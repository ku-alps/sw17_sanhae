#include<ios>
#include<math.h>
#include<vector>
using namespace std;
const int N = 100001;
int n, x, y, m, a[N][21], d[N], i;
bool f[N];
vector<vector<int>> v;

void dfs(int p, int q) {
	f[p] = 1;
	d[p] = q++;
	for (int k : v[p])
		if (!f[k]) {
			a[k][0] = p;
			dfs(k, q);
		}
}

void fill() {
	for (y = 0; y < 20; y++)
		for (x = 0; x++ - n;)
			a[x][y + 1] = a[a[x][y]][y];
}

int lca() {
	if (d[x] < d[y])
		swap(x, y);
	for (i = 21; i--;)
		if (d[x] - d[y] >= (1 << i))
			x = a[x][i];
	if (x == y) return x;
	for (i = 21; i--;)
		if (a[x][i] - a[y][i]) {
			x = a[x][i];
			y = a[y][i];
		}
	return a[x][0];
}

int main() {
	scanf("%d", &n);
	v.resize(n + 1);
	for (; ++i < n;) {
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0);
	fill();
	scanf("%*d");
	while (~scanf("%d%d", &x, &y)) printf("%d ", lca());
}
