#include<iostream>
#include<string>
using namespace std;
int n, m;
bool af[8];

void f(int k, string s) {
	if (k++ == m) cout << s << '\n';
	for (int i = 0; i < n; i++) {
		if (!af[i]) {
			af[i] = 1;
			f(k, s + to_string(i + 1) + " ");
			af[i] = 0;
		}
	}
}

int main(){
	cin >> n >> m;
	f(0, "");
}
