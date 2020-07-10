#include "gbuffer.h"

int GraphicViewPortClass::Get_LockCount(void)
{
	return (LockCount);
}



/***********************************************************************************************
 * GVPC::Get_IsDirectDraw -- provide read access to the IsDirectDraw flag                      *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   IsDirectDraw                                                                      *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    11/29/95 1:02PM ST : Created                                                             *
 *=============================================================================================*/
bool GraphicViewPortClass::Get_IsDirectDraw(void)
{
	return false;
}

/***********************************************************************************************
 * GVPC::Lock -- lock the graphics buffer for reading or writing                               *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   TRUE if surface was successfully locked                                           *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   09-19-95 12:33pm ST : Created                                                             *
 *   10/09/1995     : Moved actually functionality to GraphicBuffer                            *
 *=============================================================================================*/
bool GraphicViewPortClass::Lock(void)
{
	bool lock = GraphicBuff->Lock();
	if ( !lock ) return(false);

	if (this != GraphicBuff) {
		Attach(GraphicBuff, region.getBounds().x(), region.getBounds().y(),  region.getBounds().width(), region.getBounds().height());
	}
	return(TRUE);
}

/***********************************************************************************************
 * GVPC::Unlock -- unlock the video buffer                                                     *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   TRUE if surface was successfully unlocked                                         *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   09-19-95 02:20pm ST : Created                                                             *
 *   10/09/1995     : Moved actually functionality to GraphicBuffer                            *
 *=============================================================================================*/
bool GraphicViewPortClass::Unlock(void)
{
	bool unlock = GraphicBuff->Unlock();
	if (!unlock) return(false);
	if (this != GraphicBuff && IsDirectDraw && !GraphicBuff->LockCount) {
		Offset = 0;
	}
	return(TRUE);
}


/***************************************************************************
 * GVPC::GET_OFFSET -- Get offset for virtual view port class instance     *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     long the offset for the virtual viewport instance           *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/07/1994 PWG : Created.                                             *
 *=========================================================================*/
inline long GraphicViewPortClass::Get_Offset(void)
{
	return(Offset);
}

/***************************************************************************
 * GVPC::GET_HEIGHT -- Gets the height of a virtual viewport instance      *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     WORD the height of the virtual viewport instance            *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/07/1994 PWG : Created.                                             *
 *=========================================================================*/
inline int GraphicViewPortClass::Get_Height(void)
{
	return region.getBounds().height();
}

/***************************************************************************
 * GVPC::GET_WIDTH -- Get the width of a virtual viewport instance			*
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     WORD the width of the virtual viewport instance             *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/07/1994 PWG : Created.                                             *
 *=========================================================================*/
inline int GraphicViewPortClass::Get_Width(void)
{
	return region.getBounds().width();
}


/***************************************************************************
 * GVPC::GET_XADD -- Get the X add offset for virtual viewport instance    *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     WORD the xadd for a virtual viewport instance               *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/07/1994 PWG : Created.                                             *
 *=========================================================================*/
inline int GraphicViewPortClass::Get_XAdd(void)
{
	return(XAdd);
}
/***************************************************************************
 * GVPC::GET_XPOS -- Get the x pos of the VP on the Video                  *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     WORD the x offset to VideoBufferClass								*
 *                                                                         *
 * HISTORY:                                                                *
 *   08/22/1994 SKB : Created.                                             *
 *=========================================================================*/
inline int GraphicViewPortClass::Get_XPos(void)
{
	return region.getBounds().x();
}


/***************************************************************************
 * GVPC::GET_YPOS -- Get the y pos of the VP on the video                  *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     WORD the x offset to VideoBufferClass								*
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   08/22/1994 SKB : Created.                                             *
 *=========================================================================*/
inline int GraphicViewPortClass::Get_YPos(void)
{
	return region.getBounds().y();
}

/***************************************************************************
 * GVPC::GET_GRAPHIC_BUFFER -- Get the graphic buffer of the VP.            *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * HISTORY:                                                                *
 *   08/22/1994 SKB : Created.                                             *
 *=========================================================================*/
