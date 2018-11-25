#include <iostream>

using namespace std;

class Ebool
{
public:
    Ebool(void):m_ebool(char(0)){}

    Ebool(bool const & cpy):m_ebool(static_cast<char>(cpy)){}
    Ebool(Ebool const & cpy):m_ebool(cpy.get_Ebool()){}
    Ebool operator=(Ebool const & cpy)
    {
        this->m_ebool=cpy.get_Ebool();
        return *this;
    }
    Ebool operator=(bool const & cpy)
    {
        this->m_ebool=(this->m_ebool << 1) + static_cast<char>(cpy?1:0);
        return *this;
    }

    char get_Ebool(void) const {return this->m_ebool;}

    bool p(void) const {return this->m_ebool%2 >(this->m_ebool>>1)%2;}
    bool n(void) const {return this->m_ebool%2 <(this->m_ebool>>1)%2;}
    bool stat(void)const{return this->m_ebool%2==1?true:false;}

    void clear(void){this->m_ebool=char(0);}

private:
    char m_ebool;
};

int main()
{
    Ebool etat(false);

    cout << sizeof(etat) << endl;

    return 0;
}
