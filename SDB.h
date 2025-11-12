

#ifndef SDB_H
#define SDB_H

// Including Header Files
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;


// Macros
#define DATABASE_FILE	"Students.csv"
#define MAX_LEN			100
#define BUFF			500
#define SET				1
#define NOT_SET		   -1
#define START			1
#define END				0
#define BLUE            "\x1b[34m"
#define NORMAL          "\x1b[0m"
#define RED             "\x1b[31m"
#define GREEN           "\033[1;32m"

// Student Structure
typedef struct Node
{
	string Name;
   	string DOB; 
	string Email; 
	string Phone; 
	string Major;
	int ID;
	double GPA;
	struct Node *Link;
}Student_Slist;


// Enum Status
typedef enum
{
	SUCCESS = 1, 
	FAILURE = -1, 
	VALID = 2, 
	INVALID = -2, 
	DUPLICATE = -3
}Status;


// Enum Operation
typedef enum
{
	EXIT, //0
	ADD, 
	SEARCH, 
	EDIT, 
	DELETE, 
	DISPLAY, 
	SAVE
}Operation;


// Enum Fields
typedef enum
{
	BACK, //0
	NAME, 
	ID, 
	EMAIL, 
	PHONE, 
	DOB, 
	MAJOR, 
	GPA
}Fields;


// Function Prototypes

//void Get_Students_Data(Student_Slist **Head); //valid
void Get_Students_Data(Student_Slist *&Head); //referene, valid

//void Create_Student(Student_Slist **Head, string Name, int ID, string DOB, string Email, string Phone, string Major,double GPA); //valid
void Create_Student(Student_Slist *&Head, string Name, int ID, string DOB, string Email, string Phone, string Major, double GPA); //reference, valid

void Free_Students(Student_Slist *Head);

Status Validate_Head(Student_Slist *Head);


Status Validate_Alpha_Data(const string &Data);
Status Validate_Numerical_Data(const string &Data,int P_Flag);
Status Validate_DOB(const string &DOB);
Status Validate_Email(const string &Email);


Status Duplicate_Name(Student_Slist *Head, const string &Name);
Status Duplicate_ID(Student_Slist *Head,int ID);
Status Duplicate_Email(Student_Slist *Head, const string &Email);
Status Duplicate_Phone(Student_Slist *Head, const string &Phone);


//Status Add_Student(Student_Slist **Head); //valid 
Status Add_Student(Student_Slist *&Head); //reference, valid

Student_Slist *Search_Student(Student_Slist *Head);

//Status  Edit_Student(Student_Slist **Head); //valid
Status  Edit_Student(Student_Slist *&Head); //reference, valid

//Status  Delete_Student(Student_Slist **Head); //valid
Status  Delete_Student(Student_Slist *&Head); //reference, valid

Status  Display_Students(Student_Slist *Head);

Status  Save_Students(Student_Slist *Head);


#endif




