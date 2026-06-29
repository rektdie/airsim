#pragma once
#include <string>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>

class Object
{
public:
	Object(const std::string& filePath);

	bool Import(const std::string& path);

private:
	const aiScene* scene = nullptr;
};