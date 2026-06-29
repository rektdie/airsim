#include "object.h"
#include <iostream>

Object::Object(const std::string& filePath)
{
    std::cout << Import(filePath) << std::endl;
}

bool Object::Import(const std::string& path)
{
	Assimp::Importer importer;

    const aiScene* currScene = importer.ReadFile(path,
        aiProcess_CalcTangentSpace |
        aiProcess_Triangulate |
        aiProcess_JoinIdenticalVertices |
        aiProcess_SortByPType);

    // Import failed
    if (nullptr == currScene) {
		std::cout << "Error importing file: " << importer.GetErrorString() << std::endl;
        return false;
    }

    // Now we can access the file's contents.
	scene = currScene;

    // We're done. Everything will be cleaned up by the importer destructor
    return true;
}