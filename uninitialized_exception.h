#ifndef UNINITIALIZEDEXCEPTION_H
#define UNINITIALIZEDEXCEPTION_H

#include "exception.h"

//! Uninitialized exception
/*! The exception is thrown then the class was not initialized before use */
class UninitializedException : public Exception {

 public:
   //! Constuctor of the UninitializedException
   /*!
     \param className - name of the class which throws the exception
     \param parameter - parameter which was not initialized in the class
  */
   UninitializedException( const char * className, const char *parameter = NULL) ;

   const std::string & className() const {
      return mClassName;
   }

  private:
    std::string mClassName;
};

#endif // UNINITIALIZEDEXCEPTION_H
