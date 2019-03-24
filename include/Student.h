#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<math.h>
class Group;

class Student
{
public:
	Student(int id, std::string FIO);
	int getID();
	std::string getFIO();
	std::vector<int>& getMarks();
	int getNumMarks();
	int getAvarageMarks();
	Group& getGroup();

	void setGroup(Group* group);
	void setMarks(int mark);
private:
	int id;
	std::string FIO;
	Group* group;
	std::vector<int>marks;
	int numMarks;
};