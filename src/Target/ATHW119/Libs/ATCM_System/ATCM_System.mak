#automatically generated by C:\ATCMControl_SDK\GenWork\GenDir.tmp\4Control_R\gentools\make.pl: Version=$Revision: 1 $

!ifndef PROJECT_ROOT
!MESSAGE check environmemt: environment variable PROJECT_ROOT not defined
!ERROR PROJECT_ROOT must point to the project base directory
!endif

STATIC_RUNTIME = 0
!include <$(PROJECT_ROOT)\gentools\global.inc>
libname=ATCM_System
targettype=ATHW119
makefirst: force
  xcopy $(TARGET_BASE)\Libs\$(libname)\*.*  $(MAKEDIR)\*.* /s /Y
make_lib: force
 $(4CG) $(MAKEDIR)\$(libname).4cp  -ml:$(targettype) $(ENGBIN_DIR)\$(targettype)\libs\eng\$(libname).$(targettype).4cl
 $(4CG) $(MAKEDIR)\$(libname).4cp  -ml:$(targettype) $(ENGBIN_DIR)\$(targettype)\libs\$(libname).$(targettype).4cl
 $(4CG) -al $(ENGBIN_DIR)\$(targettype)\libs\eng\$(libname).$(targettype).4cl  $(4CL_DIR)\$(libname).4cl
doxygen: ATCM_System.doxy
	$(CP) $(PROJECT_ROOT)\gentools\4C_doxy.css .\4C_doxy.css
	doxygen ATCM_System.doxy
ATCM_System.doxy:
	$(CP) $(PROJECT_ROOT)\gentools\Sample.doxy .\ATCM_System.doxy
