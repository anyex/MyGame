#ifndef _TEXTURE_H_
#define _TEXTURE_H_
#include "GameWnd.h"
#include <stb/stb_image.h>
#include <stdio.h>

#pragma warning(disable: 4996)
#define BITMAP_ID 0x4D42
class Texture {
public:
	int width;//����ĳ�����
	int height;
	int nrChannels;//��ɫͨ����
	unsigned char* image;//��������
	GLuint textureID;//����ID
public:
	Texture() {};
	Texture(const char* filename);
	void Set(const char* filename);

	bool LoadBitmap(const char *file);
};


#endif


