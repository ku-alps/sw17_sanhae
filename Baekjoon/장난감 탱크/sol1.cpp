// https://www.acmicpc.net/problem/3043

#include<ios>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

struct p {
	int idx, x, y;
	p(int _idx, int _x, int _y) {
		idx = _idx;
		x = _x; y = _y;
	}
};

int n, i, a, b;
vector<p*> v, vx, vy;
vector<pair<int, int>> va;

int main() {
	scanf("%d", &n);

	for (; i < n; i++) {
		scanf("%d%d", &a, &b);
		p *t = new p(i + 1, a - 1, b - 1);
		v.push_back(t);
	}

	vy = vx = v;

	sort(vx.begin(), vx.end(), [](p* a, p* b)-> bool {
		return a->x < b->x;
	});

	sort(vy.begin(), vy.end(), [](p* a, p* b)-> bool {
		return a->y < b->y;
	});

	for (i = 0; i < n; i++) {
		while (vx[i]->x > i) {
			vx[i]->x--;
			va.emplace_back(vx[i]->idx, 2);
		}
	}

	for (i = n - 1; i >= 0; i--) {
		while (vx[i]->x < i) {
			vx[i]->x++;
			va.emplace_back(vx[i]->idx, 3);
		}
	}

	for (i = 0; i < n; i++) {
		while (vy[i]->y > i) {
			vy[i]->y--;
			va.emplace_back(vy[i]->idx, 0);
		}
	}

	for (i = n - 1; i >= 0; i--) {
		while (vy[i]->y < i) {
			vy[i]->y++;
			va.emplace_back(vy[i]->idx, 1);
		}
	}

	printf("%d\n", va.size());

	for (auto x : va) {
		printf("%d %c\n", x.first, "LRUD"[x.second]);
	}

}
