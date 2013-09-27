#include <iostream>
#include <string>

enum gearTypes { HEAD_ARMOR, CHEST_ARMOR, ACCESSORY, MAIN_HAND, OFF_HAND};

struct gem {

};

struct slot {
	int numSides;
	gem inhabitantGem;
};

struct gear {
	string name;
	gearTypes type;
	int numSlots;
	slot slots[];
};

using namespace std;

gear generateItem() {

}


int main () {
	gear item;
	item = generateItem();


	return 0;
}


/*
* Generally speaking, the fewer edges a shape has, the more rare/valuable it is.
*
* Circle is supportable spell
* Triangle is strong support gem
* Squares introduce sub-commands
* Pentagon is weak support gem
* Hexagon is the command slot (introduce new commands to the standard menu)
*
*
* Triangles pair with squares
*/