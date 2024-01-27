#pragma once
#include <vector>
#include "Object.h"

class Actor :public Object
{
private:
	std::vector<DVector> points;
	std::vector<Actor*> listOfActorComponents;

public:
	Actor();
	Actor(DVector in_location, DQuaternion in_rotation, DVector in_scale);
	Actor(std::vector<DVector> in_points);
	~Actor();

	virtual std::vector<DVector> GetPoints()const;
	virtual void SetPoints(const std::vector<DVector>& in_points);
	virtual void AppendPoint(const DVector& in_point);
	virtual std::vector<Actor*> GetActorComponents()const;
	virtual void SetActorComponents(const std::vector<Actor*>& in_actorComponents);
	virtual void AppendActorComponent(Actor* in_actorComponent);

	virtual void tick(double DT)override;
};