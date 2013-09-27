#include <iostream>
#include <random>
#include <vector>
#include <cmath>
 
const int GRID_SIZE = 24;
const int NUM_ROOMS = 6;
const int MAX_ROOM_SIZE = 6;
 
using namespace std;
 
struct node
{
char face;
int x;
int y;
} ;
 
 
 
node grid[GRID_SIZE][GRID_SIZE];
vector<node> rooms;
 
void init()
{
for (int i = 0; i < GRID_SIZE; i++)
{
for (int j = 0; j < GRID_SIZE; j++)
{
grid[i][j].face = '.';
grid[i][j].y = i;
grid[i][j].x = j;
}
}
}
 
node randNode()
{
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(0, GRID_SIZE-1);
node newNode;
 
newNode.x = dist(mt);
newNode.y = dist(mt);
newNode.face = grid[newNode.y][newNode.x].face;
 
return newNode;
}
 
void pepper()
{
char counter = '0';
for (int i = 0; i < NUM_ROOMS; i++)
{
node target = randNode();
if (grid[target.y][target.x].face != '.')
{
while (grid[target.y][target.x].face != '.')
{
target = randNode();
}
}
grid[target.y][target.x].face = counter;
rooms.push_back(target);
counter++;
}
}
 
void fleshRooms()
{
int width, height;
int baseW, baseH;
 
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(3, MAX_ROOM_SIZE);
 
for (size_t i = 0; i < rooms.size(); i++)
{
width = dist(mt);
height = dist(mt);
 
if (width > 3)
baseW = width/2;
else
baseW = width-1;
if (height > 3)
baseH = height/2;
else
baseH = height-1;
 
// "draw" top half of room
for (int j = 0; j < height; j++)
{
for (int k = 0; k < width; k++)
{
if (rooms[i].y - baseH + j >= 0 && rooms[i].y - baseH + j < GRID_SIZE) // ensure there's a place for it
if (rooms[i].x - baseW + k >= 0 && rooms[i].x - baseW + k < GRID_SIZE)
grid[rooms[i].y - baseH + j][rooms[i].x - baseW + k].face = '=';
}
}
}	
}
 
void joinRooms()
{
for (size_t i = 0; i < rooms.size()-1; ++i)
{
int vert = 0;
int horiz = 0;
 
//handle vertical change
if (rooms[i].y != rooms[i+1].y)
{
// vert needed
vert = rooms[i].y - rooms[i+1].y;
bool up = true;
 
//decide direction of change needed
if (vert < 0)
up = false;
 
// print vertical change
for (int j = 0; j < abs(vert); j++)
{
if (up)
grid[rooms[i].y - j][rooms[i].x].face = '=';
else
grid[rooms[i].y + j][rooms[i].x].face = '=';
}
}
 
 
// handle horizontal
if (rooms[i].x != rooms[i+1].x)
{
// horiz needed
horiz = rooms[i].x - rooms[i+1].x;
bool west = true;
 
//decide direction of change needed
if (horiz < 0)
west = false;
 
// print vertical change
for (int j = 0; j < abs(horiz); j++)
{
if (west)
grid[rooms[i].y - vert][rooms[i].x - j].face = '=';
else
grid[rooms[i].y - vert][rooms[i].x + j].face = '=';
}
}
 
 
 
//i.y > i+1.y == N
//i.y < i+1.y == S
//i.x > i+1.x == W
//i.x < i+1.x == E
}
}
 
int main ()
{
init();
pepper();
joinRooms();
fleshRooms();
 
for (size_t i = 0; i < rooms.size(); ++i)
{
grid[rooms[i].y][rooms[i].x].face = char(i + 48);
}
 
for (int i = 0; i < GRID_SIZE; i++)
{
for (int j = 0; j < GRID_SIZE; j++)
{
cout << grid[i][j].face;
}
cout << endl;
}
 
cin.get();
return 0;
}