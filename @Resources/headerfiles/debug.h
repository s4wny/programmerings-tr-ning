//Useful debug functions
#define DEBUG true
#ifdef DEBUG
    #include <cstdio>
    #include "prettyprint.hpp"

    #define nl cout << endl;
    #define debug(x) cout << #x << " = " << x << endl;
    #define wbstdin freopen("input.txt", "r", stdin);
#else
    #define EMPTYSTMT do { } while(0)
    #define nl EMPTYSTMT
    #define debug(x) EMPTYSTMT
    #define wbstdin EMPTYSTMT
#endif // DEBUG
