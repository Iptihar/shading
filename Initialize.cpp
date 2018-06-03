#include "Initialize.h"
#include "Error.h"
#include "Rec.h"

Initialize::Initialize()
{
}


Initialize::~Initialize()
{
}

void Initialize::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Colorful", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);
	SDL_GLContext glContex = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK){
		fatalError("could not initialize glew!");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0, 0, 0, 1.0);

	initShader();
}

void Initialize::initShader()
{
	colorful.compiler("shader.vert", "shader.frag");
	colorful.attribute("position");
	colorful.attribute("vColor");
	colorful.linker();
}

void Initialize::run()
{
	init();
	_image.initRec(-0.5f, 0.5f, 1.0f, -1.0f);
	draw();
	
}
void Initialize::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	colorful.use();
	_image.draw();
	colorful.unUse();
	SDL_GL_SwapWindow(window);
}