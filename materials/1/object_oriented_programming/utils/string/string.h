#ifndef __STRING_H__
#define __STRING_H__

class String {
private:
    char *str;

    void copy(const String &other);
    void free();

public:
    // constructor
    String(const char *s = "");

    // copy constructor
    String(const String &other);

    // move constructor
    String(String &&other);

    // destructor
    ~String();

    // copy assignment
    String &operator=(const String &other);

    // move assignment
    String &operator=(String &&other);

    // other methods
    void append(const char *s);
    void append(const String &s);

    void print() const;
    int length() const;

    void popBack();
    void pushBack(const char c);
};

#endif // __STRING_H__