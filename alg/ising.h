#ifndef ISING_H
#define ISING_H

#include "core/amoebotparticle.h"
#include "core/amoebotsystem.h"

class IsingParticle : public AmoebotParticle
{
    friend class IsingSystem;

public:
    enum class Spin {
      Pos,
      Neg
    };

public:
    IsingParticle(const Node head,
                    const int globalTailDir,
                    const int orientation,
                    AmoebotSystem& system,
                    Spin spin,
                    double beta);

    virtual void activate();

    virtual int headMarkColor() const;
    virtual int tailMarkColor() const;

    virtual QString inspectionText() const;

    IsingParticle& nbrAtLabel(int label) const;

protected:
    Spin spin;
    double beta;
    double switchProb;

private:
    int hamiltonian(const int mySpin) const;
};

class IsingSystem : public AmoebotSystem
{
public:
    IsingSystem(int numParticles = 200, double beta = 0.2);

    virtual bool hasTerminated() const;
};

#endif // ISING_H
