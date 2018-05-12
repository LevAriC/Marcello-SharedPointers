//
//  smart_ptr.hpp
//  collage mannage
//
//  Created by bar azouri on 26/04/2018.
//  Copyright © 2018 bar azouri. All rights reserved.
//

#ifndef smart_ptr_hpp
#define smart_ptr_hpp

#include <stdio.h>


namespace idllib {

    template <class T> class SmartPtr;
    template <class T> class IRefCount {
        friend class SmartPtr<T>;
    protected:
        virtual void __IncRefCount() = 0;
        virtual void __DecRefCount() = 0;
        virtual T * GetPtr() const = 0;
    };

    template <class T> class IRefCountImpl : public IRefCount<T> {
    private:
        int __m_counter;
    protected:
        virtual void __IncRefCount()
        {
            __m_counter++;
        }
        virtual void __DecRefCount()
        {
            __m_counter--;
            if(__m_counter<=0)
            {
                __DestroyRef();
            }
        }
        virtual T * GetPtr() const
        {
            return ((T *)this);
        }
        virtual void __DestroyRef()
        {
            if(GetPtr()!=NULL)
                delete GetPtr();
        }
    protected:
        IRefCountImpl()
        {
            __m_counter = 0;
        }
    };

    template <class T> class SmartPtr {
    private:
        IRefCount<T> *__m_refcount;
        class __RefCounter : public IRefCountImpl<T>{
        private:
            T *__m_ptr;
        protected:
            virtual T * GetPtr() const
            {
                return __m_ptr;
            }
            virtual void __DestroyRef() {delete this;}
        public:
            __RefCounter(T *ptr)
            {
                __m_ptr = ptr;
            }
            virtual ~__RefCounter()
            {
                IRefCountImpl<T>::__DestroyRef();
            }
        };

        void __Assign(void *ptr)
        {
            if(ptr==NULL)
                __Assign((IRefCount<T> *)NULL);
            else
            {
                __Assign(new __RefCounter(static_cast<T *>(ptr)));
            }
        }
        // this method is picked over __Assign(void *ptr)
        // if T implements IRefCount.
        // This allows some memory usage optimization
        void __Assign(IRefCount<T> *refcount)
        {
            if(refcount!=NULL) refcount->__IncRefCount();
            IRefCount<T> *oldref = __m_refcount;
            __m_refcount = refcount;
            if(oldref!=NULL) oldref->__DecRefCount();
        }
    public:
        SmartPtr()
        {
            __m_refcount = NULL;
        }
        SmartPtr(T * ptr)
        {
            __m_refcount = NULL;
            __Assign(ptr);
        }
        SmartPtr(const SmartPtr &sp)
        {
            __m_refcount = NULL;
            __Assign(sp.__m_refcount);
        }
        virtual ~SmartPtr()
        {
            __Assign((IRefCount<T> *)NULL);
        }

        // get the contained pointer, not really needed but...
        T *GetPtr() const
        {
            if(__m_refcount==NULL) return NULL;
            return __m_refcount->GetPtr();
        }

        // assign another smart pointer
        SmartPtr & operator = (const SmartPtr &sp) {__Assign(sp.__m_refcount); return *this;}
        // assign pointer or NULL
        SmartPtr & operator = (T * ptr) {__Assign(ptr); return *this;}
        // to access members of T
        T * operator ->()
        {
#ifdef _ASSERT
            _ASSERT(GetPtr()!=NULL);
#endif
            return GetPtr();
        }
        // conversion to T* (for function calls)
        operator T* () const
        {
            return GetPtr();
        }

        // utilities
        bool operator !()
        {
            return GetPtr()==NULL;
        }
        bool operator ==(const SmartPtr &sp)
        {
            return GetPtr()==sp.GetPtr();
        }
        bool operator !=(const SmartPtr &sp)
        {
            return GetPtr()!=sp.GetPtr();
        }
    };
};
#endif /* smart_ptr_hpp */
