
#pragma once

// -- LOCAL

// .. REFERENCES

#include "physics_integration.h"
#include "physics_entity.h"


// -- GLOBAL

#define ENABLE_SEMI_EULER 1

// .. TYPES

class PHYSICS_INTEGRATION_EULER : public PHYSICS_INTEGRATION
{
	// -- PUBLIC
	public:

	// .. CONSTRUCTORS

	PHYSICS_INTEGRATION_EULER( void ) = default;

	// ~~

	~PHYSICS_INTEGRATION_EULER( void ) = default;


	void Update( PHYSICS_ENTITY& physics_entity, const float delta_time ) override;

	// .. OPERATIONS

	void UpdateVelocity( PHYSICS_ENTITY& physics_entity, const float delta_time );

	// ~~

	void UpdatePosition( PHYSICS_ENTITY& physics_entity, const float delta_time );
};