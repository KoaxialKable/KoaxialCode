#include <iostream>
#include <string>


struct slot {
	int numSides;

};

struct gear {
	string name;
	int numSlots;

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