/* Person.cpp */

#include <iostream>
#include "Person.h"

Person::Person(std::string name, Gender g)
{
	this->name = name;
	gender = g;
}

Person::~Person() {}

void Person::addParent(Person *p)
{
	parents.push_back(p);
}

Person *Person::addChild(std::string name, Gender g)
{
	Person *child = new Person(name, g);
	child->addParent(this);
	children.push_back(child);
	return child;
}

Person *Person::addChild(Person* child)
{
	child->addParent(this);
	children.push_back(child);
	return child;
}

Person *Person::addCousin(Person* cousin)
{
	cousins.push_back(cousin);
	return cousin;
}

std::string Person::getName() const
{
	return name;
};

Gender Person::getGender() const
{
	return gender;
};

size_t Person::getNumChildren() const
{
	return children.size();
}

size_t Person::getNumParents() const
{
	return parents.size();
}

size_t Person::getNumCousins() const
{
	return cousins.size();
}

Person *Person::getParent(size_t k) const
{
	if (k < 0 || k >= parents.size()) {
		std::cout << "Error indexing parents vector.\n";
		exit(1);
	}

	return parents[k];
}

Person *Person::getChild(size_t k) const
{
	if (k < 0 || k >= children.size()) {
		std::cout << "Error indexing children's vector.\n";
		exit(1);
	}

	return children[k];
}

// family tree
std::ostream & operator<<(std::ostream & out, Person p)
{
	size_t k;

	out << "<person = " << p.name << ">" << '\n';

	if (p.parents.size() > 0) {
		out << "   <parents>" << ' ';
	}

	for (k = 0; k < p.parents.size(); k++) {
		out << " " << p.parents[k]->name << ' ';
	}

	if (p.parents.size() > 0) {
		out << "  </parents>\n";
	}

	if (p.children.size() > 0) {
		out << "   <children>" << ' ';
	}

	for (k = 0; k < p.children.size(); k++) {
		out << " " << p.children[k]->name << ' ';
	}

	if (p.children.size() > 0) {
		out << "  </children>\n";
	}

	if (p.cousins.size() > 0) {
		out << "   <cousins>" << ' ';
	}

	for (k = 0; k < p.cousins.size(); k++) {
		out << " " << p.cousins[k]->name << ' ';
	}

	if (p.cousins.size() > 0) {
		out << "  </cousins>\n";
	}

	out << "</person>\n\n";

	return out;
}

// takes a pointer to a Person object and produces a list of that person's cousins
void Person::getCousins(Person *p)
{
	std::cout << "\n" << p->getName() << "'s cousins:\n";

	for (size_t k = 0; k < p->getNumCousins(); k++) {

		std::cout << "\t" << cousins[k]->getName();

		switch (cousins[k]->getGender()) {
		case female:
			std::cout << " (f)";
			break;
		case male:
			std::cout << " (m)";
			break;
		}
	}

	std::cout << "\n";
}

// takes a pointer to a Person object and produces a list of that person's parents
void Person::showParents(Person *p)
{
	std::cout << "\n" << p->getName() << "'s parents:\n";

	for (size_t k = 0; k < p->getNumParents(); k++) {
		switch (parents[k]->getGender()) {
			case female:
				std::cout << "\tMother: ";
				break;
			case male:
				std::cout << "\tFather: ";
				break;
		}

		std::cout << parents[k]->getName();
	}
}