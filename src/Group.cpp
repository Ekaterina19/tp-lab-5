#include"Group.h"
#include"Deanery.h"

Group::Group(std::string title, int numStudents)
{
	this->title = title;
	
}

int Group::getNum()
{
	return this->num;
}

std::string Group::getTitle()
{
	return this->title;
}

Student& Group::getHead()
{
	return *this->head;
}

std::vector<Student*> Group::getStudents()
{
	return this->Students;
}
int Group::survivorsStudent()
{
	return this->Students.size();
}

bool Group::setStudent(Student& pupil)
{
	if (this->searchFIO(pupil.getFIO()) == nullptr)
	{
		this->Students.push_back(&pupil);
		this->num++;
		return true;
	}
	else
		return false;
}

Student* Group::searchFIO(const std::string& nameStudent)
{
	for (int i = 0; i < this->Students.size(); i++)
	{
		if (this->Students[i]->getFIO() == nameStudent)
			return (this->Students[i]);
	}
	return nullptr;
}

Student* Group::searchID(const int id)
{
	for (int i = 0; i < this->Students.size(); i++)
	{
		if (this->Students[i]->getID() == id)
			return this->Students[i];
	}	

}

void Group::setHead()
{
	int index = rand() % (this->Students.size());
	this->head = this->Students[index];
}

int Group::avarageGroup()
{
	int sum = 0;
	 
	for (int i = 0; i < this->Students.size(); i++)
	{
		sum += this->Students[i]->getAvarageMarks();
	}
	return round(sum / this->Students.size());
}

void Group::excludeStudent(int id)
{
	//auto I = this->Students.begin();
	//for (I; I != this->Students.end(); ++I)
	//{
	//	if ((*I)->getID() == id)
	//		break;
	//}

	//while (this->head == (*I))
	//	this->setHead();

	//this->Students.erase(I);
	for (int i = 0; i < this->Students.size(); i++)
	{
		if (this->Students[i]->getID() == id) 
		{
			while(this->Students[i] == head)
					this->setHead();

			this->Students.erase(this->Students.begin() + i);
			this->num = this->Students.size();
			this->getNum();
			break;
		}
	}
}
