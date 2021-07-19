#include "physics_integration_verlet.h"

void PHYSICS_INTEGRATION_VERLET::Update( PHYSICS_ENTITY& physics_entity, const float delta_time )
{
	auto new_pos = physics_entity.Velocity * delta_time + physics_entity.GetAcceleration() * delta_time * delta_time * 0.5f;
	auto new_vel = physics_entity.GetAcceleration() * delta_time;

	physics_entity.Position = physics_entity.Position + new_pos;
	physics_entity.Velocity = physics_entity.Velocity + new_vel;
}
