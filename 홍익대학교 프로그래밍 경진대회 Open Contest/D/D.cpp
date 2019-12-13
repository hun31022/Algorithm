#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>

using namespace std;


string S;
int N, X;
int main(){
	cin >> N >> X;
	if (26 * N < X || X<N){ // 예외 처리!
		cout << "!";
		return 0;
	}
	else{
		for (int i = 0; i < N; i++){//A로 초기화 해준다
			S.push_back('A');
		}
		X -= N;//A로 초기화 했기 때문에 (A==1)*N만큼 X에서 빼준다
		int idx = N - 1;//사전순으로 출력해야하므로 뒤에서 부터 찾는다 
		while (1){
			if (idx == -1){
				break;
			}
			if (X - 25 >0){//A+25=Z이므로 25를 빼줬을때 0보다 크다면
				S[idx] = 'Z';//Z로 바꿔준다 
				X -= 25;
			}
			else{//26보다 작다면!
				S[idx] = 'A' + X;//A에서 그 수 만큼 더 한 알파벳으로
				break;
			}
			idx--;
		}
		cout << S;
	}
}