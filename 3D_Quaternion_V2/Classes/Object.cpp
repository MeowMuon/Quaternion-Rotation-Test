#include "Object.h"

Object::Object()
{
    location = DVector(0.0);
    rotation = DQuaternion(1, 0, 0, 0);
    scale = DVector(1.0);
}

Object::Object(DVector in_location, DQuaternion in_rotation, DVector in_scale)
{
    location = in_location;
    rotation = in_rotation;
    scale = in_scale;
}

Object::Object(const Object& in_object)
{
    location = in_object.location;
    rotation = in_object.rotation;
    scale = in_object.scale;
}

DVector Object::GetLocation() const
{
    return location;
}

void Object::SetLocation(DVector in_location)
{
    location = in_location;
}

DVector Object::GetScale() const
{
    return scale;
}

void Object::SetScale(DVector in_scale)
{
    scale = in_scale;
}

DQuaternion Object::GetRotationQ() const
{
    return rotation;
}

void Object::SetRotationQ(DQuaternion in_rotation)
{
    rotation = in_rotation;
}

void Object::Move(DVector in_vector)
{
    location = location + in_vector;
}

void Object::RotateQ(DQuaternion in_rotation)
{
    rotation = Calculator::MixRotateQuaternion(rotation, in_rotation);
}

void Object::Scale(DVector in_vector)
{
    scale = scale + in_vector;
}

void Object::tick(double DT)
{
    if (canTick)
    {
        //Tick:

    }
}
