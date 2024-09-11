//  Programming 1 Course Projects
//  main.cpp
//  Course COSC-1336-029
//  Name: Josiah Swanner
//  Modified Date  and Purpose/Description
/* <9/8/2023> - Added Welcome Header and prompt for user's name
              - Added Welcome Message to user 
   <9/23/2023> - Added Selection Section to prompt the user to choose between 3 different tasks
   			  - Added Square Root functionality to the Selection Section
   			  - Added Power functionality to the Selection Section
   			  - Added GPA to Letter Grade Concersion functionality to the Selection Section
   <10/14/2023> - Added a while loop to repeat the Selection Section until the user chooses 0
              - Put the menu for the Selection Section inside a box
              - Added Triangle Creating functionality to the Selection Section
   <10/27/2023> - Moved the code for the GPA and Triangle Creating secection into their own functions
   			  - Added Calculate Weekly Pay functionality to the Selection Section
   			  - Added Calculate Interest functionality to the Selection Section
   			  - Added a function to reset the precision in the output stream
   <11/3/2023> - Moved the header into its own function
   			  - Moved the first and last name inputs into their own function
   <11/17/2023> - Added grade calculator functionality, including functions to input grades, output grades, and calculate the average grade
   <12/8/2023> - Added print contacts functionality, including an array of structs to store contact info, and a function to print the contact info
*/


#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using  namespace std;

//Defines the struct type
struct contacts {
	string fName;
	string lName;
	string phoneNum;
	contacts(string = " ", string = " ", string = " ");
};

//Function prototypes
void header();
void inputName(string&, string&);
void gpaCal();
void triangle();
double payCal(double, double);
void displayInt(double, double);
void getGrades(double[], int);
void dispGrades(double[], int);
double avrgGrade(double[], int);
void printContacts(contacts[], int);
void precReset();

int main()
{
    //****** Variable section *********
    string firstName, lastName;
    int choice;
    double x, y, ans, rate, hours, bal, interest, grades[5];
    bool end = false;
    contacts arrayContacts[3] {contacts("Josiah", "Swanner", "405-550-0939"), contacts("Kevin", "Roark", "210-837-0600"), contacts("Robert", "Digiovanni", "210-273-1098")};
    
    //****** Welcome Section **********
    //Outputs the header    
    header();
	
	//Takes inputs for the user's first and last name  
    inputName(firstName, lastName);
    
    //Outputs a welcome message to the user   
	cout << "Welcome to my course project " << firstName << " " << lastName; 
	
	//****** Selection Section **********
	cout << "\n********************************************************";
	while (!end) {
		//Prompts the user for selection
		cout << "\n|------------------------------------------------------|\n";
		cout << "| Enter 1 to calculate the square root of a number     |\n";
		cout << "| Enter 2 to calculate X to the Y power                |\n";
		cout << "| Enter 3 to convert a numerical GPA to a letter grade |\n";
		cout << "| Enter 4 to create a right triangle                   |\n";
		cout << "| Enter 5 to calculate weekly pay                      |\n";
		cout << "| Enter 6 to calculate interest                        |\n";
		cout << "| Enter 7 to calculate grades                          |\n";
		cout << "| Enter 8 to print contacts                            |\n";
		cout << "| Enter 0 to exit the program                          |\n";
		cout << "|------------------------------------------------------|\n";
		cout << "Enter your selection: ";
		cin >> choice;
	
		//Makes the selection
		switch (choice) {
			case 0:
				end = true;
				break;
			case 1:
				//Prompts and takes an input for the number to take the square root of
				cout << "Enter a number to take the square root of: ";
				cin >> x;
			
				//Takes the square root of x
				ans = pow(x, 0.5);
				
				//Outputs the square root
				cout << "The square root of " << x << " is " << ans;
				break;
			
			case 2:
				//Prompts and takes inputs for x and y
				cout << "Enter your X and Y values\n";
				cout << "Enter X: ";
				cin >> x;
				cout << "Enter Y: ";
				cin >> y;
			
				//Calculates x to the power of y
				ans = pow(x, y);
			
				//Outputs x to the power of y
				cout << x << " to the power of " << y << " is " << ans;
				break;
			
			case 3:
				gpaCal();
				break;
				
			case 4:
				triangle();
				break;
			
			case 5:
				//Prompts and takes inputs for rate and hours
				cout << "Enter your pay rate and the hours you worked this week\n";
				cout << "Enter Pay Rate: ";
				cin >> rate;
				cout << "Enter Hours: ";
				cin >> hours;
				
				//Calculates and outputs the total pay
				cout << fixed << showpoint << setprecision(2);
				cout << "Your total pay is $" << payCal(rate, hours);
				precReset();
				break;
				
			case 6:
				//Prompts and takes inputs for account balance and interest rate
				cout << "Enter your account balance and interest rate\n";
				cout << "Enter Initial Balance: ";
				cin >> bal;
				cout << "Enter Interest Rate: ";
				cin >> interest;
				
				//Applies and displays the interest
				displayInt(bal, interest);
				break;
			case 7:
				//Function to take inputs for grades
				getGrades(grades, 5);
				
				//Function to output grades and the average grade
				dispGrades(grades, 5);
				break;
			case 8:
				//Function to print the contacts
				printContacts(arrayContacts, 3);
				break;
		}
	}

    return 0;
}

