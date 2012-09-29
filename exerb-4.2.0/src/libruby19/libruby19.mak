# Microsoft Developer Studio Generated NMAKE File, Based on libruby19.dsp
!IF "$(CFG)" == ""
CFG=libruby19 - Win32 Debug
!MESSAGE �\�����w�肳��Ă��܂���B��̫�Ă� libruby19 - Win32 Debug ��ݒ肵�܂��B
!ENDIF 

!IF "$(CFG)" != "libruby19 - Win32 Release" && "$(CFG)" != "libruby19 - Win32 Debug"
!MESSAGE �w�肳�ꂽ ����� Ӱ�� "$(CFG)" �͐���������܂���B
!MESSAGE NMAKE �̎��s���ɍ\�����w��ł��܂�
!MESSAGE ����� ײݏ��ϸۂ̐ݒ���`���܂��B��:
!MESSAGE 
!MESSAGE NMAKE /f "libruby19.mak" CFG="libruby19 - Win32 Debug"
!MESSAGE 
!MESSAGE �I���\������� Ӱ��:
!MESSAGE 
!MESSAGE "libruby19 - Win32 Release" ("Win32 (x86) Static Library" �p)
!MESSAGE "libruby19 - Win32 Debug" ("Win32 (x86) Static Library" �p)
!MESSAGE 
!ERROR �����ȍ\�����w�肳��Ă��܂��B
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "libruby19 - Win32 Release"

OUTDIR=.\lib\release
INTDIR=.\obj\release
# Begin Custom Macros
OutDir=.\lib\release
# End Custom Macros

ALL : "$(OUTDIR)\libruby19.lib"


CLEAN :
	-@erase "$(INTDIR)\acosh.obj"
	-@erase "$(INTDIR)\array.obj"
	-@erase "$(INTDIR)\ascii.obj"
	-@erase "$(INTDIR)\bignum.obj"
	-@erase "$(INTDIR)\class.obj"
	-@erase "$(INTDIR)\compar.obj"
	-@erase "$(INTDIR)\crypt.obj"
	-@erase "$(INTDIR)\dir.obj"
	-@erase "$(INTDIR)\dln.obj"
	-@erase "$(INTDIR)\dmyext.obj"
	-@erase "$(INTDIR)\enum.obj"
	-@erase "$(INTDIR)\erf.obj"
	-@erase "$(INTDIR)\error.obj"
	-@erase "$(INTDIR)\euc_jp.obj"
	-@erase "$(INTDIR)\eval_exerb.obj"
	-@erase "$(INTDIR)\file.obj"
	-@erase "$(INTDIR)\finite.obj"
	-@erase "$(INTDIR)\gc.obj"
	-@erase "$(INTDIR)\hash.obj"
	-@erase "$(INTDIR)\inits.obj"
	-@erase "$(INTDIR)\io.obj"
	-@erase "$(INTDIR)\isinf.obj"
	-@erase "$(INTDIR)\isnan.obj"
	-@erase "$(INTDIR)\marshal.obj"
	-@erase "$(INTDIR)\math.obj"
	-@erase "$(INTDIR)\numeric.obj"
	-@erase "$(INTDIR)\object.obj"
	-@erase "$(INTDIR)\pack.obj"
	-@erase "$(INTDIR)\parse.obj"
	-@erase "$(INTDIR)\prec.obj"
	-@erase "$(INTDIR)\process.obj"
	-@erase "$(INTDIR)\random.obj"
	-@erase "$(INTDIR)\range.obj"
	-@erase "$(INTDIR)\re.obj"
	-@erase "$(INTDIR)\regcomp.obj"
	-@erase "$(INTDIR)\regenc.obj"
	-@erase "$(INTDIR)\regerror.obj"
	-@erase "$(INTDIR)\regexec.obj"
	-@erase "$(INTDIR)\regparse.obj"
	-@erase "$(INTDIR)\ruby.obj"
	-@erase "$(INTDIR)\signal.obj"
	-@erase "$(INTDIR)\sjis.obj"
	-@erase "$(INTDIR)\sprintf.obj"
	-@erase "$(INTDIR)\st.obj"
	-@erase "$(INTDIR)\string.obj"
	-@erase "$(INTDIR)\struct.obj"
	-@erase "$(INTDIR)\time.obj"
	-@erase "$(INTDIR)\utf8.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\variable.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\version.obj"
	-@erase "$(INTDIR)\win32.obj"
	-@erase "$(OUTDIR)\libruby19.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /w /W0 /GX /O1 /I "src" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "NT" /D "_WIN32" /D "RUBY_EXPORT" /D "RUBY19" /Fp"$(INTDIR)\libruby19.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\libruby19.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\libruby19.lib" 
LIB32_OBJS= \
	"$(INTDIR)\acosh.obj" \
	"$(INTDIR)\crypt.obj" \
	"$(INTDIR)\erf.obj" \
	"$(INTDIR)\finite.obj" \
	"$(INTDIR)\isinf.obj" \
	"$(INTDIR)\isnan.obj" \
	"$(INTDIR)\win32.obj" \
	"$(INTDIR)\array.obj" \
	"$(INTDIR)\ascii.obj" \
	"$(INTDIR)\bignum.obj" \
	"$(INTDIR)\class.obj" \
	"$(INTDIR)\compar.obj" \
	"$(INTDIR)\dir.obj" \
	"$(INTDIR)\dln.obj" \
	"$(INTDIR)\dmyext.obj" \
	"$(INTDIR)\enum.obj" \
	"$(INTDIR)\error.obj" \
	"$(INTDIR)\euc_jp.obj" \
	"$(INTDIR)\eval_exerb.obj" \
	"$(INTDIR)\file.obj" \
	"$(INTDIR)\gc.obj" \
	"$(INTDIR)\hash.obj" \
	"$(INTDIR)\inits.obj" \
	"$(INTDIR)\io.obj" \
	"$(INTDIR)\marshal.obj" \
	"$(INTDIR)\math.obj" \
	"$(INTDIR)\numeric.obj" \
	"$(INTDIR)\object.obj" \
	"$(INTDIR)\pack.obj" \
	"$(INTDIR)\parse.obj" \
	"$(INTDIR)\prec.obj" \
	"$(INTDIR)\process.obj" \
	"$(INTDIR)\random.obj" \
	"$(INTDIR)\range.obj" \
	"$(INTDIR)\re.obj" \
	"$(INTDIR)\regcomp.obj" \
	"$(INTDIR)\regenc.obj" \
	"$(INTDIR)\regerror.obj" \
	"$(INTDIR)\regexec.obj" \
	"$(INTDIR)\regparse.obj" \
	"$(INTDIR)\ruby.obj" \
	"$(INTDIR)\signal.obj" \
	"$(INTDIR)\sjis.obj" \
	"$(INTDIR)\sprintf.obj" \
	"$(INTDIR)\st.obj" \
	"$(INTDIR)\string.obj" \
	"$(INTDIR)\struct.obj" \
	"$(INTDIR)\time.obj" \
	"$(INTDIR)\utf8.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\variable.obj" \
	"$(INTDIR)\version.obj"

"$(OUTDIR)\libruby19.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "libruby19 - Win32 Debug"

OUTDIR=.\lib\debug
INTDIR=.\obj\debug
# Begin Custom Macros
OutDir=.\lib\debug
# End Custom Macros

ALL : "$(OUTDIR)\libruby19.lib"


CLEAN :
	-@erase "$(INTDIR)\acosh.obj"
	-@erase "$(INTDIR)\array.obj"
	-@erase "$(INTDIR)\ascii.obj"
	-@erase "$(INTDIR)\bignum.obj"
	-@erase "$(INTDIR)\class.obj"
	-@erase "$(INTDIR)\compar.obj"
	-@erase "$(INTDIR)\crypt.obj"
	-@erase "$(INTDIR)\dir.obj"
	-@erase "$(INTDIR)\dln.obj"
	-@erase "$(INTDIR)\dmyext.obj"
	-@erase "$(INTDIR)\enum.obj"
	-@erase "$(INTDIR)\erf.obj"
	-@erase "$(INTDIR)\error.obj"
	-@erase "$(INTDIR)\euc_jp.obj"
	-@erase "$(INTDIR)\eval_exerb.obj"
	-@erase "$(INTDIR)\file.obj"
	-@erase "$(INTDIR)\finite.obj"
	-@erase "$(INTDIR)\gc.obj"
	-@erase "$(INTDIR)\hash.obj"
	-@erase "$(INTDIR)\inits.obj"
	-@erase "$(INTDIR)\io.obj"
	-@erase "$(INTDIR)\isinf.obj"
	-@erase "$(INTDIR)\isnan.obj"
	-@erase "$(INTDIR)\marshal.obj"
	-@erase "$(INTDIR)\math.obj"
	-@erase "$(INTDIR)\numeric.obj"
	-@erase "$(INTDIR)\object.obj"
	-@erase "$(INTDIR)\pack.obj"
	-@erase "$(INTDIR)\parse.obj"
	-@erase "$(INTDIR)\prec.obj"
	-@erase "$(INTDIR)\process.obj"
	-@erase "$(INTDIR)\random.obj"
	-@erase "$(INTDIR)\range.obj"
	-@erase "$(INTDIR)\re.obj"
	-@erase "$(INTDIR)\regcomp.obj"
	-@erase "$(INTDIR)\regenc.obj"
	-@erase "$(INTDIR)\regerror.obj"
	-@erase "$(INTDIR)\regexec.obj"
	-@erase "$(INTDIR)\regparse.obj"
	-@erase "$(INTDIR)\ruby.obj"
	-@erase "$(INTDIR)\signal.obj"
	-@erase "$(INTDIR)\sjis.obj"
	-@erase "$(INTDIR)\sprintf.obj"
	-@erase "$(INTDIR)\st.obj"
	-@erase "$(INTDIR)\string.obj"
	-@erase "$(INTDIR)\struct.obj"
	-@erase "$(INTDIR)\time.obj"
	-@erase "$(INTDIR)\utf8.obj"
	-@erase "$(INTDIR)\util.obj"
	-@erase "$(INTDIR)\variable.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\version.obj"
	-@erase "$(INTDIR)\win32.obj"
	-@erase "$(OUTDIR)\libruby19.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /w /W0 /Gm /GX /ZI /Od /I "src" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NT" /D "_WIN32" /D "RUBY_EXPORT" /D "RUBY19" /Fp"$(INTDIR)\libruby19.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\libruby19.bsc" 
BSC32_SBRS= \
	
LIB32=link.exe -lib
LIB32_FLAGS=/nologo /out:"$(OUTDIR)\libruby19.lib" 
LIB32_OBJS= \
	"$(INTDIR)\acosh.obj" \
	"$(INTDIR)\crypt.obj" \
	"$(INTDIR)\erf.obj" \
	"$(INTDIR)\finite.obj" \
	"$(INTDIR)\isinf.obj" \
	"$(INTDIR)\isnan.obj" \
	"$(INTDIR)\win32.obj" \
	"$(INTDIR)\array.obj" \
	"$(INTDIR)\ascii.obj" \
	"$(INTDIR)\bignum.obj" \
	"$(INTDIR)\class.obj" \
	"$(INTDIR)\compar.obj" \
	"$(INTDIR)\dir.obj" \
	"$(INTDIR)\dln.obj" \
	"$(INTDIR)\dmyext.obj" \
	"$(INTDIR)\enum.obj" \
	"$(INTDIR)\error.obj" \
	"$(INTDIR)\euc_jp.obj" \
	"$(INTDIR)\eval_exerb.obj" \
	"$(INTDIR)\file.obj" \
	"$(INTDIR)\gc.obj" \
	"$(INTDIR)\hash.obj" \
	"$(INTDIR)\inits.obj" \
	"$(INTDIR)\io.obj" \
	"$(INTDIR)\marshal.obj" \
	"$(INTDIR)\math.obj" \
	"$(INTDIR)\numeric.obj" \
	"$(INTDIR)\object.obj" \
	"$(INTDIR)\pack.obj" \
	"$(INTDIR)\parse.obj" \
	"$(INTDIR)\prec.obj" \
	"$(INTDIR)\process.obj" \
	"$(INTDIR)\random.obj" \
	"$(INTDIR)\range.obj" \
	"$(INTDIR)\re.obj" \
	"$(INTDIR)\regcomp.obj" \
	"$(INTDIR)\regenc.obj" \
	"$(INTDIR)\regerror.obj" \
	"$(INTDIR)\regexec.obj" \
	"$(INTDIR)\regparse.obj" \
	"$(INTDIR)\ruby.obj" \
	"$(INTDIR)\signal.obj" \
	"$(INTDIR)\sjis.obj" \
	"$(INTDIR)\sprintf.obj" \
	"$(INTDIR)\st.obj" \
	"$(INTDIR)\string.obj" \
	"$(INTDIR)\struct.obj" \
	"$(INTDIR)\time.obj" \
	"$(INTDIR)\utf8.obj" \
	"$(INTDIR)\util.obj" \
	"$(INTDIR)\variable.obj" \
	"$(INTDIR)\version.obj"

"$(OUTDIR)\libruby19.lib" : "$(OUTDIR)" $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("libruby19.dep")
!INCLUDE "libruby19.dep"
!ELSE 
!MESSAGE Warning: cannot find "libruby19.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "libruby19 - Win32 Release" || "$(CFG)" == "libruby19 - Win32 Debug"
SOURCE=.\src\missing\acosh.c

"$(INTDIR)\acosh.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\missing\crypt.c

"$(INTDIR)\crypt.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\missing\erf.c

"$(INTDIR)\erf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\missing\finite.c

"$(INTDIR)\finite.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\missing\isinf.c

"$(INTDIR)\isinf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\missing\isnan.c

"$(INTDIR)\isnan.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\win32\win32.c

"$(INTDIR)\win32.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\array.c

"$(INTDIR)\array.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\ascii.c

"$(INTDIR)\ascii.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\bignum.c

"$(INTDIR)\bignum.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\class.c

"$(INTDIR)\class.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\compar.c

"$(INTDIR)\compar.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\dir.c

"$(INTDIR)\dir.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\dln.c

"$(INTDIR)\dln.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\dmyext.c

"$(INTDIR)\dmyext.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\enum.c

"$(INTDIR)\enum.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\error.c

"$(INTDIR)\error.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\euc_jp.c

"$(INTDIR)\euc_jp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\eval.c
SOURCE=.\src\eval_exerb.c

"$(INTDIR)\eval_exerb.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\file.c

"$(INTDIR)\file.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\gc.c

"$(INTDIR)\gc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\hash.c

"$(INTDIR)\hash.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\inits.c

"$(INTDIR)\inits.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\io.c

"$(INTDIR)\io.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\lex.c
SOURCE=.\src\marshal.c

"$(INTDIR)\marshal.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\math.c

"$(INTDIR)\math.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\numeric.c

"$(INTDIR)\numeric.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\object.c

"$(INTDIR)\object.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\pack.c

"$(INTDIR)\pack.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\parse.c

"$(INTDIR)\parse.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\prec.c

"$(INTDIR)\prec.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\process.c

"$(INTDIR)\process.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\random.c

"$(INTDIR)\random.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\range.c

"$(INTDIR)\range.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\re.c

"$(INTDIR)\re.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\regcomp.c

"$(INTDIR)\regcomp.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\regenc.c

"$(INTDIR)\regenc.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\regerror.c

"$(INTDIR)\regerror.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\regexec.c

"$(INTDIR)\regexec.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\regparse.c

"$(INTDIR)\regparse.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\ruby.c

"$(INTDIR)\ruby.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\signal.c

"$(INTDIR)\signal.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\sjis.c

"$(INTDIR)\sjis.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\sprintf.c

"$(INTDIR)\sprintf.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\st.c

"$(INTDIR)\st.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\string.c

"$(INTDIR)\string.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\struct.c

"$(INTDIR)\struct.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\time.c

"$(INTDIR)\time.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\utf8.c

"$(INTDIR)\utf8.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\util.c

"$(INTDIR)\util.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\variable.c

"$(INTDIR)\variable.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\src\version.c

"$(INTDIR)\version.obj" : $(SOURCE) "$(INTDIR)"
	$(CPP) $(CPP_PROJ) $(SOURCE)



!ENDIF 

