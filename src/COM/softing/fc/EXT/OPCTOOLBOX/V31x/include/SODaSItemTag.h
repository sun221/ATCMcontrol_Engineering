//-----------------------------------------------------------------------------
//                                                                            |



//                                                                            |



//                                                                            |
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//                           OPC TOOLBOX - SODaS                              |
//                                                                            |
//  Filename    : SODaSItemTag.h                                              |
//  Version     : 3.10.release                                                |
//  Date        : 4-March-2002                                                |
//                                                                            |
//  Description : Item tag classes                                            |
//                - SODaSItemTag: base class for tag and property classes     |
//                - SODaSItemTagIConnect: I/O connection data interface       |
//                - SODaSItemTagConnectQueueStore: store queued I/O mode data |
//                - SODaSItemTagConnectItemsStore: store items of the item tag|
//                    for event driven I/O                                    |
//                                                                            |
//-----------------------------------------------------------------------------

#ifndef _SODASITEMTAG_H_
#define _SODASITEMTAG_H_

#include <opcda.h>
#include "SOCmnElement.h"
#include "SODaSRequest.h"

#pragma pack(push,4)

//-----------------------------------------------------------------------------
// SODaSItemTagIConnect                                                        |
//-----------------------------------------------------------------------------

class SODAS_EXPORT SODaSItemTagIConnect
{
public:
	// read queue
	virtual SOCmnList<SODaSRequest> *getReadQueue(void);
	virtual HANDLE getReadEvent(void);

	// write queue
	virtual SOCmnList<SODaSRequest> *getWriteQueue(void);
	virtual HANDLE getWriteEvent(void);

	// connected objects (e.g items connected to the item tag)
	virtual void getAllConnectedObjects(IN DWORD objType, 
					OUT SOCmnList<SOCmnObject> &objList);
	virtual DWORD notifyAllConnectedObjects(IN OPTIONAL LPVARIANT value = NULL,
					IN OPTIONAL WORD quality = OPC_QUALITY_GOOD, IN OPTIONAL LPFILETIME timeStamp = NULL);
	virtual void addConnectedObject(IN SOCmnObject *obj);
	virtual void removeConnectedObject(IN SOCmnObject *obj);

protected:
	SODaSItemTagIConnect();
	virtual ~SODaSItemTagIConnect();

	// report updateMode notification routines
	DWORD notifyItems(IN SOCmnList<SODaSItem> *itemList, IN LPVARIANT value,
					IN WORD quality, IN LPFILETIME timeStamp);

	virtual SOCmnObject *getObjectDaSItemTagIConnect(void);
}; // SODaSItemTagIConnect


//-----------------------------------------------------------------------------
// SODaSItemTagConnectQueueStore                                              |
//-----------------------------------------------------------------------------

class SODAS_EXPORT SODaSItemTagConnectQueueStore : virtual public SODaSItemTagIConnect
{
public:
	// read queue
	virtual SOCmnList<SODaSRequest> *getReadQueue(void);
	virtual HANDLE getReadEvent(void);
	BOOL setReadQueue(IN SOCmnList<SODaSRequest> *queue);
	BOOL setReadEvent(IN HANDLE event);

	// write queue
	virtual SOCmnList<SODaSRequest> *getWriteQueue(void);
	virtual HANDLE getWriteEvent(void);
	BOOL setWriteQueue(IN SOCmnList<SODaSRequest> *queue);
	BOOL setWriteEvent(IN HANDLE event);

protected:
	HANDLE m_readEvent;						// read start event
	HANDLE m_writeEvent;					// write start event
	SOCmnList<SODaSRequest> m_readQueue;	// read queue
	SOCmnList<SODaSRequest> m_writeQueue;	// write queue

	SODaSItemTagConnectQueueStore();
	virtual ~SODaSItemTagConnectQueueStore();
}; // SODaSItemTagConnectQueueStore


//-----------------------------------------------------------------------------
// SODaSItemTagConnectItemsStore                                              |
//-----------------------------------------------------------------------------

class SODAS_EXPORT SODaSItemTagConnectItemsStore : virtual public SODaSItemTagIConnect
{
public:
	// connected objects (e.g items connected to the item tag)
	virtual void getAllConnectedObjects(IN DWORD objType, 
					OUT SOCmnList<SOCmnObject> &objList);
	virtual void addConnectedObject(IN SOCmnObject *obj);
	virtual void removeConnectedObject(IN SOCmnObject *obj);

protected:
	SOCmnList<SODaSItem> m_itemList;

	SODaSItemTagConnectItemsStore();
	virtual ~SODaSItemTagConnectItemsStore();
}; // SODaSItemTagConnectItemsStore




//-----------------------------------------------------------------------------
// SODaSItemTag                                                               |
//-----------------------------------------------------------------------------

