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
	if (26 * N < X || X<N){ // ���� ó��!
		cout << "!";
		return 0;
	}
	else{
		for (int i = 0; i < N; i++){//A�� �ʱ�ȭ ���ش�
			S.push_back('A');
		}
		X -= N;//A�� �ʱ�ȭ �߱� ������ (A==1)*N��ŭ X���� ���ش�
		int idx = N - 1;//���������� ����ؾ��ϹǷ� �ڿ��� ���� ã�´� 
		while (1){
			if (idx == -1){
				break;
			}
			if (X - 25 >0){//A+25=Z�̹Ƿ� 25�� �������� 0���� ũ�ٸ�
				S[idx] = 'Z';//Z�� �ٲ��ش� 
				X -= 25;
			}
			else{//26���� �۴ٸ�!
				S[idx] = 'A' + X;//A���� �� �� ��ŭ �� �� ���ĺ�����
				break;
			}
			idx--;
		}
		cout << S;
	}
}