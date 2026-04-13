#include <stdio.h>
#include <stdlib.h>

int gcd_recursive(int a, int b) {
    a = abs(a);
    b = abs(b);
    
    if (b == 0) return a;
    return gcd_recursive(b, a % b);
}

struct rational {
    int mo, de;
};

int get_mo(struct rational r) {
    return r.mo;
}

int get_de(struct rational r) {
    return r.de;
}

struct rational make_rational(int a, int b) {
    int gcd = gcd_recursive(a, b);
    struct rational r = {a/gcd, b/gcd};
    return r;
}

struct rational add_rational(struct rational a, struct rational b) {
    int de1 = get_de(a), de2 = get_de(b);
    int mo1 = get_mo(a)*de2, mo2 = get_mo(b)*de1;

    int new_de = de1 * de2;
    int new_mo = mo1 + mo2;

    int gcd = gcd_recursive(new_mo, new_de);
    struct rational r = {new_mo/gcd, new_de/gcd};
    return r;
}

struct rational sub_rational(struct rational a, struct rational b) {
    int de1 = get_de(a), de2 = get_de(b);
    int mo1 = get_mo(a)*de2, mo2 = get_mo(b)*de1;

    int new_de = de1 * de2;
    int new_mo = mo1 - mo2;

    int gcd = gcd_recursive(new_mo, new_de);
    struct rational r = {new_mo/gcd, new_de/gcd};
    return r;
}

struct rational mul_rational(struct rational a, struct rational b) {
    int de1 = get_de(a), de2 = get_de(b);
    int mo1 = get_mo(a), mo2 = get_mo(b);

    int new_de = de1 * de2;
    int new_mo = mo1 * mo2;

    int gcd = gcd_recursive(new_mo, new_de);
    struct rational r = {new_mo/gcd, new_de/gcd};
    return r;
}

struct rational div_rational(struct rational a, struct rational b) {
    int de1 = get_de(a), de2 = get_de(b);
    int mo1 = get_mo(a), mo2 = get_mo(b);

    int new_de = de1 * mo2;
    int new_mo = mo1 * de2;

    int gcd = gcd_recursive(new_mo, new_de);
    struct rational r = {new_mo/gcd, new_de/gcd};
    return r;
}

void print_rational(struct rational r) {
    printf("r=%d/%d\n", get_mo(r), get_de(r));
}

int main(void) {
    struct rational a = make_rational(1, 8); /* a=1/8 */
	struct rational b = make_rational(-1, 8); /* b=-1/8 */
	print_rational(add_rational(a, b));
	print_rational(sub_rational(a, b));
	print_rational(mul_rational(a, b));
	print_rational(div_rational(a, b));

	return 0;
}