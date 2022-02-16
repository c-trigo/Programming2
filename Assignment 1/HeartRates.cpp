//===============================================================================
// Filename     : HeartRates.cpp
// Authors      : Carlota Trigo La Blanca, Ignacio Novillo Calvo
// Version      : 0.1
// License      : -
// Description  : The program requests as input the relevant subject's data to 
//                obtain information about the maximum and target heart rates
//                expected according the subject's age
//===============================================================================

#include <iostream>
#include <ctime>
#include <tuple>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

/**
*
* Class Human defines all the necessary information to define
* the heart rate values
*
*/
class Human {

public:

	string firstName, lastName;		   //Date of Birth
	int day, month, year;			   //Subject's Name

	/**
	*
	* Constructor function for Class Human
	*
	* @param inp_name First Name
	* @param inp_last Last Name
	* @param DoB Day of Birth
	* @param MoB Mont of Birth
	* @param YoB Year of Birth
	*
	*/
	Human(string fN, string lN, int DoB, int MoB, int YoB) {
		firstName = fN;
		lastName = lN;
		day = DoB;
		month = MoB;
		year = YoB;
	}

	/**
	  * Change the subject's full name
	  *
	  * @param inp_last Input First Name
	  * @param inp_last Input Last Name
	  *
	  */
	void setName(string fN, string lN) {
		firstName = fN;
		lastName = lN;
	}

	/**
	* Get the subject's full name
	*
	* @returns Full name (first name + last name)
	*
	*/
	string getName() {
		return firstName + " " + lastName;
	}

	/**
	* Change the subject's full date of birth (day, month and year)
	*
	* @param DoB Day of Birth
	* @param MoB Month of Birth
	* @param YoB Year of Birth
	*
	*/
	void setDateOfBirth(int DoB, int MoB, int YoB) {

		if (DoB < 1 || DoB > 31) {
			cout << "Please input a valid day of birth\n";
			exit(0);
		}
		if (MoB < 1 || DoB > 12) {
			cout << "Please input a valid month of birth\n";
			exit(0);
		}

		day = DoB;
		month = MoB;
		year = YoB;

	}

	/**
	*
	* Get only the day of birth
	*
	* @returns day Day of Birth
	*
	*/
	int getDayOfBirth() {
		return day;
	}

	/**
	*
	* Get only the month of birth
	*
	* @returns month Month of Birth
	*
	*/
	int getMonthOfBirth() {
		return month;
	}

	/**
	*
	* Get only the year of birth
	*
	* @returns year Year of Birth
	*
	*/
	int getYearOfBirth() {
		return year;
	}

	/**
	*
	* Get the full date of birth
	*
	* @returns Tuple containing the day, month and year of birth
	*
	*/
	tuple<int, int, int> getBirthDate() {
		return { day, month, year };
	}

	/**
	*
	* Calculates the age of the subject with respect to the current date
	*
	* @returns age Age calculated
	*
	*/
	int getAge() {

		int age, currentDay, currentMonth, currentYear, dayDiff;

		time_t now = time(0);
		tm* ltm = localtime(&now);
		currentYear = 1900 + ltm->tm_year;
		currentMonth = 1 + ltm->tm_mon;
		currentDay = ltm->tm_mday;

		dayDiff = (currentYear - year) * 365 + (currentMonth - month) * 31 + (currentDay - day);
		age = dayDiff / 365;

		return age;
	}


};

/**
*
* Calculates the maximum heart rate according to the age provided
*
* @param human Subject to obtain the calculation for
*
* @returns Maximum Heart Rate
*
*/
int calculateMaximumHeartRate(Human human) {
	return 220 - human.getAge();
}

/**
*
* Calculates the target heart rates for the age provided
*
* @param human Subject to obtain the calculation for
*
* @returns Tuple with Minimum Target Heart Rate and Maximum Target Heart Rate
*
*/
tuple<int, int> calculateTargetHeartRates(Human human) {
	int maxHeartRate = calculateMaximumHeartRate(human);
	return { 0.5 * maxHeartRate, 0.85 * maxHeartRate };
}

int main() {

	string firstName, lastName;
	int dayOfBirth, monthOfBirth, yearOfBirth;

	// Input data about the subject

	cout << "Please introduce the subject's first name: \n";
	cin >> firstName;
	cout << "Please introduce the subject's last name: \n";
	cin >> lastName;
	cout << "Please introduce the subject's birth-day (DD): \n";
	cin >> dayOfBirth;
	cout << "Please introduce the subject's birth-month (MM): \n";
	cin >> monthOfBirth;
	cout << "Please introduce the subject's birth-year (YYYY): \n";
	cin >> yearOfBirth;

	// Define the object containing the subject's data

	Human human = Human(firstName, lastName, dayOfBirth, monthOfBirth, yearOfBirth);

	// Print out results

	cout << "\n|| SUBJECT'S DATA \n";
	cout << "|| Name			: " << human.getName() << " \n";
	cout << "|| Date of Birth	: " << human.getDayOfBirth() << "-" << human.getMonthOfBirth() << "-" << human.getYearOfBirth() << "\n";
	cout << "|| Age				: " << human.getAge() << "\n";
	cout << "|| Maximum HR		: " << calculateMaximumHeartRate(human) << "\n";

	// HR computations

	int maxHeartRate, minHeartRate;
	tie(minHeartRate, maxHeartRate) = calculateTargetHeartRates(human);

	cout << "|| Target HR		: " << minHeartRate << "-" << maxHeartRate << "\n";
}