GraphicBufferClass *GraphicViewPortClass::Get_Graphic_Buffer(void)
{
	return (GraphicBuff);
}

/***************************************************************************
 * GVPC::PUT_PIXEL -- stub to call curr graphic mode Put_Pixel					*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
void GraphicViewPortClass::Put_Pixel(int x, int y, unsigned char color)
{

	if (Lock()){
		SkPaint paint;
		paint.setColor(SkColorSetARGBMacro(color & 0b00000011, color & 0b11000000, color & 0b00110000, color & 0b00001100));
		canvas.drawPoint(x, y, paint);
	}
	Unlock();


}

/***************************************************************************
 * GVPC::GET_PIXEL -- stub to call curr graphic mode Get_Pixel          	*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline int	GraphicViewPortClass::Get_Pixel(int x, int y)
{
	int		return_code=0;

	if (Lock()){
		SkPixmap pixmap;
		bool success = canvas.peekPixel(&pixmap);
		assert(success);
		SkColor color = pixmap.getColor(x, y);
		return convert8888to2222(color);
	}
	Unlock();
	return(return_code);

}

/***************************************************************************
 * GVPC::CLEAR -- stub to call curr graphic mode Clear	                  *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline void	GraphicViewPortClass::Clear(unsigned char color)
{
	if (Lock()){
		canvas.clear(convert2222to8888(color));
	}
	Unlock();

}

/***************************************************************************
 * GVPC::TO_BUFFER -- stub 1 to call curr graphic mode To_Buffer				*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline long	GraphicViewPortClass::To_Buffer(int x, int y, int w, int h, void *buff, long size)
{
	long	return_code=0;
	if (Lock()){
		SkImageInfo dstInfo = SkImageInfo::Make(w, h, );
		bool success = canvas.readPixels(dstInfo, buff, size_t dstRowBytes, int x, int y)
		assert(success);
		return_code = (Buffer_To_Buffer(this, x, y, w, h, buff, size));
	}
	Unlock();
	return ( return_code );
}

/***************************************************************************
 * GVPC::TO_BUFFER -- stub 2 to call curr graphic mode To_Buffer 				*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
long	GraphicViewPortClass::To_Buffer(int x, int y, int w, int h, BufferClass *buff)
{
	long result = ToBuffer(x, y, w, h, buff->Get_Buffer(), buff->Get_Size());
	return result;
}

/***************************************************************************
 * GVPC::TO_BUFFER -- stub 3 to call curr graphic mode To_Buffer 				*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
long	GraphicViewPortClass::To_Buffer(BufferClass *buff)
{
	return ToBuffer(0, 0, region.width(), region.height(), buff);
}

/***************************************************************************
 * GVPC::BLIT -- stub 1 to call curr graphic mode Blit to GVPC					*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
HRESULT	GraphicViewPortClass::Blit(	GraphicViewPortClass& dest, int x_pixel, int y_pixel, int dx_pixel,
				int dy_pixel, int pixel_width, int pixel_height, BOOL trans)
{
	HRESULT		return_code=0;

	if (Lock()){
		if (dest.Lock()){
			return_code=(Linear_Blit_To_Linear(this, &dest, x_pixel, y_pixel
													, dx_pixel, dy_pixel
													, pixel_width, pixel_height, trans));
		}
		dest.Unlock();
	}
	Unlock();
}

/***************************************************************************
 * GVPC::BLIT -- Stub 2 to call curr graphic mode Blit to GVPC					*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
HRESULT	GraphicViewPortClass::Blit(	GraphicViewPortClass& dest, int dx, int dy, BOOL trans)
{
	HRESULT		return_code=0;

	if (Lock()){
		if (dest.Lock()){
			return_code=(Linear_Blit_To_Linear(this, &dest, 0, 0
													, dx, dy
													, Width, Height, trans));
		}
		dest.Unlock();
	}
	Unlock();
}

/***************************************************************************
 * GVPC::BLIT -- stub 3 to call curr graphic mode Blit to GVPC					*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline HRESULT	GraphicViewPortClass::Blit(	GraphicViewPortClass& dest, BOOL trans)
{
	HRESULT		return_code=0;

	if (Lock()){
		if (dest.Lock()){
			return_code=(Linear_Blit_To_Linear(this, &dest, 0, 0
													, 0, 0
													, Width, Height, trans));
		}
		dest.Unlock();
	}
	Unlock();
}


/***************************************************************************
 * GVPC::SCALE -- stub 1 to call curr graphic mode Scale to GVPC				*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline BOOL	GraphicViewPortClass::Scale(	GraphicViewPortClass &dest, int src_x, int src_y, int dst_x,
					int dst_y, int src_w, int src_h, int dst_w, int dst_h, BOOL trans, char *remap)
{
	BOOL	return_code=0;
	if (Lock()){
		if (dest.Lock()){
			return_code = (Linear_Scale_To_Linear(this, &dest, src_x, src_y, dst_x, dst_y, src_w, src_h, dst_w, dst_h, trans, remap));
		}
		dest.Unlock();
	}
	Unlock();
	return ( return_code );
}

/***************************************************************************
 * GVPC::SCALE -- stub 2 to call curr graphic mode Scale to GVPC				*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline BOOL	GraphicViewPortClass::Scale(	GraphicViewPortClass &dest, int src_x, int src_y, int dst_x,
					int dst_y, int src_w, int src_h, int dst_w, int dst_h, char *remap)
{
	BOOL	return_code=0;
	if (Lock()){
		if (dest.Lock()){
			return_code = (Linear_Scale_To_Linear(this, &dest, src_x, src_y, dst_x, dst_y, src_w, src_h, dst_w, dst_h, FALSE, remap));
		}
		dest.Unlock();
	}
	Unlock();
	return ( return_code );
}

/***************************************************************************
 * GVPC::SCALE -- stub 3 to call curr graphic mode Scale to GVPC				*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline BOOL	GraphicViewPortClass::Scale(	GraphicViewPortClass &dest, BOOL trans, char *remap)
{
	BOOL	return_code=0;
	if (Lock()){
		if (dest.Lock()){
			return_code = (Linear_Scale_To_Linear(this,	&dest, 0, 0, 0, 0, Width, Height, dest.Get_Width(), dest.Get_Height(), trans, remap));
		}
		dest.Unlock();
	}
	Unlock();
	return ( return_code );
}

/***************************************************************************
 * GVPC::SCALE -- stub 4 to call curr graphic mode Scale to GVPC				*
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/06/1995 PWG : Created.                                             *
 *=========================================================================*/
