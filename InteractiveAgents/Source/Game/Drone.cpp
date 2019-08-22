#include "Drone.h"
#include "AI/Steering/Steering.h"

Drone::Drone()
{
	m_steering = std::make_unique<Steering>();
}

Drone::~Drone()
{

}
