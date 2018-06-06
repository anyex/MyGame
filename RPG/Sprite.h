#ifndef _SPRITE_H_
#define _SPRITE_H_
#include "Texture.h"
class Texture;
class Sprite {
public:

	Sprite(Texture* tex) {  texture = tex; };
	void SetRect(float x, float y, float width, float height);
	void Draw();

	Texture* texture;
	Vector3 pos;//Œª÷√
	Vector3 Rect[4];//«¯”Ú

};


#endif