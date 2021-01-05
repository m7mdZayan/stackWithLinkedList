#include <iostream>
#include <stdlib.h>

using namespace std;

struct Student{
    int id;
    string name;
};

struct Node{
    Student s;
    Node* prev;
};

class stackClass {
    Node* tos;
public:

    stackClass(){
        tos = NULL;
    }

    int isFull() {
        Node* temp = new Node();
        if (temp == NULL ) return 1;
        delete temp;
        return 0;
    }

    void push( Student s ){
        Node* temp = new Node();
        temp->s = s;

        if ( tos == NULL ){
            tos = temp;
            tos->prev = NULL;
        }
        else{
            temp->prev = tos;
            tos = temp;
        }
    }

    int pop(Student & s ){
        if (tos == NULL){
            cout << "stack is empty" << endl;
            return 0;
        }
        else{
            s= tos->s;
            Node* temp = new Node();
            tos = tos->prev;
            delete temp;
            return 1;
        }
    }

    void display(){
        struct Node* temp;
        if (tos == NULL)
            {
                cout << "Stack is Empty" << endl;
                exit(1);
            }
        else
            {
                temp = tos;
                while (temp != NULL) {
                    cout << temp->s.id << "-> " << temp->s.name << endl;;
                    temp = temp->prev;
                }
            }
    }

    stackClass( stackClass & s ){
        tos = NULL;
        Node* temp = new Node();
        temp = s.tos;
        while ( temp != NULL ){
            this->push( temp->s );
            temp = temp->prev;
        }
        delete temp;

    }

    ~stackClass(){
        delete tos;
        cout << "object destructed" << endl;
    }

};


int main()
{
    Student s1,s2,s3,z;
    s1.name = "Mohamed";
    s1.id = 1;
    s2.name = "Mahmoud";
    s2.id = 2;
    s3.name = "ALi";
    s3.id = 3;
    stackClass myStack;
    myStack.push(s1);
    myStack.push(s2);
    myStack.push(s3);

    myStack.display();
    myStack.pop(z);
    cout << "student " << z.name << " with id " << z.id << " was popped out of stack." << endl;
    stackClass stack1(myStack);
    stack1.display();
    return 0;
}
