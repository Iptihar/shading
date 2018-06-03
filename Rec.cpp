#include "Rec.h"
#include "Vertex.h"
#include <cstddef>

Rec::Rec()
{
	vbo = 0;
}


Rec::~Rec()
{
	if (vbo != 0) {
		glDeleteBuffers(1, &vbo);
	}
}

void Rec::initRec(float x, float y, float width, float height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	if (vbo == 0){
		glGenBuffers(1, &vbo);
	}
	Vertex vertex[6];
	vertex[0].position.x = x + width;
	vertex[0].position.y = y + height;

	vertex[1].position.x = x;
	vertex[1].position.y = y + height;

	vertex[2].position.x = x;
	vertex[2].position.y = y;

	vertex[3].position.x = x;
	vertex[3].position.y = y;

	vertex[4].position.x = x + width;
	vertex[4].position.y = y;

	vertex[5].position.x = x + width;
	vertex[5].position.y = y + height;

	for (int i = 0; i < 6; i++)
	{
		vertex[i].color.r = 255;
		vertex[i].color.g = 0;
		vertex[i].color.b = 255;
		vertex[i].color.a = 255;
	}
	
	vertex[1].color.r = 0;
	vertex[1].color.g = 0;
	vertex[1].color.b = 255;
	vertex[1].color.a = 255;

	vertex[4].color.r = 0;
	vertex[4].color.g = 255;
	vertex[4].color.b = 0;
	vertex[4].color.a = 255;

	vertex[5].color.r = 255;
	vertex[5].color.g = 0;
	vertex[5].color.b = 0;
	vertex[5].color.a = 255;

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Rec::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, color));

	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}