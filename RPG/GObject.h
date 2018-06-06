#ifndef _GOBJECT_H_
#define _GOBJECT_H_
#include "GNode.h"
#include "Camera.h"
class Camera;
class GObject:public GNode {
	virtual void OnAnimate();//ִ�л�����������
	
	virtual void OnDraw(Camera* c);//���ո������ӵ��������
	virtual void OnCollision(GObject *object);//��ײ���
public:
	Vector3 position;//�����λ��
	Vector3 speed;//������ٶ�
	Vector3 acceleration;//����ļ��ٶ�
	float radius;//��ײ���뾶
	bool isDead;//�Ƿ����
	

};
#endif
