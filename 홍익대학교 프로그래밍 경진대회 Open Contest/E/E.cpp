#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>

using namespace std;

bool cmp(int p1, int p2){
	return p1 > p2;
}
int map[1024][1024];
int N;
int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
	while (1){
		int raro=0, saro=0;//2*2 ���� �� map�� ���� �� ��ġ ���� 
		for (int i = 0; i < N; i+=2){
			raro = 0;
			for (int j = 0; j < N; j+=2){
				vector<int> V;//2*2�� ���Ϳ� �־��ְ� 
				V.push_back(map[i][j]);
				V.push_back(map[i+1][j]);
				V.push_back(map[i][j+1]);
				V.push_back(map[i+1][j+1]);
				sort(V.begin(), V.end(),cmp);//������������ ���� �� 
				map[saro][raro] = V[1];// 2��°�� ū �� ã�� �� map�� ����
				raro++;
			}
			saro++;
		}
		N /= 2;
		if (N == 1){ //N==1 �� �� ���
			cout << map[0][0];
			return 0;
		}
	}
}