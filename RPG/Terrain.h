#ifndef _TERRAIN_H_
#define _TERRAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include "GameWnd.h"
#define MAP_W 32
#define MAP_SCALE 24
#define FRAND  (((float)rand()-(float)rand())/RAND_MAX)
class Terrain {
public:
	float g_terrain[MAP_W*MAP_W][3];//��������
	int g_index[MAP_W*MAP_W*2];//��������,���涥��
	float texcoord[MAP_W*MAP_W][2];//�������飬��ͼ����
	GLuint texID;//������ͼ
	
public:
	void InitTerrain(float h);
	void Draw();
	
};
#endif