inline BOOL	GraphicViewPortClass::Scale(	GraphicViewPortClass &dest, char *remap)
{
	BOOL	return_code=0;
	if (Lock()){
		if (dest.Lock()){
			return_code = (Linear_Scale_To_Linear(this, &dest, 0, 0, 0, 0, Width, Height, dest.Get_Width(), dest.Get_Height(), FALSE, remap));
		}
		dest.Unlock();
	}
	Unlock();
	return ( return_code );
}
/***************************************************************************
 * GVPC::PRINT -- stub func to print a text string                         *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/17/1995 PWG : Created.                                             *
 *=========================================================================*/
inline unsigned long	GraphicViewPortClass::Print(char const *str, int x, int y, int fcol, int bcol)
{
	unsigned long	return_code=0;
	if (Lock()){
		return_code = (Buffer_Print(this, str, x, y, fcol, bcol));
	}
	Unlock();
	return ( return_code );
}

/***************************************************************************
 * GVPC::PRINT -- Stub function to print an integer                        *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *=========================================================================*/
inline unsigned long	GraphicViewPortClass::Print(int num, int x, int y, int fcol, int bcol)
{
	char str[17];

	unsigned long	return_code=0;
	if (Lock()){
		return_code = (Buffer_Print(this, itoa(num, str, 10), x, y, fcol, bcol));
	}
	Unlock();
	return ( return_code );
}

/***************************************************************************
 * GVPC::PRINT -- Stub function to print a short to a graphic viewport     *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *=========================================================================*/
