#pragma once

#include "Enigma_Base.h"


//(hw8 only) class Plugboard : public Enigma_Component

class Rotor : public Enigma_Component
{
	public:
		Rotor ( std::string encode_table, char const& start_, char const& arrows_ ) ;

	//...
} ;

//(hw8 only) class Special_Rotor : public Rotor

class Reflector : public Enigma_Component
{
	public: 
		Reflector ( std::string encode_table );

	//...
} ;