#include<ios>
#include<vector>
#include<algorithm>

struct p {
	int a, b;
	bool operator < (p p) { return a < p.a; }
};

int a, b, m;
std::vector<p> v;

int main() {
	scanf("%*d");
	while (~scanf("%d%d", &a, &b))
		v.push_back(p{ a < b ? a : b, a < b ? b : a });
	sort(v.begin(), v.end());
	b = -1e9;
	for (p& x : v) {
		if (x.a < b) {
			if (b < x.b) {
				m += x.b - b;
				b = x.b;
			}
		}
		else m += (b = x.b) - x.a;
	}
	printf("%d", m);
}
