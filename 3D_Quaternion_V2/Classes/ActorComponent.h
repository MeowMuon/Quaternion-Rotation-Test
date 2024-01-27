#pragma once
#include "Actor.h"

class ActorComponent :public Actor
{
private:
	Actor* mainActor;
	DVector relativeLocation, relativeScale;
	DQuaternion relativeRotation;

public:
	ActorComponent(Actor* in_mainActor);
	~ActorComponent();

	virtual Actor* GetMainActor()const;
	virtual void SetMainActor(Actor* in_actor);
	virtual DVector GetRLocation()const;
	virtual void SetRLocation(DVector in_location);
	virtual DVector GetRScale()const;
	virtual void SetRScale(DVector in_scale);
	virtual DQuaternion GetRRotationQ()const;
	virtual void SetRRotationQ(DQuaternion in_rotation);

	virtual void RMove(DVector in_vector);
	virtual void RRotateQ(DQuaternion in_rotation);
	virtual void RScale(DVector in_vector);

	virtual void tick(double DT)override;
};