# Microsoft Developer Studio Project File - Name="ruby19c" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** �ҏW���Ȃ��ł������� **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=ruby19c - Win32 Debug
!MESSAGE ����͗L����Ҳ�̧�قł͂���܂���B ������ۼު�Ă�����ނ��邽�߂ɂ� NMAKE ���g�p���Ă��������B
!MESSAGE [Ҳ�̧�ق̴���߰�] ����ނ��g�p���Ď��s���Ă�������
!MESSAGE 
!MESSAGE NMAKE /f "ruby19c.mak".
!MESSAGE 
!MESSAGE NMAKE �̎��s���ɍ\�����w��ł��܂�
!MESSAGE ����� ײݏ��ϸۂ̐ݒ���`���܂��B��:
!MESSAGE 
!MESSAGE NMAKE /f "ruby19c.mak" CFG="ruby19c - Win32 Debug"
!MESSAGE 
!MESSAGE �I���\������� Ӱ��:
!MESSAGE 
!MESSAGE "ruby19c - Win32 Release" ("Win32 (x86) Console Application" �p)
!MESSAGE "ruby19c - Win32 Debug" ("Win32 (x86) Console Application" �p)
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ruby19c - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "bin\release"
# PROP Intermediate_Dir "obj\release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O1 /I "..\libruby19\src" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "NT" /D "_WIN32" /D "RUBY_EXPORT" /D "RUBY19" /YX /FD /c
# ADD BASE RSC /l 0x411 /d "NDEBUG"
# ADD RSC /l 0x411 /d "NDEBUG" /d "CUI"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib /nologo /subsystem:console /machine:I386 /out:"bin\release\ruby190c.exc"
# Begin Special Build Tool
TargetPath=.\bin\release\ruby190c.exc
SOURCE="$(InputPath)"
PostBuild_Cmds=copy $(TargetPath) ..\..\data\exerb
# End Special Build Tool

!ELSEIF  "$(CFG)" == "ruby19c - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "bin\debug"
# PROP Intermediate_Dir "obj\debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\libruby19\src" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "NT" /D "_WIN32" /D "RUBY_EXPORT" /D "RUBY19" /YX /FD /GZ /c
# ADD BASE RSC /l 0x411 /d "_DEBUG"
# ADD RSC /l 0x411 /d "_DEBUG" /d "CUI"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib /nologo /subsystem:console /debug /machine:I386 /out:"bin\debug\ruby190cd.exc" /pdbtype:sept
# Begin Special Build Tool
TargetPath=.\bin\debug\ruby190cd.exc
SOURCE="$(InputPath)"
PostBuild_Cmds=copy $(TargetPath) ..\..\data\exerb
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "ruby19c - Win32 Release"
# Name "ruby19c - Win32 Debug"
# Begin Source File

SOURCE=..\exerb\cui.cpp
# End Source File
# Begin Source File

SOURCE=..\exerb\exerb.cpp
# End Source File
# Begin Source File

SOURCE=..\exerb\exerb.h
# End Source File
# Begin Source File

SOURCE=..\libruby19\libruby19_standalone.def
# End Source File
# Begin Source File

SOURCE=..\exerb\module.cpp
# End Source File
# Begin Source File

SOURCE=..\exerb\module.h
# End Source File
# Begin Source File

SOURCE=..\exerb\resource.h
# End Source File
# Begin Source File

SOURCE=..\exerb\resource.rc
# End Source File
# Begin Source File

SOURCE=..\exerb\utility.cpp
# End Source File
# Begin Source File

SOURCE=..\exerb\utility.h
# End Source File
# End Target
# End Project
