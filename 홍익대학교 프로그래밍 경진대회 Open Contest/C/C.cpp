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
	if (V == N){//�δ����� ����Ʈ ��, ������ ��尡 �ڱ� �ڽ��� ����Ű�� ����Ŭ
		min_snail=true;
	}
	for (int i = 0; i < M; i++){
		int input;
		scanf("%d", &input);//������� �������� cin cout �ӵ��� ������. 
		if (input < N){
			printf("%d\n", arr[input]);
		}
		else{
			if (min_snail == true){
				printf("%d\n", arr[N-1]);
			}
			else{//��ⷯ ����
				int div = N - V + 1;
				int num = input - V+1;
				printf("%d\n", arr[(num%div) + (V - 1)]);
			}
		}
	}
}