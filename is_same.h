#ifndef IS_SAME_H
#define IS_SAME_H
namespace mogao
{
    template <typename T, T _val>
    struct interal_cons
    {
        static constexpr T value = _val;
    };
    template <bool _val>
    using bool_cons = interal_cons<bool, _val>;
    //
    using true_type = bool_cons<true>;
    using false_type = bool_cons<false>;
    //
    template <typename, typename>
    struct is_same_v : public false_type
    {
    };
    template <typename T>
    struct is_same_v<T, T> : public true_type
    {
    };
    //
    template <typename T1, typename T2>
    inline constexpr bool is_same = is_same_v<T1, T2>::value;
}
#endif