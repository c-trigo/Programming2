/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

float evaluateAndPrintBMI(float BMI) {
    if (18.5 > BMI) {
    cout << "You are underweight"<<endl;
    } else if (BMI > 18.5 && BMI<24.9) {
    cout << "Your weight is normal"<<endl;
    } else if (BMI > 24.9 && BMI<30) {
    cout << "You are overweight"<<endl;
    }else if (BMI >= 30) {
    cout << "You are obese" <<endl;
    }
}

string printInfo() {
    cout << "\tBMI VALUES: \n";
    cout << "Underweight\t less than 18.5 \n";
    cout << "Normal\t\t between 18.5 and 24.9 \n";
    cout << "Overweight\t between 24.9 and 30 \n";
    cout << "Obese\t\t greater or equal than 30 \n\n";
}

int main()
{
// Display information: 
    printInfo();
    
// Input BW, Height and BMI 
float BW, Height, BMI;
cout << "What is your weight (Kg)? ";
cin >> BW; // Introduce BW
cout << "What is your height (m)? ";
cin >> Height; // Introduce Height
cout << "Your weight is " << BW << "Kg and Your height is "<< Height << "m\n\n";
BMI = BW/(Height*Height);
cout << "Computed BMI is: " << BMI << "\n"; // Output BMI

cout << evaluateAndPrintBMI(BMI);
}
