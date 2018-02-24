#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
	long x, y;
	cin >> x >> y;
	x += y;
	if (x < 0) {
		cout << '-';
		x = -x;
	}
	string s = to_string(x);
	string::iterator itstr = s.end() - 1;
	for (int k = 1; itstr > s.begin(); itstr--, k++) {
		if (k % 3 == 0) {
			itstr = s.insert(itstr, ',');
		}
	}
	cout << s;
	return 0;
}
