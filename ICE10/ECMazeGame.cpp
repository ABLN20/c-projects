// implement maze game
#include <iostream>
#include <vector>
using namespace std;

// Room
class Room
{
public:
  virtual int GetPrize() const { return 1; }
  virtual ~Room() = default;
};

// Room with a bomb
class RoomWithBomb : public Room 
{
public:
  int GetPrize() const override { return -10; }
};

// Enchanted room 
class EnchantedRoom : public Room
{
public:
  int GetPrize() const override { return 20; }
};

// maze game
class MazeGame
{
public:
  MazeGame() = default;
  virtual ~MazeGame() 
  {
    for (Room* room : rooms) 
    {
        delete room;
    }
  }
  
  // create a maze with two rooms and that is it!
  virtual void CreateMaze()
  {
    Room* room1 = MakeRoom();
    rooms.push_back(room1);
    Room* room2 = MakeRoom();
    rooms.push_back(room2);
    cout << "Total prize value for the maze: " << GetTotPrize() << endl;
  }
  // get the total prize amount for the rooms
  int GetTotPrize() const
  {
    int totalPrize = 0;
    for (const Room* room : rooms) 
    {
      totalPrize += room->GetPrize();
    }
    return totalPrize;
  }
  
  virtual Room* MakeRoom() 
  {
    return new Room();
  }

private:
  vector<Room*> rooms;
};

// bombed maze
class BombedMazeGame : public MazeGame
{
public:
  BombedMazeGame() : MazeGame() {}
  Room* MakeRoom() override 
  {
    return new RoomWithBomb();
  }
};

// enchanted maze
class EnchantedMazeGame : public MazeGame
{
public:
  EnchantedMazeGame() : MazeGame() {}
  Room* MakeRoom() override 
  {
    return new EnchantedRoom();
  }
};