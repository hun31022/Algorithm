#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

long long int check[100001];//다익스트라, 도로의 길이C의 최대거리가 100,000이고 도시의 수 N의 최대가 100,000이므로 long long int
int N, M, K;
//도시 U에서 V로 갈수 있는 도로, 도로길이 C
vector<pair<int,int>> U[100001];//first: V , second: C
queue<int> Q; 
void bfs(){
	while (Q.size()>0){
		int num = Q.front();//도시 U의 번호
		Q.pop();
		for (int i = 0; i < U[num].size(); i++){//U와 연결된 V가 있다면
			if (check[U[num][i].first] == -1){//방문되지 않은곳은 바로 push
				check[U[num][i].first] = check[num] + U[num][i].second;
				Q.push(U[num][i].first);
			}
			else if (check[U[num][i].first] > -1 && check[U[num][i].first] > (check[num] + U[num][i].second)){
				check[U[num][i].first] = check[num] + U[num][i].second;
				Q.push(U[num][i].first);
			}
		}
	}
}
int main(){
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++){//-1로 초기화
		check[i] = -1;
	}
	for (int i = 0; i < M; i++){
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);//입력 횟수가 많으므로 scanf로 입력
		//e-> s로 역방향 그래프 설정;
		U[e].push_back(make_pair(s, c));
	}

	for (int i = 0; i < K; i++){
		int start;
		scanf("%d", &start);//면접장에서부터 탐색 시작
		Q.push(start);
		check[start] = 0;
		bfs();
	}
	long long int MAX = 0;
	int idx = N;
	for (int i = N;i>=1; i--){//거리가 가장 먼 거리를 구하고 
		if (check[i] >= MAX){//그런 도시가 여러 곳이면 가장 작은 번호로 출력
			idx = i;
			MAX = check[i];
		}
	}
	cout << idx<<"\n";
	cout << MAX;
}