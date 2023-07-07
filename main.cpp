#include "template.h"
#include "is_same.h"
#include "TAD.h"
//
void use_mogao_is_same()
{
    bool res = mogao::is_same<int, double>;
}
//
int main()
{
    //
    // tad::use_func();
    //
    mogao::argc::use_is_rvalue_ref();
    mogao::argc::use_is_lvalue_ref();
    //
    use_mogao_is_same();
    mogao::overload::use_fun();
    mogao::use_fun();
    return 0;
}