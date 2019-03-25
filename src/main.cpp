#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include"Student.h"
#include"Group.h"
#include"Deanery.h"

int main()
{
	srand(time(0));
	Deanery hse("Pupiles.txt", "groupName.txt");
	hse.getStudent();
	//hse.getGroup(30); //true
	hse.getMarks(5);
	hse.setHeadinGroups();
	hse.excludeDad();
	//hse.moveStudent("gorshkova ekaterina m", hse.getgroupind(std::string("pmi")));// false
	//hse.moveStudent("patrick nathaniel brooks", hse.getgroupind(std::string("p")));//false

	hse.getInfo();
	hse.putInfotoFILE("out.txt");
	
	
	// system("pause");
}
