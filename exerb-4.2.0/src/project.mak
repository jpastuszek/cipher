# Microsoft Developer Studio Generated NMAKE File, Based on project.dsp
!IF "$(CFG)" == ""
CFG=project - Win32 Debug
!MESSAGE �\�����w�肳��Ă��܂���B��̫�Ă� project - Win32 Debug ��ݒ肵�܂��B
!ENDIF 

!IF "$(CFG)" != "project - Win32 Release" && "$(CFG)" != "project - Win32 Debug"
!MESSAGE �w�肳�ꂽ ����� Ӱ�� "$(CFG)" �͐���������܂���B
!MESSAGE NMAKE �̎��s���ɍ\�����w��ł��܂�
!MESSAGE ����� ײݏ��ϸۂ̐ݒ���`���܂��B��:
!MESSAGE 
!MESSAGE NMAKE /f "project.mak" CFG="project - Win32 Debug"
!MESSAGE 
!MESSAGE �I���\������� Ӱ��:
!MESSAGE 
!MESSAGE "project - Win32 Release" ("Win32 (x86) Generic Project" �p)
!MESSAGE "project - Win32 Debug" ("Win32 (x86) Generic Project" �p)
!MESSAGE 
!ERROR �����ȍ\�����w�肳��Ă��܂��B
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

OUTDIR=.
INTDIR=.

!IF "$(RECURSE)" == "0" 

ALL : 

!ELSE 

ALL : "ruby19g - Win32 Release" "ruby19c - Win32 Release" "ruby18grt - Win32 Release" "ruby18g - Win32 Release" "ruby18crt - Win32 Release" "ruby18c - Win32 Release" 

!ENDIF 

!IF "$(RECURSE)" == "1" 
CLEAN :"ruby18c - Win32 ReleaseCLEAN" "ruby18crt - Win32 ReleaseCLEAN" "ruby18g - Win32 ReleaseCLEAN" "ruby18grt - Win32 ReleaseCLEAN" "ruby19c - Win32 ReleaseCLEAN" "ruby19g - Win32 ReleaseCLEAN" 
!ELSE 
CLEAN :
!ENDIF 
	-@erase 

!IF  "$(CFG)" == "project - Win32 Release"

MTL=midl.exe
MTL_PROJ=

!ELSEIF  "$(CFG)" == "project - Win32 Debug"

MTL=midl.exe
MTL_PROJ=

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("project.dep")
!INCLUDE "project.dep"
!ELSE 
!MESSAGE Warning: cannot find "project.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "project - Win32 Release" || "$(CFG)" == "project - Win32 Debug"

!IF  "$(CFG)" == "project - Win32 Release"

"ruby18c - Win32 Release" : 
   cd ".\ruby18c"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18c.mak CFG="ruby18c - Win32 Release" 
   cd ".."

"ruby18c - Win32 ReleaseCLEAN" : 
   cd ".\ruby18c"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18c.mak CFG="ruby18c - Win32 Release" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "project - Win32 Debug"

"ruby18c - Win32 Debug" : 
   cd ".\ruby18c"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18c.mak CFG="ruby18c - Win32 Debug" 
   cd ".."

"ruby18c - Win32 DebugCLEAN" : 
   cd ".\ruby18c"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18c.mak CFG="ruby18c - Win32 Debug" RECURSE=1 CLEAN 
   cd ".."

!ENDIF 

!IF  "$(CFG)" == "project - Win32 Release"

"ruby18crt - Win32 Release" : 
   cd ".\ruby18crt"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18crt.mak CFG="ruby18crt - Win32 Release" 
   cd ".."

"ruby18crt - Win32 ReleaseCLEAN" : 
   cd ".\ruby18crt"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18crt.mak CFG="ruby18crt - Win32 Release" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "project - Win32 Debug"

"ruby18crt - Win32 Debug" : 
   cd ".\ruby18crt"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18crt.mak CFG="ruby18crt - Win32 Debug" 
   cd ".."

"ruby18crt - Win32 DebugCLEAN" : 
   cd ".\ruby18crt"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18crt.mak CFG="ruby18crt - Win32 Debug" RECURSE=1 CLEAN 
   cd ".."

!ENDIF 

!IF  "$(CFG)" == "project - Win32 Release"

"ruby18g - Win32 Release" : 
   cd ".\ruby18g"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18g.mak CFG="ruby18g - Win32 Release" 
   cd ".."

"ruby18g - Win32 ReleaseCLEAN" : 
   cd ".\ruby18g"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18g.mak CFG="ruby18g - Win32 Release" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "project - Win32 Debug"

"ruby18g - Win32 Debug" : 
   cd ".\ruby18g"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18g.mak CFG="ruby18g - Win32 Debug" 
   cd ".."

"ruby18g - Win32 DebugCLEAN" : 
   cd ".\ruby18g"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18g.mak CFG="ruby18g - Win32 Debug" RECURSE=1 CLEAN 
   cd ".."

!ENDIF 

!IF  "$(CFG)" == "project - Win32 Release"

"ruby18grt - Win32 Release" : 
   cd ".\ruby18grt"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18grt.mak CFG="ruby18grt - Win32 Release" 
   cd ".."

"ruby18grt - Win32 ReleaseCLEAN" : 
   cd ".\ruby18grt"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18grt.mak CFG="ruby18grt - Win32 Release" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "project - Win32 Debug"

"ruby18grt - Win32 Debug" : 
   cd ".\ruby18grt"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18grt.mak CFG="ruby18grt - Win32 Debug" 
   cd ".."

"ruby18grt - Win32 DebugCLEAN" : 
   cd ".\ruby18grt"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby18grt.mak CFG="ruby18grt - Win32 Debug" RECURSE=1 CLEAN 
   cd ".."

!ENDIF 

!IF  "$(CFG)" == "project - Win32 Release"

"ruby19c - Win32 Release" : 
   cd ".\ruby19c"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby19c.mak CFG="ruby19c - Win32 Release" 
   cd ".."

"ruby19c - Win32 ReleaseCLEAN" : 
   cd ".\ruby19c"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby19c.mak CFG="ruby19c - Win32 Release" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "project - Win32 Debug"

"ruby19c - Win32 Debug" : 
   cd ".\ruby19c"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby19c.mak CFG="ruby19c - Win32 Debug" 
   cd ".."

"ruby19c - Win32 DebugCLEAN" : 
   cd ".\ruby19c"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby19c.mak CFG="ruby19c - Win32 Debug" RECURSE=1 CLEAN 
   cd ".."

!ENDIF 

!IF  "$(CFG)" == "project - Win32 Release"

"ruby19g - Win32 Release" : 
   cd ".\ruby19g"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby19g.mak CFG="ruby19g - Win32 Release" 
   cd ".."

"ruby19g - Win32 ReleaseCLEAN" : 
   cd ".\ruby19g"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby19g.mak CFG="ruby19g - Win32 Release" RECURSE=1 CLEAN 
   cd ".."

!ELSEIF  "$(CFG)" == "project - Win32 Debug"

"ruby19g - Win32 Debug" : 
   cd ".\ruby19g"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby19g.mak CFG="ruby19g - Win32 Debug" 
   cd ".."

"ruby19g - Win32 DebugCLEAN" : 
   cd ".\ruby19g"
   $(MAKE) /$(MAKEFLAGS) /F .\ruby19g.mak CFG="ruby19g - Win32 Debug" RECURSE=1 CLEAN 
   cd ".."

!ENDIF 


!ENDIF 

