using namespace std;
#include <iostream>

int main(){
	const int SMALL = 10;
	const int LARGE = 30;

	int num = 22; 

	if(num <= SMALL){
		cout << "Number is small" << endl;
	} else if (num >= LARGE){
		cout << "Number is large" << endl;
	} else {
		cout << "Number is medium" << endl;
	}

	return 0;
	 

}
