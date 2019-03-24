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
	deanery hse("Pupiles.txt", "groupname.txt");
	hse.getstudent();
	//hse.getgroup(30); //true
	hse.getmarks(5);
	hse.setheadingroups();
	hse.excludedad();
	//hse.movestudent("gorshkova ekaterina m", hse.getgroupind(std::string("pmi")));// false
	//hse.movestudent("patrick nathaniel brooks", hse.getgroupind(std::string("p")));//false

	hse.getinfo();
	hse.putinfotofile("out.txt");
	
	
	// system("pause");
}