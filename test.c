#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdarg.h>
#include <string.h>


struct TPPS {
    int a;
    int b;
    int *c;
};

struct TPPS * func_with_struct_pointer_ret();

/// test_pointer_return_struct
int test_pointer_return_struct() {
    struct TPPS *a;
    a = func_with_struct_pointer_ret();
    if (a->c[3] == 3) {
        return 0;
    } else {
        return 1;
    }
}

int func_with_struct_pointer_para(struct TPPS *i);

/// test_pointer_para_struct
int test_pointer_para_struct() {
    struct TPPS a;
    func_with_struct_pointer_para(&a);
    if (a.c[3] == 3) {
        return 0;
    } else {
        return 1;
    }
}


int func_with_pointer_para(int *i);

/// test_pointer_para
int test_pointer_para() {
    int i = 0;
    func_with_pointer_para(&i);
    if (i > 0) {
        return 1;
    } else {
        return 2;
    }
}

int test_read();

unsigned int Read_FlashFIFO[16];

void spi(unsigned int);

unsigned int test_search(unsigned long int Flash) {
    unsigned  int a, b, c, data;
    a = (Flash >> 8) & 0xFF00;
    b = (Flash) & 0xFF00;
    c = (Flash << 8) & 0xFF00;
    while (test_read() & 0x01);
    spi(a);
    spi(b);
    spi(c);
    for(int j=0; j < 16; j++) {
        Read_FlashFIFO[j] = 1;
    }
    data = Read_FlashFIFO[4];
    return data;
}

struct A33 {
    int a;
};

struct A22 {
    int a;
    struct A33 a33;
};

struct A11 {
    int a;
    int b;
    struct A22 a22;
    struct A33 a33;
    struct B11 *b11;
    struct {
        int c;
        int d;
    };
    union {
        int a;
        int b;
    } m;
};

struct B11
{
    struct A11 a11;
};

struct {
    int a;
    int b;
} g_anonymous;

///test_complex_struct_nested_1
void test_complex_struct_nested_1(struct A11 a11, struct B11 *b11, struct A22 *a22)
{
    if(g_anonymous.a > 0) {
        g_anonymous.a = 1;
    }

    if(a11.a > 0) {
        a11.a = 1;
    }
}

/// test_complex_struct_nested
void test_complex_struct_nested(struct A11 a11, /*struct B11 b11,*/ struct A22 a22) {
    if (g_anonymous.a > 0) {
        g_anonymous.a = 1;
    }
    if (a11.a > 0) {
        a11.a = 1;
    }
}

struct AAA {
    int a;
};

struct BBB {
    int a;
    struct AAA aa;
};

/// test_nest_structAA
void test_nest_structAA(struct BBB *bb) {
    int a;
    if (bb[0].aa.a == 1) {
        a = 1;
    }
}

extern int test_e;

/// test_extern_variable
int test_extern_variable() {
    if (test_e > 0) {
        return 0;
    } else {
        return 1;
    }
}

/// test_static_local
int test_static_local() {
    static int a = 0;
    if (a > 0) {
        return 1;
    } else {
        return 2;
    }
}

/// test_memset
void test_memset(char *a, int size) {
    memset(a, 0, size);
}

/// test_strcpy
void test_strcpy() {
    char a[3];
    a[0] = 'a';
    a[1] = 'a';
    a[2] = 0;
    char b[3];
    b[0] = 'a';
    b[1] = 'a';
    b[2] = 0;
    strcpy(a, b);
}

/// test_abs
int test_abs(float a) {
    if (fabs(a) == a) {
        return 0;
    } else {
        return 1;
    }
}

struct ATest{
    char a;
    char b;
    int c;
};

int ab[20];

//#pragma pack(4)
typedef struct {
    //struct A a[2];
    //int b;
    char age ;
    char  age1 ;

    short a[10];

    char ac ;
} Age;
//#pragma pack()

/// test_multi_paras
void test_multi_paras(Age b, struct ATest a)
{

    if(a.a == 1) {

    }

    if(a.b == 5) {

    }

    if(a.c == 10) {

    }

}

/// test_absolute_address_read
int test_absolute_address_read  () {
    int j = *((int *) (2));
    int k = *((int *) (2));
    *((int *) (4)) = 3;
    if (j == k) {
        return 0;
    } else {
        return 1;
    }
}

/// test_absolute_address_write
int test_absolute_address_write() {
    *((int *) (2)) = 3;
    *((int *) (2)) = 4;
    return 1;
}


/// test_printf
void test_printf() {
    printf("abc");
}

