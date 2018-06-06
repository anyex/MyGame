#ifndef _TEXTURE_H_
#define _TEXTURE_H_
#include "GameWnd.h"
#include <stb/stb_image.h>
#include <stdio.h>

#pragma warning(disable: 4996)
#define BITMAP_ID 0x4D42
class Texture {
public:
	int width;//纹理的长，宽
	int height;
	int nrChannels;//颜色通道数
	unsigned char* image;//纹理数据
	GLuint textureID;//纹理ID
public:
	Texture() {};
	Texture(const char* filename);
	void Set(const char* filename);

	bool LoadBitmap(const char *file);
};


#endif


