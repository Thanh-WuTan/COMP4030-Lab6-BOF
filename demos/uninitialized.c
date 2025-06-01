int main() { foo(); bar(); }
void foo() { char buffer[60]; read(open("/flag", 0), buffer, 60); }
void bar() { char buffer[60]; write(1, buffer, 60); }