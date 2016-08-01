#include "uninitialized_exception.h"

#include <sstream>

UninitializedException::UninitializedException( const char * className, const char *parameter )
         : Exception(0, "Unknown exception")
         , mClassName(className)  {
   std::stringstream errorMsg;
   if(parameter)
      errorMsg << "Parameter "<< parameter << " in class "<<className<<" was used before beeing initialized";
   else
      errorMsg << "Class "<< className << " was used before beeing initialized";
   SetErrorMessage(errorMsg.str());
}
