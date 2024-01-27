#include "Graphic.h"

int Graphic::SCREEN_WIDTH = 0;
int Graphic::SCREEN_HEIGHT = 0;

void Graphic::InitGraph(int in_width, int in_height)
{
	SCREEN_WIDTH = in_width;
	SCREEN_HEIGHT = in_height;
	initgraph(in_width, in_height);
}

void Graphic::CloseGraph()
{
	closegraph();
}

Actor Graphic::C_ToActor(const Actor* in_actor)
{
	DVector temp;
	Actor ans;
	ans.SetLocation(in_actor->GetLocation());
	ans.SetRotationQ(in_actor->GetRotationQ());
	ans.SetScale(in_actor->GetScale());
	int lTemp = in_actor->GetPoints().size();
	for (int i = 0; i < lTemp; i++)
	{
		temp = in_actor->GetPoints().at(i);
		//Scalling
		temp.x *= in_actor->GetScale().x;
		temp.y *= in_actor->GetScale().y;
		temp.z *= in_actor->GetScale().z;
		ans.AppendPoint(temp);
	}
	return ans;
}

Actor Graphic::C_ACToActor(const ActorComponent* in_actorComponent)
{
	Actor ans;
	DVector temp;
	ans.SetLocation(in_actorComponent->GetMainActor()->GetLocation());
	ans.SetRotationQ(in_actorComponent->GetMainActor()->GetRotationQ());
	ans.SetScale(in_actorComponent->GetMainActor()->GetScale());
	int lTemp = in_actorComponent->GetPoints().size();
	for (int i = 0; i < lTemp; i++)
	{
		temp = in_actorComponent->GetPoints().at(i);
		temp.x *= in_actorComponent->GetRScale().x;
		temp.y *= in_actorComponent->GetRScale().y;
		temp.z *= in_actorComponent->GetRScale().z;
		Calculator::RotatePQ(temp, in_actorComponent->GetRRotationQ(), temp);
		temp = temp + in_actorComponent->GetRLocation();
		temp.x *= in_actorComponent->GetMainActor()->GetScale().x;
		temp.y *= in_actorComponent->GetMainActor()->GetScale().y;
		temp.z *= in_actorComponent->GetMainActor()->GetScale().z;
		ans.AppendPoint(temp);
	}
	return ans;
}

std::vector<DVector> Graphic::C_ToWorld(const Actor* in_actor)
{
	DVector temp;
	std::vector<DVector> ans;
	int lTemp = in_actor->GetPoints().size();
	for (int i = 0; i < lTemp; i++)
	{
		temp = in_actor->GetPoints().at(i);
		Calculator::RotatePQ(temp, in_actor->GetRotationQ(), temp);
		ans.push_back(temp + in_actor->GetLocation());
	}
	return ans;
}

std::vector<DVector> Graphic::C_ToCamera(const std::vector<DVector>& in_points, const Camera* in_camera)
{
	DVector temp;
	std::vector<DVector> ans;
	int lTemp = in_points.size();
	for (int i = 0; i < lTemp; i++)
	{
		temp = in_points.at(i) - in_camera->GetLocation();
		Calculator::RotatePQ(temp, in_camera->GetRotationQ().Conjugate(), temp);
		ans.push_back(temp);
	}
	return ans;
}

std::vector<DVector> Graphic::C_R_PointsToCamera(const Actor* in_actor, const Camera* in_camera)
{
	Actor temp;
	std::vector<DVector> ans;
	temp = C_ToActor(in_actor);
	ans = C_ToWorld(&temp);
	ans = C_ToCamera(ans, in_camera);
	return ans;
}

std::vector<DVector> Graphic::C_R_ACPointsToCamera(const ActorComponent* in_actorComponent, const Camera* in_camera)
{
	Actor temp;
	std::vector<DVector> ans;
	temp = C_ACToActor(in_actorComponent);
	ans = C_ToWorld(&temp);
	ans = C_ToCamera(ans, in_camera);
	return ans;
}

std::vector<DVector2> Graphic::C_R_PointsToScreen(const std::vector<DVector>& in_points, const Camera* in_camera)
{
	DVector temp;
	DVector2 temp2;
	std::vector<DVector2> ans;
	int lTemp = in_points.size();
	for (int i = 0; i < lTemp; i++)
	{
		temp = in_points.at(i);
		temp2.x = SCREEN_WIDTH / 2 - (temp.y * in_camera->GetViewDistance() / temp.x);
		temp2.y = SCREEN_HEIGHT / 2 - (temp.z * in_camera->GetViewDistance() / temp.x);
		ans.push_back(temp2);
	}
	return ans;
}

