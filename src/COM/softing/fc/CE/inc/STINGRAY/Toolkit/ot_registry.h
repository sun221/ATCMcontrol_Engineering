// 
// Stingray Software Extension Classes
// Copyright (C) 1997 Stingray Software Inc.
// All Rights Reserved
// 
// This source code is only intended as a supplement to the
// Stingray Extension Class product.
// See the SEC help files for detailed information
// regarding using SEC classes.
// 
//  Author:			Rob Oliver
//  Description:	ot_registry.h - Registry class component header
//  Created:		Tue Aug 27 14:08:25 1998
//
//

#ifndef __OTM_REGISTRY_H__
#define  __OTM_REGISTRY_H__

// ***********************************************************
// *
// *  OT needs 8 byte packing for structures
// *
// ***********************************************************

#if (_MFC_VER >= 0x0300)
// pshpack8.h saves the current #pragma pack value
#include "pshpack8.h"
#else
#pragma pack(8)
#endif

// ***********************************************************
// *
// *  OT optimized include file
// *
// ***********************************************************

#ifndef __SECOPT_H__
    #include "toolkit\secopt.h"
#endif

// ***********************************************************
// *
// *  Registry Class
// *
// ***********************************************************

#ifdef OT_BLD_REGISTRY

	//Needed by SECRegistry
	#if defined(WIN32) && !defined(_WINREG_)
	#include <winreg.h>
	#endif

	// SECRegistry
	#ifndef __SECREG_H__
	#include "toolkit\secreg.h"
	#endif //__SECREG_H__

#else
	#pragma message("Warning:  The registry component was not included in the Objective Toolkit library.")
	#pragma message("          Add this component to the library using the BuildWizard and rebuild Objective Toolkit.")
#endif // OT_BLD_REGISTRY

// ***********************************************************
// *
// *  Restore default byte packing
// *
// ***********************************************************

#if (_MFC_VER >= 0x0300)
// poppack.h restores the original #pragma pack value
#include /* */ "poppack.h"
#else
// restore default packing value
#pragma pack()
#endif

#endif // __OTM_REGISTRY_H__