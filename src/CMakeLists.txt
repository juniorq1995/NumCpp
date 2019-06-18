#include_directories()

set(NUMCPP_SRCS
   NumCpp.hpp NumCpp.cpp
)

SET (LIB_TYPE STATIC)

add_library (NumCpp ${LIB_TYPE} ${NUMCPP_SRCS})