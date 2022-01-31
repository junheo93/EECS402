using namespace std;
#include <iostream>

void printMenu();

double toThePower(const double val, const int power);

bool evaluateCubicFormula(const double aCoeff, const double bCoeff,
	       	const double cCoeff, const double dCoeff,
	       	const double xValue, double &resultVal);

double approximateAreaWithRectangles(const double aCoeff, const double bCoeff,
	       	const double cCoeff, const double dCoeff,
	       	const double startX, const double endX, const int numRects);



#ifdef ANDREW_TEST
#include "andrewTest.h"
#else

int optionNum;

int main()
{
	printMenu();
	optionNum = 0;
	const int APPROXIMATE_INTEGRAL_OPTION = 1;
	const int EXPERIMENT_OPTION = 2;
	const int QUIT_OPTION = 3;
       	const int numCoeff = 4; // a,b,c,d
	const int numRange = 2; // xStart, xEnd
	double Coeff[numCoeff];
	double xRange[numRange];
	int numRect;
	double correctAns;
	double precisionToReach;
	double estimatedAns;
	double err;
	int rectNeeded;
	const int MAX_RECT = 100;
	
	while (optionNum != QUIT_OPTION)
	{
		cout << "YOUR CHOICE: ";
		cin >> optionNum;
		if (optionNum == APPROXIMATE_INTEGRAL_OPTION)
		{
			cout << "Enter (a b c d) for function y = a*x^3 + b*x^2 + c*x + d: ";
			cin >> Coeff[0] >> Coeff[1] >> Coeff[2] >> Coeff[3];

			cout << "Now enter x start and end values: ";
			cin >> xRange[0] >> xRange[1];
			
			cout << "Enter the number of rectangles to use: ";
			cin >> numRect;
			cout << endl;
		

			cout << "Rectangle result is: "
			     << approximateAreaWithRectangles(Coeff[0],Coeff[1],Coeff[2],Coeff[3],xRange[0],xRange[1],numRect) << endl;
			

		}
		else if (optionNum == EXPERIMENT_OPTION)
		{
			cout << "Enter (a b c d) for function y = a*x^3 + b*x^2 + c*x + d: ";
			cin >> Coeff[0] >> Coeff[1] >> Coeff[2] >> Coeff[3];

			cout << "Now enter x start and end values: ";
			cin >> xRange[0] >> xRange[1];

			cout << "Enter correct answer: ";
			cin >> correctAns;

			cout << "Enter Precision to reach: ";
			cin >> precisionToReach;



			err = 10; // arbitrary big number
			rectNeeded = 1;
			while (rectNeeded <= MAX_RECT && toThePower(err,2) <= toThePower(precisionToReach,2))
			{
				estimatedAns = approximateAreaWithRectangles(Coeff[0],Coeff[1],Coeff[2],Coeff[3],
					       	xRange[0], xRange[1], rectNeeded);
				err = estimatedAns - correctAns;

				rectNeeded++;

			}
			

			cout << "Rectangles needed to reach precision: "
				<< rectNeeded << endl;
			

		
		}
	}

	cout << "Thanks for using this program" << endl;	
	
	return 0;
}
#endif

void printMenu()
{
	cout << "1 Approximate Integral Using Rectangles" << endl;
	cout <<	"2 Experiment With Rectangle Precision" << endl;
	cout <<	"3 Quit The Program" << endl;
}

double toThePower(const double val, const int power)
{
	double poweredVal = 1;
	int i;
	for (i = 1; i <= power; i++)
	{
		poweredVal *= val;
	}

	return poweredVal;
}

bool evaluateCubicFormula(const double aCoeff, const double bCoeff,
		const double cCoeff, const double dCoeff,
		const double xValue, double &resultVal)
{
	resultVal = aCoeff*toThePower(xValue,3) + bCoeff*toThePower(xValue,2)+
		cCoeff*xValue + dCoeff;
	
	return resultVal >= 0;

}

double approximateAreaWithRectangles(const double aCoeff, const double bCoeff,
		const double cCoeff, const double dCoeff, const double startX,
		const double endX, const int numRects)
{
	double rectWidth;
	rectWidth = (endX-startX)/numRects;
	int i;
	//double startInLoop;
	double midPointInLoop;
	double recSum;
	double heightInLoop;
	double resultVal;
	recSum = 0; // initialization

	for (i = 1; i <= numRects; i++)
	{
		//startInLoop = startX + (i - 1)*rectWidth;
		midPointInLoop = startX + (i - 0.5)*rectWidth;
		heightInLoop = aCoeff*toThePower(midPointInLoop,3) + bCoeff*toThePower(midPointInLoop,2)+
			cCoeff*midPointInLoop + dCoeff;
		if (evaluateCubicFormula(aCoeff, bCoeff, cCoeff, dCoeff, midPointInLoop, resultVal))
		{
			recSum += heightInLoop*rectWidth;
		}
		else
		{
			recSum -= heightInLoop*rectWidth;
		}
	}

	return recSum;

}

