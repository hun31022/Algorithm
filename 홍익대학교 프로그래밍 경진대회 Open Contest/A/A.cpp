#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<string.h>

using namespace std;


string point[300];
int input[51];
string grade[7] = { "A+", "A0", "B+", "B0", "C+", "C0", "F" };
int main(){
	int N, hong;
	for (int i = 1; i <=50; i++){
		cin >> input[i];
		
		if (i <= 5)
			point[input[i]] = grade[0];
		else if (i >= 6 && i <= 15)
			point[input[i]] = grade[1];

		else if (i >= 16 && i <= 30)
			point[input[i]] = grade[2];

		else if (i >= 31 && i <= 35)
			point[input[i]] = grade[3];
		
		else if (i >= 36 && i <= 45)
			point[input[i]] = grade[4];
		
		else if (i>=46 && i<=48)
			point[input[i]] = grade[5];
		
		else if (i>=49 && i<=50)
			point[input[i]] = grade[6];
		
	}
	cin >> hong;
	cout << point[hong];
}