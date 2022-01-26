using namespace std;
#include <iostream>


int main()
{
	int i;
       	int valsToSum[3];
	int sum = 0;
	for (i=0, i<3, i++)
	{
		cout << "Enter int #" << i+1 << ": ";
		cin >> valsToSum[i];
	}
	cout << valsToSum[0];
	for (i = 1; i<3, i++)
	{
		cout << " + " << valsToSum[i];
	}
	cout << " = ";
	for (i = 0; i<3; i++)
	{
		sum += valsToSum[i];
	}
	cout << sum << endl;
	return 0;

}
