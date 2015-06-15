/*H>> $Header: /4CReleased/V2.20.00/COM/softing/fc/CMN/fc_baselib/StdAfx.h 1     28.02.07 19:00 Ln $
*----------------------------------------------------------------------------*
*
* =FILENAME            $Workfile: StdAfx.h $
*                       $Logfile: /4CReleased/V2.20.00/COM/softing/fc/CMN/fc_baselib/StdAfx.h $
*
* =PROJECT             7VH102  ATCMControl
*
* =SWKE                4CMN
*
* =COMPONENT           BaseLib
*
* =CURRENT      $Date: 28.02.07 19:00 $
*           $Revision: 1 $
*
* =ENVIRONMENT             Win32:
*                      MS Windows NT 4.0
*                      MSVC++ V5.0 / MFC 4.2 / ATL 2.0 / DAO 3.5
*                      MS Java 2.0
*                      MS Visual SourceSafe 5.0
*
* =REFERENCES
*==
*----------------------------------------------------------------------------*
*----------------------------------------------------------------------------*
* =DESCRIPTION
*    @DESCRIPTION@
*==
*----------------------------------------------------------------------------*
* =MODIFICATION
*  08.07.98  Je      File created
*  see history at end of file !
*==
*******************************************************************************
H<<*/

// stdafx.h : include file for standard system include files,
//      or project specific include files that are used frequently,
//      but are changed infrequently

#if !defined(AFX_STDAFX_H__0EDCCB87_14EB_11D2_B17C_006097E1BE2F__INCLUDED_)
#define AFX_STDAFX_H__0EDCCB87_14EB_11D2_B17C_006097E1BE2F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define _WIN32_WINNT 0x0400
// #define _ATL_APARTMENT_THREADED

#define _ATL_NO_SECURITY    // avoid WinNT specific calls !
#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <limits.h>
#include <errno.h>

#include <atlbase.h>
//You may derive a class from CComModule and use it if you want to override
//something, but do not change the name of _Module
extern CComModule _Module;
#include <atlcom.h>
#include <atlctl.h>

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__0EDCCB87_14EB_11D2_B17C_006097E1BE2F__INCLUDED)

/*
*----------------------------------------------------------------------------*
*  $History: StdAfx.h $
 * 
 * *****************  Version 1  *****************
 * User: Ln           Date: 28.02.07   Time: 19:00
 * Created in $/4CReleased/V2.20.00/COM/softing/fc/CMN/fc_baselib
 * 
 * *****************  Version 1  *****************
 * User: Ln           Date: 28.08.03   Time: 16:33
 * Created in $/4Control/COM/softing/fc/CMN/fc_baselib
 * 
 * *****************  Version 1  *****************
 * User: Ef           Date: 23.01.01   Time: 17:12
 * Created in $/4Control/COM/softing/fc/CMN/fc_baselib
 * utils and baselib from V1.3
 * 
 * *****************  Version 4  *****************
 * User: Su           Date: 12/02/98   Time: 2:58p
 * Updated in $/4Control/COM/softing/fc/CMN/baselib
 * Removed MFC Stuff
 * 
 * *****************  Version 3  *****************
 * User: Je           Date: 9.11.98    Time: 18:41
 * Updated in $/4Control/COM/softing/fc/CMN/baselib
 * * added XML encoding/decoding functions
 * * added CString from statically linked MFC lib
 * 
 * *****************  Version 2  *****************
 * User: Je           Date: 6.08.98    Time: 15:57
 * Updated in $/4Control/COM/softing/fc/CMN/baselib
 * * do not use NT security calls in ATL
 * 
 * *****************  Version 1  *****************
 * User: Je           Date: 8.07.98    Time: 11:21
 * Created in $/4Control/COM/softing/fc/CMN/baselib
*==
*----------------------------------------------------------------------------*
*/

// 08.07.98  Generated by VC++5.0 VBScript '4C Macros.dsm' Version 1.1/Je
// ***************************  E O F  ******************************
// $Workfile: StdAfx.h $