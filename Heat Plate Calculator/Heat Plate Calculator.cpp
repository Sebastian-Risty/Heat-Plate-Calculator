/**************************************************
  Name: Sebastian Risty
  Date: 9/15/2020
  Program name: HW2.cpp
  Program description: Calculate the average temperature
                        of various heat plates.
**************************************************/

#include <iostream>
#include <cmath>
using namespace std;

//calculate temperature at x,y coordinate for certain plate dimension
double getTemp(double x, double y, double length, double height) {
    double pi = 2 * acos(0);
    return 100 + (100 * sin(pi * (x * length / 999) / length) * sinh(pi * (y * height / 999) / length)) / sinh((pi * height) / length);
}

//calculate average temperature of all collected points for certain plate dimension
double getAverageTemp(double length, double height) {
    double tempAverage = 0;
    for (int x = 0; x <= 999; x++) {
        for (int y = 0; y <= 999; y++) {
            tempAverage += getTemp(x, y, length, height);
        }
    }
    return tempAverage / 1000000;
}

int main() {
    double largestAverageTemp = 0;
    double lengthOfHighestPlate = 0;
    double heightOfHighestPlate = 0;
    //get average temperature for each plate size
    for (int l = 1; l <= 6; ++l) {
        for (int h = 1; h <= 6; ++h) {
            double averageTemp = getAverageTemp(l, h);
            //if plate has highest avarage temp so far store plate information for later
            if (averageTemp > largestAverageTemp) {
                largestAverageTemp = averageTemp;
                lengthOfHighestPlate = l;
                heightOfHighestPlate = h;
            }
            //display plate dimension and it's average temperature
            cout << l << "x" << h << ": " << averageTemp << endl;
        }
    }
    //display the plate with the largest average temperature
    cout << "Largest average temperature plate: " << lengthOfHighestPlate << "x" << heightOfHighestPlate << " @ " << largestAverageTemp << "°C" << endl;
    return 0;
}