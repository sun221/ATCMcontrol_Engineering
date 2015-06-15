#automatically generated by ..\..\GenTools\make.pl: Version=$Revision: 1 $

!ifndef PROJECT_ROOT
!MESSAGE check environmemt: environment variable PROJECT_ROOT not defined
!ERROR PROJECT_ROOT must point to the project base directory
!endif

STATIC_RUNTIME = 0
!include <$(PROJECT_ROOT)\gentools\global.inc>
makefirst:$(EXE_DIR)\Engineering\bin\ATHW119
$(EXE_DIR)\Engineering\bin\ATHW119:
  -md $@
makefirst: $(EXE_DIR)\Engineering\bin\ATHW119\4asm.exe
$(EXE_DIR)\Engineering\bin\ATHW119\4asm.exe:
	$(CP) $(TARGET_BASE)\bin\4asm.exe $(EXE_DIR)\Engineering\bin\ATHW119\4asm.exe
postmake: make_lib
make_lib: force
     regsvr32 /s $(EXE_DIR)\Engineering\bin\cg_4claccess.dll
     regsvr32 /s $(EXE_DIR)\Engineering\bin\cg_iecfront.dll
     $(CP) $(EXE_DIR)\Pub\fc_baselib.dll $(WINDIR)\system32\fc_baselib.dll
     $(CP) $(EXE_DIR)\Pub\fc_todebug.dll $(WINDIR)\system32\fc_todebug.dll
     $(CP) $(EXE_DIR)\Pub\fc_util.dll    $(WINDIR)\system32\fc_util.dll
     cd $(MAKEDIR)\Libs
     $(MAKE) -$(MAKEFLAGS) -f Libs.mak make_lib DEBUG=$(DEBUG)
     cd $(MAKEDIR)
!if $(SUB)!=0
makemake:
	cd Online
	perl $(PROJECT_ROOT)\gentools\make.pl Online
	$(MAKE) -$(MAKEFLAGS) -f Online.mak makemake SUB=1
	cd $(MAKEDIR)
	cd KAD
	perl $(PROJECT_ROOT)\gentools\make.pl KAD
	$(MAKE) -$(MAKEFLAGS) -f KAD.mak makemake SUB=1
	cd $(MAKEDIR)
	cd AddonHandler
	perl $(PROJECT_ROOT)\gentools\make.pl AddonHandler
	$(MAKE) -$(MAKEFLAGS) -f AddonHandler.mak makemake SUB=1
	cd $(MAKEDIR)
	cd CCG
	perl $(PROJECT_ROOT)\gentools\make.pl CCG
	$(MAKE) -$(MAKEFLAGS) -f CCG.mak makemake SUB=1
	cd $(MAKEDIR)
	cd Libs
	perl $(PROJECT_ROOT)\gentools\make.pl Libs
	$(MAKE) -$(MAKEFLAGS) -f Libs.mak makemake SUB=1
	cd $(MAKEDIR)
makefirst oleclasses javaclasses precompile compile prelink link makelast:
	cd Online
	$(MAKE) -$(MAKEFLAGS) -f Online.mak $@ SUB=1 DEBUG=$(DEBUG)
	cd $(MAKEDIR)
	cd KAD
	$(MAKE) -$(MAKEFLAGS) -f KAD.mak $@ SUB=1 DEBUG=$(DEBUG)
	cd $(MAKEDIR)
	cd AddonHandler
	$(MAKE) -$(MAKEFLAGS) -f AddonHandler.mak $@ SUB=1 DEBUG=$(DEBUG)
	cd $(MAKEDIR)
	cd CCG
	$(MAKE) -$(MAKEFLAGS) -f CCG.mak $@ SUB=1 DEBUG=$(DEBUG)
	cd $(MAKEDIR)
	cd Libs
	$(MAKE) -$(MAKEFLAGS) -f Libs.mak $@ SUB=1 DEBUG=$(DEBUG)
	cd $(MAKEDIR)
clean::
	cd Online
	$(MAKE) -$(MAKEFLAGS) -f Online.mak clean SUB=1 DEBUG=$(DEBUG)
	cd $(MAKEDIR)
	cd KAD
	$(MAKE) -$(MAKEFLAGS) -f KAD.mak clean SUB=1 DEBUG=$(DEBUG)
	cd $(MAKEDIR)
	cd AddonHandler
	$(MAKE) -$(MAKEFLAGS) -f AddonHandler.mak clean SUB=1 DEBUG=$(DEBUG)
	cd $(MAKEDIR)
	cd CCG
	$(MAKE) -$(MAKEFLAGS) -f CCG.mak clean SUB=1 DEBUG=$(DEBUG)
	cd $(MAKEDIR)
	cd Libs
	$(MAKE) -$(MAKEFLAGS) -f Libs.mak clean SUB=1 DEBUG=$(DEBUG)
	cd $(MAKEDIR)
!endif
doxygen: ATHW119.doxy
	$(CP) $(PROJECT_ROOT)\gentools\4C_doxy.css .\4C_doxy.css
	doxygen ATHW119.doxy
ATHW119.doxy:
	$(CP) $(PROJECT_ROOT)\gentools\Sample.doxy .\ATHW119.doxy
