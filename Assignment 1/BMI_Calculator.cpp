//===============================================================================
// Filename     : BMI_Calculator.cpp
// Authors      : Carlota Trigo La Blanca, Ignacio Novillo Calvo
// Version      : 0.1
// License      : -
// Description  : The program takes as input the values for the 
//                height and weight of the user and calculates the corresponding
//                BMI (Body Mass Index) value. Range of this value is also given
//                to the user
//===============================================================================


#include <iostream>
#include <cmath>

using namespace std;

/**
* Calculates BMI value using the weight and height provided as inputs
* 
* @param weight Value of the weight in kg (accepts decimals)
* @param height Value of the height in m (accepts decimals)
* 
* @returns BMI Final value calculated
* 
*/
float calculateBMI(float weight, float height) {
    return (weight / pow(height, 2));
}

/**
* Takes BMI value and input and calculates its corresponding range.
* 
* @param BMI Value calculated for the BMI
* 
*/
void evaluateAndPrintBMI(float BMI) {

    cout << "\nYour BMI is: " << BMI <<"\n";
    if (BMI< 18.5) {
        cout << "According to this value, your weight is considered as underweight.\n";
    }
    else if ((18.5 <= BMI) && (BMI < 25)) {
        cout << "According to this value, your weight is considered as normal.\n";
    }
    else if ((25 <= BMI) && (BMI < 30)) {
        cout << "According to this value, your weight is considered as overweight.\n";
    }
    else{
        cout << "According to this value, your weight is considered as obese.\n";
    }
}

/**
* Prints the information regarding the range values according to thetheDepartment of Health
* and Human Services/National Institutes of Health
* 
*/
void printInfo() {
    cout << "\n|| BMI VALUES: \n";
    cout << "||    Underweight: less than 18.5\n";
    cout << "||    Normal : between 18.5 and 24.9\n";
    cout << "||    Overweight: between 25 and 29.9\n";
    cout << "||    Obese: 30 or greater\n";
}

int main() {

    float weight, height, BMI;                              // Initialization of variables

    cout <<"Please input your weight (in kg): ";
    cin >> weight;                                     // Weight input
    cout << "Please input your height (in m): ";
    cin >> height;                                     // Height input

    BMI = calculateBMI(weight, height);                     // BMI is obtained, and the remaining functions are called
    evaluateAndPrintBMI(BMI);
    printInfo();

    return 0;
 }

