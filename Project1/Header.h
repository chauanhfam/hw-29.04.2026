#pragma once
typedef unsigned int uint;
typedef unsigned short ushort;

struct Date
{
	ushort day;
	ushort month;
	ushort year;
};
struct Student
{
	char* name;
	Date birthdayDate;
	uint id;
	float average;
};