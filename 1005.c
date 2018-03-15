#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string s,x;
	string dic[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	cin >> s;
	int c = 0;
	for (int i = 0; i < s.length(); i++)
		c = c + s[i] - '0';
	x = to_string(c);
	cout << dic[x[0] - '0'];
	for (int i = 1; i < x.length(); i++)
		cout << " " << dic[x[i] - '0'];
	cout << endl;

	return 0;
}
