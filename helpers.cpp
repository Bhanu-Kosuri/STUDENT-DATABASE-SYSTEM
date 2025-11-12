

#include "SDB.h"


// Get_Students_Data Function Definition
void Get_Students_Data(Student_Slist *&Head)
{
	// Opening DATABASE in Read Mode
	ifstream file_obj;
	file_obj.open(DATABASE_FILE);

	//ifstream file_obj(DATABASE_FILE); //valid 

	// Open Validation
	if ( !file_obj ) // if ( file_obj.is_open() == false )
	{
		cerr << RED << "ERROR: No Database is Found to Get Students Data!\n" << NORMAL;
		return;
	}

	// Moving File offset to End
	file_obj.seekg(0, ios::end);

	// File Empty or Not Validation
	if ( file_obj.tellg() <= 0 || file_obj.fail())
	{
		cerr << RED << "ERROR: " << DATABASE_FILE << " Database is Empty!\n" << NORMAL;
		return;
	}

	// Moving File offset to Start
	file_obj.seekg(0, ios::beg);

	// Declaring Student_Data String
	string Student_Data;

	// Reading Each Student data from File
	while ( getline(file_obj, Student_Data) )
	{
		if(Student_Data.empty())
			continue;

		stringstream ss(Student_Data);
		string Name, ID, DOB, Email, Phone, Major, GPA;

		// Read comma-separated values
        getline(ss, Name, ',');
        getline(ss, ID, ',');
        getline(ss, DOB, ',');
        getline(ss, Email, ',');
        getline(ss, Phone, ',');
        getline(ss, Major, ',');
        getline(ss, GPA, ',');
		
		// Trim trailing \r if file is from Windows
		if (!GPA.empty() && GPA.back() == '\r')
    		GPA.pop_back();

		// Validation
		if ( Validate_Alpha_Data(Name) == INVALID ||
			Validate_Numerical_Data(ID,NOT_SET) == INVALID ||
		    Validate_DOB(DOB) == INVALID ||
			Validate_Email(Email) == INVALID ||
			Validate_Numerical_Data(Phone,SET) == INVALID ||
			Validate_Alpha_Data(Major) == INVALID ||
		    Validate_Numerical_Data(GPA,NOT_SET) == INVALID )
		{
			continue;
		}

		// Checking for Duplicate Data
		else if ( Duplicate_Name(Head,Name) == DUPLICATE ||
				Duplicate_ID(Head,stoi(ID)) == DUPLICATE ||
				Duplicate_Email(Head,Email) == DUPLICATE ||
				Duplicate_Phone(Head,Phone) == DUPLICATE )
		{
			continue;
		}

		// Calling Create_Student Function
		else if ( !Name.empty() && !ID.empty() && !DOB.empty() && !Email.empty() && !Phone.empty() && !Major.empty() && !GPA.empty() )
		{
			Create_Student(Head,Name,stoi(ID),DOB,Email,Phone,Major,stof(GPA));
		}
	}

	// Closing File
	file_obj.close();
}



// Validate_Head Function Definition
Status Validate_Head(Student_Slist *Head)
{
	// Returning FAILURE if Head is NULL
	if ( Head == nullptr )
	{
		cerr << RED << "\nERROR: Students List is Empty!\n" << NORMAL;
		return FAILURE;
	}

	return SUCCESS;
}


// Validate_Alpha_Data Function Definition
Status Validate_Alpha_Data(const string &Data)
{
	// Iterating through string
	for(char ch : Data)
	{
		// Returning INVALID if ch is Not a Alphabet or Space
		//if (!isalpha(ch) && ch != ' ') //works only for A-Z, a-z
		if (!isalpha(static_cast<unsigned char>(ch)) && ch != ' ')
			return INVALID;
	}

	return VALID;
}


