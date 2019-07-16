#include<iostream>
#include<string>
using namespace std;
int n, m;

void f(int k, int x, string s) {
	if (k++ == m) { cout << s << '\n'; return; }
	for (int i = x; i <= n; i++)
		f(k, i, s + to_string(i) + " ");
}

int main() {
	cin >> n >> m;
	f(0, 1, "");
}
