#include "Renderable.h"
using namespace RenderCore;

Renderable::Renderable() : Component(), mMaterial(NULL), mMesh(NULL)
{

}

Renderable::~Renderable()
{

}

void Renderable::Initialize(const std::string& meshName, const std::string& materialName)
{

}