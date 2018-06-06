#include "GNode.h"
//判断是否是第一个孩子节点
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
//判断此节点是否是最后一个孩子节点
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
//为该节点插入一个双亲节点
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
//为该节点插入一个子节点
void GNode::InsertChildNode(GNode* newChild)
{
	if (newChild->IsParent())//如果有双亲节点
	{
		newChild->DetachParent();//断开与双亲节点的连接
	}
	newChild->parentNode = this;

	if (childNode)
	{
		newChild->prevNode = childNode->prevNode;
	}
}
//断开与双亲节点的连接
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
//计数节点数目
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