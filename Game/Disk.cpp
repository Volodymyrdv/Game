#include "Disk.h"
#include <iostream>
void Disk::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(shape);
}

Disk::Disk(const Vector2f& position, const Color& color, float width)
{
	this->position = position;
	shape.setSize(Vector2f(width, 48));
	shape.setPosition(position);
	shape.setFillColor(color);
	shape.setOrigin(width / 2, 48 / 2);
	shape.setOutlineColor(Color::Black);
	shape.setOutlineThickness(2);
}

void Disk::setDiskPosition(Vector2f pos)
{
	position = pos;
	shape.setPosition(pos);
}

Vector2f Disk::getDiskPosition() const
{
	return shape.getPosition();
}

Vector2f Disk::getSize() const
{
	return shape.getSize();
}
