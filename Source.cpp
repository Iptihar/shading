#include <windows.h>
#include <GL/glew.h>
#include <string>
#include "shader.h"
#include "Error.h"
#include <SDL2/SDL.h>
#include "Rec.h"
#include "Initialize.h"

int main(int argc, char *argv[]) {
	Initialize go;
	go.run();
	system("pause");
	return 0;
}