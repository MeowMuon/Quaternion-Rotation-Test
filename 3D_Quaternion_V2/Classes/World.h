#pragma once
#include <vector>
#include "../Calculator/Calculator.h"
#include "Object.h"
#include "Actor.h"
#include "ActorComponent.h"
#include "Camera.h"

class World
{
private:
	std::vector<Actor*> listOfActors;
	std::vector<Camera*> listOfCameras;
	int activeCamNum;

public:
	World();
	~World();

	std::vector<Actor*> GetActorList()const;
	void SetActorList(const std::vector<Actor*>& in_listOfActors);
	void AppendActorList(Actor* in_actor);
	std::vector<Camera*> GetCameraList()const;
	void SetCameraList(const std::vector<Camera*> in_listOfCameras);
	void AppendCameraList(Camera* in_camera);
	int GetCamNum()const;
	void ActiveCam(int in_cameraNumber);
};