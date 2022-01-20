#include "ParticleSystem.h"

void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_Vertices, states);
}

void ParticleSystem::init(int numParticles)
{
	m_Vertices.setPrimitiveType(Points);
	m_Vertices.resize(numParticles);
	for (int i = 0; i < numParticles; i++)
	{
		srand(time(0) + i);
		float angle = (rand() % 360) * 3.14f / 180.f;
		float speed = (rand() % 600) + 600.f;
		Vector2f direction;
		direction = Vector2f(cos(angle) * speed, sin(angle) * speed);
		m_Particles.push_back(Particle(direction));
	}
}

void ParticleSystem::emitParticles(Vector2f startPosition)
{
	m_IsRunning = true;
	m_Duration = 2;

	int curVertex = 0;

	for (auto it = m_Particles.begin(); it != m_Particles.end(); it++)
	{
		m_Vertices[curVertex++].color = Color::Yellow;
		it->setPosition(startPosition);
	}
}

void ParticleSystem::update(float dt)
{
	m_Duration -= dt;
	vector<Particle>::iterator i;
	int curVertex = 0;
	for (i = m_Particles.begin(); i != m_Particles.end(); i++)
	{
		(*i).update(dt);
		m_Vertices[curVertex++].position = i->getPosition(); 
	}
	if (m_Duration < 0)
	{
		m_IsRunning = false;
	}
}

bool ParticleSystem::running()
{
	return m_IsRunning;
}
