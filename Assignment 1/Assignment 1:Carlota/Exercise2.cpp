/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

// classes example
#include <iostream>
#include <ctime>
#include <sstream>
#include <vector>
using namespace std;

class Human {
    int Day, Month, Year;
    string Name, LastName; 
  public:
    void setName(string inp_name) {
        Name = inp_name;
    }
    void setLastName(string inp_last) {
        LastName = inp_last;
    }
    string getFullName() {
        // Name 'space' LastName
        return Name +" "+ LastName;
    }
    void setDay(int inp_day) {
        if (inp_day>31 || inp_day<1) {
            // In the case that a non proper day has been introduced: 
            while (inp_day>31 || inp_day<1){
                cout << "Not possible. Your birth-day should be a number between 1 and 31: ";
                cin >> inp_day;
                Day = inp_day;
            };
        } else  {
         Day = inp_day;
        }
    }
    void setMonth(int inp_month) {
        // In the case that a non proper month has been introduced: 
        if (inp_month>12 || inp_month<1){
            while (inp_month>12 || inp_month<1){
                cout << "Not possible. Months should be a number between 1 and 12: ";
                cin >> inp_month;
                Month = inp_month;
            };
        } else  {
         Month = inp_month;
        }
    }
    void setYear(int inp_year) {
         Year = inp_year;
    }
    string getBirthday() {
        // Day - Month - Year
        return to_string(Day) +"-"+ to_string(Month) +"-"+to_string(Year);
    }
    int getAge(){
        int days_alive; 
        // Obtain todays date: 
        time_t now = time(0);
        tm *ltm = localtime(&now);  
        int currentYear=1900 + ltm->tm_year;
        int currentMonth=1 + ltm->tm_mon;
        int currentDate=ltm->tm_mday;
        // How many days has the person been alive? 
        days_alive = abs(currentDate - Day) + 30*abs(currentMonth - Month) + 365*abs(currentYear - Year); 
        // total days / (365 day/year) = total years
        int tot_year = days_alive/365; 
        if (Month>currentMonth){
            tot_year=tot_year-1; // This kind of people have not celebrated their Bday yet
        };
    return tot_year;
    }
};

int calculateMaximumHeartRate(float years) {
    int maxHR = 220 - years; // Apply formula
    return maxHR;
} 

float calculateTargetHeartRates(int maxHR, float *lowHR, float *upHR) {
    // Apply formula
    *lowHR=0.5*maxHR; 
    *upHR=0.85*maxHR; 
    return 0; 
}

int main () {
    Human person;
    string inp_name, inp_last, FullName, Birthday; 
    float lowHR, upHR; 
    int Age, maxHR; 
    int inp_day, inp_month, inp_year;
    // Alternatively: 
    /*person.setName("Juan"); 
    person.setLastName("Gonzalez"); 
    person.setDay(11); 
    person.setMonth(11); 
    person.setYear(2000); */

    // Input data about the person
    // Name: 
    cout << "What is your name? ";
    cin >> inp_name; // Introduce Name
    person.setName(inp_name);
    // Last Name
    cout << "What is your last name? ";
    cin >> inp_last; // Introduce Last Name
    person.setLastName(inp_last);
    // Day of birth
    cout << "What is your birth-day? ";
    cin >> inp_day; // Introduce Birth Day
    person.setDay(inp_day);
    // Month of birth
    cout << "What is your birth-month? ";
    cin >> inp_month; // Introduce Birth Month
    person.setMonth(inp_month);
    // Year of birth
    cout << "What is your birth-year? ";
    cin >> inp_year; // Introduce Birth Year
    person.setYear(inp_year);

    // Use the get functions
    FullName = person.getFullName(); // Obtain full name: first name + last name
    Birthday = person.getBirthday(); // Obtain birthday: day - month - year
    Age = person.getAge(); // Compute Age in years
    
    // HR computations
    maxHR = calculateMaximumHeartRate(Age); // Compute HR
    calculateTargetHeartRates(maxHR, &lowHR, &upHR); // Compute target HR range. 
    
    // Print out results
    cout << "\n\tHUMAN DATA: "<<endl;
    cout << "Full Name: "<<FullName<<endl; 
    
    cout << "Birthday: "<<Birthday<<endl; 

    cout << "Age in years: "<<Age <<endl;
    
    cout << "Maximum Heart Rate: "<<maxHR <<endl;
    
    cout << "Target Heart Rate: "<< lowHR << "-" << upHR  <<endl;
}
