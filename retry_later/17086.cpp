#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int N, M;
int area[50][50];

int dx[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
//BFS 탐색 함수
int recur(int r, int c)
{
	bool visited[50][50];
	memset(visited, false, sizeof(visited)); // 함수 안에서 memset 사용
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(r, c, 0));
	visited[r][c] = true;
	while (!q.empty())
	{
		int OGr = get<0>(q.front());
		int OGc = get<1>(q.front());
		int dist = get<2>(q.front());
		q.pop();
		if (area[OGr][OGc] == 1)
			return dist;

		for (int i = 0; i < 8; i++)
		{
			int nr = OGr + dx[i];
			int nc = OGc + dy[i];
			if (nr < 0 || nr >= N) continue; // 입력받은 그래프를 벗어나면 반복문으로 다시 돌아간다.
			if (nc < 0 || nc >= M) continue;
			if (visited[nr][nc]) continue;
			visited[nr][nc] = true;
			q.push(make_tuple(nr, nc, dist + 1));
		}
	}
	return -1;
}

void sol()
{
	int max_dist = -1;
	for(int y = 0; y< N; y++)
		for (int x = 0; x < M; x++)
		{
			if (area[y][x] != 1)
				max_dist = max(max_dist, recur(y, x));
		}
	cout << max_dist;
}
int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> area[i][j];
		}
	}
	sol();
}