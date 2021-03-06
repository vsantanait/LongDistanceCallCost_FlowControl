#include <iostream>
#include <string>
using namespace std;

int main() {

	char continueProgram = 'Y'; //Y or N

	do {

		//INPUT #1
		//Day of Week (Two char Variable: Mo, Tu, We, Th. Fr, Sa, Su)
		char dayChar1 = ' ', dayChar2 = ' ';

		string callDay = ""; //callDay = dayChar1 + dayChar2;
		string callDayVal = ""; //Sunday, ... , Saturday
		bool monFri = false;
		bool invalidInput = false;


		//INPUT #2
		//Call Start Time (24-hour Notation: "00:00", "23:59")
		string callStartTime = "";


		//INPUT #3
		//Call Length (In Minutes, int Variable)
		int callLength = 0;
		double callRate = 0.0; // 0.40, 0.25, or 0.15

		//TWO DIGITS AFTER DICIMAL POINT
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);


		cout << "Welcome! This program computes the cost of a long distance call." << endl;
		cout << endl;

		//USER INPUT REQUEST
		cout << "Please enter the Day of the week the Long Distance" << endl;
		cout << "Call will take place (Mo: Monday, Tu: Tuesday, etc.): ";
		cin >> dayChar1 >> dayChar2;
		cout << endl;

		cout << "Please enter the time when the call will start"
			 << " (In 24-hour Notation. For ex. 2:00PM is 14:00, 12:30AM is 00:30): ";
		cin >> callStartTime;
		cout << endl;

		cout << "Please enter what the length of the call will be "
			 << "(in minutes) to the nearest integer value: ";
		cin >> callLength;
		cout << endl;


		
		//COMPUTE DAY OF WEEK
		callDay = string() + dayChar1 + dayChar2;
		if (callDay == "Su" || callDay == "SU" || callDay == "su" || callDay == "sU")
		{
			callDayVal = "Sunday";

		}
		else if (callDay == "Mo" || callDay == "MO" || callDay == "mo" || callDay == "mO")
		{
			callDayVal = "Monday";
			monFri = true;
		}
		else if (callDay == "Tu" || callDay == "TU" || callDay == "tu" || callDay == "tU")
		{
			callDayVal = "Tuesday";
			monFri = true;
		}
		else if (callDay == "We" || callDay == "WE" || callDay == "we" || callDay == "wE")
		{
			callDayVal = "Wednesday";
			monFri = true;
		}
		else if (callDay == "Th" || callDay == "TH" || callDay == "th" || callDay == "tH")
		{
			callDayVal = "Thursday";
			monFri = true;
		}
		else if (callDay == "Fr" || callDay == "FR" || callDay == "fr" || callDay == "fR")
		{
			callDayVal = "Friday";
			monFri = true;
		}
		else if (callDay == "Sa" || callDay == "SA" || callDay == "sa" || callDay == "sA")
		{
			callDayVal = "Saturday";
		}
		else {

			invalidInput = true;
			cout << "ERROR! You've entered " << callDay << ", which is an invalid day for Call Day of the Week." << endl;
			cout << endl;

		}

		

		//COMPUTE TIME OF DAY
		int colPos = callStartTime.find(":");

		if (colPos >= 0) {
		
			string houString = callStartTime.substr(0, colPos);
			string minString = callStartTime.substr(colPos + 1, 2); //ADD 1 to colPos, or it will include :

			//string to int 
			int houInt = std::stoi(houString);
			int minInt = std::stoi(minString);

			if ((houInt >= 0 && houInt <= 23) && (houString.length() > 0 && houString.length() <= 2)) {
				if ((minInt >= 0) && (minInt <= 59) && (minString.length() == 2)) {

					//24 to 12 hour - START
					string time = "";
					switch (houInt)
					{
					case 0:
						time = string() + "12:" + minString + "AM";
						break;
					case 1:
						time = string() + "1:" + minString + "AM";
						break;
					case 2:
						time = string() + "2:" + minString + "AM";
						break;
					case 3:
						time = string() + "3:" + minString + "AM";
						break;
					case 4:
						time = string() + "4:" + minString + "AM";
						break;
					case 5:
						time = string() + "5:" + minString + "AM";
						break;
					case 6:
						time = string() + "6:" + minString + "AM";
						break;
					case 7:
						time = string() + "7:" + minString + "AM";
						break;
					case 8:
						time = string() + "8:" + minString + "AM";
						break;
					case 9:
						time = string() + "9:" + minString + "AM";
						break;
					case 10:
						time = string() + "10:" + minString + "AM";
						break;
					case 11:
						time = string() + "11:" + minString + "AM";
						break;
					case 12:
						time = string() + "12:" + minString + "PM";
						break;
					case 13:
						time = string() + "1:" + minString + "PM";
						break;
					case 14:
						time = string() + "2:" + minString + "PM";
						break;
					case 15:
						time = string() + "3:" + minString + "PM";
						break;
					case 16:
						time = string() + "4:" + minString + "PM";
						break;
					case 17:
						time = string() + "5:" + minString + "PM";
						break;
					case 18:
						time = string() + "6:" + minString + "PM";
						break;
					case 19:
						time = string() + "7:" + minString + "PM";
						break;
					case 20:
						time = string() + "8:" + minString + "PM";
						break;
					case 21:
						time = string() + "9:" + minString + "PM";
						break;
					case 22:
						time = string() + "10:" + minString + "PM";
						break;
					case 23:
						time = string() + "11:" + minString + "PM";
						break;
					case 24:
						time = string() + "12:" + minString + "AM";
						break;
					}
					//24 to 12 hour - END


						//Call Start Time between 8A - 6P
					if (((houInt >= 8) && (houInt <= 17) || (houInt == 18 && minInt == 0)) && (monFri)) {

						cout << "The call start time is between 8AM and 6PM." << endl;
						callRate = 0.40;

					}
					//Call Start Time before 8A or after 6P
					else if ((((houInt < 8) && (houInt >= 0)) || ((houInt >= 18) && (houInt < 24))) && (monFri)) {

						cout << "The call start time is before 8AM and after 6PM." << endl;
						callRate = 0.25;

					}
					else if (callDayVal == "Saturday" || callDayVal == "Sunday") {

						cout << "The call was made on a Saturday or on a Sunday." << endl;
						callRate = 0.15;

					}

				}
				else {

					invalidInput = true; //VARIABLE houInt and/or minInt is not valid
					cout << "ERROR! You've entered " << callStartTime << ", which is an invalid Call Start Time." << endl;
					cout << endl;

				}
			}
			else {

				invalidInput = true; //VARIABLE houInt and/or minInt is not valid
				cout << "ERROR! You've entered " << callStartTime << ", which is an invalid Call Start Time." << endl;
				cout << endl;

			}
		
		}
		else {

			invalidInput = true; //VARIABLE houInt and/or minInt is not valid
			cout << "ERROR! You've entered " << callStartTime << ", which is an invalid Call Start Time." << endl;
			cout << endl;

		}
		


		//COMPUTE CALL TIME
		double callCost = 0.0;

		//may need to move this after the callLength cin statement
		if (cin.fail()) {

		invalidInput = true; //VARIABLE callLength is not valid
		cout << "ERROR! You've entered " << callLength << ", which is an invalid Call Length int value." << endl;
		cin.clear();
		cout << endl;

		}
		else {

		callCost = callRate * callLength;
		//cout << "callCost = callRate * callLength = " << callRate << " * " << callLength << " = " << callCost << endl;
		cout << endl;

		}



		//OUTPUT
		if (!invalidInput) {

			cout << "The cost of a call that you make on a " << callDayVal << ", starting at" << endl;
			cout << callStartTime << ", for a duration of " << callLength << " minutes is" << endl;
			cout << "$" << callCost << " dollars." << endl;
			cout << endl;

			cout << "Would you like to know the value of another long distance call?" << endl;
			cout << "Please enter Y for Yes, or N for No." << endl;
			cin >> continueProgram;
			cout << endl;

		}
		else {

			cout << "You entered an invalid input." << endl;

			cout << "Would you like to know the value of another long distance call?" << endl;
			cout << "Please enter Y for Yes, or N for No." << endl;
			cin >> continueProgram;
			cout << endl;

		}


	} while ((continueProgram == 'Y') || (continueProgram == 'y'));
	

	return 0;

}