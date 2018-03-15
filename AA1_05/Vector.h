#pragma once
#include <vector>
#include <iostream>

struct personas
{
	std::string name;
	std::string birth;
	std::string dni;
};


std::vector<int>v1(5);std::vector<int>v2(10);std::vector<int>v3({ 10,9,8,7,6,5,4,3,2,1 });std::vector<std::string>v4({ "Gertrudis","Pancracia","Anacleto","Hipólito","Eustaquio","Fulgencia" });std::vector<int>v5(v3);std::vector<personas>v6({ { "Juanjo Chicote Jacas","25-03-1987","12345678L" } });//addVectorsvoid addVectors(std::vector<int>a, std::vector<int>b){	for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it)		std::}