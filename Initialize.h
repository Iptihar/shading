#pragma once
#include<SDL2/SDL.h>
#include <GL/glew.h>
#include "Rec.h"
#include "shader.h"
#include <windows.h>

class Initialize
{
public:
	Initialize();
	~Initialize();
	void run();

private:
	void init();
	void initShader();
	SDL_Window* window;
	void draw();

	Rec _image;
	shader colorful;
};

