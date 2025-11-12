

#include "SDB.h"


extern Student_Slist *Prev;


// Delete_Student Function Definition
Status Delete_Student(Student_Slist *&Head)
{
	// Calling Search_Student Function to get Student Address
	Student_Slist *temp = Search_Student(Head);

	// Returning FAILURE if Student Not Found
	if ( temp == nullptr )
		return FAILURE;

	// Deleting 1st Student if temp is Equal to Head
	if ( temp == Head )
	{
		// Updating Head With temp's Link
		Head = temp -> Link;
		delete temp;
		return SUCCESS;
	}

	// Else Updating Prev's Link With temp's Link
	Prev -> Link = temp -> Link;

	// Freeing temp
	delete temp;

	return SUCCESS;
}

