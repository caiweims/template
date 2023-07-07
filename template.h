#ifndef TEMPLATE_H
#define TEMPLATE_H
#include "is_same.h"
#include <string>
#include <utility>
#include <type_traits> //for remove_reference
namespace mogao
{
    template <typename T>
    void fun(T &&val)
    {
        using value_type = T;
        val += 1;
        auto res = val;
    }
    void use_fun()
    {
        int i = 12;
        fun(i);
    }
    namespace overload
    {
        template <typename T>
        void fun_v1(T &&val)
        {
        }
        template <typename T>
        void fun_v1(const T &val)
        {
        }
        void use_fun()
        {
            // r-value "string" can be works?
            fun_v1(12);       // non-const r-value
            fun_v1("string"); // const r-value
        }
    }
    void use_remove_rerf()
    {
        std::string str1("string"), str2;
        std::string &&str3{"string"};
        std::string &str4 = str1;
        using type1 = std::remove_reference<decltype(str3)>::type;
        using type2 = std::remove_reference<std::string &>::type;
        if (mogao::is_same_v<type1, type2>::value)
        {
        }
    }
    ////////////////////////////////////////////////////////////////////////
    //
    //
    ////////////////////////////////////////////////////////////////////////
    namespace argc
    {
        // used in type deduiced by template
        template <typename T>
        struct is_lvalue_reference : public mogao::false_type
        {
        };
        template <typename T>
        struct is_lvalue_reference<T &> : public mogao::true_type
        {
        };
        //
        template <typename T>
        struct is_rvalue_ref : public mogao::false_type
        {
        };
        template <typename T>
        struct is_rvalue_ref<T &&> : public mogao::true_type
        {
        };
        //
        void use_is_lvalue_ref()
        {
            int val = 12;
            auto res = is_lvalue_reference<int>::value;
        }
        //
        void called(int &&val) {}
        // return type diff with parameter
        template <typename T>
        T &&forward(T &t) // or (T&& t)
        {
            return static_cast<T &&>(t);
        }
        //
        template <typename T>
        void func(T &&t)
        {
            // called(t);
            called(forward<T>(t));
        }
        template <typename T>
        void func_v2(T &&t)
        {
            called(std::move(t));
        }
        void use_is_rvalue_ref()
        {
            int val = 12;
            int &&rrval = 12;
            func_v2(std::move(rrval));
            // called(rrval);
            int &rval = rrval;
            // func(rval); //???
            //  not works
            //  std::move(val)
            //  or std::forward<int&&>(val)
            //  called(val);
            func(12);
        }
    } // end namespace argc
} // end namespace
#endif