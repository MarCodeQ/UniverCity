#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct Item *ptr;

struct Item
{
    double coef;
    int exp;
    ptr next;
};

void insertItem(ptr &first, double coef, int exp)
{
    ptr newItem = new Item;
    newItem->coef = coef;
    newItem->exp = exp;
    newItem->next = nullptr;

    if (!first)
    {
        first = newItem;
        return;
    }

    ptr curr = first;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = newItem;
}
void normalizePolynomial(ptr &first)
{
    ptr current = first;
    ptr prev = first;
    while (current != NULL)
    {
        ptr fixer = current->next;
        ptr flag = current;
        while (fixer != NULL)
        {
            if (fixer->exp == current->exp)
            {
                current->coef += fixer->coef;
                flag->next = fixer->next;
                delete fixer;
                fixer = flag->next;
            }
            else
            {
                flag = fixer;
                fixer = fixer->next;
            }
        }
        if (current->coef == 0)
        {
            if (current == first)
            {
                first = current->next;
                delete current;
                current = first;
            }
            else
            {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
}

void printPolynomial(ptr first)
{
    ptr curr = first;
    while (curr)
    {

        cout << "(" << curr->coef << "," << curr->exp << ") ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    ptr polynomial = nullptr;
    insertItem(polynomial, 1, 1);
    insertItem(polynomial, -1, 1);
    insertItem(polynomial, 2, 0);
    insertItem(polynomial, 3, 1);
    insertItem(polynomial, 4, 0);

    cout << "Original polynomial: ";
    printPolynomial(polynomial);

    cout << "Normalized polynomial: ";
    normalizePolynomial(polynomial);
    printPolynomial(polynomial);

    return 0;
}
