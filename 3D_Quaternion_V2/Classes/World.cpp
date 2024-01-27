#include "World.h"

World::World()
{
	listOfActors = {};
	listOfCameras = {};
	activeCamNum = 0;
}

World::~World()
{

}

std::vector<Actor*> World::GetActorList() const
{
	return listOfActors;
}

void World::SetActorList(const std::vector<Actor*>& in_listOfActors)
{
	listOfActors = in_listOfActors;
}

void World::AppendActorList(Actor* in_actor)
{
	listOfActors.push_back(in_actor);
}

std::vector<Camera*> World::GetCameraList() const
{
	return listOfCameras;
}

void World::SetCameraList(const std::vector<Camera*> in_listOfCameras)
{
	listOfCameras = in_listOfCameras;
}

void World::AppendCameraList(Camera* in_camera)
{
	listOfCameras.push_back(in_camera);
}

int World::GetCamNum() const
{
	return activeCamNum;
}

void World::ActiveCam(int in_cameraNumber)
{
	activeCamNum = in_cameraNumber;
}
