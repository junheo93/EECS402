using namespace std;
#include <iostream>

int main (){
	
	int count = 0;

	for (int i = 0; i < 30; i+=1){
		if(i % 7 != 0 && i % 3 != 0){
			count += i;

		}

	}
	return 0;
}

