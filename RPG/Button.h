#ifndef _BUTTON_H_
#define _BUTTON_H_
#include "Sprite.h"

class Button:public Sprite {
public:
	Button(Texture* tex) :Sprite(tex) {};
	void SetOnClick();//����¼�
	
};
#endif
