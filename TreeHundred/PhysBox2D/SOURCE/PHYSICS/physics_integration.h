// This class is the base interface of all integration classes
// It is a self explenatory class, the only thing that is worth
// mentioning is that some classes come with a scale factor for
// their delta time that should be passed to the delta time of
// their integration to get the desired results.

#pragma once

// -- LOCAL

// .. REFERENCES

#include "physics_entity.h"
#include <assert.h>

// -- GLOBAL

// .. CONSTANTS

// .. TYPES

class PHYSICS_INTEGRATION
{
	// -- PUBLIC

public:

	// .. CONSTRUCTORS

	PHYSICS_INTEGRATION( void ) = default;


	// ~~

	virtual ~PHYSICS_INTEGRATION( void ) = default;

	// .. ACCESSORS

	// .. INQUERIES

	// .. OPERATIONS

	virtual void Update( PHYSICS_ENTITY& physics_entity, const float delta_time ) = 0;

	// .. FUNCTIONS

	// -- PRIVATE

private:

	// .. ATTRIBUTES

	// .. VARIABLES

};