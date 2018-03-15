#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int M;
	string unlock, lock, in, out, id;
	string in_first = "23:59:59", out_last = "00:00:00";
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> id >> in >> out;
		if (in.compare(in_first) <= 0) {
			unlock = id;
			in_first = in;
		}
		if (out.compare(out_last) >= 0) {
			lock = id;
			out_last = out;
		}
	}
	cout << unlock << " " << lock << endl;

	return 0;
}
