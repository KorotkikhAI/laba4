#include <iostream>
#include <cassert>
using namespace std;
char nibble_to_hex(uint8_t i) {
    assert(0x0 <= i && i <= 0xf);
    char digits[] = "0123456789abcdef";
    return digits[i];
}
void print_in_hex(uint8_t byte)
{
    cout << nibble_to_hex(byte >> 4);
    cout<< nibble_to_hex(byte & 0b00001111);
}
const uint8_t*
as_bytes(const void* data) {
    return reinterpret_cast<const uint8_t*>(data);
}
void print_in_hex(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_hex(bytes[i]);

        if ((i + 1) % 16 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}
char bit_digit(uint8_t byte, uint8_t bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
}
void print_in_binary(uint8_t byte) {
    for (uint8_t bit = 7; bit > 0; bit--) {
        cout << bit_digit(byte, bit);
    }
    cout<<bit_digit(byte,0);
}

void
print_in_binary(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);

        if ((i + 1) % 4 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}
struct Student {
    char name [17];
    uint16_t year;
    float sred_ball;
    uint8_t sex;
    int classes;
    Student * starosta;
};
int main()
{   uint16_t oper1,oper3,res;
    char oper2;

    assert(nibble_to_hex(0x0) == '0');
    assert(nibble_to_hex(0x1) == '1');
    assert(nibble_to_hex(0x2) == '2');
    assert(nibble_to_hex(0x3) == '3');
    assert(nibble_to_hex(0x4) == '4');
    assert(nibble_to_hex(0x5) == '5');
    assert(nibble_to_hex(0x6) == '6');
    assert(nibble_to_hex(0x7) == '7');
    assert(nibble_to_hex(0x8) == '8');
    assert(nibble_to_hex(0x9) == '9');
    assert(nibble_to_hex(0xa) == 'a');
    assert(nibble_to_hex(0xb) == 'b');
    assert(nibble_to_hex(0xc) == 'c');
    assert(nibble_to_hex(0xd) == 'd');
    assert(nibble_to_hex(0xe) == 'e');
    assert(nibble_to_hex(0xf) == 'f');
    cin>>oper1>>oper2>>oper3;
    switch (oper2)
    {
case '&':

        res=oper1&oper3;
        print_in_hex(&oper1,sizeof(oper1));
        cout<<oper2;
        print_in_hex(&oper3,sizeof(oper3));
        cout<<" = ";
        print_in_hex(&res,sizeof(res));
        cout<<'\n';
        print_in_binary(&oper1,sizeof(oper1));
        cout<<oper2<<" ";
        print_in_binary(&oper2,sizeof(oper2));
        cout<<" = ";
        print_in_binary(&res,sizeof(res));
        break;
    case '|':

        res=oper1|oper3;
        print_in_hex(&oper1,sizeof(oper1));
        cout<<oper2;
        print_in_hex(&oper3,sizeof(oper3));
        cout<<" = ";
        print_in_hex(&res,sizeof(res));
        cout<<'\n';
        print_in_binary(&oper1,sizeof(oper1));
        cout<<oper2<<" ";
        print_in_binary(&oper2,sizeof(oper2));
        cout<<" = ";
        print_in_binary(&res,sizeof(res));
        break;

    case '^':

        res=oper1^oper3;
        print_in_hex(&oper1,sizeof(oper1));
        cout<<oper2;
        print_in_hex(&oper3,sizeof(oper3));
        cout<<" = ";
        print_in_hex(&res,sizeof(res));
        cout<<'\n';
        print_in_binary(&oper1,sizeof(oper1));
        cout<<oper2<<" ";
        print_in_binary(&oper2,sizeof(oper2));
        cout<<" = ";
        print_in_binary(&res,sizeof(res));
        break;
    }
    Student students[3];
    {
        {
            "petya";2017;4.1;0;7;nullptr;
        }
        {
            "vasya",2041,3.1,0,7,&students[0];
        }
        {
            "dima",2011,1.1,0,7,students[0];
        }

    }
    cout<<endl<<"Address of array: "<<&students<<endl;
    cout<<"size of array: "<<sizeof(students)<<endl;
    cout<<"\t address of element: "<<"\t Size of element: "<<endl;
    for (int i=0; i<3;i++)
        cout<<i<<"\t"<<&students[i]<<"\t\t"<<sizeof(students[i])<<endl;
    cout<<"FOR FIRST ELEM OF ARRAY: "<<endl;
    cout<<"\t Addres of field: "<<"\t size of field: "<<"\toffset"<<endl;
    cout<<"NAME:\t"<<&students[0].name<<"\t\t";
    cout<<sizeof(students[0].name)<<"\t\t\t"<<offsetof(struct Student, name)<<endl;
    cout<<"YEAR:\t"<<&students[0].year<<"\t\t";
    cout<<sizeof(students[0].year)<<"\t\t\t"<<offsetof(struct Student, sred_ball)<<endl;
    cout<<"SREDBALL:\t"<<&students[0].sred_ball<<"\t\t";
    cout<<sizeof(students[0].sred_ball)<<"\t\t\t"<<offsetof(struct Student, sred_ball)
            <<endl;
    cout<<"SEX:\t"<<&students[0].sex<<"\t\t";
    cout<<sizeof(students[0].sex)<<"\t\t\t"<<offsetof(struct Student, classes)<<endl;
    cout<<"calsses:\t"<<&students[0].classes<<"\t\t";
    cout<<sizeof(students[0].classes)<<"\t\t\t"<<offsetof(struct Student, classes)<<endl;
    cout<<"Starosta:\t"<<&students[0].starosta<<"\t\t";
    cout<<sizeof(students[0].starosta)<<"\t\t\t"<<offsetof(struct Student, starosta)
            <<endl;
}

