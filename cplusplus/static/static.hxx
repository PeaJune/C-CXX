#ifndef __TEST_STATIC_HXX__
#define __TEST_STATIC_HXX__

enum class egg{Small, Medium, Large, Jumbo};
enum struct t_shirt{Small, Medium, Large, Jumbo};

class CStatic
{
    public:
        static int pa;
        inline static void set_pb(int s);
        inline static int get_pb();
        static void show();
    private:
        static int pb;
};

int CStatic::get_pb()
{
    return pb;
}
void CStatic::set_pb(int s)
{
    pb=s;
}

//int CStatic::pb = 0;
#endif