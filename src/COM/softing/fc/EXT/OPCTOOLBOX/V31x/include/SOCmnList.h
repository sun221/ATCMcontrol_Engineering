//-----------------------------------------------------------------------------
//                                                                            |



//                                                                            |



//                                                                            |
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//                           OPC TOOLBOX - SOCmn                              |
//                                                                            |
//  Filename    : SOCmnList.h                                                 |
//  Version     : 3.11.release                                                |
//  Date        : 2-April-2003                                                |
//                                                                            |
//  Description : List classes                                                |
//                - SOCmnList: common list class                              |
//                - SOCmnStringList: string list class                        |
//                - SOCmnDWORDList: DWORD list class                          |
//                - SOCmnListPosition: position while iterating the list      |
//                - SOCmnListConfig: list configuration                       |
//                - SOCmnListEntry: entry of list                             |
//                - SOCmnListEntryWithKey: entry with key information stored  |
//                - SOCmnListInfoSimpleList: information for simple list      |
//                - SOCmnListInfoFullList: information for complex list       |
//                - SOCmnListBlock: entry of free blocks list                 |
//                                                                            |
//-----------------------------------------------------------------------------

#ifndef _SOCMNLIST_H_
#define _SOCMNLIST_H_

#include "SOCmnString.h"
class SOCmnSync;

#pragma pack(push,4)

// list types
#define SOCMNLIST_TYPE_NOTINIT				0x8000
#define SOCMNLIST_TYPE_ORG_LIST				0x4000
#define SOCMNLIST_TYPE_ORG_MAP				0x2000
#define SOCMNLIST_TYPE_ORG_MASK				0x6000
#define SOCMNLIST_TYPE_OBJ_DWORD			0x0001
#define SOCMNLIST_TYPE_OBJ_VOID				0x0002
#define SOCMNLIST_TYPE_OBJ_STRING			0x0003
#define SOCMNLIST_TYPE_OBJ_OBJECT			0x0004
#define SOCMNLIST_TYPE_OBJ_VARIANT			0x0005
#define SOCMNLIST_TYPE_OBJ_INTERFACE		0x0006
#define SOCMNLIST_TYPE_OBJ_DATA				0x0007
#define SOCMNLIST_TYPE_OBJ_MASK				0x0007
#define SOCMNLIST_TYPE_KEY_NO				0x0010
#define SOCMNLIST_TYPE_KEY_DWORD			0x0020
#define SOCMNLIST_TYPE_KEY_STRING			0x0030
#define SOCMNLIST_TYPE_KEY_MASK				0x0030
#define SOCMNLIST_TYPE_OBJECT_KEY_STRING	0x0040
#define SOCMNLIST_TYPE_SYNCED				0x0100
#define SOCMNLIST_TYPE_BLOCKED				0x0200
#define SOCMNLIST_TYPE_FLAGS				0x0400
#define SOCMNLIST_TYPE_INFO_FULL_LIST		0x0700

// list states
#define SOCMNLIST_STATE_AUTO_UNLOCKED	0x01
#define SOCMNLIST_STATE_AUTO_LOCKED		0x02
#define SOCMNLIST_STATE_AUTO_NOTLOCK	0x03
#define SOCMNLIST_STATE_AUTO_MASK		0x03
#define SOCMNLIST_STATE_CREATED			0x80

// list flags
#define SOCMNLIST_FLAG_DIRTY	0x01


//-----------------------------------------------------------------------------
// SOCmnListPosition                                                          |
//-----------------------------------------------------------------------------

struct tagSOCmnListPosition {};
typedef tagSOCmnListPosition *SOCmnListPosition;


//-----------------------------------------------------------------------------
// SOCmnListConfig                                                            |
//-----------------------------------------------------------------------------

class SOCMN_EXPORT SOCmnListConfig
{
public:
	SOCmnListConfig(void);

	WORD m_type;			// list type
	BYTE m_entriesPerBlock;	// default number of block elements
	WORD m_hashTableSize;	// size of hash table
}; // SOCmnListConfig


//-----------------------------------------------------------------------------
// SOCmnListBlock                                                             |
//-----------------------------------------------------------------------------

class SOCmnListHeader;

class SOCMN_EXPORT SOCmnListBlock
{
friend SOCmnListHeader;
protected:
	SOCmnListBlock *m_next;	// next list block
}; // SOCmnListBlock


//-----------------------------------------------------------------------------
// SOCmnListEntry                                                             |
//-----------------------------------------------------------------------------

class SOCmnObject;
class SOCmnVariant;
class SOCmnString;

class SOCMN_EXPORT SOCmnListEntry
{
friend SOCmnListHeader;
public:
	SOCmnListEntry(void);
	~SOCmnListEntry(void);

protected:
	union
	{
	void *m_object;			// the object of the entry 
	DWORD m_objectDWORD;
	SOCmnString *m_objectString;
	SOCmnVariant *m_objectVariant;
	SOCmnObject *m_objectObject;
	};
	SOCmnListEntry *m_next;	// next list entry
}; // SOCmnListEntry


