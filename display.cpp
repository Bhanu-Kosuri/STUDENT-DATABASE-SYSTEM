

#include "SDB.h"


// Display_Students Function Definition
Status Display_Students(Student_Slist *Head)
{
	int Count = 0;
	cout << BLUE;

	// Running a Loop Until Head
	while ( Head )
	{
		// Displaying Student's Data
		cout << "\n##########   Student " << ++Count << " Info:\n";
		cout << "NAME     : " << Head -> Name << endl;
        cout << "ID       : " << Head -> ID << endl;
        cout << "DOB      : " << Head -> DOB << endl;
        cout << "EMAIL ID : " << Head -> Email << endl;
        cout << "PHONE NO : " << Head -> Phone << endl;
        cout << "MAJOR    : " << Head -> Major << endl;
        cout << "GPA      : " << Head -> GPA << endl;

		// Moving Head
		Head = Head -> Link;
	}

	cout << NORMAL;

	return SUCCESS;
}


