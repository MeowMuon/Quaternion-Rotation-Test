#include "ActorComponent.h"

ActorComponent::ActorComponent(Actor* in_mainActor) :Actor()
{
	in_mainActor->AppendActorComponent(this);
	mainActor = in_mainActor;
	relativeLocation = DVector(0.0);
	relativeScale = DVector(1.0);
	relativeRotation = DQuaternion(1, 0, 0, 0);
}

ActorComponent::~ActorComponent()
{

}

Actor* ActorComponent::GetMainActor() const
{
	return mainActor;
}

void ActorComponent::SetMainActor(Actor* in_actor)
{
	mainActor = in_actor;
}

DVector ActorComponent::GetRLocation() const
{
	return relativeLocation;
}

void ActorComponent::SetRLocation(DVector in_location)
{
	relativeLocation = in_location;
}

DVector ActorComponent::GetRScale() const
{
	return relativeScale;
}

void ActorComponent::SetRScale(DVector in_scale)
{
	relativeScale = in_scale;
}

DQuaternion ActorComponent::GetRRotationQ() const
{
	return relativeRotation;
}

void ActorComponent::SetRRotationQ(DQuaternion in_rotation)
{
	relativeRotation = in_rotation;
}

void ActorComponent::RMove(DVector in_vector)
{
	relativeLocation = relativeLocation + in_vector;
}

void ActorComponent::RRotateQ(DQuaternion in_rotation)
{
	relativeRotation = Calculator::MixRotateQuaternion(relativeRotation, in_rotation);
}

void ActorComponent::RScale(DVector in_vector)
{
	relativeScale = relativeScale + in_vector;
}

void ActorComponent::tick(double DT)
{
	if (canTick)
	{
		Actor::tick(DT);
		//Tick:
		SetLocation(mainActor->GetLocation());
		SetRotationQ(mainActor->GetRotationQ());
		SetScale(mainActor->GetScale());
	}
}
