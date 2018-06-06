#include "Sprite.h"
void Sprite::SetRect(float x, float y, float width, float height)
{
	Rect[0].x = x;
	Rect[0].y = y;

	Rect[1].x = x + width;
	Rect[1].y = y;

	Rect[2].x = x + width;
	Rect[2].y = y + height;

	Rect[3].x = x;
	Rect[3].y = y + height;

}

void Sprite::Draw()
{
	glEnable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glBindTexture(GL_TEXTURE_2D, texture->textureID);

	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 1.0f);glVertex3f(Rect[0].x, Rect[0].y, Rect[0].z);
	glTexCoord2f(1.0f, 1.0f);glVertex3f(Rect[1].x, Rect[1].y, Rect[1].z);
	glTexCoord2f(1.0f, 0.0f);glVertex3f(Rect[2].x, Rect[2].y, Rect[2].z);
	glTexCoord2f(0.0f, 0.0f);glVertex3f(Rect[3].x, Rect[3].y, Rect[3].z);

	glEnd();
	
}