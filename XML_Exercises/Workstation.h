#pragma once
#include "pugixml.hpp"
#include<iostream>
class Workstation {

public:

	Workstation(int, int, int);
  static Workstation *parseWorkstation(pugi::xml_node);
  friend std::ostream& operator<<(std::ostream& os, const Workstation& workstation);
private:
	int building;
	int floor;
	int desc;
};