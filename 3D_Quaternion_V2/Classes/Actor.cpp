#include "Actor.h"

Actor::Actor():Object()
{
	points = {};
}

Actor::Actor(DVector in_location, DQuaternion in_rotation, DVector in_scale) : Object(in_location, in_rotation, in_scale)
{
	points = {};
}

Actor::Actor(std::vector<DVector> in_points):Object()
{
	points = in_points;
}

Actor::~Actor()
{
}

std::vector<DVector> Actor::GetPoints() const
{
	return points;
}

void Actor::SetPoints(const std::vector<DVector>& in_points)
{
	points = in_points;
}

void Actor::AppendPoint(const DVector& in_point)
{
	points.push_back(in_point);
}

std::vector<Actor*> Actor::GetActorComponents() const
{
	return listOfActorComponents;
}

void Actor::SetActorComponents(const std::vector<Actor*>& in_actorComponents)
{
	listOfActorComponents = in_actorComponents;
}

void Actor::AppendActorComponent(Actor* in_actorComponent)
{
	listOfActorComponents.push_back(in_actorComponent);
}

void Actor::tick(double DT)
{
	if (canTick)
	{
		Object::tick(DT);
		//Tick:
		int tempSize = listOfActorComponents.size();
		for (int i = 0; i < tempSize; i++)
		{
			listOfActorComponents.at(i)->tick(DT);
		}
	}
}