//Function to output the header
void header() {
	cout << "********************************************************\n";
	cout << "*             Programming 1 Course Project             *\n";
	cout << "********************************************************\n";
}

//Function to take the input for the user's first and last name
void inputName(string& fn, string& ln) {
	cout << "Please input your first name: ";
    cin >> fn;  
    cout << "Please input your last name: ";
    cin >> ln;
}

//Function to convert a GPA to a letter grade
void gpaCal() {
	double gpa;
	char grade;
	
	//Prompts and takes an input for gpa
	cout << "Enter your GPA: ";
	cin >> gpa;
	
	//Converts gpa into a letter grade
	if (gpa >= 4)
		grade = 'A';
	else if (gpa >= 3)
		grade = 'B';
	else if (gpa >= 2)
		grade = 'C';
	else if (gpa >= 1)
		grade = 'D';
	else
		grade = 'F';
		
	//Outputs the letter grade
	cout << "Your letter grade is a(n) " << grade;
}

//Function to draw a triangle
void triangle() {
	int triSize, countV, countH;
	
	//Prompts and takes an input for the size of the triangle
	cout << "Enter the size of the triangle: ";
	cin >> triSize;
			
	//Outputs the triangle
	for (countV = 1; countV <= triSize; countV++) {
		for (countH = 1; countH <= countV; countH++)
			cout << "* ";
		cout << '\n';
	}
}

//Function to calculate total pay
double payCal(double r, double h) {
	if (h <= 40)
		return r * h;
	else
		return (r * 40) + ((h - 40) * (r * 1.5));
}

//Function to apply interest and display interest
void displayInt(double b, double i) {
	cout << fixed << showpoint << setprecision(2);
	for (int count = 1; count <= 5; count++) {
		b = b + (b * i);
		cout << "Year " << count << ": $" << b << endl;
	}
	precReset();
}

//Function to get the grades
void getGrades(double g[], int size) {
	cout << "Enter the grades of the students: " << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter Student " << i + 1 << ": ";
		cin >> g[i];
	}
}

//Function to ouput the grades
void dispGrades(double g[], int size) {
	cout << fixed << showpoint << setprecision(2);
	for (int i = 0; i < size; i++) {
		cout << "Student " << i + 1 << ": " << g[i] << endl;
	}
	cout << "The average grade is " << avrgGrade(g, size);
	precReset();
}

//Function to calculate the average grade
double avrgGrade(double g[], int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum = sum + g[i];
	}
	return sum / size;
}

//Constructor for the contacts struct
contacts::contacts(string fn, string ln, string pn) {
	fName = fn;
	lName = ln;
	phoneNum = pn;
}

//Function to print the contacts
void printContacts(contacts con[], int size) {
	cout << "Contact list:" << endl;
	for (int i = 0; i < size; i++) {
		cout << "Name: " << con[i].fName << ' ' << con[i].lName << endl;
		cout << "Phone: " << con[i].phoneNum << endl;
		cout << endl;
	}
}

//Function to reset the precision in the output stream
void precReset() {
	cout.unsetf(ios::fixed);
	cout.unsetf(ios::showpoint);
	cout << setprecision(15);
}
