#ifndef _SCENCE_H_
#define _SCENCE_H_
#include "Camera.h"
class Scence {
public:
	void OnAnimate(float deltaTime);
	void OnDraw(Camera* camera);
	void OnPrepare();

};
#endif
