#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

long long int check[100001];//���ͽ�Ʈ��, ������ ����C�� �ִ�Ÿ��� 100,000�̰� ������ �� N�� �ִ밡 100,000�̹Ƿ� long long int
int N, M, K;
//���� U���� V�� ���� �ִ� ����, ���α��� C
vector<pair<int,int>> U[100001];//first: V , second: C
queue<int> Q; 
void bfs(){
	while (Q.size()>0){
		int num = Q.front();//���� U�� ��ȣ
		Q.pop();
		for (int i = 0; i < U[num].size(); i++){//U�� ����� V�� �ִٸ�
			if (check[U[num][i].first] == -1){//�湮���� �������� �ٷ� push
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
	for (int i = 1; i <= N; i++){//-1�� �ʱ�ȭ
		check[i] = -1;
	}
	for (int i = 0; i < M; i++){
		int s, e, c;
		scanf("%d %d %d", &s, &e, &c);//�Է� Ƚ���� �����Ƿ� scanf�� �Է�
		//e-> s�� ������ �׷��� ����;
		U[e].push_back(make_pair(s, c));
	}

	for (int i = 0; i < K; i++){
		int start;
		scanf("%d", &start);//�����忡������ Ž�� ����
		Q.push(start);
		check[start] = 0;
		bfs();
	}
	long long int MAX = 0;
	int idx = N;
	for (int i = N;i>=1; i--){//�Ÿ��� ���� �� �Ÿ��� ���ϰ� 
		if (check[i] >= MAX){//�׷� ���ð� ���� ���̸� ���� ���� ��ȣ�� ���
			idx = i;
			MAX = check[i];
		}
	}
	cout << idx<<"\n";
	cout << MAX;
}