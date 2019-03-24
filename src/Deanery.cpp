#include"Deanery.h"

Deanery::Deanery(std::string fileStudents, std::string fileGroups)
{
	FileNameGroups = fileGroups;
	FileNameStudents = fileStudents;
}

void Deanery::getStudent()
{
	std::ifstream file(FileNameStudents);
	std::string FIO;
	int id = 0;

	while (getline(file, FIO))
	{
		this->students.push_back(new Student(id, FIO));
		id++;
	}
	file.close();
}
bool Deanery::getGroup(int countSudentinGroup)
{
	this->countStudent = countSudentinGroup;
	std::ifstream file(FileNameGroups);
	std::string groupName;
	int numGroup = 0;
	while (getline(file, groupName))
	{
		this->groups.push_back(new Group(groupName, countSudentinGroup));
		if (groupDistribution(countSudentinGroup, numGroup) == true)
		{
			++numGroup;
		}
		else
			return false;
	}
	file.close();

	return true;
}
bool Deanery::groupDistribution(int countStudentinGroup, int numGroup)
{
	for (int i = 0; i < countStudentinGroup; i++)
	{
		if (this->groups[numGroup]->setStudent(*this->students[i+numGroup*countStudentinGroup]) == true)
		{
			this->students[i+numGroup*countStudentinGroup]->setGroup(groups[numGroup]);
		}
		else
		{
			return false;
		}
	}
	return true;

}
void Deanery::getMarks(int countMarks)
{
	int mark;
	
	for (int i = 0; i < this->students.size(); i++)
	{
		for (int j = 0; j < countMarks; j++)
		{
			mark = rand() % 4 + 2;
			this->students[i]->setMarks(mark);
		}
	}
}
void Deanery::setHeadinGroups()
{
	for (int i = 0; i < this->groups.size(); i++)
	{
		this->groups[i]->setHead();
	}
}
void Deanery::excludeDad()
{
	countExcludeStudent = 0;
	/*auto I = this->students.begin();

	for (I; I != this->students.end(); ++I)
	{
		if ((*I)->getAvarageMarks() < 3)
		{
			((*I)->getGroup()).excludeStudent((*I)->getID());
			students.erase(I);
			this->countExcludeStudent++;

		}
	}*/

	for (int i = 0; i < this->students.size(); i++)
	{
		if (this->students[i]->getAvarageMarks() < 3)
		{
			(this->students[i]->getGroup()).excludeStudent(this->students[i]->getID());
			this->students.erase(students.begin() + i);
			i--;
			this->countExcludeStudent++;
		}
	}
	
}
Group* Deanery::getGroupinD(const std::string& title)
{
	for (int i = 0; i < this->groups.size(); i++)
	{
		if (this->groups[i]->getTitle() == title)
			return (this->groups[i]);
		else

			return nullptr;
	}
}
bool Deanery::moveStudent(std::string nameStudent, Group* nameGroup)
{
	if (nameGroup == nullptr)
		return false;

	for (int i = 0; i < this->students.size(); i++)
	{
		if (this->students[i]->getFIO() == nameStudent)
		{
			for (int j = 0; j < this->groups.size(); j++)
			{
				if (this->groups[j]->getTitle() == nameGroup->getTitle())
				{
					Group* hisGroup = &this->students[i]->getGroup();

					if (
						nameGroup->setStudent(*this->students[i]) == true	 
						)
					{
					
						hisGroup->excludeStudent(this->students[i]->getID());
						this->students[i]->setGroup(nameGroup);
						nameGroup->getNum();
						
						return true;
					}
					else
						return false;
				}

			}
			return false;
		}

	}
	return false;
}

void Deanery::getInfo()
{
	for (int j = 0; j < this->groups.size(); j++)
	{
		std::cout << "===================================================================================================" << std::endl;
		std::cout << "\n";
		std::cout << " Name group is " << this->groups[j]->getTitle() << " ." << std::endl;
		std::cout << " Count of students in the group = "<< this->groups[j]->getNum() << std::endl;
		std::cout << "--------------------------------------------------------------------------------------------------" << std::endl;
		for (int i = 0; i < this->groups[j]->getNum(); i++)
		{
			std::cout << "|" << i+1 << "|\t"
					  << this->students[i+j*(this->groups[j]->getNum())]->getID() << ": " 
					  << this->students[i+j*(this->groups[j]->getNum())]->getFIO()<<"  |"
					  << this->students[i+j*(this->groups[j]->getNum())]->getAvarageMarks() << "|" << std::endl;
			std::cout << "Marks :";
			for (int k = 0; k < this->students[j]->getNumMarks(); k++)
				std::cout << this->students[i + j * (this->groups[j]->getNum())]->getMarks()[k] << " ";
			std::cout << "\n";
		}
		std::cout << "--------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "Avarage Mark in Group = " << this->groups[j]->avarageGroup() << std::endl;
		std::cout << "--------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "Head of group is " << this->groups[j]->getHead().getID() << " "
				  << this->groups[j]->getHead().getFIO() << std::endl;
		std::cout << "===================================================================================================" << std::endl;
		std::cout << "===================================================================================================" << std::endl;
		std::cout << "\n";
	}
	std::cout << "Count of desided students = " << this->countExcludeStudent << std::endl;
}

void Deanery::putInfotoFILE(std::string FileName)
{
	std::ofstream out;
	out.open(FileName.c_str());
	
	if (out.is_open())
	{
		for (int j = 0; j < this->groups.size(); j++)
		{
			out << "===================================================================================================" << std::endl;
			out << "\n";
			out << " Name group is " << this->groups[j]->getTitle() << " ." << std::endl;
			out << " Count of students in the group = " << this->groups[j]->getNum() << std::endl;
			out << "--------------------------------------------------------------------------------------------------" << std::endl;
			for (int i = 0; i < this->groups[j]->getNum(); i++)
			{
				out << "|" << i + 1 << "|\t"
					<< this->students[i + j * (this->groups[j]->getNum())]->getID() << ": "
					<< this->students[i + j * (this->groups[j]->getNum())]->getFIO() << "  |"
					<< this->students[i + j * (this->groups[j]->getNum())]->getAvarageMarks() << "|" << std::endl;
				out << "Marks :";
				for (int k = 0; k < this->students[j]->getNumMarks(); k++)
						out << this->students[i + j * (this->groups[j]->getNum())]->getMarks()[k] << " ";
				out << "\n";
			}
			out << "--------------------------------------------------------------------------------------------------" << std::endl;
			out << "Avarage Mark in Group = " << this->groups[j]->avarageGroup() << std::endl;
			out << "--------------------------------------------------------------------------------------------------" << std::endl;
			out << "Head of group is " << this->groups[j]->getHead().getID() << " "
				<< this->groups[j]->getHead().getFIO() << std::endl;
			out << "===================================================================================================" << std::endl;
			out << "===================================================================================================" << std::endl;
			out << "\n";
		}
		out << "Count of desided students = " << this->countExcludeStudent << std::endl;

	}
	out.close();
}

