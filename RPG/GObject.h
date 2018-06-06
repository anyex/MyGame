#ifndef _GOBJECT_H_
#define _GOBJECT_H_
#include "GNode.h"
#include "Camera.h"
class Camera;
class GObject:public GNode {
	virtual void OnAnimate();//执行基本的物理处理
	
	virtual void OnDraw(Camera* c);//按照给定的视点绘制物体
	virtual void OnCollision(GObject *object);//碰撞检测
public:
	Vector3 position;//物体的位置
	Vector3 speed;//物体的速度
	Vector3 acceleration;//物体的加速度
	float radius;//碰撞检测半径
	bool isDead;//是否存在
	

};
#endif
