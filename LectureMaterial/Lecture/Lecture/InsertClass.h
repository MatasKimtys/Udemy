#include <iostream>
class InsertClass
{
    friend bool operator==(const InsertClass &lhs, const InsertClass&rhs);
    friend InsertClass operator-(const InsertClass &obj);
    friend InsertClass operator+(const InsertClass &lhs, const InsertClass &rhs);

    friend std::ostream &operator<<(std::ostream &out, const InsertClass &rhs);
    friend std::istream &operator>>(std::istream &in, const InsertClass &rhs);

private:
    char *str; // C-style string

public:
    void set_data_value(int d)
    {
        *data = d;
    }

    int get_data_value()
    {
        return *data;
    }
    InsertClass(); // No args Constructor
    InsertClass(const char *s); // Overloaded Constructor
    InsertClass(const InsertClass &source); // Copy Constructor
    InsertClass(InsertClass &&source) noexcept; // Move Constructor
    ~InsertClass();

    InsertClass &operator=(const InsertClass &rhs); // Copy assignment
    InsertClass &operator=(InsertClass &&rhs);  // Move assignment
    InsertClass operator-() const; // Make lowercase
    InsertClass operator+(const InsertClass &rhs) const; // concatenate
    bool operator==(const InsertClass &rhs) const;
};