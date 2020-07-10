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

#ifndef SKIA_GBUFFER_H
#define SKIA_GBUFFER_H

#include <SkCanvas.h>
#include <SkRegion.h>

#include "buffer.h"

class GraphicBufferClass;

/*=========================================================================*/
/* GraphicViewPortClass - Holds viewport information on a viewport which	*/
/*		has been attached to a GraphicBuffer.  A viewport is effectively a	*/
/*		rectangular subset of the full buffer which is used for clipping and	*/
/*		the like.																				*/
/*																									*/
/*			char	  	*Buffer	-		is the offset to view port buffer			*/
/*			int	  	Width		-		is the width of view port						*/
/*			int	  	Height	-		is the height of view port						*/
/*			int	  	XAdd		-		is add value to go from the end of a line	*/
/*											to the beginning of the next line			*/
/*			int		XPos;		- 		x offset into its associated VideoBuffer	*/
/*			int		YPos;		-		y offset into its associated VideoBuffer	*/
/*=========================================================================*/
class GraphicViewPortClass {
	public:

		/*===================================================================*/
		/* Define the base constructor and destructors for the class			*/
		/*===================================================================*/
		GraphicViewPortClass(GraphicBufferClass* graphic_buff, int x, int y, int w, int h);
		GraphicViewPortClass();
		~GraphicViewPortClass();

		/*===================================================================*/
		/* define functions to get at the private data members					*/
		/*===================================================================*/
		long	Get_Offset(void);
		int	Get_Height(void);
		int	Get_Width(void);
		int	Get_XAdd(void);
		int	Get_XPos(void);
		int	Get_YPos(void);
		int	Get_Pitch(void);
		inline bool	Get_IsDirectDraw(void);
		GraphicBufferClass	*Get_Graphic_Buffer(void);

		/*===================================================================*/
		/* Define a function which allows us to change a video viewport on	*/
		/*		the fly.																			*/
		/*===================================================================*/
		bool Change(int x, int y, int w, int h);

		/*===================================================================*/
		/* Define the set of common graphic functions that are supported by	*/
		/*		both Graphic ViewPorts and VideoViewPorts.							*/
		/*===================================================================*/
		void	Put_Pixel(int x, int y, unsigned char color);
		int	Get_Pixel(int x, int y);
		void	Clear(unsigned char color = 0);
		long	To_Buffer(int x, int y, int w, int h, void *buff, long size);
		long	To_Buffer(int x, int y, int w, int h, BufferClass *buff);
		long	To_Buffer(BufferClass *buff);
		HRESULT	Blit(	GraphicViewPortClass& dest, int x_pixel, int y_pixel, int dx_pixel,
						int dy_pixel, int pixel_width, int pixel_height, bool trans = false);
		HRESULT	Blit(	GraphicViewPortClass& dest, int dx, int dy, bool trans = false);
		HRESULT	Blit(	GraphicViewPortClass& dest, bool trans = false);
		HRESULT	Blit(	VideoViewPortClass& dest, int x_pixel, int y_pixel, int dx_pixel,
						int dy_pixel, int pixel_width, int pixel_height, bool trans = false);
		HRESULT	Blit(	VideoViewPortClass& dest, int dx, int dy, bool trans = false);
		HRESULT	Blit(	VideoViewPortClass& dest, bool trans = false);
		bool	Scale(	GraphicViewPortClass &dest, int src_x, int src_y, int dst_x,
							int dst_y, int src_w, int src_h, int dst_w, int dst_h, bool trans = false, char *remap = nullptr);
		bool	Scale(	GraphicViewPortClass &dest, int src_x, int src_y, int dst_x,
							int dst_y, int src_w, int src_h, int dst_w, int dst_h, char *remap);
		bool	Scale(	GraphicViewPortClass &dest, bool trans = false, char *remap = nullptr);
		bool	Scale(	GraphicViewPortClass &dest, char *remap);
		bool	Scale(	VideoViewPortClass &dest, int src_x, int src_y, int dst_x,
							int dst_y, int src_w, int src_h, int dst_w, int dst_h, bool trans = false, char *remap = nullptr);
		bool	Scale(	VideoViewPortClass &dest, int src_x, int src_y, int dst_x,
							int dst_y, int src_w, int src_h, int dst_w, int dst_h, char *remap);
		bool	Scale(	VideoViewPortClass &dest, bool trans = false, char *remap = nullptr);
		bool	Scale(	VideoViewPortClass &dest, char *remap);
		unsigned long	Print(char const *string, int x_pixel, int y_pixel, int fcolor, int bcolor);
		unsigned long	Print(short num, int x_pixel, int y_pixel, int fcol, int bcol);
		unsigned long	Print(int num, int x_pixel, int y_pixel, int fcol, int bcol);
		unsigned long	Print(long num, int x_pixel, int y_pixel, int fcol, int bcol);

