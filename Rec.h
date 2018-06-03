#pragma once
#include <GL/glew.h>
#include <windows.h>

class Rec
{
public:
	Rec();
    ~Rec();

	void initRec(float x, float y, float width, float height);
	void draw();
private:
	float _x;
	float _y;
	float _width;
	float _height;
	GLuint vbo;
};

