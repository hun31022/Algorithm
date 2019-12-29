#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
using namespace std;
int T, N;

int main(){
	cin >> T;
	cin.ignore();
	for (int i = 0; i < T; i++){
		string input;
		getline(cin, input);
		if (input.size() != 7){//문자열 길이가 7이 아니면 0 출력
			printf("0\n");
		}
		else{
			if (input[0] == input[1] && input[1] != input[2] && input[2] == input[3] && input[3] != input[4] && input[4] != input[5] && input[5] == input[6]){
				printf("1\n");
			}//커맨드 형식이 맞다면 1출력
			else{
				printf("0\n");
			}
		}
	}
}