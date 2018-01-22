// COMP 151 - Grade Frequency
// Program that reads grades and returns the total number of grades
// on a category.
// @author: Pedro J. Navarrete
// V 1.00

#include <iostream>
#include <iomanip>

using namespace std;

const int MAXGRADES = 50;

typedef char GradeType[MAXGRADES]; // new data type for grades

void getGrades(GradeType, int&); // gets grades input
void printGrades(GradeType, int&); // prints the number of grades
int getFrequency(GradeType, int&, char); // gets the frequency of a letter


int main() {

	GradeType arrayOfGrades;
	int numOfGrades;

	getGrades(arrayOfGrades, numOfGrades);
	printGrades(arrayOfGrades, numOfGrades);

	return 0;
}

//*******************************************************************
//	getGrades														*
//	task:	This asks the user to input the number of grades.		*
//			It then asks the user to input those grades in			*
//			letter form. The data is placed in the arrayOfGrades	*
//*******************************************************************
void getGrades(GradeType arrayOfGrades, int& numOfGrades) {
	cout << "Please input the number of grades to be read in. (1 - " << MAXGRADES << ")\n";
	cin >> numOfGrades;

	cout << "\nAll grades must be upper case A B C D or F\n";

	for (size_t i = 0; i < numOfGrades; i++)
	{
		cout << "Input a grade\n";
		cin >> arrayOfGrades[i];
		if (arrayOfGrades[i] != 'A' &&
			arrayOfGrades[i] != 'B' &&
			arrayOfGrades[i] != 'C' &&
			arrayOfGrades[i] != 'D' &&
			arrayOfGrades[i] != 'F')
		{
			cout << "\nAll grades must be upper case A B C D or F\n";
			i--;
		}
	}
}

//*******************************************************************
//	getFrequency													*
//	task:	This looks for the character in the array and returns	*
//			the number of grades in that category					*
//*******************************************************************
int getFrequency(GradeType arrayOfGrades, int& numOfGrades, char category) {
	int frequency = 0;
	for (size_t i = 0; i < numOfGrades; i++){
		if (arrayOfGrades[i] == category){
			frequency++;
		}
	}
	return frequency;
}

//*******************************************************************
//	printGrades														*
//	task:	This prints the frequency of the grades					*
//*******************************************************************
void printGrades(GradeType arrayOfGrades, int& numOfGrades) {

	cout << "\nNumber of A = " << getFrequency(arrayOfGrades, numOfGrades, 'A');
	cout << "\nNumber of B = " << getFrequency(arrayOfGrades, numOfGrades, 'B');
	cout << "\nNumber of C = " << getFrequency(arrayOfGrades, numOfGrades, 'C');
	cout << "\nNumber of D = " << getFrequency(arrayOfGrades, numOfGrades, 'D');
	cout << "\nNumber of F = " << getFrequency(arrayOfGrades, numOfGrades, 'F');
	cout << endl;
}