

#include "SDB.h"


// Create_Student Function Definition
void Create_Student(Student_Slist *&Head, string Name, int ID, string DOB, string Email, string Phone, string Major, double GPA) 
{
	// Creating a Student
	Student_Slist *New = new Student_Slist; 

	// New Validation
	if ( New == nullptr )
	{
		cerr << RED << "\nERROR: Failed to Create New Student!\n" << NORMAL;
		return;
	}

	// Updating Fields of Student
	New -> Link = nullptr;
	New -> ID = ID;
	New -> GPA = GPA;
	New -> Name = Name;
	New -> DOB = DOB;
	New -> Email = Email;
	New -> Phone = Phone;
	New -> Major = Major;

	// Inserting New Student at First if List is Empty
	if ( Head == NULL )
	{
		Head = New;
		return;
	}

	// Declaring temp Ptr
	Student_Slist *temp = Head;

	// Traversing List
	while ( temp -> Link != NULL)
	{
		temp = temp -> Link;
	}

	// Updtaing temp's Link with New
	temp -> Link = New;
	return;
}