//-----------------------------------------------------------------------------
// SOCmnListEntryWithKey                                                      |
//-----------------------------------------------------------------------------
 
class SOCmnString;

class SOCMN_EXPORT SOCmnListEntryWithKey : public SOCmnListEntry
{
friend SOCmnListHeader;
public:
	SOCmnListEntryWithKey(void);
	~SOCmnListEntryWithKey(void);

protected:
	union
	{
	void *m_key;	// key
	DWORD m_keyDWORD;
	SOCmnString *m_keyString;
	};
}; // SOCmnListEntryWithKey


//-----------------------------------------------------------------------------
// SOCmnListInfoSimpleList                                                    |
//-----------------------------------------------------------------------------

class SOCMN_EXPORT SOCmnListInfoSimpleList
{
friend SOCmnListHeader;
public:
	SOCmnListInfoSimpleList(void);
	~SOCmnListInfoSimpleList(void);

protected:
	union
	{
	void *m_start;	// first entry of the list
	SOCmnListEntry *m_startEntry;
	SOCmnListEntryWithKey *m_startEntryWithKey;
	};
	union
	{
	void *m_end;	// last entry of the list
	SOCmnListEntry *m_endEntry;
	SOCmnListEntryWithKey *m_endEntryWithKey;
	};
}; // SOCmnListInfoSimpleList


//-----------------------------------------------------------------------------
// SOCmnListInfoFullList                                                      |
//-----------------------------------------------------------------------------

class SOCMN_EXPORT SOCmnListInfoFullList : public SOCmnListInfoSimpleList
{
friend SOCmnListHeader;
public:
	SOCmnListInfoFullList(void);
	~SOCmnListInfoFullList(void);

protected:
	SOCmnSync *m_sync;				// synchronisation object
	union
	{
	void *m_free;					// first element of free entries list
	SOCmnListEntry *m_freeEntry;
	};
	SOCmnListBlock *m_blockFirst;	// first element of free blocks list
	WORD m_count;					// number of entries in the list
	BYTE m_defaultBlockElements;	// default number of elements per block
	BYTE m_flags;					// list flags
}; // SOCmnListInfoFullList


//-----------------------------------------------------------------------------
// SOCmnListInfoMap                                                           |
//-----------------------------------------------------------------------------

class SOCMN_EXPORT SOCmnListInfoMap 
{
friend SOCmnListHeader;
public:
	SOCmnListInfoMap(void);
	~SOCmnListInfoMap(void);

protected:
	void *m_hashTable;				// pointer to first hash table entry
	SOCmnSync *m_sync;				// synchronisation object
	union
	{
	void *m_free;					// first element of free entries list
	SOCmnListEntry *m_freeEntry;
	};
	SOCmnListBlock *m_blockFirst;	// first element of free blocks list
	WORD m_count;					// number of entries in the list
	WORD m_hashTableSize;			// size of hash table
	BYTE m_defaultBlockElements;	// default number of elements per block
	BYTE m_flags;					// list flags
}; // SOCmnListInfoMap


//-----------------------------------------------------------------------------
// SOCmnListHeader                                                            |
//-----------------------------------------------------------------------------

class SOCMN_EXPORT SOCmnListHeader
{
public:

	// constructor
	SOCmnListHeader(void);

	// destructor
	~SOCmnListHeader(void); 

	// assign existing list
	SOCmnListHeader& operator=(IN const SOCmnListHeader& list);
	void detach(void);

	// create/ list
	BOOL create(IN OPTIONAL SOCmnListConfig *creationConfig = NULL);
	void destroy(void);
	BOOL clone(IN SOCmnListHeader& list);

	SOCmnListPosition add(IN void *obj, IN void *key, IN WORD keyType);
	SOCmnListPosition addMemory(IN void *memory, IN DWORD len, IN void *key, IN WORD keyType);
	DWORD getCount(void);
	BOOL isEmpty(void);
	SOCmnListPosition push(IN void *obj);

	SOCmnListPosition update(IN void *obj, IN void *key, IN WORD keyType);

	SOCmnListPosition getStartPosition(void);
	void *getNext(IN OUT SOCmnListPosition& pos, IN WORD keyType, OUT void **key) const;

	BOOL removeObject(IN void *obj);
	BOOL removeKey(IN void *key, IN WORD keyType);
	BOOL removeAt(IN SOCmnListPosition pos);
	BOOL removeHead(void);
	void removeAll(void);

	void *getHead(void);
	void *getIndex(IN DWORD idx, IN WORD keyType, OUT void **key);
	void *pop(void);
	
	SOCmnListPosition findObject(IN void *obj);
	void *findKey(IN void *key, IN WORD keyType, OUT BOOL *found);

	BOOL isDirty(void) const; 
	BOOL setDirty(IN BOOL dirty);

	BOOL getKey(IN SOCmnListEntry *entry, IN WORD keyType, OUT void **key) const;
	BOOL hasKey(IN SOCmnListEntry *entry, void *key, IN WORD keyType) const;
	BOOL hasObject(IN SOCmnListEntry *entry, void *obj) const;
	BOOL getObjectKey(IN void *obj, IN WORD keyType, OUT void **key) const;

