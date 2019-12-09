#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>

using namespace std;

int N, M, V;
int arr[200000];
bool min_snail=false;
int main(){
	cin >> N >> M >> V;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	if (V == N){//민달팽이 리스트 즉, 마지막 노드가 자기 자신을 가리키는 사이클
		min_snail=true;
	}
	for (int i = 0; i < M; i++){
		int input;
		scanf("%d", &input);//입출력이 많을때는 cin cout 속도가 느리다. 
		if (input < N){
			printf("%d\n", arr[input]);
		}
		else{
			if (min_snail == true){
				printf("%d\n", arr[N-1]);
			}
			else{//모듈러 연산
				int div = N - V + 1;
				int num = input - V+1;
				printf("%d\n", arr[(num%div) + (V - 1)]);
			}
		}
	}
}