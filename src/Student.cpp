#include"Group.h"
#include"Student.h"

Student::Student(int id, std::string FIO)
{
	this->FIO = FIO;
	this->id = id;
}
int Student::getID()
{
	return this->id;
}

std::string Student::getFIO()
{
	return this->FIO;
}
std::vector<int>& Student::getMarks()
{
	return this->marks;
}
int Student::getNumMarks()
{
	return this->numMarks;
}

int Student::getAvarageMarks()
{
	int sum = 0;
	for (int i = 0; i < this->numMarks; i++)
	{
		sum += this->marks[i];
	}
	return round(sum / this->numMarks);
}

Group& Student::getGroup()
{
	return *this->group;
}

void Student::setGroup(Group* group)
{
	this->group = group;
}

void Student::setMarks(int mark)
{
	this->marks.push_back(mark);
	this->numMarks = this->marks.size();
}
