// created from IAR device io file with regex search and replace
// `#define ([A-Z0-9]+)\s+\(\*\(([A-Z0-9]+_t) \*\)\s+0x[A-F0-9]+\)`
// to `struct $1_tag { static $2& value() { return $1; } }; `
#ifndef UT_HAL_TMP_HEADER
#define UT_HAL_TMP_HEADER

#define CREATE_MEMBER_DETECTOR(X)                                                   \
template<typename T> class Detect_##X {                                             \
    struct Fallback { int X; };                                                     \
    struct Derived : T, Fallback { };                                               \
                                                                                    \
    template<typename U, U> struct Check;                                           \
                                                                                    \
    typedef char ArrayOfOne[1];                                                     \
    typedef char ArrayOfTwo[2];                                                     \
                                                                                    \
    template<typename U> static ArrayOfOne & func(Check<int Fallback::*, &U::X> *); \
    template<typename U> static ArrayOfTwo & func(...);                             \
  public:                                                                           \
    typedef Detect_##X type;                                                        \
    enum { value = sizeof(func<Derived>(0)) == 2 };                                 \
};


#endif  // UT_HAL_TMP_HEADER