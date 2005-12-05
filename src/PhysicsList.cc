#include "SimG4Core/Physics/interface/PhysicsList.h"
#include "SimG4Core/Physics/interface/DDG4ProductionCuts.h"

PhysicsList::PhysicsList(const edm::ParameterSet & p) 
    : G4VModularPhysicsList(), m_pPhysics(p) 
{
    //if (m_pPhysics.getParameter<bool>("CutsPerRegion")) 
      // prodCuts = new DDG4ProductionCuts();	
}
 
PhysicsList::~PhysicsList() 
{
    if (prodCuts!=0) delete prodCuts;
}

void PhysicsList::SetCuts() 
{ 
    if (!m_pPhysics.getParameter<bool>("CutsPerRegion"))
    {	 
       SetDefaultCutValue(m_pPhysics.getParameter<double>("DefaultCutValue")*cm);
       SetCutsWithDefault();
    }
    else
    {
       DDG4ProductionCuts prodCuts;
       prodCuts.update();
    }
    if (m_pPhysics.getParameter<int>("Verbosity") > 1) 
	G4VUserPhysicsList::DumpCutValuesTable();
}