	DWORD hashKey(IN void *key, IN WORD keyType) const;

	// synchonisation
	void lock(void);
	void unlock(void);

	// list type
	BOOL isMap(void) const;
	BOOL isList(void) const;
	BOOL isInit(void) const;
	WORD getType(void) const;

	SOCmnSync *getSyncObject(void);

	// prevent locking
	void doAutoLock(IN BOOL doIt);
	void autoUnlock(void);

	BOOL createBlock(DWORD blockElements);
	BOOL setDefaultBlockElements(BYTE blockElements);
	DWORD getAvailableAllocatedEntries(void);

	void autoLock(void);

	void ensureType(IN WORD type);

protected:
	union 
	{
	void *m_info;
	SOCmnListInfoSimpleList *m_infoSimpleList;
	SOCmnListInfoFullList *m_infoFullList;
	SOCmnListInfoMap *m_infoMap;
	};
	WORD m_type;
	BYTE m_state;

	// create list entry
	SOCmnListEntry *createEntry(IN void *obj, IN void *key, IN WORD keyType);
	void destroyEntry(IN SOCmnListEntry *entry);
	SOCmnListEntry *cloneEntry(IN SOCmnListEntry *entryS);
	SOCmnListEntry *allocateEntry(void);

	void updateCount(IN BOOL increment);

	void checkInit(void) const;
}; // SOCmnListHeader

inline void SOCmnListHeader::autoLock(void)
{ if ((m_state & SOCMNLIST_STATE_AUTO_MASK) == SOCMNLIST_STATE_AUTO_UNLOCKED) { lock(); m_state = (m_state & ~SOCMNLIST_STATE_AUTO_MASK) | SOCMNLIST_STATE_AUTO_LOCKED; } }

inline void SOCmnListHeader::autoUnlock(void)
{ if ((m_state & SOCMNLIST_STATE_AUTO_MASK) == SOCMNLIST_STATE_AUTO_LOCKED) { unlock(); m_state = (m_state & ~SOCMNLIST_STATE_AUTO_MASK) | SOCMNLIST_STATE_AUTO_UNLOCKED; } }

inline BOOL SOCmnListHeader::isMap(void) const
{ return ((m_type & SOCMNLIST_TYPE_ORG_MASK) == SOCMNLIST_TYPE_ORG_MAP); }

inline BOOL SOCmnListHeader::isList(void) const
{ return ((m_type & SOCMNLIST_TYPE_ORG_MASK) == SOCMNLIST_TYPE_ORG_LIST); }

inline WORD SOCmnListHeader::getType(void) const
{ return m_type; }

inline BOOL SOCmnListHeader::isInit(void) const
{ return ((m_type & SOCMNLIST_TYPE_NOTINIT) == 0); }




//-----------------------------------------------------------------------------
// SOCmnList                                                                  |
//-----------------------------------------------------------------------------

