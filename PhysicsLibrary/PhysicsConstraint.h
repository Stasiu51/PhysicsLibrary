#pragma once

#ifdef PHYSICSLIBRARY_EXPORTS
#define PHYSICSLIBRARY_API __declspec(dllexport)
#else
#define PHYSICSLIBRARY_API __declspec(dllimport)
#endif

class PHYSICSLIBRARY_API PhysicsConstraint
{
public:
	virtual void applyConstraint() = 0;
};

