/* voc 2.1.0 [2023/10/25] for clang LP64 on darwin xtspa */

#ifndef HashMap__h
#define HashMap__h

#include "SYSTEM.h"

typedef
	struct HashMap_HashTableDesc *HashMap_HashTable;

typedef
	struct HashMap_NObjectDesc *HashMap_NObject;

typedef
	struct {
		ADDRESS len[1];
		HashMap_NObject data[1];
	} *HashMap_hcontainer;

typedef
	struct HashMap_VObjectDesc *HashMap_VObject;

typedef
	struct HashMap_KObjectDesc *HashMap_KObject;

typedef
	struct HashMap_kObjectArrayDesc *HashMap_kObjectArray;

typedef
	struct HashMap_vObjectArrayDesc *HashMap_vObjectArray;

typedef
	struct HashMap_HashTableDesc {
		HashMap_hcontainer container;
		HashMap_HashTable (*Create)(INT16);
		INT16 (*NumberOfElements)(HashMap_HashTable);
		BOOLEAN (*IsEmpty)(HashMap_HashTable);
		char _prvt0[48];
		HashMap_VObject (*Get)(HashMap_HashTable, HashMap_KObject);
		void (*AddOrReplace)(HashMap_HashTable, HashMap_KObject, HashMap_VObject);
		HashMap_VObject (*Remove)(HashMap_HashTable, HashMap_KObject);
		HashMap_kObjectArray (*Keys)(HashMap_HashTable);
		HashMap_vObjectArray (*Values)(HashMap_HashTable);
		char _prvt1[12];
	} HashMap_HashTableDesc;

typedef
	struct HashMap_NObjectDesc {
		char _prvt0[1];
	} HashMap_NObjectDesc;

typedef
	struct HashMap_KObjectDesc { /* HashMap_NObjectDesc */
		char _prvt0[1];
	} HashMap_KObjectDesc;

typedef
	struct HashMap_MapEntryDesc *HashMap_MapEntry;

typedef
	struct HashMap_MapEntryDesc { /* HashMap_NObjectDesc */
		HashMap_KObject key;
		HashMap_VObject value;
	} HashMap_MapEntryDesc;

typedef
	struct HashMap_NodeDesc *HashMap_Node;

typedef
	struct HashMap_NodeDesc { /* HashMap_NObjectDesc */
		char _prvt0[8];
		HashMap_MapEntry entry;
		HashMap_Node next;
	} HashMap_NodeDesc;

typedef
	struct HashMap_VObjectDesc { /* HashMap_NObjectDesc */
		char _prvt0[1];
	} HashMap_VObjectDesc;

typedef
	struct HashMap_kObjectArrayDesc {
		INT64 _prvt0;
		INT16 capacity;
		struct {
			ADDRESS len[1];
			HashMap_KObject data[1];
		} *container;
	} HashMap_kObjectArrayDesc;

typedef
	struct HashMap_vObjectArrayDesc {
		INT64 _prvt0;
		INT16 capacity;
		struct {
			ADDRESS len[1];
			HashMap_VObject data[1];
		} *container;
	} HashMap_vObjectArrayDesc;



import ADDRESS *HashMap_NObjectDesc__typ;
import ADDRESS *HashMap_KObjectDesc__typ;
import ADDRESS *HashMap_VObjectDesc__typ;
import ADDRESS *HashMap_MapEntryDesc__typ;
import ADDRESS *HashMap_NodeDesc__typ;
import ADDRESS *HashMap_kObjectArrayDesc__typ;
import ADDRESS *HashMap_vObjectArrayDesc__typ;
import ADDRESS *HashMap_HashTableDesc__typ;

import HashMap_HashTable HashMap_Create (INT16 size);
import INT16 HashMap_HashFunction (HashMap_KObject key, INT16 range);
import BOOLEAN HashMap_IsEmpty (HashMap_HashTable h);
import HashMap_kObjectArray HashMap_Keys (HashMap_HashTable h);
import INT16 HashMap_NumberOfElements (HashMap_HashTable h);
import HashMap_vObjectArray HashMap_Values (HashMap_HashTable h);
import void *HashMap__init(void);


#endif // HashMap
