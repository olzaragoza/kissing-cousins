/* main.cpp */

/*
This program adds people to the tree.
A member function takes a pointer to a Person object and produces a list of that person's cousins.
Code to display the full tree was commented out to keep the output simple.
Also, commented out are lines of code to display each cousin's parents.
*/

#include<iostream>
#include "Person.h"

int main(int argc, char** argv)
{
	/****	people (unrelated)	****/
	Person adam("Adam", male);
	Person eve("Eve", female);
	Person joan("Joan", female);
	Person george("George", male);
	Person joseph("Joseph", male);
	Person hillary("Hillary", female);

	/*****		2nd generation		*****/
	// Adam and Eve are parents of Abel, Martha, Mary, and Bill
	Person *pAbel = eve.addChild(new Person("Abel", male));
	adam.addChild(pAbel);

	Person *pMartha = eve.addChild(new Person("Martha", female));
	adam.addChild(pMartha);

	Person *pMary = eve.addChild(new Person("Mary", female));
	adam.addChild(pMary);

	Person *pBill = eve.addChild(new Person("Bill", male));
	adam.addChild(pBill);

	/*****		3nd generation		*****/
	// Joan Abel are parents of Missy
	Person *pMissy = joan.addChild("Missy", female);
	pAbel->addChild(pMissy);

	// George and Martha are parents of Jacky and Patsy
	Person *pJacky = george.addChild("Jacky", female);
	pMartha->addChild(pJacky);

	Person *pPatsy = george.addChild("Patsy", female);
	pMartha->addChild(pPatsy);

	// Mary and Joseph are parents of James
	Person *pJames = pMary->addChild("James", male);
	joseph.addChild(pJames);
	
	// Bill and Hillary are parents of Chelsea
	Person *pChelsea = pBill->addChild("Chelsea", female);
	hillary.addChild(pChelsea);
	
	/*****		Cousins		*****/
	pMissy->addCousin(pJacky);
	pMissy->addCousin(pPatsy);
	pMissy->addCousin(pJames);
	pMissy->addCousin(pChelsea);

	pJacky->addCousin(pMissy);
	pJacky->addCousin(pJames);
	pJacky->addCousin(pChelsea);

	pPatsy->addCousin(pMissy);
	pPatsy->addCousin(pJames);
	pPatsy->addCousin(pChelsea);

	pJames->addCousin(pMissy);
	pJames->addCousin(pJacky);
	pJames->addCousin(pPatsy);
	pJames->addCousin(pChelsea);

	pChelsea->addCousin(pMissy);
	pChelsea->addCousin(pJacky);
	pChelsea->addCousin(pPatsy);
	pChelsea->addCousin(pJames);

	// output all the people in the tree

	/*
	std::cout << "\nAll the people in the tree:\n\n";
	std::cout << adam << eve;
	std::cout << *pAbel << joan << george << *pMartha << *pMary << joseph << *pBill << hillary;
	std::cout << *pMissy << *pJacky << *pPatsy << *pJames << *pChelsea << "\n";
	*/

	std::cout << "\n\t********    Cousins    ********\n";
//	std::cout << "\n\t****    Parents and Cousins    ****\n";

//	pMissy->showParents(pMissy);
	pMissy->getCousins(pMissy);

//	pJacky->showParents(pJacky);
	pJacky->getCousins(pJacky);

//	pPatsy->showParents(pPatsy);
	pPatsy->getCousins(pPatsy);

//	pJames->showParents(pJames);
	pJames->getCousins(pJames);

//	pChelsea->showParents(pChelsea);
	pChelsea->getCousins(pChelsea);

	std::cout << "\n\n";
	return 0;
}