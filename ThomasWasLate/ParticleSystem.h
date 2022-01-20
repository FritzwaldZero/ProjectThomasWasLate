#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <SFML/Graphics.hpp>
#include "Particle.h"

using namespace sf;
using namespace std;

class ParticleSystem : public Drawable 
{
private:
	VertexArray m_Vertices;
	vector<Particle> m_Particles;
	float m_Duration; 
	bool m_IsRunning = false;
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void init(int count);
	void emitParticles(Vector2f position);
	void update(float dt);
	bool running();
};






#endif
