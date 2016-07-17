/* Person.h */

#pragma once
#include <vector>
#include <string>

enum Gender { male, female };

class Person
{
private:
	Gender gender;
	std::string name;
	std::vector<Person *> parents;
	std::vector<Person *> children;
	std::vector<Person *> cousins;
	void addParent(Person *p);

public:
	Person(std::string name, Gender g);
	~Person();

	Person *addChild(std::string name, Gender g);
	Person *addChild(Person *p);
	Person *addCousin(Person *p);

	friend std::ostream &operator << (std::ostream &out, Person p);

	std::string getName() const;

	Gender getGender() const;

	// warning C4267: conversion from 'size_t' to 'type', possible loss of data
	// use size_t instead of int
	size_t getNumChildren() const;
	size_t getNumParents() const;
	size_t getNumCousins() const;

	Person *getChild(size_t k) const;
	Person *getParent(size_t k) const;

	void getCousins(Person *);
	void showParents(Person *);
};