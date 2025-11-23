#ifdef PRINT_DEBUG
#define BUGPRINT(x)                                                            \
  do {                                                                         \
    std::cerr << __FILE__ << ":" << __LINE__ << ": ";                          \
    std::cerr << #x << " -> " << (x) << std::endl;                             \
  } while (0) // Trick to force a semicolon after calling BUGPRINT.
#else
#define BUGPRINT(x)
#endif

// See: https://gcc.gnu.org/onlinedocs/cpp/Stringizing.html
#define STRING(x) STRING2(x)
#define STRING2(x) #x

#define TWO_X(x) x * 2 // Wrong: missing parentheses.
