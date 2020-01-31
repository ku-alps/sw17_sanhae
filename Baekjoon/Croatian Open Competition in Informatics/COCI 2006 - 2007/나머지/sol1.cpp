// https://www.acmicpc.net/problem/3052

#include<ios>
int a[42], k, n;

int main() {
	while (~scanf("%d", k)) {
		if (!a[k %= 42]) n += a[k] = 1;
	}
	printf("%d", n);
}
