#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    char open;
    char close;
    struct node *next;
};

int main()
{
    struct node *head, *type2, *type3, *type4;
    head = (struct node *)malloc(sizeof(struct node));
    type2 = (struct node *)malloc(sizeof(struct node));
    type3 = (struct node *)malloc(sizeof(struct node));
    type4 = (struct node *)malloc(sizeof(struct node));
    head->open = '{';
    head->close = '}';
    head->next = type2;

    type2->open = '[';
    type2->close = ']';
    type2->next = type3;

    type3->open = '(';
    type3->close = ')';
    type3->next = type4;

    type4->open = '<';
    type4->close = '>';
    type4->next = NULL;

    string input;

    cout << "Please enter some parenthesis opening and closing" << endl;
    getline(cin, input);
    cout << "Let's check if your input is valid parenthesis" << endl;

    int size = input.length();
    int i = 0, j = size - 1;
    if(size % 2 == 0 ) {

    while (i < j)
    {
        struct node *current = head;

        while (current != NULL)
        {
            if (input[i] == current->open && input[j] == current->close)
            {

                break;
            }
            current = current->next;
        }

        if (current == NULL)
        {
            cout << "Not a valid parenthesis" << endl;
            exit(0);
        }

        i++;
        j--;
    }

    cout << "The given input is a valid parenthesis" << endl;
    }
    else {
        cout<<"Invalid parenthesis"<<endl;
    }
    return 0;
}
