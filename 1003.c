#include <iostream>

using namespace std;
int road[502][502] = { 0 };
int team[502] = { 0 };
int marked[502] = { 0 };
int N, M, C1, C2;
int min_roads = 0;
int max_teams = 0;
int c = 0;

void dfs(int c1, int c2, int teams, int roads) {
	if (road[c1][c2] == 0 && c1 != c2)
		return;
	if (marked[c2] == 1)
		return;
	teams += team[c2];
	roads += road[c1][c2];
	if (roads > min_roads && min_roads != 0)
		return;
	marked[c2] = 1;
	if (c2 == C2) {
		if (min_roads == 0) {
			min_roads = roads;
			max_teams = teams;
			c = 1;
		}
		else {
			if (roads < min_roads) {
				min_roads = roads;
				max_teams = teams;
				c = 1;
			}
			else if (roads == min_roads) {
				c++;
				if (max_teams < teams)
					max_teams = teams;
			}
		}
		marked[c2] = 0;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (i == c2) continue;
		dfs(c2, i, teams, roads);
	}
	marked[c2] = 0;
	return;
}

int main(void)
{
	int teams = 0;
	int roads = 0;
	cin >> N >> M >> C1 >> C2;
	for (int i = 0; i < N; i++)
		cin >> team[i];
	for (int i = 0; i < M; i++) {
		int c1, c2, d;
		cin >> c1 >> c2 >> d;
		road[c1][c2] = road[c2][c1] = d;
	}
	if (C1 == C2)
		cout << 1 << " " << team[C1] << endl;
	else {
		dfs(C1, C1, teams, roads);
		cout << c << " " << max_teams << endl;
	}

	return 0;
}
