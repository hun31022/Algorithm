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

int main(){
	cin >> N >> M >> V;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++){
		int input;
		scanf("%d", &input);
		if (input < N){
			printf("%d\n", arr[input]);
		}
	}
}