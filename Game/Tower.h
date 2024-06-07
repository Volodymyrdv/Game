#pragma once
#include "Disk.h"
#include <stack>
using namespace std;
class Tower
{
public:
	void setPositionTower(Vector2f position);
	void drawTower(RenderWindow& window);
	void firstStep(int numberOfDiscs);
	void movedDisk(Tower& tower1);
	int sizeTower();
	bool checkRules(Tower& tower1);
private:
	stack<Disk> tower;
	Vector2f position;
	Disk peakTower();
	bool isTowerEmpty();
};

