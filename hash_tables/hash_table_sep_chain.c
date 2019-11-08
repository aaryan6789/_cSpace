#include <stdio.h>
#include <stdlib.h>

/**
Design a HashMap without using any built-in hash table libraries.
To be specific, your design should include these functions:

put(key, value) :
Insert a (key, value) pair into the HashMap.
If the value already exists in the HashMap, update the value.

get(key):
Returns the value to which the specified key is mapped, or -1
if this map contains no mapping for the key.

remove(key) :
Remove the mapping for the value key if this map contains
the mapping for the key.

Example:
MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);
hashMap.put(2, 2);
hashMap.get(1);            	// returns 1
hashMap.get(3);            	// returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            	// returns 1
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            	// returns -1 (not found)

Note:

All keys and values will be in the range of [0, 1000000].
The number of operations will be in the range of [1, 10000].
Please do not use the built-in HashMap library.
*/


#define KEY_MOD 10000
typedef struct ht_node ht_node;
struct ht_node{
    int key;
    int val;
    ht_node* next;
};

typedef struct {
    ht_node** hashTable;
} MyHashMap;

/** Initialize your data structure here. */
MyHashMap* myHashMapCreate();

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value);

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key);

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key);

void myHashMapFree(MyHashMap* obj);



/** Initialize your data structure here. */
MyHashMap* myHashMapCreate() {
    MyHashMap* obj = malloc(sizeof(MyHashMap));
    obj->hashTable = calloc(10000, sizeof(ht_node*));

    for(int i = 0; i < 10000; i++){
        obj->hashTable[i] = calloc(1, sizeof(ht_node));
        obj->hashTable[i]->key = -1;
    }
    return obj;
}

/** value will always be non-negative. */
void myHashMapPut(MyHashMap* obj, int key, int value) {
    ht_node* newNode = malloc(sizeof(ht_node));
    newNode -> key = -1;
    newNode -> next = NULL;

	// If no key value pair exist
    if(obj->hashTable[key%KEY_MOD]->key == -1){
        obj->hashTable[key%KEY_MOD]->key = key;
        obj->hashTable[key%KEY_MOD]->val = value;
        obj->hashTable[key%KEY_MOD]->next = newNode;
    }
	else { //Resolve conflict

		// Get the 1st node of the Linket list for that hash (key%KEY_MOD)
		ht_node* temp = obj->hashTable[key%KEY_MOD];

        while(temp->next){
            if(temp->key == key){
                temp->val = value;		// Update the value
                return;
            }
			// Else move forward
            temp = temp->next;
        }

		// If reach here that means the key doesnt exist, so Update the value
        temp->key = key;
        temp->val = value;
        temp->next = newNode;
    }

    return;

}

/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
int myHashMapGet(MyHashMap* obj, int key) {
	ht_node* temp = obj->hashTable[key%KEY_MOD];

	while(temp){
        if(temp->key == key){
            return temp -> val;
        }
        else{
            temp = temp -> next;
        }
    }

	return -1;
}

/** Removes the mapping of the specified value key if this map contains a mapping for the key */
void myHashMapRemove(MyHashMap* obj, int key) {
    ht_node* temp = obj -> hashTable[key%KEY_MOD];
    ht_node* pre;

	if(temp -> key == key){
        obj -> hashTable[key%KEY_MOD] = temp -> next;
        return;
    }

    while(temp){
        if(temp -> key == key){
            pre -> next = temp -> next;
            free(temp);
            return;
        }
        else{
            pre = temp;
            temp = temp -> next;
        }
    }
}

void myHashMapFree(MyHashMap* obj) {
    for(int i = 0; i < 10000; i++)
    {
        free(obj -> hashTable[i]);
    }
    free(obj->hashTable);
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);

 * int param_2 = myHashMapGet(obj, key);

 * myHashMapRemove(obj, key);

 * myHashMapFree(obj);
*/