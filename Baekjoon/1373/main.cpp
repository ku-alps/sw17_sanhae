#include<ios>
int x, c = 2, a[1000003];
int main() {
	while (~scanf("%1d", a + c++));
	for (x = --c % 3; x < c; x += 3)
		printf("%d", a[x + 2] + 2 * a[x + 1] + 4 * a[x]);
}
