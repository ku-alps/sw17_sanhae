// https://www.acmicpc.net/problem/3053

#include<ios>
#include<math.h>
const double p = acos(-1.0);
int n;

int main() {
	scanf("%d", &n);
	printf("%f %f", n*n*p, 2.0*n*n);
}
