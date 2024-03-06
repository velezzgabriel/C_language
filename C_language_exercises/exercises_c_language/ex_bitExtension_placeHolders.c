/*

Placeholder	Size (bytes)	Range of Values
%d,%i	    4           0x80000000 to 0x7FFFFFFF
%u	        4	        0x00000000 to 0xFFFFFFFF
%f	        4	        Approximately ±3.4 x 10^-38 to ±3.4 x 10^38
%e, %g	    4	        Varies with float precision
%x, %X	    4	        0 to FFFFFFFF (8 hexadecimal digits)
%o	        4	        0x0 to 0xFFFFFFFF
%c	        1	        Typically represents ASCII characters
%s	        Variable	Represents a sequence of characters
%p	        8	        Represents memory addresses
%ld	        8	        -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
%lu	        8	        0 to 18,446,744,073,709,551,615
%lld	    8	        Approximately -9.2 x 10^18 to 9.2 x 10^18
%llu	    8	        0 to 18,446,744,073,709,551,615
%hx	        2	        0 to FFFF (4 hexadecimal digits)
%ho	        2	        0 to 17777 (6 octal digits)
%hd	        2	        -32,768 to 32,767
%hu	        2	        0 to 65,535
%%	        1	        Represents the literal '%' character



PlaceH	    Data Type	        Bytes	Range of Values (Hexadecimal)
%c	        char	            1	    0x00 to 0xFF
%d, %i	    int	                4	    0x80000000 to 0x7FFFFFFF
%u	        unsigned int	    4	    0x00000000 to 0xFFFFFFFF
%f	        float	            Varies	Varies
%e, %g	    float	            Varies	Varies
%x, %X	    unsigned int        4	    0x0 to 0xFFFFFFFF
%o	        unsigned int	    4	    0x0 to 0xFFFFFFFF
%ld	        long	            8	    0x8000000000000000 to 0x7FFFFFFFFFFFFFFF
%lu	        unsigned long	    8	    0x0000000000000000 to 0xFFFFFFFFFFFFFFFF
%lld	    long long	        8	    Varies
%llu	    unsigned long long	8	    0x0000000000000000 to 0xFFFFFFFFFFFFFFFF
%hx	        short	            2   	0x0 to 0xFFFF
%ho	        unsigned short	    2	    0x0 to 0xFFFF
%hd	        short	            2	    0x8000 to 0x7FFF
%hu	        unsigned short	    2	    0x0 to 0xFFFF

*/

