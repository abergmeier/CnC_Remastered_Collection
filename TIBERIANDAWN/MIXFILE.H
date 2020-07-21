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

/* $Header:   F:\projects\c&c\vcs\code\mixfile.h_v   2.18   16 Oct 1995 16:47:22   JOE_BOSTIC  $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               *** 
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : MIXFILE.H                                                    *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : October 18, 1994                                             *
 *                                                                                             *
 *                  Last Update : October 18, 1994   [JLB]                                     *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef MIXFILE_H
#define MIXFILE_H

#include <cstdint>

#include	"LINK.H"

class MixFileClass : public LinkClass 
{
	public:
		char const *Filename;			// Filename of mixfile.

		MixFileClass(char const *filename);
		~MixFileClass(void);

		static bool Free(char const *filename);
		static void Free_All(void);
		void Free(void);
		bool Cache(void);
		static bool Cache(char const *filename);
		static bool Offset(char const *filename, void ** realptr = 0, MixFileClass ** mixfile = 0, std::int32_t * offset = 0, std::int32_t * size = 0);
		static void const * Retrieve(char const *filename);

		template <class Func>
		void Foreach(Func func) {
			for (int i = 0; i != Count; ++i) {
				func(Buffer[i]);
			}
		}

		#pragma pack(push, 1)
		struct SubBlock {
			std::int32_t CRC;				// CRC code for embedded file.
			std::int32_t Offset;			// Offset from start of data section.
			std::int32_t Size;				// Size of data subfile.

			int operator < (SubBlock & two) const {return (CRC < two.CRC);};
			int operator > (SubBlock & two) const {return (CRC > two.CRC);};
			int operator == (SubBlock & two) const {return (CRC == two.CRC);};
		};
		#pragma pack(pop)

	private:
		static MixFileClass * Finder(char const *filename);
		std::int32_t Offset(std::int32_t crc, std::int32_t *size = 0);

		#pragma pack(push, 1)
		typedef struct {
			std::int16_t	count;
			std::int32_t	size;
		} FileHeader;
		#pragma pack(pop)

		int Count;							// Number of sub-blocks.
		std::int32_t DataSize;						// Size of raw data.
		SubBlock * Buffer;				// Array of sub blocks (could be in EMS).
		void *Data;							// Pointer to raw data.

		static MixFileClass * First;
};

#endif
