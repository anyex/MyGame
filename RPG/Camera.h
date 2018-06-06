#ifndef _CAMERA_H_
#define _CAMERA_H_
#include "Vector3.h"
#include "GObject.h"
#include "GameWnd.h"
class Camera {
public:
	Camera();
	Camera(Vector3 *look);
	Camera(Vector3 *pos, Vector3* look);
	~Camera();
	void LookAt(GObject* object);//观察一个对象
	void MoveObject(GObject* object);//移动到某一个对象

	void RotateYaw(float radians);//绕Y轴旋转(偏转)
	void RotatePitch(float radians);//绕x轴旋转(俯仰)
	void RotateRoll(float radians);//绕z轴旋转(侧滚)
	void Update(float deltaTime);//做周期更新
	void MoveDirect(Vector3 moveDirect);//沿着某一个方向移动
	void SwitchTo3D();//转变为3D坐标系
	void SwitchTo2D();//转变为2D坐标系
	void RotateView(float angle, float x, float y, float z);

public:
	//定义相机
	Vector3 pos;
	Vector3 view;
	Vector3 up;
	float yaw;//方位角
	float pitch;//俯仰角度
	Vector3 speed;//变换速度
	Vector3 forword, right;//相机的朝向和右坐标轴
	bool moveLeft, moveRight, moveForward, moveBack;

	int w, h;//窗口的长宽
	
};



#endif