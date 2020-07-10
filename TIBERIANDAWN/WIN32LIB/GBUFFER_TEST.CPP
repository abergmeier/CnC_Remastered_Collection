
#include "GBUFFER.H"

unsigned char CurrentPalette[768];

GameInFocus = true;

/*
** Pointer to a function we will call if we detect loss of focus
*/
void (*Gbuffer_Focus_Loss_Function)(void) = NULL;

GraphicViewPortClass *LogicPage;

void Block_Mouse(class GraphicBufferClass *) {
}

void Unblock_Mouse(class GraphicBufferClass *) {

}

#if 0
LPDIRECTDRAW7 dd;
LPDIRECTDRAWSURFACE7 surfaceFront;
LPDIRECTDRAWSURFACE7 surfaceBack;

void init() {

  auto hRet = DirectDrawCreateEx(NULL, (VOID**)&dd, IID_IDirectDraw7, 
                             NULL);
  if( hRet != DD_OK )
    exit(1);

  hRet = dd->SetDisplayMode(640, 480, 256, 0, 0);
  if( hRet != DD_OK )
    exit(2);

  DDSURFACEDESC2 surfaceDesc;

  ZeroMemory(&surfaceDesc, sizeof(surfaceDesc));
  surfaceDesc.dwSize = sizeof(surfaceDesc);
  surfaceDesc.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
  surfaceDesc.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE | DDSCAPS_FLIP |
    DDSCAPS_COMPLEX;
  surfaceDesc.dwBackBufferCount = 1;

  hRet = dd->CreateSurface(&surfaceDesc, &surfaceFront, NULL);
  if( hRet != DD_OK )
    exit(3);

  DDSCAPS2 caps;

  ZeroMemory(&caps, sizeof(caps));
  caps.dwCaps = DDSCAPS_BACKBUFFER;
  hRet = g_pDDSFront->GetAttachedSurface(&caps, &surfaceBack);
  if( hRet != DD_OK )
    exit(4);
}
#endif

int main() {
    
    Build_Fading_Table(CurrentPalette, FadingGreen, GREEN, 110);

    GraphicBufferClass viewport;
    viewport.DD_Init(GBC_NONE);

    return 0;
}
