/// \file
/// \brief \b [Internal] Random number generator
///
/// This file is part of RakNet Copyright 2003 Kevin Jenkins.
///
/// Usage of RakNet is subject to the appropriate license agreement.
/// Creative Commons Licensees are subject to the
/// license found at
/// http://creativecommons.org/licenses/by-nc/2.5/
/// Single application licensees are subject to the license found at
/// http://www.jenkinssoftware.com/SingleApplicationLicense.html
/// Custom license users are subject to the terms therein.
/// GPL license users are subject to the GNU General Public
/// License as published by the Free
/// Software Foundation; either version 2 of the License, or (at your
/// option) any later version.


#ifndef __RAND_H
#define __RAND_H 

#include "Export.h"

/// Initialise seed for Random Generator
/// \note not threadSafe, use an instance of RakNetRandom if necessary per thread
/// \param[in] seed The seed value for the random number generator.
extern void RAK_DLL_EXPORT seedMT( unsigned int seed );

/// \internal
/// \note not threadSafe, use an instance of RakNetRandom if necessary per thread
extern unsigned int RAK_DLL_EXPORT reloadMT( void );

/// Gets a random unsigned int
/// \note not threadSafe, use an instance of RakNetRandom if necessary per thread
/// \return an integer random value.
extern unsigned int RAK_DLL_EXPORT randomMT( void );

/// Gets a random float
/// \note not threadSafe, use an instance of RakNetRandom if necessary per thread
/// \return 0 to 1.0f, inclusive
extern float RAK_DLL_EXPORT frandomMT( void );

/// Randomizes a buffer
/// \note not threadSafe, use an instance of RakNetRandom if necessary per thread
extern void RAK_DLL_EXPORT fillBufferMT( void *buffer, unsigned int bytes );

// Same thing as above functions, but not global
class RAK_DLL_EXPORT RakNetRandom
{
public:
	RakNetRandom();
	~RakNetRandom();
	void SeedMT( unsigned int seed );
	unsigned int ReloadMT( void );
	unsigned int RandomMT( void );
	float FrandomMT( void );
	void FillBufferMT( void *buffer, unsigned int bytes );

protected:
	unsigned int state[ 624 + 1 ];
	unsigned int *next;
	int left;
};

#endif
