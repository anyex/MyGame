#include "Terrain.h"

void Terrain::InitTerrain(float h)
{
	int index = 0;
	int Vertex;
	for (int z = 0;z < MAP_W;z++)
	{
		for (int x = 0;x < MAP_W;x++)
		{
			Vertex = z*MAP_W + x;
			g_terrain[Vertex][0] = (float)x*MAP_SCALE;
			g_terrain[Vertex][1] = (float)h + FRAND*h;
			g_terrain[Vertex][2] = -float(z)*MAP_SCALE;

			texcoord[Vertex][0] = (float)x;
			texcoord[Vertex][1] = (float)z;

			g_index[index++] = Vertex;
			g_index[index++] = Vertex + MAP_W;
		}
	}

	glEnableClientState(GL_VERTEX_ARRAY);//启用顶点数组
	glVertexPointer(3, GL_FLOAT, 0, g_terrain);//指定顶点数组的位置，3表示每个顶点由三个量组成
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, texcoord);//启用纹理数组
}

void Terrain::Draw()
{
	glBindTexture(GL_TEXTURE_2D, texID);
	//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	for (int z = 0; z < MAP_W - 1; z++)
		glDrawElements(GL_TRIANGLE_STRIP, MAP_W * 2, GL_UNSIGNED_INT, &g_index[z*MAP_W * 2]);

}