template <class T> class SOCmnList
{
public:
	// constructors
	SOCmnList(void) {}
	SOCmnList(IN const SOCmnList<T>& list) { m_list = list.m_list; }
	SOCmnList(IN SOCmnList<T> *list) { if (list) m_list = list->m_list; }

	// destructor
	~SOCmnList(void) {} 

	// assign list
	SOCmnList& operator=(IN SOCmnList<T>* list) { if (list) { m_list = list->m_list; } return *this; }
	SOCmnList& operator=(IN const SOCmnList<T>& list) { m_list = list.m_list; return *this; }
	void attach(IN SOCmnList<T>* list) { if (list) { m_list = list->m_list; } }
	void detach(void) { m_list.detach(); }

	// check if list is initialized
	bool operator!() { return !m_list.isInit(); } 
	BOOL isInit(void) const { return m_list.isInit(); }
	operator SOCmnListPosition(void) { return m_list.getStartPosition(); } 

	// create list
	BOOL create(IN SOCmnListConfig *creationConfig) { return m_list.create(creationConfig); }
	BOOL create(IN WORD type) { SOCmnListConfig cfg; cfg.m_type = type; cfg.m_entriesPerBlock = 10; cfg.m_hashTableSize = 17; return m_list.create(&cfg); }

	// clone existing list
	BOOL clone(IN SOCmnList<T> &list) { return m_list.clone(list.m_list); }
	BOOL clone(IN SOCmnList<T> *list) { if (list) return m_list.clone(list->m_list); else return FALSE; }

	// free list
	void destroy(void) { m_list.destroy(); }	

	// remove all list and map entries
	void clear(void) { m_list.removeAll(); }
	void removeAll(void) { m_list.removeAll(); }

	// get start position
	SOCmnListPosition getStartPosition(void) { return m_list.getStartPosition(); }

	// get entry count
	DWORD getCount(void) { return m_list.getCount(); }

	// check if list is empty
	BOOL isEmpty(void) { return m_list.isEmpty(); }

	//-- get --

	// get current object (additional get key on next entry too) and get next position
	T* getNext(IN OUT SOCmnListPosition& pos) const { return ((T*) m_list.getNext(pos, SOCMNLIST_TYPE_KEY_NO, NULL)); }
	T* getNext(IN OUT SOCmnListPosition& pos, OUT DWORD *key) const { return ((T*) m_list.getNext(pos, SOCMNLIST_TYPE_KEY_DWORD, (void **)key)); }
	T* getNext(IN OUT SOCmnListPosition& pos, OUT SOCmnString *key) const { return ((T*) m_list.getNext(pos, SOCMNLIST_TYPE_KEY_STRING, (void **)key)); }

	// get head object 
	T* getHead(void) { return (T*)m_list.getHead(); }

	// get the object at specific index (zero based)
	T* getIndex(IN DWORD idx) { return (T*)m_list.getIndex(idx, SOCMNLIST_TYPE_KEY_NO, NULL); }

	// get object from the head of the list
	T* pop(void) { return (T*)m_list.pop(); }

	//-- add --

	// add object (with key)
	BOOL add(IN T *obj) { return (m_list.add((void *) obj, 0, SOCMNLIST_TYPE_KEY_NO) != NULL); }
	BOOL add(IN T *obj, IN DWORD key) { return (m_list.add((void *) obj, (void *)key, SOCMNLIST_TYPE_KEY_DWORD) != NULL); }
	BOOL add(IN T *obj, IN LPCTSTR key) { return (m_list.add((void *) obj, (void *)key, SOCMNLIST_TYPE_KEY_STRING) != NULL); }

	// add void object (with key)
	BOOL addMemory(IN T *memory, IN DWORD len) { return (NULL != m_list.addMemory((void *)memory, len, (void *)NULL, SOCMNLIST_TYPE_KEY_NO)); }
	BOOL addMemory(IN T *memory, IN DWORD len, IN DWORD key) { return (NULL != m_list.addMemory((void *)memory, len, (void *)key, SOCMNLIST_TYPE_KEY_DWORD)); }
	BOOL addMemory(IN T *memory, IN DWORD len, IN LPCTSTR key) { return (NULL != m_list.addMemory((void *)memory, len, (void *)key, SOCMNLIST_TYPE_KEY_STRING)); }

	// add object a the head of the list
	BOOL push(IN T *obj) { return (m_list.push((void *) obj) != NULL); }

	//-- update -- 	

	// update object
	BOOL update(IN T *obj, IN DWORD key) { return (m_list.update((void *) obj, (void *)key, SOCMNLIST_TYPE_KEY_DWORD) != NULL); }
	BOOL update(IN T *obj, IN LPCTSTR key) { return (m_list.update((void *) obj, (void *)key, SOCMNLIST_TYPE_KEY_STRING) != NULL); }

	//-- find --

	// find object by key
	T *findKey(IN LPCTSTR key) { return ((T*)m_list.findKey((void *)key, SOCMNLIST_TYPE_KEY_STRING, NULL)); }
	T *findKey(IN DWORD key) { return ((T*)m_list.findKey((void *)key, SOCMNLIST_TYPE_KEY_DWORD, NULL)); }
	BOOL findKey(IN DWORD key, OUT T** obj) { T *found = NULL; BOOL ret; found = (T*)m_list.findKey((void *)key, SOCMNLIST_TYPE_KEY_DWORD, NULL); if (obj) *obj = found; ret = (NULL != found); if ((m_list.getType() & SOCMNLIST_TYPE_OBJ_MASK) == SOCMNLIST_TYPE_OBJ_OBJECT) ((SOCmnObject *)found)->release(); return ret; }
	BOOL findKey(IN LPCTSTR key, OUT T** obj) { T *found = NULL; BOOL ret; found = (T*)m_list.findKey((void *)key, SOCMNLIST_TYPE_KEY_STRING, NULL); if (obj) *obj = found; ret = (NULL != found); if ((m_list.getType() & SOCMNLIST_TYPE_OBJ_MASK) == SOCMNLIST_TYPE_OBJ_OBJECT) ((SOCmnObject *)found)->release(); return ret; }

	// find position of object (check if object is in list)
	SOCmnListPosition findObject(IN T* obj) { return m_list.findObject((void *)obj); }

	//-- remove --

	// remove list entry by object
	BOOL removeObject(IN T* obj) { return m_list.removeObject((void *)obj); }

	// remove list entry by key
	BOOL removeKey(IN LPCTSTR key) { return m_list.removeKey((void *)key, SOCMNLIST_TYPE_KEY_STRING); }
	BOOL removeKey(IN DWORD key) { return m_list.removeKey((void *)key, SOCMNLIST_TYPE_KEY_DWORD); }

	// remove list entry by position
	BOOL removeAt(IN SOCmnListPosition pos) { return m_list.removeAt(pos); }
	BOOL removeHead(void) { return m_list.removeHead(); }

	//-- sync --

	// lock list and map
	void lock(void) { m_list.lock(); }

	// unlock list and map
	void unlock(void) { m_list.unlock(); }

	// prevent locking
	void autoLock(void) { m_list.autoLock(); }
	void dontAutoLock(void) { m_list.doAutoLock(FALSE); }
	void autoUnlock(void) { m_list.autoUnlock(); }

	// get lock object
	SOCmnSync *getSyncObject(void) { return m_list.getSyncObject(); }

	//-- dirty --

	BOOL isDirty(void) const { return m_list.isDirty(); }
	BOOL setDirty(OPTIONAL IN BOOL dirty = FALSE) { return m_list.setDirty(dirty); }

	//-- block --

	// set the default number of entries allocated in a block
	BOOL setDefaultEntriesPerBlock(IN BYTE number) { return m_list.setDefaultBlockElements(number); }

	// allocate a block
	BOOL allocateBlock(IN DWORD number) { return m_list.createBlock(number); }

	DWORD getAvailableAllocatedEntries(void) { return m_list.getAvailableAllocatedEntries(); }

	BOOL isMap(void) const { return m_list.isMap(); }
	BOOL isList(void) const { return m_list.isList(); }

	void ensureType(IN WORD type) { m_list.ensureType(type); }

	// compatibiliy to previous versions
	// DO NOT USE THIS METHODS !
	SOCmnListPosition AddTail(IN T* obj) { return m_list.add((void *) obj, 0, SOCMNLIST_TYPE_KEY_NO); }
	SOCmnListPosition Find(IN T* obj) { return m_list.findObject((void *)obj); }
	DWORD GetCount(void) { return m_list.getCount(); }
	SOCmnListPosition GetHeadPosition(void) { return m_list.getStartPosition(); }
	T* GetNext(IN OUT SOCmnListPosition& pos) const { return ((T*) m_list.getNext(pos, SOCMNLIST_TYPE_KEY_NO, NULL)); }
	BOOL IsEmpty(void) { return m_list.isEmpty(); }
	void RemoveAll(void) { m_list.removeAll(); }
	BOOL RemoveAt(IN SOCmnListPosition pos) { return m_list.removeAt(pos); }
	BOOL RemoveHead(void) { return m_list.removeHead(); }

protected:
	SOCmnListHeader m_list;
}; // SOCmnList



