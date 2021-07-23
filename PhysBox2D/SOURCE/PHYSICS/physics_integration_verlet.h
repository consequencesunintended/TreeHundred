#pragma once

// -- LOCAL

// .. REFERENCES

#include "physics_integration.h"
#include "physics_entity.h"

// -- GLOBAL

// .. TYPES

class PHYSICS_INTEGRATION_VERLET : public PHYSICS_INTEGRATION
{
	// -- PUBLIC
	public:

	// .. CONSTRUCTORS

	PHYSICS_INTEGRATION_VERLET( void ) = default;

	// ~~

	~PHYSICS_INTEGRATION_VERLET( void ) = default;

	void Update( PHYSICS_ENTITY& physics_entity, const float delta_time ) override;
};