/// test_dynamic_parameter
int testdp(int a, ...) {
    va_list ap;
    va_start(ap, a);
    int b = va_arg(ap, int);
    va_end(ap);
    if (b > 0) {
        return 1;
    } else {
        return 2;
    }

}

/// test_dynamic_parameter
int test_dynamic_parameter(int i) {
    return testdp(1, i);
}

/// test_sqrt
int test1(double a) {
    double b = sqrt(a);
    if (b == 3) {
        return 1;
    } else {
        return 0;
    }
}

struct TestP1 {
    int a;
    int b;
};

struct TestP2 {
    struct TestP1 *a;
    int b;
    int c;
};

int test_struct_first_field_pointer(struct TestP2 *t) {
    t->b = 1;
    if (t->a->a > 0) {
        return 1;
    } else {
        return 2;
    }
}

struct {
    int a;
    int b;
} A, *B;

/// test_anonymous_struct
int test_anonymous_struct() {
    if (A.a > 0) {
        return 1;
    } else {
        return 2;
    }
}

/// test_anonymous_struct_pointer
int test_anonymous_struct_pointer() {
    if (B->a > 0) {
        return 1;
    } else {
        return 2;
    }
}

union U {
    int *a;
    long b;
};
union U e[2];

union U e1;

/// test_union_global_1
int test_union_global_1(long a) {

    if (e[0].a[0] == 5) {
        return 3;
    }

    if (e[1].b == 5) {
        return 4;
    }

    return 2;
}

/// test_union_global_2
int test_union_global_2(union U test) {
    if (e1.a[0] == 5) {
        return 3;
    }

    if (test.a[0] == 5) {
        return 4;
    }

    return 2;
}


///test_void_pointer
int test_void_pointer(void *test) {
    int *a = test;
    if (a[3] > 1) {
        return 1;
    } else {
        return 2;
    }
}

typedef char (*funp)(int a);

/// test_function_pointer
int test_function_pointer(funp fun) {
    char a = fun(2);
    if (a > 0) {
        return 0;
    } else {
        return 1;
    }
}


int g1[10];
int *g2;

/// test_global_assignment
int test_global_assignment() {
    g2 = g1;
    if (g2[2] > 0) {
        return 1;
    } else {
        return 0;
    }
}

///test_rem
int test_rem(int a, int b) {
    a = a % b;
    if (a > 0) {
        return 1;
    } else {
        return 2;
    }
}

int test3() {
    return 1;
}

/// test_precision
int test_precision() {
    int a = test3();
    if (a > 0) {
        return 1;
    } else {
        return 2;
    }
}


extern int test2();

/// test_symbolize_global
int test_symbolize_global() {
    int a = test2();
    if (a > 0) {
        int b = test2();
        if (b > 3)
            return 0;
        else
            return 4;
    } else {
        return 1;
    }
}

struct AG2 {
    int a;
};

struct AG1 {
    int a;
    struct AG2 *b;
};

struct AG {
    int a;
    int *b;
    int c;
    int d;
    int f;
    int e;
    int g;
};

struct ABCD {
    void *a;
    int b;
};

int test_ABCD(struct ABCD *a) {
    if (a->b > 0) {
        return 0;
    } else {
        return 1;
    }
}

/// test_dynamic_type_1
void test_dynamic_type_1(void *a)
{
    int b;
    struct ABCD * a1 = (struct ABCD *)a;
    int * a2 = (int *)a1->a;

    if(a1->b == 1) {
        b = 1;
    }
    if(a2[0] == 3) {
        b = 2;
    }

}

/// test_dynamic_type
int test_dynamic_type(struct AG1 *t) {
    struct AG *a = (struct AG *) t->b;
    if (a->b[3] > 0) {
        return 1;
    } else {
        return 0;
    }
}

struct AG global_struct;
struct AG *global_struct_pointer;
struct AG global_struct_array[10];

/// test_global
int test_global(int a) {
    if (a > global_struct.a) {
        return 0;
    } else {
        if (global_struct.b[4] > 5) {
            return 1;
        } else {
            return 2;
        }
    }
}

/// test_global_pointer
int test_global_pointer(int a) {
    if (a > global_struct_pointer->a) {
        return 0;
    } else {
        if (global_struct_pointer->b[4] > 5) {
            return 1;
        } else {
            return 2;
        }
    }
}

/// test_global_array
int test_global_array(int a) {
    if (a > global_struct_array[4].a) {
        return 0;
    } else {
        if (global_struct_array[4].b[4] > 5) {
            return 1;
        } else {
            return 2;
        }
    }
}

