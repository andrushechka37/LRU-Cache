#define DEBUG
#ifdef DEBUG
#define PRINT_DEBUG(func) func
#else
#define PRINT_DEBUG(func) ;
#endif