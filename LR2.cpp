#include <iostream>
#include <vector>

class Bitstring {
private:
    std::vector<int> data;
    int size;

public:
    Bitstring(int size) : size(size) {
        data.resize(size);
    }

    ~Bitstring() {}

    void setValue(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }

    int getValue(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        else {
            std::cout << "Bitstring wrong index " << index << std::endl;
            return 0;
        }
    }

    void print(const std::string& name) const {
        std::cout << name << " ";
        for (int i = 0; i < size; ++i) {
            std::cout << getValue(i) << " ";
        }
        std::cout << std::endl;
    }

    void notOperation() {
        for (int i = 0; i < size; ++i) {
            data[i] = 1 - data[i];
        }
    }

    void orOperation(const Bitstring& other) {
        for (int i = 0; i < size; ++i) {
            /*if (data[i] == 1 and other.getValue(i) == 1) {
                data[i] = 1;
            }
            else if (data[i] == 1 and other.getValue(i) == 0) {
                data[i] = 1;
            }
            else if (data[i] == 0 and other.getValue(i) == 1) {
                data[i] = 1;
            }
            else if (data[i] == 0 and other.getValue(i) == 0) {
                data[i] = 0;
            }*/
            data[i] = data[i] | other.getValue(i);
        }
    }

    void xorOperation(const Bitstring& other) {
        for (int i = 0; i < size; ++i) {
            /*if (data[i] == 1 and other.getValue(i) == 1) {
                data[i] = 0;
            }
            else if (data[i] == 1 and other.getValue(i) == 0) {
                data[i] = 1;
            }
            else if (data[i] == 0 and other.getValue(i) == 1) {
                data[i] = 1;
            }
            else if (data[i] == 0 and other.getValue(i) == 0) {
                data[i] = 0;
            }*/
            data[i] = data[i] ^ other.getValue(i);
        }
    }

    void andOperation(const Bitstring& other) {
        for (int i = 0; i < size; ++i) {
            /* if (data[i] == 1 and other.getValue(i) == 1) {
                 data[i] = 1;
             }
             else if (data[i] == 1 and other.getValue(i) == 0) {
                 data[i] = 0;
             }
             else if (data[i] == 0 and other.getValue(i) == 1) {
                 data[i] = 0;
             }
             else if (data[i] == 0 and other.getValue(i) == 0) {
                 data[i] = 0;
             }*/
            data[i] = data[i] & other.getValue(i);
        }
    }

    void cyclicShiftRight(int shift) {
        shift %= size;
        std::vector<int> temp = data;
        for (int i = 0; i < size; ++i) {
            data[(i + shift) % size] = temp[i];
        }
    }
};

int main() {
    int size;
    // std::cout << "Enter the size of Bitstrings: ";
    std::cin >> size;

    Bitstring Bitstring1(size);
    Bitstring Bitstring2(size);

    // std::cout << "Enter values for Bitstring1: ";
    for (int i = 0; i < size; ++i) {
        int value;
        std::cin >> value;
        Bitstring1.setValue(i, value);
    }

    // std::cout << "Enter values for Bitstring2: ";
    for (int i = 0; i < size; ++i) {
        int value;
        std::cin >> value;
        Bitstring2.setValue(i, value);
    }

    Bitstring Bitstring_copy = Bitstring1;
    Bitstring1.print("Bitstring1 =");
    Bitstring_copy.notOperation();
    Bitstring_copy.print("not Bitstring1 =");

    Bitstring_copy = Bitstring2;
    Bitstring2.print("Bitstring2=");
    Bitstring_copy.notOperation();
    Bitstring_copy.print("not Bitstring2 =");

    Bitstring Bitstring1_copy = Bitstring1;
    Bitstring1_copy.orOperation(Bitstring2);
    std::cout << "Bitstring1 or Bitstring2 =";
    Bitstring1_copy.print("");

    Bitstring1_copy = Bitstring1;
    Bitstring1_copy.xorOperation(Bitstring2);
    std::cout << "Bitstring1 xor Bitstring2 =";
    Bitstring1_copy.print("");

    Bitstring1_copy = Bitstring1;
    Bitstring1_copy.andOperation(Bitstring2);
    std::cout << "Bitstring1 and Bitstring2 =";
    Bitstring1_copy.print("");

    while (true) {
        int action, shift;
        // std::cout << "Enter action (0 to exit, 1 for shift Bitstring1, 2 for shift Bitstring2): ";
        std::cin >> action;

        if (action == 0) {
            break;
        }
        else if (action == 1) {
            //std::cout << "Enter the number of positions to shift Bitstring1 to the right: ";
            std::cin >> shift;
            std::cout << "cycle sdvig " << shift << " Bitstring1" << std::endl;
            Bitstring1.cyclicShiftRight(shift);
        }
        else if (action == 2) {
            // std::cout << "Enter the number of positions to shift Bitstring2 to the right: ";
            std::cin >> shift;
            std::cout << "cycle sdvig " << shift << " Bitstring2" << std::endl;
            Bitstring2.cyclicShiftRight(shift);
        }

        Bitstring_copy = Bitstring1;
        Bitstring1.print("Bitstring1 =");
        Bitstring_copy.notOperation();
        Bitstring_copy.print("not Bitstring1 =");

        Bitstring_copy = Bitstring2;
        Bitstring2.print("Bitstring2=");
        Bitstring_copy.notOperation();
        Bitstring_copy.print("not Bitstring2 =");

        Bitstring Bitstring1_copy = Bitstring1;
        Bitstring1_copy.orOperation(Bitstring2);
        std::cout << "Bitstring1 or Bitstring2 =";
        Bitstring1_copy.print("");

        Bitstring1_copy = Bitstring1;
        Bitstring1_copy.xorOperation(Bitstring2);
        std::cout << "Bitstring1 xor Bitstring2 =";
        Bitstring1_copy.print("");

        Bitstring1_copy = Bitstring1;
        Bitstring1_copy.andOperation(Bitstring2);
        std::cout << "Bitstring1 and Bitstring2 =";
        Bitstring1_copy.print("");
    }

    return 0;
}