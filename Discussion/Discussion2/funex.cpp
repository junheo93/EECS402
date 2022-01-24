using namespace std;
#include <iostream>

int add_twenty(int input);

int main(){
	int number = 20;

	cout << number << endl;

	number = add_twenty(number);

	cout << number << endl;
	
	return 0;
}

int add_twenty(int input) {
	input += 20;
	return input;
}

