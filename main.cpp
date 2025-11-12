/*
Name: Bhanu Kosuri
Project: Student Database System
*/


#include "SDB.h"


char Back;

// Main Function
int main(void)
{
	// Declaring Head Pointer
	Student_Slist *Head = nullptr;

	// Calling Get_Students_Data Function
	cout << GREEN << "INFO: Getting Students Data from " << DATABASE_FILE << " Database...\n" << NORMAL;
	Get_Students_Data(Head);
	cout << GREEN << "INFO: Done.\n" << NORMAL;

	int Choice, Save_Flag = SAVE, Ret;
	char Option;

	// Super Loop
	while (1)
	{
		// Displaying a Menu to User
		cout << BLUE << "\n##########   STUDENT DATABASE   ##########\n";
		cout << "##########   Features:\n\n";
		cout << "0.Exit\n1.Add Student\n2.Search Student\n3.Edit Student\n";
		cout << "4.Delete Student\n5.Display Students\n6.Save Students\n" << NORMAL;

		// Reading Choice
		cout << "\nEnter Your Choice: ";
		cin >> Choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//flush leftover newline

		// Using Switch Case for Choice
		switch ( Choice )
		{
			// Add a Student
			case ADD:
			{
				cout << BLUE << "\n##########   STUDENT DATABASE   ##########\n";
				cout << "##########   Add Student:\n" << NORMAL;

				// Calling Add_Student Function & Validating
				Add_Student(Head) == FAILURE ?
				cerr << RED << "\nERROR: Failed to Add Student Data!\n" << NORMAL :
				cout << GREEN << "\nINFO: Successfully Added Student Data\n" << NORMAL;

				Save_Flag = ADD;
				break;
			}

			// Search for a Student
			case SEARCH:
			{
				// Head Validation
				if ( Validate_Head(Head) == FAILURE )
					break;

				cout << BLUE << "\n##########   STUDENT DATABASE   ##########\n";
				cout << "##########   Search Student by:\n" << NORMAL;

				// Calling Search_Student & Validating
				Student_Slist *temp = Search_Student(Head);

				if ( Back == SET )
				{
					Back = NOT_SET;
						break;
				}

				else if ( temp == NULL)
				{
					cerr << RED << "ERROR: Student Not Found!\n" << NORMAL;
						break;
				}

				// Printing Search Result
				cout << BLUE << "\n##########   Search Result:\n";
				cout << "NAME     : " << temp -> Name << endl;
        		cout << "ID       : " << temp -> ID << endl;
        		cout << "DOB      : " << temp -> DOB << endl;
        		cout << "EMAIL ID : " << temp -> Email << endl;
        		cout << "PHONE NO : " << temp -> Phone << endl;
        		cout << "MAJOR    : " << temp -> Major << endl;
        		cout << "GPA      : " << temp -> GPA << NORMAL;
				cout << GREEN << "\nINFO: Student Found.\n" << NORMAL;

				break;
			}

			// Edit a Student
			case EDIT:
			{
				// Head Validation
				if ( Validate_Head(Head) == FAILURE )
					break;

				cout << BLUE << "\n##########   STUDENT DATABASE   ##########\n";
				cout << "##########   Search Student to Edit by:\n" << NORMAL;

				// Calling Edit_Student Function & Validating
				Ret = Edit_Student(Head);

				if ( Back == SET )
				{
					Back = NOT_SET;
						break;
				}

				if ( Ret == FAILURE )
					cerr << RED << "\nERROR: Student Not Found!\n" << NORMAL;

				// Updating Save_Flag if Ret is SUCCESS
				else
				{
					cout << GREEN << "\nINFO: Successfully Edited Student Data.\n" << NORMAL;
					Save_Flag = EDIT;
				}

				break;
			}

			// Delete a Student
			case DELETE:
			{
				// Head Validation
				if ( Validate_Head(Head) == FAILURE )
					break;

				cout << BLUE << "\n##########   STUDENT DATABASE   ##########\n";
				cout << "##########   Search Student to Delete by:\n" << NORMAL;

				// Calling Delete_Student Function & Validating
				Ret = Delete_Student(Head);

				if ( Ret == FAILURE )
					cerr << RED << "\nERROR: Student Not Found!\n" << NORMAL;

				// Updating Save_Flag if Ret is SUCCESS
				else
				{
					cout << GREEN << "\nINFO: Successfully Deleted Student Data.\n" << NORMAL;
					Save_Flag = DELETE;
				}

				break;
			}

			// Display a Student
			case DISPLAY:
			{
				// Head Validation
				if ( Validate_Head(Head) == FAILURE )
					break;

				cout << BLUE << "\n##########   STUDENT DATABASE   ##########\n";
				cout << "##########   Display Students:\n" << NORMAL;

				// Calling Display_Students Function & Validating
				if ( Display_Students(Head) == SUCCESS )
					cout << GREEN << "\nINFO: Successfully Displayed Students Data.\n" << NORMAL;

				break;
			}

			// Save Students
			case SAVE:
			{
				// Head Validation
				if ( Validate_Head(Head) == FAILURE )
					break;

				cout << BLUE << "\n##########   STUDENT DATABASE   ##########\n";
				cout << "##########   Save Students:\n" << NORMAL;

				// Calling Save_Students Function & Validating
				if ( Save_Students(Head) == SUCCESS )
					cout << GREEN << "\nINFO: Successfully Saved Students Data in " << DATABASE_FILE << " Database.\n" << NORMAL;

				Save_Flag = SAVE;
				break;
			}

			// Exit
			case EXIT:
			{
				cout << BLUE << "\n##########   STUDENT DATABASE   ##########\n";
				cout << "##########   Exit:\n" << NORMAL;

				// Save_Flag Validation
				if ( Save_Flag == SAVE )
				{
					cout << GREEN << "\nINFO: Exited from Student Database.\n" << NORMAL;
					exit(EXIT_SUCCESS);
				}

				// Reading Choice to Save Data or Not
				cout << "\nINFO: Students Data is Not Saved! You May loose Newly Registered/Changed Student Entries!\n";
				cout << "Enter Y/y to Save & Exit or N/n to Exit: ";
				cin >> Option;

				// Calling Save_Students Function if Option is Y/y
				if ( Option == 'Y' || Option == 'y' )
				{
					Save_Students(Head);
			    	cout << GREEN << "\nINFO: Successfully Saved Students Data in " << DATABASE_FILE << " Database.\n" << NORMAL;
				}

				// Calling Free_Students Function to Free out Memory
				Free_Students(Head);
				cout << GREEN << "\nINFO: Exited from Student Database.\n" << NORMAL;
				exit(EXIT_SUCCESS);

				break;
			}

			// Invalid Choice
			default:

				cerr << RED << "\nERROR: Invalid Choice!%s\n" << NORMAL;
				break;
		}
	}

	return 0;
}






