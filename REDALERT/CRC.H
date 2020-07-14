//
// Copyright 2020 Electronic Arts Inc.
//
// TiberianDawn.DLL and RedAlert.dll and corresponding source code is free 
// software: you can redistribute it and/or modify it under the terms of 
// the GNU General Public License as published by the Free Software Foundation, 
// either version 3 of the License, or (at your option) any later version.

// TiberianDawn.DLL and RedAlert.dll and corresponding source code is distributed 
// in the hope that it will be useful, but with permitted additional restrictions 
// under Section 7 of the GPL. See the GNU General Public License in LICENSE.TXT 
// distributed with this program. You should have received a copy of the 
// GNU General Public License along with permitted additional restrictions 
// with this program. If not, see https://github.com/electronicarts/CnC_Remastered_Collection

/* $Header: /CounterStrike/CRC.H 1     3/03/97 10:24a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : CRC.H                                                        *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : 03/02/96                                                     *
 *                                                                                             *
 *                  Last Update : March 2, 1996 [JLB]                                          *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


#ifndef CRC_H
#define CRC_H

#include <limits>
#include <cstdint>
#include	<stdlib.h>

// Shameless plug from libstdc++-v3/include/std/bit
template<typename _Tp>
constexpr _Tp
__rotl(_Tp __x, unsigned int __s) noexcept
{
	constexpr auto _Nd = std::numeric_limits<_Tp>::digits;
	const unsigned __sN = __s % _Nd;
	return (__x << __sN) | (__x >> ((_Nd - __sN) % _Nd));
}


/*
**	This is a CRC engine class. It will process submitted data and generate a CRC from it.
**	Well, actually, the value returned is not a true CRC. However, it shares the same strength
**	characteristic and is faster to generate than the traditional CRC. This object is treated like
**	a method class. If it is called as a function (using the function operator), it will return
**	the CRC value. There are other function operators to submit data for processing.
*/
class CRCEngine {
	public:

		// Constructor for CRC engine (it can have an override initial CRC value).
		CRCEngine(std::int32_t initial=0) : CRC(initial), Index(0) {
			StagingBuffer.Composite = 0;
		};

		// Fetches CRC value.
		std::int32_t operator() (void) const {return(Value());};

		// Submits one byte sized datum to the CRC accumulator.
		void operator() (char datum);

		// Submits an arbitrary buffer to the CRC accumulator.
		std::int32_t operator() (void const * buffer, int length);

		// Implicit conversion operator so this object appears like a 'long integer'.
		operator std::int32_t(void) const {return(Value());};

	protected:

		bool Buffer_Needs_Data(void) const {
			return(Index != 0);
		};

		std::int32_t Value(void) const {
			if (Buffer_Needs_Data()) {
#ifdef _MSC_VER
				return(_lrotl(CRC, 1) + StagingBuffer.Composite);
#else
				return(__rotl(CRC, 1) + StagingBuffer.Composite);
#endif
			}
			return(CRC);
		};

		/*
		**	Current accumulator of the CRC value. This value doesn't take into
		**	consideration any pending data in the staging buffer.
		*/
		std::int32_t CRC;

		/*
		**	This is the sub index into the staging buffer used to keep track of
		**	partial data blocks as they are submitted to the CRC engine.
		*/
		std::int32_t Index;

		/*
		**	This is the buffer that holds the incoming partial data. When the buffer
		**	is filled, the value is transformed into the CRC and the buffer is flushed
		**	in preparation for additional data.
		*/
		union {
			std::int32_t Composite;
			char Buffer[sizeof(std::int32_t)];
		} StagingBuffer;
};

#endif

