#pragma once
#include <string>

using std::string;

// Base Class
class Ship {
	// friend
	friend class Boat;
	friend class Is;
	friend class Der;
	// attributes
	bool BoatLife;
	bool IsLife;
	bool DerLife;
public:
	// constructor
	Ship();
	// methods
	bool CheckBoat();
	bool CheckIs();
	bool CheckDer();
};



// Inherited Class Boat
//class Boat : public Ship {
class Boat {
	// Attributes
	string B;
	string O;
	string A;
	string T;
	bool HitB;
	bool HitO;
	bool HitA;
	bool HitT;
public:
	// constructor
	Boat();
	//mathods
	void BHit();
	void OHit();
	void AHit();
	void THit();
	void BoatL(Ship &i, bool BoatLife);
};


// Inhereted Class Is
class Is {
	//attributes
	string I;
	string S;
	bool HitI;
	bool HitS;
public :
	// constructor
	Is();
	//methods
	void IHit();
	void SHit();
	void IsL(Ship& i, bool IsLife);
};
// Inhereted Class Der
class Der {
public: 
	//attributes
	string D;
	string E;
	string R;
	bool HitD;
	bool HitE;
	bool HitR;
	// constructor
	Der();
	//methods
	void DHit();
	void EHit();
	void RHit();
	void DerL(Ship& i, bool DerLife);

};