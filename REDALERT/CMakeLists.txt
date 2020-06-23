# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project( sample_cmake )

# flags

# files

# include
include_directories( 
    "${PROJECT_SOURCE_DIR}"
    "${PROJECT_SOURCE_DIR}/win32lib"
)

# target
add_executable( cnc 
    CRC.CPP
    BASE64.CPP
    SHA.CPP
    LZO1X_D.CPP
    LZO1X_C.CPP
    LCW.CPP
    LZW.CPP

    PIPE.CPP
    BUFF.CPP
    STRAW.CPP
    LZOPIPE.CPP
    B64PIPE.CPP
    XPIPE.CPP
    XSTRAW.CPP
    LZWPIPE.CPP
    LZOSTRAW.CPP
    LCWSTRAW.CPP

    # Following file compiles - but needs to be tested,
    # as it was a hack,
    LZWOTRAW.CPP
    
    # This is a complete hack - which needs to be coded
    LCWCOMP.CPP
    
    # Following files - do not compile

    # following files compile, but lack some other symbols bellow
    # Missing code is in ASM:
    # REDALERT/LCWCOMP.ASM
    # REDALERT/LCW.H

    # WIP - still not compiling
    # INI.CPP 
    # PK.CPP
    # INT.CPP
    # FIXED.CPP
    # B64STRAW.CPP
    # CCFILE.CPP
    # CRCPIPE.CPP
    # CRCSTRAW.CPP
    # HEAP.CPP
    # SHAPIPE.CPP
    # SHASTRAW.CPP
    # READLINE.CPP
)

