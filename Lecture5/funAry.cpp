using namespace std;
#include <iostream>

int sumAry(
		int num, //# of elems in ary
		int ary[]  //array of vals to usm
	  )
{
	int sum = 0; 
	int i;

	for (i = 0; i < num; i++)
	{
		sum += ary[i];
	}
	return sum;
}

int main()
{
	int iary[5] = {3, 5, 7, 9, 11};
	int x;

	x = sumAry(5,iary);
	cout << "Sum: " << x <<endl;

	return 0;
}

