# Microsoft Developer Studio Project File - Name="SPKonvert" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) External Target" 0x0106

CFG=SPKonvert - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SPKonvert.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SPKonvert.mak" CFG="SPKonvert - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SPKonvert - Win32 Release" (based on "Win32 (x86) External Target")
!MESSAGE "SPKonvert - Win32 Debug" (based on "Win32 (x86) External Target")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/4CReleased/V2.20.00/TargetBase/Tools/SPKonvert", NEXFAAAA"
# PROP Scc_LocalPath "."

!IF  "$(CFG)" == "SPKonvert - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Cmd_Line "NMAKE /f SPKonvert.mak"
# PROP BASE Rebuild_Opt "clean all"
# PROP BASE Target_File "SPKonvert.exe"
# PROP BASE Bsc_Name "SPKonvert.bsc"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Cmd_Line "NMAKE /f SPKonvert.mak"
# PROP Rebuild_Opt "clean all"
# PROP Target_File "SPKonvert.exe"
# PROP Bsc_Name "SPKonvert.bsc"
# PROP Target_Dir ""

!ELSEIF  "$(CFG)" == "SPKonvert - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Cmd_Line "NMAKE /f SPKonvert.mak"
# PROP BASE Rebuild_Opt "clean all"
# PROP BASE Target_File "SPKonvert.exe"
# PROP BASE Bsc_Name "SPKonvert.bsc"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Cmd_Line "NMAKE /f SPKonvert.mak"
# PROP Rebuild_Opt "clean all"
# PROP Target_File "SPKonvert.exe"
# PROP Bsc_Name "SPKonvert.bsc"
# PROP Target_Dir ""

!ENDIF 

# Begin Target

# Name "SPKonvert - Win32 Release"
# Name "SPKonvert - Win32 Debug"

!IF  "$(CFG)" == "SPKonvert - Win32 Release"

!ELSEIF  "$(CFG)" == "SPKonvert - Win32 Debug"

!ENDIF 

# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\GHFile.cpp
# End Source File
# Begin Source File

SOURCE=.\SPKonvert.cpp
# End Source File
# Begin Source File

SOURCE=.\SPKonvert.rc
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\GHFile.h
# End Source File
# Begin Source File

SOURCE=.\PouProtectData.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SPKonvert.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\version.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\SPKonvert.inf
# End Source File
# End Target
# End Project
