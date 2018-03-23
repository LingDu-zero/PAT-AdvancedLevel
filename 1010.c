#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void)
{
	string n1, n2;
	int tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	long long a = 0, b = 0, k = 0;
	if (tag == 2) swap(n1, n2);
	int index = 0;
	while (!n1.empty()) {
		char temp = n1.back();
		if (temp >= 'a'&&temp <= 'z') a += (temp - 'a' + 10)*pow(radix, index);
		else a += (temp - '0')*pow(radix, index);
		n1.pop_back();
		index++;
	}

	char temp = 0;
	long long left = 0, right = a + 1;
	for (int i = 0; i < n2.length(); i++)
		if (temp < n2[i]) temp = n2[i];
	if (temp >= 'a'&&temp <= 'z') left = temp - 'a' + 11;
	else left = temp - '0' + 1;
	k = a + 2;
	while (left <= right) {
		b = 0;
		long long m = (left + right) / 2;
		index = 0;
		string s = n2;
		while (!s.empty()) {
			char c = s.back();
			if (c >= 'a'&&c <= 'z') b += (c - 'a' + 10)*pow(m, index);
			else b += (c - '0')*pow(m, index);
			s.pop_back();
			index++;
			if (b > a || b < 0) break;
		}
		if (b == a) {
			k = min(m, k);
			break;
		}
		else if (b > a || b < 0) right = m - 1;
		else if (b < a) left = m + 1;
	}
	if (k == a + 2) cout << "Impossible" << endl;
	else cout << k << endl;

	return 0;
}
