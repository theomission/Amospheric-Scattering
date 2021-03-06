#pragma once

#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#include <gl/glew.h>
#include <gl/GL.h>
#include <SOIL.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <vector>


using namespace std;

struct TextureUnit
{
	GLuint m_activeUnit;
	GLuint m_target;
	GLuint m_ID;
};

class TextureManager{

private:
	TextureManager();
	TextureManager(const TextureManager&) = delete;
	const TextureManager& operator=(const TextureManager&) = delete;

	/*---------------------------------------Data Members---------------------------------------*/
	static unique_ptr<TextureManager> m_Instance;
	static once_flag m_onceFlag;

	map<string, GLuint> m_texIDMap;
	//map<GLuint, GLuint> m_textureTargets;
	vector<TextureUnit> m_activeTextureUnits;
	unsigned int m_activeTextureCount; 

public:

	static TextureManager& GetInstance();
	void LoadTexture2D(string filename, string textureAlias);
	void LoadTextureCubeMap(vector<string> textureFaces, string textureAlias);
	void BindTexture2D(string texAlias, string sampler, GLuint program);
	void BindTextureCubeMap(string texAlias, string sampler, GLuint program);
	void unbindTexture(string texAlias);
	void unbindAllTextures();


};

#endif