DVector2 Graphic::C_R_PointToScreen(const DVector in_point, const Camera* in_camera)
{
	DVector2 ans;
	ans.x = SCREEN_WIDTH / 2 - (in_point.y * in_camera->GetViewDistance() / in_point.x);
	ans.y = SCREEN_HEIGHT / 2 - (in_point.z * in_camera->GetViewDistance() / in_point.x);
	return ans;
}

DVector2 Graphic::C_ConvertNegativeLine(const DVector in_negativePoint, const DVector in_positivePoint, const Camera* in_camera)
{
	double a = 1;
	DVector temp = DVector
	(
		a,
		in_negativePoint.y - (
			(in_negativePoint.y - in_positivePoint.y) *
			(fabs(in_negativePoint.x) + a) /
			(fabs(in_negativePoint.x) + fabs(in_positivePoint.x) + a)
			),
		in_negativePoint.z - (
			(in_negativePoint.z - in_positivePoint.z) *
			(fabs(in_negativePoint.x) + a) /
			(fabs(in_negativePoint.x) + fabs(in_positivePoint.x) + a)
			)
		);
	DVector2 ans = C_R_PointToScreen(temp, in_camera);
	return ans;
}

void Graphic::DisplayAC(const Actor* in_actorComponent, const Camera* in_camera)
{
	std::vector<DVector> temp;
	std::vector<DVector2> temp2;
	ActorComponent* AC = dynamic_cast<ActorComponent*>(const_cast<Actor*>(in_actorComponent));
	int lTemp;
	temp = C_R_ACPointsToCamera(AC, in_camera);
	temp2 = C_R_PointsToScreen(temp, in_camera);
	lTemp = temp2.size();
	for (int i = 1; i < lTemp; i++)
	{
		if (temp[i - 1].x < 0 && temp[i].x < 0)
		{
			continue;
		}
		else if (temp[i - 1].x < 0)
		{
			DVector2 tempConvertedPoint = C_ConvertNegativeLine(temp[i - 1], temp[i], in_camera);
			line(tempConvertedPoint.x, tempConvertedPoint.y, temp2.at(i).x, temp2.at(i).y);
		}
		else if (temp[i].x < 0)
		{
			DVector2 tempConvertedPoint = C_ConvertNegativeLine(temp[i], temp[i - 1], in_camera);
			line(temp2.at(i - 1).x, temp2.at(i - 1).y, tempConvertedPoint.x, tempConvertedPoint.y);
		}
		else
		{
			line(temp2.at(i - 1).x, temp2.at(i - 1).y, temp2.at(i).x, temp2.at(i).y);
		}
	}
	lTemp = in_actorComponent->GetActorComponents().size();
	for (int i = 0; i < lTemp; i++)
	{
		DisplayAC(in_actorComponent->GetActorComponents().at(i), in_camera);
	}

}

void Graphic::DisplayA(const Actor* in_actor, const Camera* in_camera)
{
	std::vector<DVector> temp;
	std::vector<DVector2> temp2;
	temp = C_R_PointsToCamera(in_actor, in_camera);
	temp2 = C_R_PointsToScreen(temp, in_camera);
	int lTemp = temp2.size();
		for (int i = 1; i < lTemp; i++)
		{
			if (temp[i - 1].x < 0 && temp[i].x < 0)
			{
				continue;
			}
			else if (temp[i - 1].x < 0)
			{
				DVector2 tempConvertedPoint = C_ConvertNegativeLine(temp[i - 1], temp[i], in_camera);
				line(tempConvertedPoint.x, tempConvertedPoint.y, temp2.at(i).x, temp2.at(i).y);
			}
			else if (temp[i].x < 0)
			{
				DVector2 tempConvertedPoint = C_ConvertNegativeLine(temp[i], temp[i - 1], in_camera);
				line(temp2.at(i - 1).x, temp2.at(i - 1).y, tempConvertedPoint.x, tempConvertedPoint.y);
			}
			else
			{
				line(temp2.at(i - 1).x, temp2.at(i - 1).y, temp2.at(i).x, temp2.at(i).y);
			}
		}
	lTemp = in_actor->GetActorComponents().size();
	for (int i = 0; i < lTemp; i++)
	{
		DisplayAC(in_actor->GetActorComponents().at(i), in_camera);
	}
}

void Graphic::Erase()
{
	cleardevice();
}
