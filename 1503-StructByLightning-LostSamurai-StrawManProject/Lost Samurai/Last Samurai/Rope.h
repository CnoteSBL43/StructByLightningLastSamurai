#pragma once
#include"Link.h"
#include <vector>
#include"ParticleMass.h"
#include "../SGD Wrappers/SGD_Geometry.h"
class Rope
{
private:
	int numberOfParticles, numberOfLinks, particleLength;
	std::vector <Link> links;
	std::vector <ParticleMass> particles;

	SGD::Vector topAnchor, bottomAnchor;
public:
	Rope();
	~Rope();
	Rope(int length, int _numberOfParticles, SGD::Vector location);
	ParticleMass* GetParticleAt(int x);
	Link* GetLink(int x);
	void CreateLink(ParticleMass* particle1, ParticleMass* particle2);
	void Update(float dt);
	void Render(float dt);
	//Accessors
	int GetNumberOfParticles(){ return numberOfParticles; }
	int GetNumberOfLinks(){ return numberOfLinks; }
	int GetParticleLength(){ return particleLength; }
	//Mutators
	void SetNumberOfParticles(int _particles){ numberOfParticles = _particles; }
	void SetNumberOfLinks(int _links){ numberOfLinks = _links; }
	void SetParticleLenght(int _length){ particleLength = _length; }

};