inline unsigned long	GraphicViewPortClass::Print(short num, int x, int y, int fcol, int bcol)
{
	char str[17];

	unsigned long	return_code=0;
	if (Lock()){
		return_code = (Buffer_Print(this, itoa(num, str, 10), x, y, fcol, bcol));
	}
	Unlock();
	return ( return_code );
}

/***************************************************************************
 * GVPC::PRINT -- stub function to print a long on a graphic view port     *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *=========================================================================*/
inline unsigned long	GraphicViewPortClass::Print(long num, int x, int y, int fcol, int bcol)
{
	char str[33];

	unsigned long	return_code=0;
	if (Lock()){
		return_code = (Buffer_Print(this, ltoa(num, str,10), x, y, fcol, bcol));
	}
	Unlock();
	return ( return_code );
}

/***************************************************************************
 * GVPC::DRAW_STAMP -- stub function to draw a tile on a graphic view port *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *=========================================================================*/
inline void GraphicViewPortClass::Draw_Stamp(void const *icondata, int icon, int x_pixel, int y_pixel, void const *remap)
{
	if (Lock()){
		Buffer_Draw_Stamp(this, icondata, icon, x_pixel, y_pixel, remap);
	}
	Unlock();
}



/***************************************************************************
 * GVPC::DRAW_STAMP -- stub function to draw a tile on a graphic view port *
 *                     This version clips the tile to a window             *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *    07/31/1995 BWG : Created.                                            *
 *=========================================================================*/
extern BOOL IconCacheAllowed;
inline void GraphicViewPortClass::Draw_Stamp(void const * icondata, int icon, int x_pixel, int y_pixel, void const * remap, int clip_window)
{
	int	cache_index=-1;

   int drewit = 0;
	if (IconCacheAllowed){
		if (IsDirectDraw){
			if (!remap){
				cache_index = Is_Icon_Cached(icondata,icon);
			}

			if (cache_index != -1){
				if (CachedIcons[cache_index].Get_Is_Cached()  ){
					CachedIcons[cache_index].Draw_It (GraphicBuff->Get_DD_Surface() , x_pixel, y_pixel,
																WindowList[clip_window][WINDOWX] + XPos,
																WindowList[clip_window][WINDOWY] +YPos,
																WindowList[clip_window][WINDOWWIDTH],
																WindowList[clip_window][WINDOWHEIGHT]);
					CachedIconsDrawn++;
               drewit = 1;
				}
			}
		}
	}


   if (drewit == 0) {
		if (Lock()){
			UnCachedIconsDrawn++;
			Buffer_Draw_Stamp_Clip(this, icondata, icon, x_pixel, y_pixel, remap, WindowList[clip_window][WINDOWX], WindowList[clip_window][WINDOWY], WindowList[clip_window][WINDOWWIDTH], WindowList[clip_window][WINDOWHEIGHT]);
		}
   }
	Unlock();
}


/***************************************************************************
 * GVPC::DRAW_LINE -- Stub function to draw line in Graphic Viewport Class *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/16/1995 PWG : Created.                                             *
 *=========================================================================*/
inline VOID GraphicViewPortClass::Draw_Line(int sx, int sy, int dx, int dy, unsigned char color)
{
	if (Lock()){
		Buffer_Draw_Line(this, sx, sy, dx, dy, color);
	}
	Unlock();
}

/***************************************************************************
 * GVPC::FILL_RECT -- Stub function to fill rectangle in a GVPC            *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/16/1995 PWG : Created.                                             *
 *=========================================================================*/
