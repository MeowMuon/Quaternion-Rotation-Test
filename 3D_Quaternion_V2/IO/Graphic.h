#pragma once
#include <graphics.h>
#include "../Classes/World.h"

class Graphic
{
public:
	static int SCREEN_WIDTH, SCREEN_HEIGHT;

public:
	static void InitGraph(int in_width, int in_height);
	static void CloseGraph();
private:
	static Actor C_ToActor(const Actor* in_actor);
	static Actor C_ACToActor(const ActorComponent* in_actorComponent);
	static std::vector<DVector> C_ToWorld(const Actor* in_actor);
	static std::vector<DVector> C_ToCamera(const std::vector<DVector>& in_points, const Camera* in_camera);
	static std::vector<DVector> C_R_PointsToCamera(const Actor* in_actor, const Camera* in_camera);
	static std::vector<DVector> C_R_ACPointsToCamera(const ActorComponent* in_actorComponent, const Camera* in_camera);
	static std::vector<DVector2> C_R_PointsToScreen(const std::vector<DVector>& in_points, const Camera* in_camera);
	static DVector2 C_R_PointToScreen(const DVector in_point, const Camera* in_camera);
	static DVector2 C_ConvertNegativeLine(const DVector in_negativePoint, const DVector in_positivePoint, const Camera* in_camera);
	static void DisplayAC(const Actor* in_actorComponent, const Camera* in_camera);
public:
	static void DisplayA(const Actor* in_actor, const Camera* in_camera);

	static void Erase();
};