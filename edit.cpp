

#include "SDB.h"


// Global Variables
extern char Back;

// Edit_Student Function Definition
Status Edit_Student(Student_Slist *&Head)
{
	// Calling Search_Student Function to Get Student Address
	Student_Slist *Edit = Search_Student(Head);

	// Returning FAILURE if Student is Not Found
	if ( Edit == nullptr )
		return FAILURE;

	// Displaying Current Student Data
	cout << GREEN << "INFO: Student Found.\n" << NORMAL;
	cout << BLUE << "\n##########   Current Student Data:\n";
	cout << "NAME     : " << Edit -> Name << endl;
    cout << "ID       : " << Edit -> ID << endl;
    cout << "DOB      : " << Edit -> DOB << endl;
    cout << "EMAIL ID : " << Edit -> Email << endl;
    cout << "PHONE NO : " << Edit -> Phone << endl;
    cout << "MAJOR    : " << Edit -> Major << endl;
    cout << "GPA      : " << Edit -> GPA << endl;

	int Run = START, Choice;

	// Running a Loop Until Run
	while ( Run )
	{
		// Displaying a Menu
		cout << BLUE << "\n##########   Edit Student by:\n";
		cout << "0.Back\n1.Name\n2.ID\n3.Email ID\n4.Phone No\n5.DOB\n6.Major\n7.GPA\n" << NORMAL;

		// Reading Choice
		cout << "\nEnter Your Choice: ";
		cin >> Choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//flush leftover newline

		// Using Switch Case for Choice
		switch ( Choice )
		{
			// Name
			case NAME:
			{
				string Name;
				while (1)
				{
					// Reading Name
					cout << "Old Name of the Student: " << Edit -> Name;
					cout << "\nEnter New Name of the Student: ";
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

				// Changing Name
				Edit -> Name = Name;
				cout << GREEN << "INFO: Successfully Edited Student's Name.\n" << NORMAL;

				break;
			}

			// ID
			case ID:
			{
				string ID;
				while (1)
				{
					// Reading ID
					cout << "Old ID of the Student: " << Edit -> ID;
					cout << "\nEnter New ID of the Student: ";
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

				// Changing ID
				Edit -> ID = stoi(ID);
				cout << GREEN << "INFO: Successfully Edited Student's ID.\n" << NORMAL;

				break;
			}

			// Email
			case EMAIL:
			{
				string Email;
				while (1)
				{
					// Reading Email
					cout << "Old Email of the Student: " << Edit -> Email;
					cout << "\nEnter New Email ID of the Student: ";
					getline(cin, Email);

					// Email ID Validation
					if ( Validate_Email(Email) == INVALID )
					{
						cerr << RED << "ERROR: Please Enter a Valid Email ID with @ & .com\n" << NORMAL;
						continue;
					}

					// Duplicate Email ID Validation
					if ( Duplicate_Email(Head,Email) == DUPLICATE )
					{
			  			cerr << RED << "ERROR: Given Email ID is Already Existing! Please Enter a New Email ID!\n" << NORMAL;
						continue;
					}

					break;
				}

				// Changing Email ID
				Edit -> Email = Email;
				cout << GREEN << "INFO: Successfully Edited Student's Email ID.\n" << NORMAL;

				break;
			}

			// Phone
			case PHONE:
			{
				string Phone;
				while (1)
				{
					// Reading Phone
					cout << "Old Phone of the Student: " << Edit -> Phone;
					cout << "\nEnter New Phone No of the Student: ";
					getline(cin, Phone);

					// Phone No Validation
					if ( Validate_Numerical_Data(Phone,SET) == INVALID )
					{
						cerr << RED << "ERROR: Please Enter a Valid Phone No with Only 10 Digits!\n" << NORMAL;
						continue;
					}

					// Duplicate Phone No Validation
					if ( Duplicate_Phone(Head,Phone) == DUPLICATE )
					{
			  			cerr << RED << "ERROR: Given Phone No is Already Existing! Please Enter a New Phone No!\n" << NORMAL;
						continue;
					}

					break;
				}

				// Changing Phone No
				Edit -> Phone = Phone;
				cout << GREEN << "INFO: Successfully Edited Student's Phone No.\n" << NORMAL;

				break;
			}

			// DOB
			case DOB:
			{
				string DOB;
				while (1)
				{
					// Reading DOB
					cout << "Old DOB of the Student: " << Edit -> DOB;
					cout << "\nEnter New DOB of the Student: ";
					getline(cin, DOB);

					// DOB Validation
					if ( Validate_DOB(DOB) == INVALID )
					{
	   					cerr << RED << "ERROR: Please Enter a Valid DOB in Only DDMMYY or DD/MM/YY or DD-MM-YY Format!\n" << NORMAL;
						continue;
					}

					break;
				}

				// Changing DOB
				Edit -> DOB = DOB;
				cout << GREEN << "INFO: Successfully Edited Student's DOB.\n" << NORMAL;

				break;
			}

			// Major
			case MAJOR:
			{
				string Major;
				while (1)
				{
					// Reading Major
					cout << "Old Major of the Student: " << Edit -> Major;
					cout << "\nEnter New Major Field of Study of the Student: ";
					getline(cin, Major);

					// Major Validation
					if ( Validate_Alpha_Data(Major) == INVALID )
					{
						cerr << RED << "ERROR: Please Enter a Valid Major with Only Alphabets & Spaces!\n" << NORMAL;
						continue;
					}

					break;
				}

				// Changing Major
				Edit -> Major = Major;
				cout << GREEN << "INFO: Successfully Edited Student's Major.\n" << NORMAL;

				break;
			}

			// GPA
			case GPA:
			{
				string GPA;
				while (1)
				{
					// Reading GPA
					cout << "Old GPA of the Student: " << Edit -> GPA;
					cout << "\nEnter New GPA of the Student: ";
					getline(cin, GPA);

					// GPA Validation
					if ( Validate_Numerical_Data(GPA,NOT_SET) == INVALID )
					{
						cerr << RED << "ERROR: Please Enter a Valid GPA with Only Digits & .\n" << NORMAL;
						continue;
					}

					break;
				}

				// Changing GPA
				Edit -> GPA = stof(GPA);
				cout << GREEN << "INFO: Successfully Edited Student's GPA.\n" << NORMAL;

				break;
			}

			// Exit
			case BACK:

				// Resetting Run
				Run = END;
				cout << GREEN << "INFO: Going Back.\n" << NORMAL;
				break;


			// Invalid Choice
			default:

				cout << RED << "ERROR: Invalid Choice!\n" << NORMAL;
				break;

		}
	}

	cout << BLUE << "\n##########   Student Data after Editing:\n";
	cout << "NAME     : " << Edit -> Name << endl;
    cout << "ID       : " << Edit -> ID << endl;
    cout << "DOB      : " << Edit -> DOB << endl;
    cout << "EMAIL ID : " << Edit -> Email << endl;
    cout << "PHONE NO : " << Edit -> Phone << endl;
    cout << "MAJOR    : " << Edit -> Major << endl;
    cout << "GPA      : " << Edit -> GPA << endl;

	return SUCCESS;
}



