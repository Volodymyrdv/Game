#include "Tower.h"

void Tower::setPositionTower(Vector2f position)
{
	this->position = position;
}

void Tower::drawTower(RenderWindow& window)
{
	stack<Disk>temp = tower;
	while (!temp.empty())
	{
		window.draw(temp.top());
		temp.pop();
	}
}

void Tower::firstStep(int numberOfDiscs)
{
	Color color[6] = { Color(0,77,255), Color(0,189,255),Color(38,255,0),Color(255,248,0),Color(255,155,0),Color(255,0,0) };
	int width[6] = { 102,122,142,162,182,202 };
	float y = position.y;
	for (int i = numberOfDiscs-1; i >=0 ; i--)
	{
		Disk disk(Vector2f( position.x,y ), color[i], width[i]);
		tower.push(disk);
		y-=48;
	}
}

void Tower::movedDisk(Tower& tower1)
{
	Disk temp = peakTower();
	if (tower1.isTowerEmpty())
	{
		temp.setDiskPosition(tower1.position);
		tower.pop();
		tower1.tower.push(temp);
	} 
	else
	{
		Vector2f pos = tower1.peakTower().getDiskPosition();
		temp.setDiskPosition(Vector2f(pos.x, pos.y - 48));
		tower.pop();
		tower1.tower.push(temp);
	}
}

Disk Tower::peakTower()
{
	return tower.top();
}

bool Tower::isTowerEmpty()
{
	return tower.empty();
}

int Tower::sizeTower()
{
	return tower.size();
}

bool Tower::checkRules(Tower& tower1)
{ 
	if (tower.empty())
	{
		return true;
	}
	if (tower1.isTowerEmpty())
	{
		return false;
	}
	return tower.top().getSize().x >= tower1.tower.top().getSize().x;
}


