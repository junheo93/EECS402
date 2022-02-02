using namespace std;
#include <iostream>

class Cup
{
    private:
        int ounces;
        string color;

    public:
        void fill(int addedOunces)
        {
            ounces += addedOunces;
        }
        
        bool isEmpty();

};

int main()
{
    Cup soloCup;


    return 0;
}