# List of all available files, move the to compilation one at a time
    # 2KEYFRAM.CPP
    # AADATA.CPP
    # ABSTRACT.CPP
    # ADATA.CPP
    # ADPCM.CPP
    # AIRCRAFT.CPP
    # ANIM.CPP
    # AUDIO.CPP
    # BAR.CPP
    # BASE.CPP
    # BBDATA.CPP
    # BDATA.CPP
    # BENCH.CPP
    # BFIOFILE.CPP
    # BIGCHECK.CPP
    # BLOWFISH.CPP
    # BLOWPIPE.CPP
    # BLWSTRAW.CPP
    # BMP8.CPP
    # BUILDING.CPP
    # BULLET.CPP
    # CARGO.CPP
    # CARRY.CPP
    # CCDDE.CPP
    # CCINI.CPP
    # CCMPATH.CPP
    # CCPTR.CPP
    # CCTEN.CPP
    # CDATA.CPP
    # CDFILE.CPP
    # CELL.CPP
    # CHECKBOX.CPP
    # CHEKLIST.CPP
    # CLASS.CPP
    # COLRLIST.CPP
    # COMBAT.CPP
    # COMBUF.CPP
    # COMINIT.CPP
    # COMQUEUE.CPP
    # CONFDLG.CPP
    # CONNECT.CPP
    # CONQUER.CPP
    # CONST.CPP
    # CONTROL.CPP
    # COORD.CPP
    # CRATE.CPP
    # CREDITS.CPP
    # CREW.CPP
    # CSTRAW.CPP
    # DDE.CPP
    # DEBUG.CPP
    # DESCDLG.CPP
    # DIAL8.CPP
    # DIALOG.CPP
    # DIBFILE.CPP
    # DIBUTIL.CPP
    # DISPLAY.CPP
    # DOOR.CPP
    # DPMI.CPP
    # DRIVE.CPP
    # DROP.CPP
    # DTABLE.CPP
    # DYNAVEC.CPP
    # EDIT.CPP
    # EGOS.CPP
    # ENDING.CPP
    # EVENT.CPP
    # EXPAND.CPP
    # FACE.CPP
    # FACING.CPP
    # FACTORY.CPP
    # FIELD.CPP
    # FINDPATH.CPP
    # FLASHER.CPP
    # FLY.CPP
    # FOOT.CPP
    # FUSE.CPP
    # GADGET.CPP
    # GAMEDLG.CPP
    # GAUGE.CPP
    # GETCPU.CPP
    # GLOBALS.CPP
    # GOPTIONS.CPP
    # GSCREEN.CPP
    # HDATA.CPP
    # HELP.CPP
    # HOUSE.CPP
    # HSV.CPP
    # ICONLIST.CPP
    # IDATA.CPP
    # INFANTRY.CPP
    # INIBIN.CPP
    # INICODE.CPP
    # INIT.CPP
    # INTERNET.CPP
    # INTERPAL.CPP
    # INTRO.CPP
    # IOMAP.CPP
    # IOOBJ.CPP
    # IPX95.CPP
    # IPXADDR.CPP
    # IPXCONN.CPP
    # IPX.CPP
    # IPXGCONN.CPP
    # IPXMGR.CPP
    # ITABLE.CPP
    # JSHELL.CPP
    # KEYBOARD.CPP
    # KEY.CPP
    # LAYER.CPP
    # LCW.CPP
    # LCWPIPE.CPP
    # LCWUNCMP.CPP
    # LINK.CPP
    # LIST.CPP
    # LOADDLG.CPP
    # LOGIC.CPP
    # MAP.CPP
    # MAPEDDLG.CPP
    # MAPEDIT.CPP
    # MAPEDPLC.CPP
    # MAPEDSEL.CPP
    # MAPEDTM.CPP
    # MAPSEL.CPP
    # MCI.CPP
    # MCIMOVIE.CPP
    # MENUS.CPP
    # MISSION.CPP
    # MIXFILE.CPP
    # MONOC.CPP
    # MOUSE.CPP
    # MP.CPP
    # MPGSET.CPP
    # MPLAYER.CPP
    # MPLIB.CPP
    # MPMGRD.CPP
    # MPMGRW.CPP
    # MPU.CPP
    # MSGBOX.CPP
    # MSGLIST.CPP
    # NETDLG.CPP
    # NOSEQCON.CPP
    # NULLCONN.CPP
    # NULLDLG.CPP
    # NULLMGR.CPP
    # OBJECT.CPP
    # ODATA.CPP
    # OPTIONS.CPP
    # OVERLAY.CPP
    # PACKET.CPP
    # PALETTEC.CPP
    # PKPIPE.CPP
    # PKSTRAW.CPP
    # POWER.CPP
    # PROFILE.CPP
    # QUEUE.CPP
    # RADAR.CPP
    # RADIO.CPP
    # RAMFILE.CPP
    # RAND.CPP
    # RANDOM.CPP
    # RAWFILE.CPP
    # RAWOLAPI.CPP
    # RECT.CPP
    # REINF.CPP
    # RGB.CPP
    # RNDSTRAW.CPP
    # ROTBMP.CPP
    # RULES.CPP
    # SAVELOAD.CPP
    # SCENARIO.CPP
    # SCORE.CPP
    # SCROLL.CPP
    # SDATA.CPP
    # SEDITDLG.CPP
    # SENDFILE.CPP
    # SEQCONN.CPP
    # SESSION.CPP
    

    # SHAPEBTN.CPP
    # SIDEBAR.CPP
    # SIDEBARGlyphx.CPP
    # SLIDER.CPP
    # SMUDGE.CPP
    # SOUNDDLG.CPP
    # SPECIAL.CPP
    # SPRITE.CPP
    # STARTUP.CPP
    # STATBTN.CPP
    # STATS.CPP
    # STUB.CPP
    # SUPER.CPP
    # SURFACE.CPP
    # TAB.CPP
    # TACTION.CPP
    # TARGET.CPP
    # TCPIP.CPP
    # TDATA.CPP
    # TEAM.CPP
    # TEAMTYPE.CPP
    # TECHNO.CPP
    # TEMPLATE.CPP
    # TENMGR.CPP
    # TERRAIN.CPP
    # TEVENT.CPP
    # TEXTBTN.CPP
    # THEME.CPP
    # TOGGLE.CPP
    # TOOLTIP.CPP
    # TRACKER.CPP
    # TRIGGER.CPP
    # TRIGTYPE.CPP
    # TURRET.CPP
    # TXTLABEL.CPP
    # UDATA.CPP
    # UDPADDR.CPP
    # UNIT.CPP
    # UTRACKER.CPP
    # VDATA.CPP
    # VECTOR.CPP
    # VERSION.CPP
    # VESSEL.CPP
    # VISUDLG.CPP
    # VORTEX.CPP
    # W95TRACE.CPP
    # WARHEAD.CPP
    # WEAPON.CPP
    # WINSTUB.CPP
    # WOLAPIOB.CPP
    # WOL_CGAM.CPP
    # WOL_CHAT.CPP
    # WOL_DNLD.CPP
    # WOLEDIT.CPP
    # WOL_GSUP.CPP
    # WOL_LOGN.CPP
    # WOL_MAIN.CPP
    # WOL_OPT.CPP
    # WOLSTRNG.CPP
    # WSPIPX.CPP
    # _WSPROTO.CPP
    # WSPROTO.CPP
    # WSPUDP.CPP
