#ifndef COMMON_H
#define COMMON_H

#define DeleteObject(object) if((object) != NULL) {delete object; object = NULL;}
#define DeleteObjects(objects) if((objects) != NULL) {delete[] objects; objects = NULL;}
#define ReleaseObject(object) if((object) != NULL) {object->Release(); object = NULL;}

#endif