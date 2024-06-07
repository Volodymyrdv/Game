#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Disk:public Drawable,public Transformable
{
public:
	Disk(const Vector2f& position, const Color& color, float width);
	void setDiskPosition(Vector2f pos);
	Vector2f getDiskPosition() const;
	Vector2f getSize() const;

private:
	Vector2f position;
	RectangleShape shape;
	virtual void draw(RenderTarget& target, RenderStates states) const override;
};

