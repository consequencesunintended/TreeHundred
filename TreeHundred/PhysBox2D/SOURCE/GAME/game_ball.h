#pragma once

#include "physics_entity.h"
#include "graphics_entity.h"

class GAME_MOVEABLE_BALL : public MOVEABLE_PHYSICS_ENTITY, public GRAPHICS_CIRCLE
{

};

class GAME_STATIC_BALL : public STATIC_PHYSICS_ENTITY, public GRAPHICS_CIRCLE
{

};