#include <string>
#include "ship.h"

using std::string;

// Constructor for Ship
Ship::Ship() {
	BoatLife = 1;
	IsLife = 1;
	DerLife = 1;
}
// Used to return all life values, used within Source code to determine if game should continue.
bool Ship::CheckBoat() {
	return BoatLife;
}
bool Ship::CheckIs() {
	return IsLife;
}
bool Ship::CheckDer() {
	return DerLife;
}

// Initialize class Boat, with attributes HitB, HitO, HitA, and HitT all equivelant to 0.
Boat::Boat() {
	HitB = 0;
	HitO = 0;
	HitA = 0;
	HitT = 0;
}
// Methods for Boat used within source code when a specific "Hit" occurs.
void Boat::BHit() {
	HitB = 1;
}
void Boat::OHit() {
	HitO = 1;
}
void Boat::AHit() {
	HitA = 1;
}
void Boat::THit() {
	HitT = 1;
}
// Method used to make variable BoatLife = 0 in Ship. 
void Boat::BoatL(Ship& i, bool Boatlife) {
	if((HitB == 1) && (HitO == 1) && (HitA == 1) && (HitT == 1))
	i.BoatLife = Boatlife;
}

// Initialize class Is, with attributes HitI and HitS all equivelant to 0.
Is::Is() {
	HitI = 0;
	HitS = 0;
}

// Methods for Is used within source code when a specific "Hit" occurs.
void Is::IHit() {
	HitI = 1;
}
void Is::SHit() {
	HitS = 1;
}

// Method used to make variable IsLife = 0 in Ship. 
void Is::IsL(Ship& i, bool Islife) {
	if ((HitI == 1) && (HitS == 1))
		i.IsLife = Islife;
}
// Initialize class Der, with attributes HitD, HitE, and HitR all equivelant to 0.
Der::Der() {
	HitD = 0;
	HitE = 0;
	HitR = 0;
}
// Methods for Der used within source code when a specific "Hit" occurs.
void Der::DHit() {
	HitD = 1;
}
void Der::EHit() {
	HitE = 1;
}
void Der::RHit() {
	HitR = 1;
}
// Method used to make variable DerLife = 0 in Ship. 
void Der::DerL(Ship& i, bool Derlife) {
	if ((HitD == 1) && (HitE == 1) && (HitR == 1))
		i.DerLife = Derlife;
}