// Memory allocation types                                                    
typedef enum _tagEnumMemAlloc
{
  useMalloc = 0,
  useCoTaskMemAlloc = 1,
} enumMemAlloc;

//-----------------------------------------------------------------------------
// SOCmnStringList                                                            |
//-----------------------------------------------------------------------------

class SOCMN_EXPORT SOCmnStringList
{
public:
	// constructors
	SOCmnStringList(void) {}
	SOCmnStringList(IN const SOCmnStringList& list) { m_list = list.m_list; }
	SOCmnStringList(IN SOCmnStringList *list) { if (list) m_list = list->m_list; }

	// destructor
	~SOCmnStringList(void) {}

	// create list
	BOOL create(void) { SOCmnListConfig cfg; cfg.m_type = (SOCMNLIST_TYPE_ORG_LIST | SOCMNLIST_TYPE_KEY_NO | SOCMNLIST_TYPE_OBJ_STRING); cfg.m_entriesPerBlock = 10; cfg.m_hashTableSize = 17; return m_list.create(&cfg); }
	BOOL create(IN WORD type) { SOCmnListConfig cfg; cfg.m_type = type; cfg.m_entriesPerBlock = 10; cfg.m_hashTableSize = 17; return m_list.create(&cfg); }
	BOOL create(IN SOCmnListConfig *creationConfig) { return m_list.create(creationConfig); }

	// assign list
	SOCmnStringList& operator=(IN SOCmnStringList* list) { if (list) { m_list = list->m_list; } return *this; }
	SOCmnStringList& operator=(IN const SOCmnStringList& list) { m_list = list.m_list; return *this; }
	void attach(IN SOCmnStringList* list) { if (list) { m_list = list->m_list; } }
	void detach(void) { m_list.detach(); }

	// check if list is initialized
	bool operator!() { return !m_list.isInit(); } 
	BOOL isInit(void) const { return m_list.isInit(); }
	operator SOCmnListPosition(void) { return m_list.getStartPosition(); } 

	// clone existing list
	BOOL clone(IN SOCmnStringList &list) { return m_list.clone(list.m_list); }
	BOOL clone(IN SOCmnStringList *list) { if (list) return m_list.clone(list->m_list); else return FALSE; }

	// free list
	void destroy(void) { m_list.destroy(); }	

	// remove all list and map entries
	void clear(void) { m_list.removeAll(); }
	void removeAll(void) { m_list.removeAll(); }

	// get start position
	SOCmnListPosition getStartPosition(void) { return m_list.getStartPosition(); }

	// get entry count
	DWORD getCount(void) { return m_list.getCount(); }

	// check if list is empty
	BOOL isEmpty(void) { return m_list.isEmpty(); }

	//-- get --

	// get current object (additional get key on next entry too) and get next position
	SOCmnString getNext(IN OUT SOCmnListPosition& pos) const { SOCmnString str; str = ((SOCmnString *) m_list.getNext(pos, NULL, NULL)); return str; }
	SOCmnString getNext(IN OUT SOCmnListPosition& pos, OUT DWORD *key) const { SOCmnString str; str = ((SOCmnString *) m_list.getNext(pos, SOCMNLIST_TYPE_KEY_DWORD, (void **)key)); return str; }
	SOCmnString getNext(IN OUT SOCmnListPosition& pos, OUT SOCmnString *key) const { SOCmnString str; str = ((SOCmnString *) m_list.getNext(pos, SOCMNLIST_TYPE_KEY_STRING, (void **)key)); return str; }

