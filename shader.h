#pragma once
#include <string>
#include <GL/glew.h>
#include <windows.h>

class shader
{
public:
	shader();
	virtual ~shader();

	void compiler(const std::string& vPath, const std::string& fPath);
	void linker();
	void attribute(const std::string& name);
	void use();
	void unUse();

private:
	int num_attribute = 0;
	GLuint program;
	GLuint vertex;
	GLuint fragment;

};

