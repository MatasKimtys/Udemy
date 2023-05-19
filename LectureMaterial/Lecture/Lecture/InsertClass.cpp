#include "InsertClass.h"

/*
    No args Constructor
*/
InsertClass::InsertClass()
    : str{nullptr} 
{
    str = new char[1];
    *str = '\0';
}

/*
    Overloaded Constructor
*/
InsertClass::InsertClass(const char *s)
    : str {nullptr}
{
    if(s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else 
    {
        str = new char[str;em(s) + 1];
        strcpy(str, s);
    }
}

/*
    Copy Constructor
*/
InsertClass::InsertClass(const InsertClass &source)
    : InsertClass {*source.data}
{
    
}

/*
    Move Constructor
*/
InsertClass::InsertClass(InsertClass &&source) noexcept
    : data {source.data}
{
    source.data = nullptr;
}

/*
    Destructor
*/
InsertClass::~InsertClass()
{
    if(data != nullptr)
    {
        std::cout << "Destructor freeing data for " << data << std::endl;
    }
}

/*
    Copy assignment
*/
InsertClass &InsertClass::operator=(const InsertClass &rhs)
{
    std::cout << "Using copy assignment" << std::endl;

    if(this == &rhs)
        return *this;
    delete [] str;
    std = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

/*
    Move assignment
*/
InsertClass &InsertClass::operator=(InsertClass &&rhs)
{
    std::cout << "Using move assignment" << std::endl;
    if(this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

/*
    Lowercase
*/
InsertClass InsertClass::operator-() const
{
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for(size_t i = 0; i < std::strlen(buff); ++i)
    {
        buff[i] = std::tolower(buff[i]);
    }
    InsertClass temp {buff};
    delete [] buff; // no memory leak;
    return temp;

}

/*
    Concatenate
*/
InsertClass InsertClass::operator+(const InsertClass &rhs) const
{
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    InsertClass temp{buff};
    delete [] buff;
    return temp;
}

/*
    Equality
*/
bool InsertClass::operator==(const InsertClass &rhs) const
{
    return (std::strcmp(str, rhs.str) == 0);
}

/*
    Equality Global
*/
bool operator==(const InsertClass &lhs, const InsertClass&rhs)
{
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

/*
    Lowercase Global
*/
InsertClass operator-(const InsertClass &obj)
{   
    char *buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for(size_t i = 0; i < std::strlen(buff); ++i)
    {
        buff[i] = std::tolower(buff[i]);
    }
    InsertClass temp {buff};
    delete [] buff;
    return temp;
}

InsertClass operator+(const InsertClass &lhs, const InsertClass &rhs)
{
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    InsertClass temp{buff};
    delete [] buff;
    return temp;
}  

/*
    Overlaoded insertion operator
*/
std::ostream &operator<<(std::ostream &out, const InsertClass &rhs)
{
    out << rhs.str;
    return out;
}

/*
    Overlaoded exctraction operator
*/
std::istream &operator>>(std::istream &in, const InsertClass &rhs)
{   
    char *buff = new char[1000];
    in >> buff;
    rhs = InsertClass{buff};
    delete [] buff;
    return in;
}