// Validate_Numerical_Data Function Definition
Status Validate_Numerical_Data(const string &Data,int P_Flag)
{
	// P_Flag Validation for Phone Digits
	if ( P_Flag == SET )
	{
		if ( Data.size() != 10 )
			return INVALID;
	}

	// Iterating through string
	// For ID and GPA
	for (char ch : Data)
	{
		// Returning INVALID if Data[i] is Not a Digit or '.'(For GPA)
		//if (!isdigit(ch) && ch != '.') //works only for A-Z, a-z
		if (!isdigit(static_cast<unsigned char>(ch)) && ch != '.')
			return INVALID;
	}

	return VALID;
}


// Validate_DOB Function Definition
Status Validate_DOB(const string &DOB)
{
	// Iterating through string
	for(char ch : DOB)
	{
		// Returning INVALID if DOB[i] is Not a Digit or '/' or '-'
		if ( !isdigit(static_cast<unsigned char>(ch)) && ch != '/' && ch != '-')
			return INVALID;
	}

	return VALID;
}

	
Status Validate_Email(const string &Email)
{
    // Basic checks for structure
    size_t atPos = Email.find('@');
    size_t dotPos = Email.find('.', atPos);

    // Must contain '@' and '.'
	// If '@' is found, find() returns its index (0-based position).
	// If '@' is not found, find() returns std::string::npos.

    if (atPos == std::string::npos || dotPos == std::string::npos)
        return INVALID;

    // '@' cannot be first, '.' must come after '@'
    if (atPos == 0 || dotPos <= atPos + 1)
        return INVALID;

    // Must end with "com"
    if (Email.size() < 4 || Email.substr(Email.size() - 3) != "com")
        return INVALID;

    // Should not contain spaces
    if (Email.find(' ') != std::string::npos)
        return INVALID;

    return VALID;
}

// Duplicate_Name Function Definition
Status Duplicate_Name(Student_Slist *Head, const string &Name)
{
	// Running a Loop until Head Reaches Null
	while ( Head )
	{
		string existing_name = Head->Name;
		string new_name = Name;

		//std::transform(input_begin, input_end, output_begin, function); //need <algorithm>

		transform(existing_name.begin(), existing_name.end(), existing_name.begin(), ::tolower);
        transform(new_name.begin(), new_name.end(), new_name.begin(), ::tolower);
		// Returning DUPLICATE if Name is Already Existing
		if(existing_name == new_name)
			return DUPLICATE;

		// Moving Head
		Head = Head -> Link;
	}

	return SUCCESS;
}

// Duplicate_ID Function Definition
Status Duplicate_ID(Student_Slist *Head,int ID)
{
	// Running a Loop until Head Reaches Null
	while ( Head )
	{
		// Returning DUPLICATE if ID is Already Existing
		if ( Head -> ID == ID )
			return DUPLICATE;

		// Moving Head
		Head = Head -> Link;
	}

	return SUCCESS;
}

// Duplicate_Phone Function Definition
Status Duplicate_Phone(Student_Slist *Head, const string &Phone)
{
	// Running a Loop until Head Reaches Null
	while ( Head )
	{
		// Returning DUPLICATE if Phone is Already Existing
		if ( Head -> Phone == Phone)
			return DUPLICATE;

		// Moving Head
		Head = Head -> Link;
	}

	return SUCCESS;
}

// Duplicate_Email Function Definition
Status Duplicate_Email(Student_Slist *Head, const string &Email)
{
	// Running a Loop until Head Reaches Null
	while ( Head )
	{
		// Returning DUPLICATE if Email is Already Existing
		if ( Head -> Email == Email)
			return DUPLICATE;

		// Moving Head
		Head = Head -> Link;
	}

	return SUCCESS;
}

// Free_Students Function Definition
void Free_Students(Student_Slist *Head)
{
	// Running a Loop until Head
	while ( Head )
	{
		// Updating Del & Moving Head
		Student_Slist *temp = Head;
		Head = temp -> Link;

		// Freeing Del
		delete temp;
	}
}


