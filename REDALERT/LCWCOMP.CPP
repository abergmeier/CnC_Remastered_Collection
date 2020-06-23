#include "LCW.H"
#include "COMPAT.H"
#include "BUFF.H"
#include "XSTRAW.H"
#include "XPIPE.H"

int CDCL LCW_Comp(void const * source, void * dest, int length)
{
/*
; compress data to the following codes in the format b = byte, w = word
; n = byte code pulled from compressed data
;   Bit field of n		command		description
; n=0xxxyyyy,yyyyyyyy		short run	back y bytes and run x+3
; n=10xxxxxx,n1,n2,...,nx+1	med length	copy the next x+1 bytes
; n=11xxxxxx,w1			med run		run x+3 bytes from offset w1
; n=11111111,w1,w2		long run	run w1 bytes from offset w2
; n=10000000			end		end of data reached
;

implement code from LCWCOMP.ASM
*/

    return 0;
}
