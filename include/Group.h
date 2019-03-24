#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<ctime>
#include<math.h>
#include"Student.h"

class Deanery;

class Group
{
public:
	Group(std::string title, int numStudents);
	std::string getTitle();
	int getNum();
	Student& getHead();
	std::vector<Student*> getStudents();
	int avarageGroup();

	bool setStudent(Student& pupil);
	Student* searchFIO(const std::string& nameStudent);
	Student* searchID(const int id);
	void setHead();
	void excludeStudent(int id);
	int survivorsStudent();
private:
	std::string title;
	int num;
	Student* head;
	std::vector<Student*>Students;
};
