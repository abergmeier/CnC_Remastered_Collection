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

/***************************************************************************
 **     C O N F I D E N T I A L --- W E S T W O O D   S T U D I O S       **
 ***************************************************************************
 *                                                                         *
 *                 Project Name : Memory System                            *
 *                                                                         *
 *                    File Name : MEMFLAG.H                                *
 *                                                                         *
 *                   Programmer : Jeff Wilson                              *
 *                                                                         *
 *                   Start Date : April 4, 1994                            *
 *                                                                         *
 *                  Last Update : September 8, 1994   [IML]                *
 *                                                                         *
 *-------------------------------------------------------------------------*
 * Functions:                                                              *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#ifndef TD_MEMFLAG_H
#define TD_MEMFLAG_H

/*=========================================================================*/
/* The following prototypes are for the file: MEM_COPY.ASM						*/
/*=========================================================================*/

extern "C" {
	void Mem_Copy(void const *source, void *dest, unsigned long bytes_to_copy);
}

inline void *Add_Long_To_Pointer(void const *ptr, long size)
{
 	return ((void *) ( (char const *) ptr + size));
}

#endif //TD_MEMFLAG_H
