#include "Vehicle.h"
#include <iostream>
using namespace std;
int main()
{
	VehicleSurrogate v[10];
	Bus b;
	v[1] = b;
	v[2] = v[1];
	system("pause");
	return 0;
}