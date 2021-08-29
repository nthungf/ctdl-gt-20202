/*
 * Cho xâu ký tự S bao gồm các ký tự in hoa khác nhau.
 * Hãy đưa ra tất cả các hoán vị của xâu ký tự S.
 * Ví dụ S=”ABC” ta có kết quả {ABC ACB BAC BCA CAB CBA}.
 */

#include <bits/stdc++.h>
using namespace std;

int check = 0;

void output(string a) {
	for (int i = 1; i < a.size(); i++) {
		cout << a[i];
	}
	cout << " ";
}

void reverse(string &a, int x, int y) {
	while (x < y) {
		swap(a[x++], a[y--]);
	}
}

void gen(string &a) {
	int n = a.size() - 1;
	int j = n - 1;
	while (a[j] >= a[j + 1])
		j--;
	if (j > 0) {
		int k = j + 1;
		for (int i = j + 1; i <= n; i++) {
			if (a[i] > a[j] && a[i] < a[k]) {
				k = i;
			}
		}
		swap(a[j], a[k]);
		reverse(a, j + 1, n);
	} else
		check = 1;
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		check = 0;
		string s;
		cin >> s;
		s.resize(s.size() + 1);
		for (int i = s.size() - 1; i > 0; --i) {
			s[i] = s[i - 1];
		}
		s[0] = '0';
		while (!check) {
			output(s);
			gen(s);
		}
		cout << "\n";
	}
	return 0;
}