//
// Created by Zhenbang Chen on 1/26/17.
//

int test(int i) {
    return i + 1;
}

#ifdef __cplusplus
extern "C" {
#endif

void secore_symbolize(void *address, unsigned int size);

#ifdef __cplusplus
}
#endif

/// test_malloc
int test_malloc() {
    int *p = malloc(sizeof(int) * 4);
    secore_symbolize(p, sizeof(int) *4);
    if (p[2] > 0) {
        return 1;
    } else {
        free(p);
        return 2;
    }
}

struct A {
    int a;
    int b;
};


struct B {
    double a;
    int *b;
    int *d;
    struct A *c;
};

struct C {
    float *a;
};


struct D {
    double a;
    int *b;
    int *d;
    struct C *c;
};

struct E {
    int *a;
    struct D *b;
};

typedef struct {
    int a;
    struct E b;
} F;

typedef struct {
    struct A a;
    int b;
} G;


typedef struct {
    float *a;
} AA;

typedef struct {
    AA a;
} BB;

typedef struct {
    BB a;
} CC;

typedef struct {
    CC a;
} DD;

struct Z {
    int a[5];
};


union UU {
    int a;
    int b;
    double c;
};

enum AE {
    a1 = 5,
    a2
};

union UU1 {
    int *a;
    double c;
};


struct ABit {
    char a:1;
    char b:7;
    int *c;
};

#pragma  pack(2)

struct ABit1 {
    int a:1;
    int b:2;
    int c:1;
};

#pragma  unpack

typedef union {
    char a;
    int b;
    float c;
    double *d;
} unionA;

typedef struct {
    unionA a;
    unionA *b;
    unionA c[5];
} structA;

///test_union_pointer_array
int test_union_pointer_array(unionA test) {
    if (test.d[4] > 5.0) {
        return 0;
    } else {
        return 1;
    }
}

/// test_union_complex
int test_union_complex(structA test) {
    if (test.b->d[2] > 5.0) {
        return 0;
    } else {
        return 1;
    }
}

/// test_struct_bit
int test_struct_bit(struct ABit1 *a) {
    if (a->a == 1) {
        return 1;
    } else {
        return 2;
    }
}

/// test_union_pointer
int test_union_pointer(union UU1 *a) {
    if (a->a[2] == 2) {
        return 1;
    } else {
        return 2;
    }
}

/// test_enum
int test_enum(enum AE t) {
    if (t == a1) {
        return 1;
    } else {
        return 2;
    }
}

/// test_union
int test_union(union UU *a) {
    if ((a->a + a->b) == 2) {
        return 1;
    } else {
        return 2;
    }
}


/// test_switch
int test_switch(int i) {
    switch (i) {
        case 1:
        case 10:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        default:
            return 4;
    }
}

/// test_struct_array_element
int test_struct_array_element(struct Z a) {
    if (a.a[3] == 5) {
        return 1;
    } else {
        return 2;
    }
}

/// test_struct_array
int test_struct_array(struct B test[]) {
    if (test[1].b[3] > 0) {
        return 0;
    } else {
        return 1;
    }
}

/// test_nested_typedef
int test_nested_typedef(DD *t) {
    if (t->a.a.a.a[5] > 11.1) {
        return 0;
    } else {
        return 1;
    }
}

