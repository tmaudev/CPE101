#ifndef NCHECKIT
#include <string.h>
#include <stdio.h>
#define checkit_int(X,Y)\
   {\
      int _x = X, _y = Y;\
      if (_x == _y)\
      {\
         printf("Test passed on line %d.\n", __LINE__);\
      }\
      else\
      {\
         printf("Test FAILED on line %d.  %s is %d, expected %d.\n",\
            __LINE__, #X, _x, _y);\
      }\
   }
#define checkit_double(X,Y)\
   {\
      double _x = X, _y = Y;\
      double _epsilon = 0.0001;\
      if ((_x <= _y + _epsilon) && (_x >= _y - _epsilon))\
      {\
         printf("Test passed on line %d.\n", __LINE__);\
      }\
      else\
      {\
         printf("Test FAILED on line %d.  %s is %f, expected %f.\n",\
            __LINE__, #X, _x, _y);\
      }\
   }
#define checkit_char(X,Y)\
   {\
      char _x = X, _y = Y;\
      if (_x == _y)\
      {\
         printf("Test passed on line %d.\n", __LINE__);\
      }\
      else\
      {\
         printf("Test FAILED on line %d.  %s is '%c', expected '%c'.\n",\
            __LINE__, #X, _x, _y);\
      }\
   }
#define checkit_string(X,Y)\
   {\
      char *_x = X, *_y = Y;\
      if (!strcmp(_x,_y))\
      {\
         printf("Test passed on line %d.\n", __LINE__);\
      }\
      else\
      {\
         printf("Test FAILED on line %d.  %s is \"%s\", expected \"%s\".\n",\
            __LINE__, #X, _x, _y);\
      }\
   }
#else
#define checkit_int(X,Y)
#define checkit_double(X,Y)
#define checkit_char(X,Y)
#define checkit_string(X,Y)
#endif
