class Screen{
public:
    Screen& clear (char = bkground);
private:
    static const char bkground;
};
const char bkground = 'A';
// Screen& Screen::clear(char = bkground){


// }