inline VOID GraphicViewPortClass::Fill_Rect(int sx, int sy, int dx, int dy, unsigned char color)
{
	if (  AllowHardwareBlitFills
			&& IsDirectDraw
			&& ( (dx-sx) * (dy-sy) >= (32*32) )
			&& GraphicBuff->Get_DD_Surface()->GetBltStatus(DDGBS_CANBLT) == DD_OK){
		DDBLTFX	blit_effects;
		RECT	dest_rectangle;

		dest_rectangle.left	=sx+XPos;
		dest_rectangle.top	=sy+YPos;
		dest_rectangle.right	=dx+XPos;
		dest_rectangle.bottom=dy+YPos;

		if (dest_rectangle.left<XPos){
			dest_rectangle.left=XPos;
		}

		if (dest_rectangle.right >= Width + XPos){
			dest_rectangle.right = Width +XPos -1;
		}

		if (dest_rectangle.top<YPos){
			dest_rectangle.top=YPos;
		}

		if (dest_rectangle.bottom >= Height + YPos){
			dest_rectangle.bottom = Height + YPos -1;
		}

		if (dest_rectangle.left >= dest_rectangle.right)  return;
		if (dest_rectangle.top  >= dest_rectangle.bottom) return;

		dest_rectangle.right++;
		dest_rectangle.bottom++;

		blit_effects.dwSize=sizeof(blit_effects);
		blit_effects.dwFillColor = color;
		GraphicBuff->Get_DD_Surface()->Blt(&dest_rectangle,
														NULL,
														NULL,
														DDBLT_WAIT | DDBLT_ASYNC | DDBLT_COLORFILL,
														&blit_effects);
	} else {
		if (Lock()){
			Buffer_Fill_Rect(this, sx, sy, dx, dy, color);
			Unlock();
		}
	}
}


/***************************************************************************
 * GVPC::REMAP -- Stub function to remap a GVPC                            *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   01/16/1995 PWG : Created.                                             *
 *=========================================================================*/
inline VOID GraphicViewPortClass::Remap(int sx, int sy, int width, int height, VOID *remap)
{
	if (Lock()){
		Buffer_Remap(this, sx, sy, width, height, remap);
	}
	Unlock();
}


inline VOID GraphicViewPortClass::Fill_Quad(VOID *span_buff, int x0, int y0, int x1, int y1,
							int x2, int y2, int x3, int y3, int color)
{
	if (Lock()){
		Buffer_Fill_Quad(this, span_buff, x0, y0, x1, y1, x2, y2, x3, y3, color);
	}
	Unlock();
}

/***************************************************************************
 * GVPC::REMAP -- Short form to remap an entire graphic view port          *
 *                                                                         *
 * INPUT:		BYTE * to the remap table to use										*
 *                                                                         *
 * OUTPUT:     none                                                        *
 *                                                                         *
 * HISTORY:                                                                *
 *   07/01/1994 PWG : Created.                                             *
 *=========================================================================*/
inline VOID GraphicViewPortClass::Remap(VOID *remap)
{
	if (Lock()){
		Buffer_Remap(this, 0, 0, Width, Height, remap);
	}
	Unlock();
}

inline int GraphicViewPortClass::Get_Pitch(void)
{
	return(Pitch);
}

/***************************************************************************
 * GVPC::GRAPHICVIEWPORTCLASS -- Default constructor for view port class   *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     none                                                        *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/09/1994 PWG : Created.                                             *
 *=========================================================================*/
GraphicViewPortClass::GraphicViewPortClass(void)
{
}

/***************************************************************************
 * GVPC::ATTACH -- Attaches a viewport to a buffer class                   *
 *                                                                         *
 * INPUT:		GraphicBufferClass *g_buff	- pointer to gbuff to attach to  *
 *					int x                     - x position to attach to			*
 *					int y 							- y position to attach to			*
 *					int w							- width of the view port			*
 *					int h							- height of the view port			*
 *                                                                         *
 * OUTPUT:     none                                                        *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/10/1994 PWG : Created.                                             *
 *=========================================================================*/
