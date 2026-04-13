#include <math.h>
enum coordinate_type { RECTANGULAR = 1, POLAR };

struct complex_struct {
	enum coordinate_type t;
	double a, b;
};

double real_part(struct complex_struct z) {
    if (z.t == POLAR)
	    return z.a * cos(z.b);
    else
        return z.a;
}

double img_part(struct complex_struct z) {
    if (z.t == POLAR)
	    return z.a * sin(z.b);
    else 
        return z.b;
}

double magnitude(struct complex_struct z) {
    if (z.t == POLAR)
	    return z.a;
    else
        return sqrt(z.a * z.a + z.b * z.b);
}

double angle(struct complex_struct z) {
    if (z.t == POLAR)
	    return z.b;
    else 
        return atan2(z.b, z.a);
}