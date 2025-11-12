

#include "SDB.h"


// Save_Students Function Definition
Status Save_Students(Student_Slist *Head)
{
	// Opening File in Writing Mode
	ofstream file_obj;
	file_obj.open(DATABASE_FILE);

	//ofstream file_obj(DATABASE_FILE);
	
	// Printing An Error & Exiting if File is Not Present
	if ( !file_obj )
	{
		cerr << RED << "ERROR: " << DATABASE_FILE << " File Doesn't Exist!\n" << NORMAL;
		exit(EXIT_FAILURE);
	}

	// Running a Loop until Head
	while ( Head )
	{
		// Printing Students Data into the File
		file_obj << Head->Name << ","
                 << Head->ID << ","
                 << Head->DOB << ","
                 << Head->Email << ","
                 << Head->Phone << ","
                 << Head->Major << ","
                 << Head->GPA << "\n";

		// Moving Head
		Head = Head -> Link;
	}

	// Closing File
	file_obj.close();

	return SUCCESS;
}



