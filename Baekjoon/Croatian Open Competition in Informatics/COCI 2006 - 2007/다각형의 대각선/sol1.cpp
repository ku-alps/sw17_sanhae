//https://www.acmicpc.net/problem/3049

#include<ios>
int n, i = 1, s;
int main() {
	scanf("%d", &n);
	for (; i < n - 2; i++)
        s += i * (n - 2 - i) * (n - 1 - i);
	printf("%d", s / 2);
}
