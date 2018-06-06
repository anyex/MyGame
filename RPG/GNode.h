#ifndef _GNODE_H_
#define _GNODE_H_
#include <stdio.h>

class GNode {
public:
	GNode* parentNode;//双亲节点
	GNode* childNode;//孩子节点
	GNode* prevNode;//前节点
	GNode* nextNode;//后节点

public:
	bool IsParent() { return (parentNode != NULL); }//判断是否有双亲节点
	bool IsChild(){ return (childNode != NULL); }//判断是否有孩子节点
	bool IsFristChildNode();//判断是否是第一个孩子节点
	bool IsLastChildNode();//判断此节点是否是最后一个孩子节点
	void InsertParentNode(GNode* newParent);//为该节点插入一个双亲节点
	void InsertChildNode(GNode* newChild);//为该节点插入一个子节点
	void DetachParent();//断开与双亲节点的连接
	int CountGNode();//计数节点数目
	GNode();
	GNode(GNode* node);
	virtual ~GNode();

};

#endif
