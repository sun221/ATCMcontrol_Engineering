/* $Header: /4CReleased/V2.20.00/TargetBase/ONLINE/inc/CSC_OnlineErr.h 1     28.02.07 19:06 Ln $
 * ------------------------------------------------------------------------------
 *
 * =FILENAME			$Workfile: CSC_OnlineErr.h $
 *						 $Logfile: /4CReleased/V2.20.00/TargetBase/ONLINE/inc/CSC_OnlineErr.h $
 *
 * =PROJECT 			ATCMControl V2.x
 *
 * =SWKE				Targetbase / Online
 *
 * =COMPONENT			OnlLibServ
 *
 * =CURRENT 	 $Date: 28.02.07 19:06 $
 *			 $Revision: 1 $
 *
 * ------------------------------------------------------------------------------
 *
 
 

 
 *	All Rights Reserved.
 *
 * ------------------------------------------------------------------------------
 */

#ifndef _CSC_ONLINE_ERR_H
#define _CSC_ONLINE_ERR_H

//standard setting for severity:
//predefined system wide facility codes (do not change!). You may
//insert additional facility codes between the main areas:
//currently supported languages:
//     0x409   English USA
//     0x407   German

//-----------------------------------------------------------------------------
// CSC_Online Error messages
//-----------------------------------------------------------------------------


//==========================================================================================
//------------------------------------------------------------------------------------------
// CSC_Online Server messages in range 1000 - 1999
//------------------------------------------------------------------------------------------
//
//
// %1      error number as integer; for all error and warning messages!
//         %1 is not present for all informational messages
//
// %2 to %4    inserts, must always be a string
//
//
//
//*****    Error messages
//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//
#define E_FACILITY_SYSCOM                0x220


//
// Define the severity codes
//


//
// MessageId: E_CSC_TRANSFER_SINGLE_DOWNLOADER_ALLOWED
//
// MessageText:
//
//  error SC%1!d!: Only a single download session at the same time allowed to 4C control
//
#define E_CSC_TRANSFER_SINGLE_DOWNLOADER_ALLOWED ((HRESULT)0xC00003E9L)

//----
//
// MessageId: E_CSC_NO_VALID_LICENSE_INFO
//
// MessageText:
//
//  error SC%1!d!: Cannot access license info for CSC_Online server
//
#define E_CSC_NO_VALID_LICENSE_INFO      ((HRESULT)0xC00003EAL)

//----
//
// MessageId: E_CSC_NO_REMOTE_DLOAD_FOR_BUNDLE_ALLOWED
//
// MessageText:
//
//  error SC%1!d!: This bundled license allows no remote download
//
#define E_CSC_NO_REMOTE_DLOAD_FOR_BUNDLE_ALLOWED ((HRESULT)0xC00003EBL)

//----
//
// MessageId: E_CSC_NO_FTP_SESSION
//
// MessageText:
//
//  error SC%1!d!: Connection to Web server for transfer of visualisation domains failed
//
#define E_CSC_NO_FTP_SESSION             ((HRESULT)0xC00003ECL)

//----
//
// MessageId: E_CSC_NO_CONNECT_TO_CONTROL
//
// MessageText:
//
//  error SC%1!d!: COM Connection to control failed
//
#define E_CSC_NO_CONNECT_TO_CONTROL      ((HRESULT)0xC00003EDL)

//----
//
// MessageId: E_CSC_NO_DEBUG_SESSION_TO_CONTROL
//
// MessageText:
//
//  error SC%1!d!: Cannot establish a debug connection to control
//
#define E_CSC_NO_DEBUG_SESSION_TO_CONTROL ((HRESULT)0xC00003EEL)

//----
//
// MessageId: E_CSC_BAD_SECURITY_FILE_SYNTAX
//
// MessageText:
//
//  error SC%1!d!: Bad security file syntax
//
#define E_CSC_BAD_SECURITY_FILE_SYNTAX   ((HRESULT)0xC00003EFL)

//----
//
// MessageId: S_CSC_COMM_SESSION_LOGOUT_FORCED
//
// MessageText:
//
//  warning SC%1!d!: User %2 from engineering %3 forced disconnect of debugger
//
#define S_CSC_COMM_SESSION_LOGOUT_FORCED ((HRESULT)0x400003F0L)

//----
//
// MessageId: E_CSC_CONTROL_NOT_RUNNING
//
// MessageText:
//
//  fatal error SC%1!d!: 4C Control is not running
//
#define E_CSC_CONTROL_NOT_RUNNING        ((HRESULT)0xC00003F1L)

//----
//
// MessageId: E_CSC_RESOURCE_CLEARED
//
// MessageText:
//
//  fatal error SC%1!d!: The resource is cleared
//
#define E_CSC_RESOURCE_CLEARED           ((HRESULT)0xC00003F2L)

//----
//==========================================================================================
//------------------------------------------------------------------------------------------
// CSC_Online ActiveX-Control messages in range 2000 - 2999
//------------------------------------------------------------------------------------------
//
//
// %1      error number as integer; for all error and warning messages!
//         %1 is not present for all informational messages
//
// %2 to %4    inserts, must always be a string
//
//
//
//*****    Error messages
//
// MessageId: E_CSC_SESSION_BAD_ADDRESS
//
// MessageText:
//
//  error SC2000: Connection address string format wrong
//
#define E_CSC_SESSION_BAD_ADDRESS        ((HRESULT)0xC00007D0L)

//
// MessageId: E_CSC_SESSION_NOT_CONNECTED
//
// MessageText:
//
//  error SC2001: No connection to target.
//
#define E_CSC_SESSION_NOT_CONNECTED      ((HRESULT)0xC00007D1L)

//
// MessageId: E_CSC_REQUEST_TIMEOUT
//
// MessageText:
//
//  error SC2002: %1 command request timed out.
//
#define E_CSC_REQUEST_TIMEOUT            ((HRESULT)0xC00007D2L)


//*****    Informational messages
//----
//
// MessageId: S_CSC_VAR_NOT_CONNECTED
//
// MessageText:
//
//  warning SC%1!d!: Variable was added but is not yet connected
//
#define S_CSC_VAR_NOT_CONNECTED          ((HRESULT)0x400007E4L)

//----

#endif

/* ---------------------------------------------------------------------------- */
