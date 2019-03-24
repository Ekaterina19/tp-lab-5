#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<ctime>
#include"Group.h"

class Deanery
{
public:
	std::string FileNameStudents;
	std::string FileNameGroups;

	Deanery(std::string fileStudents, std::string fileGroups);
	void getStudent();
	bool getGroup(int countStudentinGroup);
	bool groupDistribution(int countStudentinGroup, int numGroup);
	void getMarks(int countMarks);
	void setHeadinGroups();
	void getInfo();
	void excludeDad();
	Group*getGroupinD(const std::string& title);
	bool moveStudent(std::string nameStudent, Group* nameGroup);
	void putInfotoFILE(std::string FileName);
private:
	int countStudent;
	int countExcludeStudent;
	std::vector<Student*>students;
	std::vector<Group*>groups;
};