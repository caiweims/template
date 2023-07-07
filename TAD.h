#ifndef TAD_H
#define TAD_H
// TAD means template argument deduction
namespace tad
{
    template <typename T>
    void func(T t) // if t is const ,T will have const info
    {
    }
    template <typename T>
    void func_ref(const T &t)
    {
    }
    template <typename T>
    void func_pnt(const T *t)
    {
    }
    //
    template <typename T>
    void func_s(T *&t)
    {
    }
    void use_func()
    {

        int val = 12;
        //
        const int cval = 12;
        int *p = &val;
        func_ref(val);
        func_pnt(p);

        //
        int a[12] = {};
        // array to point
        func(a);
        func_s(p); //(a) not works!
    }
}
#endif