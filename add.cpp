

#include "SDB.h"



// Add_Student Function Definition
Status Add_Student(Student_Slist *&Head)
{
	// Clear any leftover newline from previous input
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');


	// Declaring Fields
	string Name;
	string ID;
	string DOB;
	string Email;
	string Phone;
	string Major;
	string GPA;

	while (1)
	{
		// Reading Name
		cout << "\nEnter Name of the Student: ";
		getline(cin, Name);

		// Name Validation
		if ( Validate_Alpha_Data(Name) == INVALID )
		{
			cerr << RED << "ERROR: Please Enter a Valid Name with Only Alphabets & Spaces!\n" << NORMAL;
			continue;
		}

		// Duplicate Name Validation
		if ( Duplicate_Name(Head,Name) == DUPLICATE )
		{
			cerr << RED << "ERROR: Given Name is Already Existing! Please Enter a New Name!\n" << NORMAL;
			continue;
		}

		break;
	}

	while (1)
	{
		// Reading ID
		cout << "\nEnter ID of the Student: ";
		getline(cin, ID);

		// ID Validation
		if ( Validate_Numerical_Data(ID,NOT_SET) == INVALID )
		{
			cerr << RED << "ERROR: Please Enter a Valid ID with Only Digits!\n" << NORMAL;
			continue;
		}

		// Duplicate ID Validation
		if ( Duplicate_ID(Head,stoi(ID)) == DUPLICATE )
		{
			cerr << RED << "ERROR: Given ID is Already Existing! Please Enter a New ID!\n" << NORMAL;
			continue;
		}

		break;
	}

	while (1)
	{	
		// Reading DOB
		cout << "\nEnter DOB of the Student: ";
		getline(cin, DOB);

		// DOB Validation
		if ( Validate_DOB(DOB) == INVALID )
		{
	   		cerr << RED << "ERROR: Please Enter a Valid DOB in Only DDMMYY or DD/MM/YY or DD-MM-YY Format!\n" << NORMAL;
			continue;
		}

		break;
	}

	while (1)
	{
		// Reading Email
		cout << "\nEnter Email ID of the Student: ";
		getline(cin, Email);

		// Email Validation
		if ( Validate_Email(Email) == INVALID )
		{
			cerr << RED << "ERROR: Please Enter a Valid Email ID with Only @ & .com!\n" << NORMAL;
			continue;
		}

		// Duplicate Email Validation
		if ( Duplicate_Email(Head,Email) == DUPLICATE )
		{
			cerr << RED << "ERROR: Given Email ID is Already Existing! Please Enter a New Email ID!\n" << NORMAL;
			continue;
		}

		break;
	}

	while (1)
	{
		// Reading Phone
		cout << "\nEnter Phone No of the Student: ";
		getline(cin, Phone);

		// Phone Validation
		if ( Validate_Numerical_Data(Phone,SET) == INVALID )
		{
			cerr << RED << "ERROR: Please Enter a Valid Phone No with Only 10 Digits!\n" << NORMAL;
			continue;
		}

		// Duplicate Phone Validation
		if ( Duplicate_Phone(Head,Phone) == DUPLICATE )
		{
			cerr << RED << "ERROR: Given Phone No is Already Existing! Please Enter a New Phone No!\n" << NORMAL;
			continue;
		}

		break;
	}

	while (1)
	{
		// Reading Major
		printf("\nEnter Major Field of Study of the Student: ");
		getline(cin, Major);

		// Major Validation
		if ( Validate_Alpha_Data(Major) == INVALID )
		{
			cerr << RED << "ERROR: Please Enter a Valid Major Study with Only Alphabets & Spaces!\n" << NORMAL;
			continue;
		}

		break;
	}

	while (1)
	{
		// Reading GPA
		printf("\nEnter GPA of the Student: ");
		getline(cin, GPA);

		// GPA Validation
		if ( Validate_Numerical_Data(GPA,NOT_SET) == INVALID )
		{
			cerr << "ERROR: Please Enter a Valid GPA with Only Digits & .\n" << NORMAL;
			continue;
		}

		break;
	}

	// Calling Create_Student Function
	Create_Student(Head,Name,stoi(ID),DOB,Email,Phone,Major,stof(GPA));

	return SUCCESS;
}