/// wxb_test_simple_struct
int wxb_test_simple_struct(G test) {
    if (test.b > 11) {
        if (test.a.a + test.a.b < 11) {
            return 2;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

/// wxb_test_struct_field_complex
int wxb_test_struct_field_complex(F *struct_f, struct B struct_b) {
    if (struct_f->a > 2) {
        return 1;
    } else {
        if (struct_f->b.a[3] == 5) {
            return 2;
        } else {
            if (struct_f->b.b->a == 11.1) {
                return 3;
            } else {
                if (struct_b.a == 11.1) {
                    return 4;
                } else {
                    if (struct_b.c->a > 8) {
                        return 5;
                    } else {
                        return 6;
                    }
                }
            }
        }
    }
}


/// test_typedef
int test_typedef(F *test) {
    if (test->b.a[3] == 5) {
        return 1;
    } else {
        return 0;
    }
}


/// test_watchdog
int test_watchdog(int i) {
    while (i < 0) {
        i--;
    }
    return i;
}

/// test_double_pointer_integer
int test_double_pointer_integer(double *a, int i) {
    if (a[i] > 100) {
        return 0;
    } else {
        return 1;
    }
}


/// test_double_pointer
int test_double_pointer(double *a) {
    if (a[1] == 10.0) {
        return 1;
    } else {
        return 2;
    }
}

/// test_char_a
int test_char_a(char *a, char *b) {
    int index = 24 / 6;
    if (a[0] == b[0]) {
        return 1;
    } else if (a[index] == b[index]) {
        return 2;
    } else {
        return 0;
    }
}

/// test_struct_field
int test_struct_field(struct B *test) {
    if (test->c->a == 11) {
        if (test->b[10] == 3) {
            return 1;
        } else if (test->d[3] == 4) {
            return 2;
        }
        return 0;
    } else {
        return 3;
    }
}

/// wxb_test_struct_field
int wxb_test_struct_field(struct E *test) {
    if (test->b->c->a[5] == 11) {
        if (test->b->b[10] == 3) {
            return 1;
        } else if (test->b->d[3] == 4) {
            return 2;
        }
        return 0;
    } else {
        return 3;
    }
}


/// test_while
int test_while(unsigned int a) {
    while (a > 0 && a < 5) {
        a--;
    }
    return 1;
}

/// test_divbyzero
int test_divbyzero(int a, int b) {
    if (a == 5) {
        return a / b;
    } else {
        return 2;
    }
}

/// test_int_pointer
int test_int_pointer(int *a, int i) {
    if (i >= 0 && a[i] > 0) {
        if (a[i + 1] < 0) {
            return 1;
        } else {
            return 2;
        }
    }
    return 3;
}

/// test_char
int test_char(char a, char b, char c) {
    char t = 0x12;
    if (a == 'c') {
        if (b == 'a' && c == 'b') {
            return 1;
        } else {
            return 2;
        }
    }
    return 0;
}

/// test_float_1
int test_float_1(float a) {
    if ( a == 15) {
        return 1;
    } else {
        return 0;
    }
}

/// test_float
int test_float(float a) {
    if (a * a * a == 8) {
        return 0;
    } else {
        return 1;
    }
}

/// test_overflow
int test_overflow(int a, int b) {
    if (a > 0 && b > 0) {
        if ((a + b) < 0) {
            return 1;
        } else {
            return 2;
        }
    }
    return 0;
}

/// test_bfs
int test_bfs(int a, int b) {
    if (a == 0) {
        if (b == 0) {
            return 1;
        } else {
            return 2;
        }
    } else {
        if (b == 3) {
            return 3;
        } else {
            return 4;
        }
    }
}


/// test_UC_multiple_arguments_pointer_pointer_integer_integer
int test_UC_multiple_arguments_pointer_pointer_integer_integer(int *a, int *b, int i, int j) {
    if (a[i] > 10) {
        if (b[j] > 100) {
            return 1;
        } else {
            return 2;
        }
    } else {
        return 3;
    }
}

/// test_UC_multiple_arguments_pointer_integer
int test_UC_multiple_arguments_pointer_integer(int *a, int i) {
    if (a[i] > 0) {
        return 1;
    } else {
        return 0;
    }
}

/// test_UC_multiple_arguments
int test_UC_multiple_arguments(int a, int b) {
    if (a > 90) {
        if (b > 20) {
            return 1;
        } else {
            return 2;
        }
    } else {
        return 3;
    }
}

/// test_UC_se_symbolic_pointer_write_complex
int test_UC_se_symbolic_pointer_write_complex(int *a) {
    a[0] = 1;
    int *b = a;
    b++;
    if (b[1] > 1) {
        int *c = a;
        if (c[1] > 1)
            return 1;
        else
            return 2;
    } else {
        return 0;
    }
}

/// test_UC_se_symbolic_pointer_write
int test_UC_se_symbolic_pointer_write(int *a) {
    a[5] = 1;
    if (a[5] > 1) {
        return 1;
    } else {
        return 0;
    }
}

/// test_UC_se_symbolic_pointer
int test_UC_se_symbolic_pointer(int *a) {
    if (a[1] > 0) {
        return 1;
    } else {
        return 0;
    }
}

/// test_UC_se_symbolic_int
int test_UC_se_symbolic_int(int a) {
    if (a > 0) {
        return 1;
    } else {
        return 0;
    }
}

/// test_assign
int test_assign(int *a) {
    a[2] = 1;
    return a[2];
}

enum State {
    SET,
    UNSET
};

enum State getState();

void test_return_enum() {
    int b = 0;
    enum State a = getState();
    if(a == SET) {
        b = 1;
    } else {
        b = 2;
    }
}
