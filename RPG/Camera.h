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
	void LookAt(GObject* object);//�۲�һ������
	void MoveObject(GObject* object);//�ƶ���ĳһ������

	void RotateYaw(float radians);//��Y����ת(ƫת)
	void RotatePitch(float radians);//��x����ת(����)
	void RotateRoll(float radians);//��z����ת(���)
	void Update(float deltaTime);//�����ڸ���
	void MoveDirect(Vector3 moveDirect);//����ĳһ�������ƶ�
	void SwitchTo3D();//ת��Ϊ3D����ϵ
	void SwitchTo2D();//ת��Ϊ2D����ϵ
	void RotateView(float angle, float x, float y, float z);

public:
	//�������
	Vector3 pos;
	Vector3 view;
	Vector3 up;
	float yaw;//��λ��
	float pitch;//�����Ƕ�
	Vector3 speed;//�任�ٶ�
	Vector3 forword, right;//����ĳ������������
	bool moveLeft, moveRight, moveForward, moveBack;

	int w, h;//���ڵĳ���
	
};



#endif