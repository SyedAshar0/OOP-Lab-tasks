#include <iostream>
#include <any>
#include <exception>
#include <typeinfo>
using namespace std;
class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "bad type,type bad";
    }
};
template<typename Tag = void>  
class TypeSafeContainer {
private:
    std::any data;
public:
    template<typename T>
    void store(const T& value) {
        data = value;
    }
    template<typename T>
    T get() const {
        try {
            return std::any_cast<T>(data);
        } catch (const std::bad_any_cast&) {
            throw BadTypeException();
        }
    }
};
int main() {
    TypeSafeContainer<> container;
    container.store(42); 
    try {
        cout << container.get<int>() << endl;      
        cout << container.get<string>() << endl;    
    } catch (const BadTypeException& e) {
        cout << "Caught: " << e.what() << endl;
    }
    return 0;
}
