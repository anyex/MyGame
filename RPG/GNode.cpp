#include "GNode.h"
//�ж��Ƿ��ǵ�һ�����ӽڵ�
bool GNode::IsFristChildNode()
{
	if (parentNode)
	{
		return (parentNode->childNode == this);
	}
	else {
		return false;
	}
}
//�жϴ˽ڵ��Ƿ������һ�����ӽڵ�
bool GNode::IsLastChildNode()
{
	if (parentNode)
	{
		return (parentNode->childNode->parentNode == this);
	}
	else
	{
		return false;
	}
}
//Ϊ�ýڵ����һ��˫�׽ڵ�
void GNode::InsertParentNode(GNode* newParent)
{
	if (parentNode)
	{
		DetachParent();
	}
	parentNode = newParent;
	if (parentNode->childNode)
	{
		prevNode = parentNode->childNode->prevNode;
		nextNode = prevNode->childNode;
		parentNode->childNode->parentNode->nextNode = this;
		parentNode->childNode->prevNode = this;
	}
	else {
		parentNode->childNode = this;
	}

}
//Ϊ�ýڵ����һ���ӽڵ�
void GNode::InsertChildNode(GNode* newChild)
{
	if (newChild->IsParent())//�����˫�׽ڵ�
	{
		newChild->DetachParent();//�Ͽ���˫�׽ڵ������
	}
	newChild->parentNode = this;

	if (childNode)
	{
		newChild->prevNode = childNode->prevNode;
	}
}
//�Ͽ���˫�׽ڵ������
void GNode::DetachParent()
{
	if (parentNode&&parentNode->childNode == this)
	{
		if (nextNode != this)
		{
			parentNode->childNode = nextNode;
		}
		else
			parentNode->childNode = NULL;
	}
	prevNode->nextNode = nextNode;
	nextNode->prevNode = prevNode;

	prevNode = this;
	nextNode = this;
}
//�����ڵ���Ŀ
int GNode::CountGNode()
{
	if (childNode)
	{
		return childNode->CountGNode() + 1;

	}
	else
		return 1;

}
GNode::GNode()
{
	parentNode = childNode = NULL;
	prevNode = nextNode = this;
}
GNode::GNode(GNode* node)
{
	parentNode = childNode = NULL;
	prevNode = nextNode = this;
	InsertParentNode(node);
}
GNode:: ~GNode()
{
	DetachParent();
	while (childNode)
	{
		delete childNode;
	}
}