	// get head object 
	SOCmnString getHead(void) { SOCmnString str; str = (SOCmnString *)m_list.getHead(); return str; }

	// get the object at specific index (zero based)
	SOCmnString getIndex(IN DWORD idx) { SOCmnString str; str = (SOCmnString *)m_list.getIndex(idx, SOCMNLIST_TYPE_KEY_NO, NULL); return str; }

	// get object from the head of the list
	SOCmnString pop(void) { SOCmnString str; str = (SOCmnString *)m_list.getHead(); m_list.removeHead(); return str; }

	//-- add --

	// add object (with key)
	BOOL add(IN SOCmnString obj) { return (m_list.add((void *)&obj, 0, SOCMNLIST_TYPE_KEY_NO) != NULL); }
	BOOL add(IN LPCTSTR sz) { SOCmnString str(sz); return (m_list.add((void *)&str, 0,  SOCMNLIST_TYPE_KEY_NO) != NULL); }
	BOOL add(IN SOCmnString obj, IN DWORD key) { return (m_list.add((void *)&obj, (void *)key, SOCMNLIST_TYPE_KEY_DWORD) != NULL); }
	BOOL add(IN SOCmnString obj, IN LPCTSTR key) { return (m_list.add((void *)&obj, (void *)key, SOCMNLIST_TYPE_KEY_STRING) != NULL); }

	// add object a the head of the list
	BOOL push(IN SOCmnString obj) { return (m_list.push((void *)&obj) != NULL); }
	BOOL push(IN LPCTSTR sz) { SOCmnString str(sz); return (m_list.push((void *)&str) != NULL); }

	//-- update -- 	

	// update object
	BOOL update(IN SOCmnString obj, IN DWORD key) { return (m_list.update((void *)&obj, (void *)key, SOCMNLIST_TYPE_KEY_DWORD) != NULL); }
	BOOL update(IN SOCmnString obj, IN LPCTSTR key) { return (m_list.update((void *)&obj, (void *)key, SOCMNLIST_TYPE_KEY_STRING) != NULL); }

	//-- find --

	// find object by key
	SOCmnString findKey(IN LPCTSTR key) { SOCmnString *str; str = (SOCmnString *)((SOCmnString *)m_list.findKey((void *)key, SOCMNLIST_TYPE_KEY_STRING, NULL)); return *str; }
	SOCmnString findKey(IN DWORD key) { SOCmnString *str; str = (SOCmnString *)((SOCmnString *)m_list.findKey((void *)key, SOCMNLIST_TYPE_KEY_DWORD, NULL)); return *str; }
	BOOL findKey(IN DWORD key, OUT SOCmnString* obj) { SOCmnString *str; str = (SOCmnString *)((SOCmnString *)m_list.findKey((void *)key, SOCMNLIST_TYPE_KEY_DWORD, NULL)); if (obj) *obj = str; return (NULL != str); }
	BOOL findKey(IN LPCTSTR key, OUT SOCmnString* obj) { SOCmnString *str; str = (SOCmnString *)((SOCmnString *)m_list.findKey((void *)key, SOCMNLIST_TYPE_KEY_STRING, NULL)); if (obj) *obj = str; return (NULL != str); }

	// find position of object (check if object is in list)
	SOCmnListPosition findObject(IN SOCmnString obj) { return m_list.findObject((void *)&obj); }

	//-- remove --

	BOOL removeObject(IN SOCmnString obj) { return m_list.removeObject((void *)&obj); }

	// remove list entry by key
	BOOL removeKey(IN LPCTSTR key) { return m_list.removeKey((void *)key, SOCMNLIST_TYPE_KEY_STRING); }
	BOOL removeKey(IN DWORD key) { return m_list.removeKey((void *)key, SOCMNLIST_TYPE_KEY_DWORD); }

	// remove list entry by position
	BOOL removeAt(IN SOCmnListPosition pos) { return m_list.removeAt(pos); }
	BOOL removeHead(void) { return m_list.removeHead(); }

	//-- sync --

	// lock list and map
	void lock(void) { m_list.lock(); }

	// unlock list and map
	void unlock(void) { m_list.unlock(); }

	// prevent locking
	void autoLock(void) { m_list.autoLock(); }
	void dontAutoLock(void) { m_list.doAutoLock(FALSE); }
	void autoUnlock(void) { m_list.autoUnlock(); }

	// get lock object
	SOCmnSync *getSyncObject(void) { return m_list.getSyncObject(); }

	BOOL isDirty(void) { return m_list.isDirty(); }
	BOOL setDirty(OPTIONAL IN BOOL dirty = FALSE) { return m_list.setDirty(dirty); }

	//-- block --

	// set the default number of entries allocated in a block
	BOOL setDefaultEntriesPerBlock(IN BYTE number) { return m_list.setDefaultBlockElements(number); }

