#ifndef SCRIPTINTERFACE_H
#define SCRIPTINTERFACE_H

#include <QObject>

#include "alg/examplealgorithm.h"
#include "sim/simulator.h"

class ScriptInterface : public QObject
{
    Q_OBJECT
public:
    explicit ScriptInterface(Simulator& _sim);
    
public slots:
    void round();

    void exampleAlgorithmInstance(int size);

private:
    Simulator& sim;
};

inline ScriptInterface::ScriptInterface(Simulator& _sim)
    : sim(_sim)
{
    sim.setSystem(ExampleAlgorithm::instance(5));
}

inline void ScriptInterface::round()
{
    sim.round();
}

inline void ScriptInterface::exampleAlgorithmInstance(int size)
{
    sim.setSystem(ExampleAlgorithm::instance(size));
}

#endif // SCRIPTINTERFACE_H