		/*===================================================================*/
		/* Define the list of graphic functions which work only with a 		*/
		/*		graphic buffer.																*/
		/*===================================================================*/
		void Draw_Line(int sx, int sy, int dx, int dy, unsigned char color);
		void Draw_Rect(int sx, int sy, int dx, int dy, unsigned char color);
		void Fill_Rect(int sx, int sy, int dx, int dy, unsigned char color);
		void Fill_Quad(void *span_buff, int x0, int y0, int x1, int y1,
							int x2, int y2, int x3, int y3, int color);
		void Remap(int sx, int sy, int width, int height, void *remap);
		void Remap(void *remap);
		void Draw_Stamp(void const *icondata, int icon, int x_pixel, int y_pixel, void const *remap);
		void Draw_Stamp(void const *icondata, int icon, int x_pixel, int y_pixel, void const *remap, int clip_window);

// PG_TO_FIX
// This seems to be missing. Might not be needed anyway since it looks like it's only used for UI drawing. ST - 12/17/2018 6:11PM
		void Texture_Fill_Rect (int xpos, int ypos, int width, int height, void const *shape_pointer, int source_width, int source_height) {
			return;
		}

//	This doesnt seem to exist anywhere?? - Steve T 9/26/95 6:05PM
//		VOID Grey_Out_Region(int x, int y, int width, int height, int color);

		//
		// New members to lock and unlock the direct draw video memory
		//
		inline bool 	Lock ();
		inline bool 	Unlock();
		inline int		Get_LockCount();

		/*===================================================================*/
		/* Define functions to attach the viewport to a graphicbuffer			*/
		/*===================================================================*/
		void Attach(GraphicBufferClass *graphic_buff, int x, int y, int w, int h);
		void Attach(GraphicBufferClass *video_buff, int w, int h);

	protected:

		/*===================================================================*/
		/* Define the data used by a GraphicViewPortClass							*/
		/*===================================================================*/
        SkRegion                region;
/*
		long					Offset;			// offset to graphic page
		int						Width;			// width of graphic page
		int						Height;			// height of graphic page
		int						XAdd;			// xadd for graphic page (0)
		int						XPos;			// x offset in relation to graphicbuff
		int						YPos;			// y offset in relation to graphicbuff
*/
		long					Pitch;			//Distance from one line to the next
		GraphicBufferClass		*GraphicBuff;	// related graphic buff


};

/*=========================================================================*/
/* GraphicBufferClass - A GraphicBuffer refers to an actual instance of an	*/
/*		allocated buffer.  The GraphicBuffer may be drawn to directly 			*/
/*		becuase it inherits a ViewPort which represents its physcial size.	*/
/*																									*/
/*			BYTE	  	*Buffer	-		is the offset to graphic buffer				*/
/*			int	  	Width		-		is the width of graphic buffer				*/
/*			int	  	Height	-		is the height of graphic buffer				*/
/*			int	  	XAdd		-		is the xadd of graphic buffer					*/
/*			int		XPos;		- 		will be 0 because it is graphicbuff			*/
/*			int		YPos;		-		will be 0 because it is graphicbuff			*/
/*			long	Pitch		-		modulo of buffer for reading and writing																						*/
/*			bool	IsDirectDraw - 		flag if its a direct draw surface																						*/
/*=========================================================================*/
class GraphicBufferClass : public GraphicViewPortClass, public BufferClass {

	public:
		GraphicBufferClass(int w, int h, GBC_Enum flags);
		GraphicBufferClass(int w, int h,	void *buffer, long size);
		GraphicBufferClass(int w, int h, void *buffer = nullptr);
		GraphicBufferClass(void);
		~GraphicBufferClass();

		void Init(int w, int h, void *buffer, long size, GBC_Enum flags);
		void Un_Init(void);
		bool Lock(void);
		bool Unlock(void);

		void Scale_Rotate(BitmapClass &bmp,TPoint2D const &pt,long scale,unsigned char angle);

	protected:
		SkCanvas canvas;

};

#endif //SKIA_GBUFFER_H