	// allocate a block
	BOOL allocateBlock(IN DWORD number) { return m_list.createBlock(number); }

	BOOL isMap(void) const { return m_list.isMap(); }
	BOOL isList(void) const { return m_list.isList(); }

	// compatibiliy to previous versions
	// DO NOT USE THIS METHODS !
	SOCmnListPosition AddTail(IN LPCTSTR sz) { SOCmnString str(sz); return m_list.add((void *)&str, 0,  SOCMNLIST_TYPE_KEY_NO); }
	SOCmnListPosition Find(IN SOCmnString obj) {  return m_list.findObject((void *)&obj); }
	DWORD GetCount(void) { return m_list.getCount(); }
	SOCmnListPosition GetHeadPosition(void) { return m_list.getStartPosition(); }
	SOCmnString GetNext(IN OUT SOCmnListPosition& pos) const { SOCmnString str; str = ((SOCmnString *) m_list.getNext(pos, NULL, NULL)); return str; }
	BOOL IsEmpty(void) { return m_list.isEmpty(); }
	void RemoveAll(void) { m_list.removeAll(); }
	BOOL RemoveAt(IN SOCmnListPosition pos) { return m_list.removeAt(pos); }
	BOOL RemoveHead(void) { return m_list.removeHead(); }

protected:
	SOCmnListHeader m_list;
}; // SOCmnStringList


//-----------------------------------------------------------------------------
// SOCmnDWORDList                                                             |
//-----------------------------------------------------------------------------

class SOCMN_EXPORT SOCmnDWORDList 
{
public:
	// constructors
	SOCmnDWORDList(void) {}
	SOCmnDWORDList(IN const SOCmnDWORDList& list) { m_list = list.m_list; }
	SOCmnDWORDList(IN SOCmnDWORDList *list) { if (list) m_list = list->m_list; }

	// destructor
	~SOCmnDWORDList(void) {} 

	// assign list
	SOCmnDWORDList& operator=(IN SOCmnDWORDList* list) { if (list) { m_list = list->m_list; } return *this; }
	SOCmnDWORDList& operator=(IN const SOCmnDWORDList& list) { m_list = list.m_list; return *this; }
	void attach(IN SOCmnDWORDList* list) { if (list) { m_list = list->m_list; } }
	void detach(void) { m_list.detach(); }

	// check if list is initialized
	bool operator!() { return !m_list.isInit(); } 
	BOOL isInit(void) const { return m_list.isInit(); }
	operator SOCmnListPosition(void) { return m_list.getStartPosition(); } 

	// create list
	BOOL create(void) { SOCmnListConfig cfg; cfg.m_type = (SOCMNLIST_TYPE_ORG_LIST | SOCMNLIST_TYPE_KEY_NO | SOCMNLIST_TYPE_OBJ_DWORD); cfg.m_entriesPerBlock = 10; cfg.m_hashTableSize = 17; return m_list.create(&cfg); }
	BOOL create(IN WORD type) { SOCmnListConfig cfg; cfg.m_type = type; cfg.m_entriesPerBlock = 10; cfg.m_hashTableSize = 17; return m_list.create(&cfg); }
	BOOL create(IN SOCmnListConfig *creationConfig) { return m_list.create(creationConfig); }

	// clone existing list
	BOOL clone(IN SOCmnDWORDList &list) { return m_list.clone(list.m_list); }
	BOOL clone(IN SOCmnDWORDList *list) { if (list) return m_list.clone(list->m_list); else return FALSE; }

	// free list
	void destroy(void) { m_list.destroy(); }	

	// remove all list and map entries
	void clear(void) { m_list.removeAll(); }
	void removeAll(void) { m_list.removeAll(); }

	// get start position
	SOCmnListPosition getStartPosition(void) { return m_list.getStartPosition(); }

	// get entry count
	DWORD getCount(void) { return m_list.getCount(); }

	// check if list is empty
	BOOL isEmpty(void) { return m_list.isEmpty(); }

	//-- get --

	// get current object (additional get key on next entry too) and get next position
	DWORD getNext(IN OUT SOCmnListPosition& pos) const { return ((DWORD) m_list.getNext(pos, SOCMNLIST_TYPE_KEY_NO, NULL)); }
	DWORD getNext(IN OUT SOCmnListPosition& pos, OUT DWORD *key) const { return ((DWORD) m_list.getNext(pos, SOCMNLIST_TYPE_KEY_DWORD, (void **)key)); }
	DWORD getNext(IN OUT SOCmnListPosition& pos, OUT SOCmnString *key) const { return ((DWORD) m_list.getNext(pos, SOCMNLIST_TYPE_KEY_STRING, (void **)key)); }

	// get head object 
	DWORD getHead(void) { return (DWORD)m_list.getHead(); }

	// get the object at specific index (zero based)
	DWORD getIndex(IN DWORD idx) { return (DWORD)m_list.getIndex(idx, SOCMNLIST_TYPE_KEY_NO, NULL); }

	// get object from the head of the list
	DWORD pop(void) { return (DWORD)m_list.pop(); }

	//-- add --

