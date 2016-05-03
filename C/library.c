#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BookHolder
{
    int *books; // The actual book positions
    int holding; // Number of books in this struct
} BookHolder;

void printArray(int array[], int *items)
{
    for (int i = 0; i < *items; i++)
    {
        printf("%d\n", array[i]);
    }
}

int cmpfunc (const void * b, const void * a)
{
    return ( *(int*)a - *(int*)b );
}

void doubleUp(int *array, int *items)
{
    for (int i = 0; i < *items; i++)
        array[i] *= 2;
}

void prep(BookHolder *holder, int *items)
{
    holder->books = malloc(sizeof(int) * (int)*items);
    holder->holding = 0;
}

void removeHolding(BookHolder *holder, BookHolder *oldHolder, int *canHold)
{
    for (int i = 0; i < oldHolder->holding; i += *canHold)
    {
        holder->books[holder->holding] = oldHolder->books[i];
        holder->holding++;
    }
}

int sum(int *array, int *items)
{
    int total = 0;
    for (int i = 0; i < *items; i++)
        total += array[i];

    return total;
}


int main()
{
    int numItems, canHold;

    scanf("%d %d", &numItems, &canHold);

    // Create storage for the books
    BookHolder posBooks;
    BookHolder negBooks;

    // Allocate storage
    prep(&posBooks, &numItems);
    prep(&negBooks, &numItems);

    int tempBook;
    for (int i = 0; i < numItems; i++)
    {
        scanf("%d", &tempBook);
        if (tempBook > 0)
        {
           posBooks.books[posBooks.holding] = (int)tempBook;
           posBooks.holding++;
        }
        else
        {
           negBooks.books[negBooks.holding] = -1*(int)tempBook;
           negBooks.holding++;
        }
    }

    // Sort em
    qsort(posBooks.books, posBooks.holding, sizeof(int), cmpfunc);
    qsort(negBooks.books, negBooks.holding, sizeof(int), cmpfunc);

    // Double each value
    doubleUp(posBooks.books, &posBooks.holding);
    doubleUp(negBooks.books, &negBooks.holding);

    // Create new holders for the books
    BookHolder posBooksHolding;
    BookHolder negBooksHolding;
    prep(&posBooksHolding, &numItems);
    prep(&negBooksHolding, &numItems);

    // We can carry alot of books
    removeHolding(&posBooksHolding, &posBooks, &canHold);
    removeHolding(&negBooksHolding, &negBooks, &canHold);

    // Determine which is bigger and half it
    if (posBooksHolding.books[0] > negBooksHolding.books[0])
        posBooksHolding.books[0] /= 2;
    else
        negBooksHolding.books[0] /= 2;

    // Sum and print the answer
    int total = 0;
    total += sum(posBooksHolding.books, &posBooksHolding.holding);
    total += sum(negBooksHolding.books, &negBooksHolding.holding);
    printf("%d\n", total);

    /*printf("OLD\n");*/
    /*printArray(posBooks.books, &posBooks.holding);*/
    /*printArray(negBooks.books, &negBooks.holding);*/
    /*printf("NEW\n");*/
    /*printArray(posBooksHolding.books, &posBooksHolding.holding);*/
    /*printArray(negBooksHolding.books, &negBooksHolding.holding);*/
    
    // Free the memory when done
    free(posBooks.books);
    free(negBooks.books);
    free(posBooksHolding.books);
    free(negBooksHolding.books);

    return 0;
}
