#ifndef CUB_MEMORY_SHARED_OBJECT_H
#define CUB_MEMORY_SHARED_OBJECT_H

#include "cub/cub.h"

CUB_NS_BEGIN

struct SharedObject
{
    SharedObject();
    virtual ~SharedObject();
    
    void addRef();
    void subRef();
    void setOnlyFree();
    virtual void destroy(){};
    virtual bool needDestroy(){return false;};

    unsigned int getRefCount() const;

    bool onlyThisRef() const;

private:
    unsigned int count;
};

CUB_NS_END

#endif
