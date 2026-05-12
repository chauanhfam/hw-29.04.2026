#pragma once

Student createStudent()
{
	cin.ignore();
	Student std{};
	static uint id = 100;
	std.id = id++;
	const int N = 20;
	char n[N];
	cout << "Enter name: ";
	cin.getline(n, N);
	std.name = new char[strlen(n) +1];
	strcpy_s(std.name, strlen(n) + 1, n);
	cout << "Enter average: ";
	cin >> std.average;
	cout << "BirthdayDate (year month day): ";
	cin >> std.birthdayDate.year;
	cin >> std.birthdayDate.month;
	cin >> std.birthdayDate.day;
	return std;
}
void showStudent(Student& std)
{
	cout << "\n===============\n";
	cout << std.id << '\t'
		<< std.name << '\t'
		<< std.average << '\t'
		<< std.birthdayDate.day << '.' << std.birthdayDate.month << '.'
		<< std.birthdayDate.year << endl;
	cout << "\n===============\n";
}
void showAllStudents(Student* students, uint size)
{
	for (uint i = 0; i < size; i++)
	{
		showStudent(students[i]);
	}
}
void clearNames(Student* students, uint size)
{
	for (int i = 0; i < size; i++)
	{
		delete[] students[i].name;
	}
}
void clear(Student* students, uint size)
{
	clearNames(students, size);
	delete[] students;
}
void addStudent(Student*& students, uint& size)
{
	cout << "Adding new student" << endl;
	Student newStudent = createStudent();
	Student* x = new Student[size + 1];

	for (uint i = 0; i < size; i++)
	{
		x[i] = students[i];
	}
	x[size] = newStudent;
	delete[] students;
	students = x;
	size++;
}
void removeStudentById(Student*& students, uint& size, uint idToRemove)
{
	int indexToRemove = -1;
	for (uint i = 0; i < size; i++)
	{
		if (students[i].id == idToRemove)
		{
			indexToRemove = i;
			break;
		}
	}
	if (indexToRemove == -1)
	{
		cout << "Student with ID " << idToRemove << " not found!" << endl;
		return;
	}
	delete[] students[indexToRemove].name;

	Student* x = new Student[size - 1];
	for (uint i = 0, j = 0; i < size; i++)
	{
		if (i != indexToRemove)
		{
			x[j++] = students[i];
		}
	}
	delete[] students;
	students = x;
	size--;
	cout << "Student with ID " << idToRemove << " removed successfully" << endl;
}
void sorting(Student* students, uint size, void(*sort)(Student* students, uint size))
{
	sort(students, size);
}
void sortByName(Student* students, uint size)
{
	//bubble sort
	for (uint i = 0; i < size - 1; i++)
	{
		for (uint j = 0; j < size - 1 - i; j++)
		{
			if (strcmp(students[j].name, students[j + 1].name) > 0)
			{
				/*Student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;*/
				swap(students[j], students[j + 1]);
			}
		}
	}
}
void sortByAverage(Student* students, uint size)
{
	//bubble sort
	for (uint i = 0; i < size - 1; i++)
	{
		for (uint j = 0; j < size - 1 - i; j++)
		{
			if (strcmp(students[j].name, students[j + 1].name) > 0)
			{
				/*Student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;*/
				swap(students[j], students[j + 1]);
			}
		}
	}
}