	// add object (with key)
	BOOL add(IN DWORD dw) { return (m_list.add((void *)dw, NULL, SOCMNLIST_TYPE_KEY_NO) != NULL); }
	BOOL add(IN DWORD dw, IN DWORD key) { return (m_list.add((void *)dw, (void *)key, SOCMNLIST_TYPE_KEY_DWORD) != NULL); }
	BOOL add(IN DWORD dw, IN LPCTSTR key) { return (m_list.add((void *)dw, (void *)key, SOCMNLIST_TYPE_KEY_STRING) != NULL); }

	// add object a the head of the list
	BOOL push(IN DWORD dw) { return (m_list.push((void *)dw) != NULL); }

	//-- update -- 	

	// update object
	BOOL update(IN DWORD dw, IN DWORD key) { return (m_list.update((void *)dw, (void *)key, SOCMNLIST_TYPE_KEY_DWORD) != NULL); }
	BOOL update(IN DWORD dw, IN LPCTSTR key) { return (m_list.update((void *)dw, (void *)key, SOCMNLIST_TYPE_KEY_STRING) != NULL); }

	//-- find --

	// find object by key
	DWORD findKey(IN LPCTSTR key) { return ((DWORD)m_list.findKey((void *)key, SOCMNLIST_TYPE_KEY_STRING, NULL)); }
	DWORD findKey(IN DWORD key) { return ((DWORD)m_list.findKey((void *)key, SOCMNLIST_TYPE_KEY_DWORD, NULL)); }
	BOOL findKey(IN DWORD key, OUT DWORD* obj) { DWORD foundObj = NULL; BOOL found; foundObj = (DWORD)m_list.findKey((void *)key, SOCMNLIST_TYPE_KEY_DWORD, &found); if (obj) *obj = foundObj; return found; }
	BOOL findKey(IN LPCTSTR key, OUT DWORD* obj) { DWORD foundObj = NULL; BOOL found; foundObj = (DWORD)m_list.findKey((void *)key, SOCMNLIST_TYPE_KEY_STRING, &found); if (obj) *obj = foundObj; return found; }

	// find position of object (check if object is in list)
	SOCmnListPosition findObject(IN DWORD obj) { SOCmnListPosition pos; pos = m_list.findObject((void *)obj); return pos; }

	//-- remove --

	// remove list entry by object
	BOOL removeObject(IN DWORD obj) { return m_list.removeObject((void *)obj); }

	// remove list entry by key
	BOOL removeKey(IN LPCTSTR key) { return m_list.removeKey((void *)key, SOCMNLIST_TYPE_KEY_STRING); }
	BOOL removeKey(IN DWORD key) { return m_list.removeKey((void *)key, SOCMNLIST_TYPE_KEY_DWORD); }

	// remove list entry by position
	BOOL removeAt(IN SOCmnListPosition pos) { return m_list.removeAt(pos); }
	BOOL removeHead(void) { return m_list.removeHead(); }

	//-- sync --

	// lock list and map
	void lock(void) { m_list.lock(); }

	// unlock list and map
	void unlock(void) { m_list.unlock(); }

	// prevent locking
	void autoLock(void) { m_list.autoLock(); }
	void dontAutoLock(void) { m_list.doAutoLock(FALSE); }
	void autoUnlock(void) { m_list.autoUnlock(); }

	// get lock object
	SOCmnSync *getSyncObject(void) { return m_list.getSyncObject(); }

	//-- dirty --

	BOOL isDirty(void) { return m_list.isDirty(); }
	BOOL setDirty(OPTIONAL IN BOOL dirty = FALSE) { return m_list.setDirty(dirty); }

	//-- block --

	// set the default number of entries allocated in a block
	BOOL setDefaultEntriesPerBlock(IN BYTE number) { return m_list.setDefaultBlockElements(number); }

	// allocate a block
	BOOL allocateBlock(IN DWORD number) { return m_list.createBlock(number); }

	BOOL isMap(void) const { return m_list.isMap(); }
	BOOL isList(void) const { return m_list.isList(); }

	// compatibiliy to previous versions
	// DO NOT USE THIS METHODS !
	SOCmnListPosition AddTail(IN DWORD obj) { return m_list.add((void *) obj, 0, SOCMNLIST_TYPE_KEY_NO); }
	SOCmnListPosition Find(IN DWORD obj) { return m_list.findObject((void *)obj); }
	DWORD GetCount(void) { return m_list.getCount(); }
	SOCmnListPosition GetHeadPosition(void) { return m_list.getStartPosition(); }
	DWORD GetNext(IN OUT SOCmnListPosition& pos) const { return ((DWORD) m_list.getNext(pos, SOCMNLIST_TYPE_KEY_NO, NULL)); }
	BOOL IsEmpty(void) { return m_list.isEmpty(); }
	void RemoveAll(void) { m_list.removeAll(); }
	BOOL RemoveAt(IN SOCmnListPosition pos) { return m_list.removeAt(pos); }
	BOOL RemoveHead(void) { return m_list.removeHead(); }

protected:
	SOCmnListHeader m_list;
}; // SOCmnDWORDList

#pragma pack(pop)
#endif
