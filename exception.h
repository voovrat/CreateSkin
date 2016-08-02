#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

//! Base exception class
class Exception {
public:
   //! constructor
   Exception( int errcode, const char *name) {
       mErrcode=errcode;
       mErrtype = name;
   };

   //! errorcode
   int errcode() const {
       return mErrcode;
   }

   //! error type (name)
   const char *errtype() const {
       return mErrtype;
   }


   //! exception message
   operator const std::string & () const {
     return message;
   }

   //! message in c-string format
   operator const char * () const {
     return message.c_str();
   }

protected:

  //! set error message
  void SetErrorMessage( const std::string & msg ) {
    message = msg;
  }

  //! the same in c-string
  void SetErrorMessage(const char *msg) {
    message = msg;
  }

  int mErrcode;
  const char *mErrtype;

  std::string message;
};

#endif // EXCEPTION_H