void GraphicViewPortClass::Attach(GraphicBufferClass *gbuffer, int x, int y, int w, int h)
{
	/*======================================================================*/
	/* Can not attach a Graphic View Port if it is actually the physical		*/
	/*	   representation of a Graphic Buffer.											*/
	/*======================================================================*/
	if (this == Get_Graphic_Buffer())  {
		return;
	}

	/*======================================================================*/
	/* Verify that the x and y coordinates are valid and placed within the	*/
	/*		physical buffer.																	*/
	/*======================================================================*/
	if (x < 0) 										// you cannot place view port off
		x = 0;										//		the left edge of physical buf
	if (x >= gbuffer->Get_Width())			// you cannot place left edge off
		x = gbuffer->Get_Width() - 1;			//		the right edge of physical buf
	if (y < 0) 										// you cannot place view port off
		y = 0;										//		the top edge of physical buf
	if (y >= gbuffer->Get_Height()) 			// you cannot place view port off
		y = gbuffer->Get_Height() - 1;		//		bottom edge of physical buf

	/*======================================================================*/
	/* Adjust the width and height of necessary										*/
	/*======================================================================*/
	if (x + w > gbuffer->Get_Width()) 		// if the x plus width is larger
		w = gbuffer->Get_Width() - x;			//		than physical, fix width

	if (y + h > gbuffer->Get_Height()) 		// if the y plus height is larger
		h = gbuffer->Get_Height() - y;		//		than physical, fix height

	/*======================================================================*/
	/* Get a pointer to the top left edge of the buffer.							*/
	/*======================================================================*/
 	Offset 		= gbuffer->Get_Offset() + ((gbuffer->Get_Width()+gbuffer->Get_Pitch()) * y) + x;

	region.setRect(x, y, x + w, y + h);
#if 0
	/*======================================================================*/
	/* Copy over all of the variables that we need to store.						*/
	/*======================================================================*/
 	XPos			= x;
 	YPos			= y;
 	XAdd			= gbuffer->Get_Width() - w;
 	Width			= w;
 	Height		= h;
	Pitch			= gbuffer->Get_Pitch();
#endif
 	GraphicBuff = gbuffer;
#if 0
	IsDirectDraw= gbuffer->IsDirectDraw;
#endif
}

/***************************************************************************
 * GBC::INIT -- Core function responsible for initing a GBC                *
 *                                                                         *
 * INPUT:		int 		- the width in pixels of the GraphicBufferClass    *
 *					int		- the heigh in pixels of the GraphicBufferClass		*
 *					void *	- pointer to user supplied buffer (system will		*
 *								  allocate space if buffer is NULL)						*
 *					long		- size of the user provided buffer						*
 *					GBC_Enum	- flags if this is defined as a direct draw			*
 *	                       surface														*
 *                                                                         *
 * OUTPUT:		none                                                        *
 *                                                                         *
 * HISTORY:                                                                *
 *   10/09/1995     : Created.                                             *
 *=========================================================================*/
void GraphicBufferClass::Init(int w, int h, void *buffer, long size, GBC_Enum flags)
{
	Size			= size;									// find size of physical buffer
	Width			= w;										// Record width of Buffer
	Height		= h;										// Record height of Buffer

	//
	// If the surface we are creating is a direct draw object then
	//   we need to do a direct draw init.  Otherwise we will do
	//   a normal alloc.
	//
	if (flags & (GBC_VIDEOMEM | GBC_VISIBLE)) {
		DD_Init(flags);
	} else {
		if (buffer) {										// if buffer is specified
			Buffer		= (BYTE *)buffer;				//		point to it and mark
			Allocated	= FALSE;							//		it as user allocated
		} else {
			if (!Size) Size = w*h;
			Buffer		= new BYTE[Size];				// otherwise allocate it and
			Allocated	= TRUE;							//		mark it system alloced
		}
		Offset			= (long)Buffer;				// Get offset to the buffer
		IsDirectDraw	= FALSE;
	}

	Pitch			= 0;										// Record width of Buffer
	XAdd			= 0;										// Record XAdd of Buffer
	XPos			= 0;										// Record XPos of Buffer
	YPos			= 0;										// Record YPos of Buffer
	GraphicBuff	= this;									// Get a pointer to our self
}

/***************************************************************************
 * GBC::GRAPHICBUFFERCLASS -- Default constructor (requires explicit init) *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     none                                                        *
 *                                                                         *
 * HISTORY:                                                                *
 *   10/09/1995     : Created.                                             *
 *=========================================================================*/
GraphicBufferClass::GraphicBufferClass(void)
{
	GraphicBuff			= this; 							// Get a pointer to our self
	VideoSurfacePtr	= NULL;
	memset(&VideoSurfaceDescription, 0, sizeof(DDSURFACEDESC));
}

