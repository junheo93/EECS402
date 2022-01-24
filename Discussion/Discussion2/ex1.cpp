using namespace std;
#include <iostream>

int main(){
	int count = 0;
	int MAX_NUM = 30;
	for(int i = 1; i < MAX_NUM; i+= 2) {
		count += i;
		cout << count << endl;

	}
	return 0;
}
