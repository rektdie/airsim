#include "object.h"
#include <iostream>

Object::Object(const std::string& filePath)
{
    Import(filePath);
}

bool Object::Import(const std::string& path)
{
    scene = importer.ReadFile(path,
        aiProcess_CalcTangentSpace |
        aiProcess_Triangulate |
        aiProcess_JoinIdenticalVertices |
        aiProcess_SortByPType);

    // Import failed
    if (nullptr == scene) {
		std::cout << "Error importing file: " << importer.GetErrorString() << std::endl;
        return false;
    }

    // We're done. Everything will be cleaned up by the importer destructor
    return true;
}