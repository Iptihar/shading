#include "shader.h"
#include "Error.h"
#include <fstream>
#include <vector>
shader::shader()
{
	
}

shader::~shader()
{

}

void shader::compiler(const std::string& vPath, const std::string& fPath)
{
	program = glCreateProgram();
	vertex = glCreateShader(GL_VERTEX_SHADER);
	if (vertex == 0) {
		fatalError("Vertex shader failed to create!");
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	if (vertex == 0) {
		fatalError("Fragment shader failed to create!");
	}
	std::ifstream vFile(vPath);
	if (vFile.fail()) {
		perror(vPath.c_str());
		fatalError("Failed to open" + vPath);
	}
	std::string vContent = "";
	std::string vline;
	while (std::getline(vFile, vline)) {
		vContent += vline + "\n";
	}
	vFile.close();
	const char* vContentPtr = vContent.c_str();
	glShaderSource(vertex, 1, &vContentPtr, nullptr);
	glCompileShader(vertex);

	std::ifstream fFile(fPath);
	if (fFile.fail()) {
		perror(fPath.c_str());
		fatalError("Failed to open" + fPath);
	}
	std::string fContent = "";
	std::string fline;
	while (std::getline(fFile, fline)) {
		fContent += fline + "\n";
	}
	fFile.close();
	const char* fContentPtr = fContent.c_str();
	glShaderSource(fragment, 1, &fContentPtr, nullptr);
	glCompileShader(fragment);
}
void shader::linker()
{
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	GLint isLinked = 0;
	glGetProgramiv(program, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE){
		GLint maxLength = 0;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);
		glDeleteProgram(program);
		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void shader::attribute(const std::string& name)
{
	glBindAttribLocation(program, num_attribute++, name.c_str());
}

void shader::use()
{
	glUseProgram(program);
	for (int i = 0; i < num_attribute; i++)
	{
		glEnableVertexAttribArray(i);
	}
}

void shader::unUse()
{
	glUseProgram(0);
	for (int i = 0; i < num_attribute; i++)
	{
		glDisableVertexAttribArray(i);
	}
}