#define SODASITEMTAG_MASK_DYNAMIC      0x80
#define SODASITEMTAG_MASK_ACCESSRIGHTS 0x03
#define SODASITEMTAG_MASK_DEFAULTACCESSRIGHTS 0x04
#define SODASITEMTAG_MASK_DEVICEIOMODE 0x07
#define SODASITEMTAG_MASK_UPDATEMODE   0x80

class SODaSCache;
class SODaSItem;

class SODAS_EXPORT SODaSItemTag 
: public SOCmnElement,
  virtual public SODaSItemTagIConnect
{
friend SODaSRequest;
friend SODaSGroup;

public:
	// device I/O mode of item tag 
	enum itemTagDeviceIOMode
	{
		direct = 1, // direct I/O (calls handleRequest)
		queue,      // queued I/O (uses SODaSItemTagIQueue)
		cache,			// use the value of the cache it's the current device value (event driven)
		transaction,// direct blocked I/O of more requests (calls SODaSTransaction::handleRequests)
		constant,   // constant tag value (setConstantValue)
		delegate    // delegate the request to another request
	};

	// update mode for cyclic reads
	enum itemTagUpdateMode
	{
		poll = 0x00,	// poll tag and check for changes
		report = 0x80	// use report list to get the changes
	};

	SODaSItemTag(IN DWORD objType); 
	
	// item tag name
	virtual HRESULT setName(IN LPCTSTR name);

	// pointer to cache object
	virtual BOOL setCache(IN SODaSCache *cache);
	SODaSCache *getCache(void);
	BOOL hasCache(IN SODaSCache *cache) const;

	// access rights
	virtual BOOL setAccessRights(IN DWORD rights);
	DWORD getAccessRights(void) const;
	virtual DWORD getAccessRights(IN SODaSServer *server);
	BOOL areDefaultAccessRights(void) const;

	// native datatype
	virtual BOOL setNativeDatatype(IN VARTYPE datatype);
	VARTYPE getNativeDatatype(void) const;

	// datatype conversion
	virtual BOOL supportDatatype(IN VARTYPE dataType);
	virtual HRESULT supportReqDatatype(IN VARTYPE reqDataType);

	// access paths
	virtual BOOL setAccessPaths(IN SOCmnStringList *accessPaths);
	virtual void getAccessPaths(OUT SOCmnStringList *accessPaths);
	virtual BOOL checkAccessPath(IN SOCmnString accessPath);

	// I/O mode
	virtual BYTE getDeviceIOMode(IN SODaSRequest *req);
	void setDeviceIOMode(BYTE deviceIOMode);

	// update mode
	BYTE getUpdateMode(void) const;
	void setUpdateMode(BYTE updateMode);

	// dynamic created item tag
	virtual BOOL setDynamic(IN BOOL dynamic);
	BOOL getDynamic(void) const;

	// constant item tag value (sets I/O mode to constant)
	BOOL setConstantValue(LPVARIANT value);

	// request handling
	virtual void handleRequest(IN SODaSRequest *request);

	// engineering units information and type
	virtual BOOL getEUInfo(OUT LPVARIANT info);
	virtual OPCEUTYPE getEUType(void);

	// item tags item id
	virtual SOCmnString getItemID(void);

	// device state and state info for watch
	virtual SOCmnString getDeviceState(void);
	virtual SOCmnString getDeviceStateInfo(void);

protected:
	virtual ~SODaSItemTag(void); 

	SODaSCache *m_cache;			// cache object
	VARTYPE m_nativeDatatype;		// native datatype
	BYTE m_accessRightsAndDynamic;	// access rights and dynamic flag
	BYTE m_deviceIOAndUpdateMode;	// device I/O mode and update mode

	virtual BOOL addToQueue(IN SODaSRequest *req, IN BOOL readQueue);
	virtual BOOL signalQueueEvent(IN BOOL readEvent);

	virtual SOCmnObject *getObjectDaSItemTagIConnect(void);

	// callbacks
	virtual void onSetAccessRights(IN DWORD rights);
	virtual void onSetNativeDatatype(IN VARTYPE datatype);
}; // SODaSItemTag

inline BOOL SODaSItemTag::hasCache(SODaSCache *cache) const
{ return (m_cache == cache); }

inline DWORD SODaSItemTag::getAccessRights(void) const
{ return m_accessRightsAndDynamic & SODASITEMTAG_MASK_ACCESSRIGHTS; }

inline BOOL SODaSItemTag::areDefaultAccessRights(void) const
{ return m_accessRightsAndDynamic & SODASITEMTAG_MASK_DEFAULTACCESSRIGHTS; }

inline VARTYPE SODaSItemTag::getNativeDatatype(void) const
{ return m_nativeDatatype; }

inline BOOL SODaSItemTag::getDynamic(void) const
{ return (m_accessRightsAndDynamic & SODASITEMTAG_MASK_DYNAMIC); }

inline BYTE SODaSItemTag::getUpdateMode(void) const
{ return (m_deviceIOAndUpdateMode & SODASITEMTAG_MASK_UPDATEMODE); }

#define GenericItemTag SODaSItemTag

#pragma pack(pop)
#endif
