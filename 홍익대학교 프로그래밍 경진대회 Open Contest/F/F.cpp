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
char input[1000001];//�ִ� �ڸ����� ���ϱ� ���� �迭
int main(){
	cin >> T;
	for (int t = 0; t < T; t++){
		int N;
		scanf("%d", &N);
		cin.ignore();//scanf���� �Էµڿ� ���Ͱ� �����־ �����ֱ�
		char temp[1000001];//�ּ� �ڸ����� ���ϱ� ���� �迭
		for (int i = 0; i < N; i++){
			scanf("%c", &input[i]);
			temp[i] = input[i];
		}
		for (int i = 0; i < N; i++){//?�� �ִٸ� ������ ��� 1�� ä�� �� �������� ���� ū ���� ���´�. ���� ���� ���� 0���� ä���� �� 
			if (input[i] == '?'){
				input[i] = '1';//��δ� 1��
				temp[i] = '0';//��δ� 0����
			}
		}
		int idx = 0;
		int MAX;
		int MIN;
		bool zero_check = false;
		bool check1 = false, check2 = false;//check1�� ù��°�� 1�� ���� ��� üũ, check2�� �� ���� 1�� ���� ��� üũ
		for (int i = 0; i < N; i++){//�ִ� �ڸ��� ����
			if (input[i] - '0' == 1){
				if (check1 == false){
					check1 = true;
					idx = N - i-1;//1�� ���� ��ġ�� ���� 2�����̱� ������ �տ������� N-i
					
				}
				else if (check1 == true && idx != 0){
					check2 = true;
				}
			}
		}
		if (check1 == true && check2 == true){//1�� �ι� �̻� ���� ���
			idx++;
		}
		else if (check1==false && check2==false){//��� 0���� ���� ��� 
			zero_check = true;
		}
		if (zero_check == true){//�ִ� �ڸ��� ���ϱ�
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

		if (zero_check == true){//�ּ� �ڸ��� ���ϱ�
			MIN = 1;
		}
		else{
			MIN = N + idx;
		}
		printf("%d %d\n", MAX, MIN);
	}
}