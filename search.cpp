

#include "SDB.h"

// Global Variables
Student_Slist *Prev;
extern char Back;

// Search_Student Function Definition
Student_Slist *Search_Student(Student_Slist *Head)
{
	// Declaring Key & Choice
	string Key;
	int Choice;

	// Displaying Choices to Search
	cout << BLUE << "\n0.Back\n1.Name\n2.ID\n3.Email ID\n4.Phone No\n" << NORMAL;

	READ_CHOICE:

	cout << "\nEnter Your Choice: ";
	cin >> Choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

	// Using Switch Case for Choice
	switch ( Choice )
	{

		// Exit
		case BACK:
			cout << GREEN << "\n\nINFO: Going Back.\n" << NORMAL;
			Back = SET;
			return nullptr;

		// Name
		case NAME:

			// Reading Name
			cout << "\nEnter Name of the Student: ";
			getline(cin, Key);
			break;
	
		// ID
		case ID:

			// Reading ID
			cout << "\nEnter ID of the Student: ";
			getline(cin, Key);
			break;

		case EMAIL:

			// Reading Email
			cout << "\nEnter Email ID of the Student: ";
			getline(cin, Key);
			break;

		// Phone
		case PHONE:

			// Reading Phone
			cout << "\nEnter Phone No of the Student: ";
			getline(cin, Key);
			break;

		// Invalid Choice
		default:

			cerr << RED << "\nERROR: Invalid Choice!\n" << NORMAL;
			goto READ_CHOICE;
	}
	
	// Running a Loop Until Head
	while ( Head )
	{
		bool match = false;

		// Returning Head if Key Data is Found
		switch (Choice)
        {
            case NAME:
                match = (Head->Name == Key);
                break;

            case ID:
                try 
				{
                    match = (Head->ID == stoi(Key));
                } 
				catch (const invalid_argument&) 
				{
                    cerr << RED << "ERROR: ID must be numeric!\n" << NORMAL;
                    return nullptr;
                }
                break;

            case EMAIL:
                match = (Head->Email == Key);
                break;

            case PHONE:
                match = (Head->Phone == Key);
                break;
        }
		
		if(match)
			return Head;

		// Moving Head & Updating Prev
		Prev = Head;
		Head = Head -> Link;
	}

	return nullptr;
}





