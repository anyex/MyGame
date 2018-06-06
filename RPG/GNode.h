#ifndef _GNODE_H_
#define _GNODE_H_
#include <stdio.h>

class GNode {
public:
	GNode* parentNode;//˫�׽ڵ�
	GNode* childNode;//���ӽڵ�
	GNode* prevNode;//ǰ�ڵ�
	GNode* nextNode;//��ڵ�

public:
	bool IsParent() { return (parentNode != NULL); }//�ж��Ƿ���˫�׽ڵ�
	bool IsChild(){ return (childNode != NULL); }//�ж��Ƿ��к��ӽڵ�
	bool IsFristChildNode();//�ж��Ƿ��ǵ�һ�����ӽڵ�
	bool IsLastChildNode();//�жϴ˽ڵ��Ƿ������һ�����ӽڵ�
	void InsertParentNode(GNode* newParent);//Ϊ�ýڵ����һ��˫�׽ڵ�
	void InsertChildNode(GNode* newChild);//Ϊ�ýڵ����һ���ӽڵ�
	void DetachParent();//�Ͽ���˫�׽ڵ������
	int CountGNode();//�����ڵ���Ŀ
	GNode();
	GNode(GNode* node);
	virtual ~GNode();

};

#endif
