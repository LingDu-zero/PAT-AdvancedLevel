#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100];
int marked[100] = { 0 };
int level[100] = { 0 };
int maxlevel = -1;

void bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int id = q.front();
		q.pop();
		maxlevel = max(maxlevel, level[id]);
		if (adj[id].size() == 0) {
			marked[level[id]]++;
		}
		for (int i = 0; i < adj[id].size(); i++) {
			q.push(adj[id][i]);
			level[adj[id][i]] = level[id] + 1;
		}
	}
}

int main(void)
{
	int N, M, id, k;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> id >> k;
		while (k--) {
			cin >> temp;
			adj[id].push_back(temp);
		}
	}
	bfs();
	cout << marked[0];
	for (int i = 1; i <= maxlevel; i++)
		cout << " " << marked[i];
	cout << endl;

	return 0;
}
