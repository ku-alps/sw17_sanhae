#include<ios>
int n, m;
int main() {
	scanf("%*d");
	while (~scanf("%d%d", &n, &m)) {
		while (m--)scanf("%*d%*d");
		printf("%d ", --n);
	}
}
