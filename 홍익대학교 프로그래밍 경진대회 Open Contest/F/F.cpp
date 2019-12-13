#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<math.h>
using namespace std;

int T;
char input[1000001];//최대 자리수를 구하기 위한 배열
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		int N;
		scanf("%d", &N);
		cin.ignore();//scanf에서 입력뒤에 엔터가 남아있어서 지워주기
		char temp[1000001];//최소 자리수를 구하기 위한 배열
		for (int i = 0; i < N; i++){
			scanf("%c", &input[i]);
			temp[i] = input[i];
		}
		for (int i = 0; i < N; i++){//?가 있다면 이진수 모두 1로 채운 후 곱했을때 가장 큰 수가 나온다. 가장 작은 수는 0으로 채웠을 때 
			if (input[i] == '?'){
				input[i] = '1';//모두다 1로
				temp[i] = '0';//모두다 0으로
			}
		}
		int idx = 0;
		int MAX;
		int MIN;
		bool zero_check = false;
		bool check1 = false, check2 = false;//check1은 첫번째로 1이 나온 경우 체크, check2는 그 다음 1이 나온 경우 체크
		for (int i = 0; i < N; i++){//최대 자리수 부터
			if (input[i] - '0' == 1){
				if (check1 == false){
					check1 = true;
					idx = N - i-1;//1이 나온 위치를 저장 2진수이기 때문에 앞에서부터 N-i
					
				}
				else if (check1 == true && idx != 0){
					check2 = true;
				}
			}
		}
		if (check1 == true && check2 == true){//1이 두번 이상 나온 경우
			idx++;
		}
		else if (check1==false && check2==false){//모두 0으로 나온 경우 
			zero_check = true;
		}
		if (zero_check == true){//최대 자리수 구하기
			MAX = 1;
		}
		else{
			MAX = N + idx;
		}

		check1 = false, check2 = false;
		idx = 0;
		zero_check = false;
		for (int i = 0; i < N; i++){
			if (temp[i] - '0' == 1){
				if (check1 == false){
					check1 = true;
					idx = N - i - 1;
				}
				else if (check1 == true && idx != 0){
					check2 = true;
				}
			}
		}
		if (check1 == true && check2 == true){
			idx++;
		}
		else if (check1 == false && check2 == false){
			zero_check = true;
		}

		if (zero_check == true){//최소 자리수 구하기
			MIN = 1;
		}
		else{
			MIN = N + idx;
		}
		printf("%d %d\n", MAX, MIN);
	}
}