#pragma once

#include "physics_entity.h"
#include "graphics_helper.h"

class GAME_STATIC_PLATFORM : public STATIC_PHYSICS_ENTITY, public GRAPHICS_SQUARE
{

};

class GAME_MOVEABLE_PLATFORM : public MOVEABLE_PHYSICS_ENTITY, public GRAPHICS_SQUARE
{

};