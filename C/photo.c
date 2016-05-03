#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum Turn
{
    H = 3,
    N = 2,
    V = 1,
    U = 0
} Turn;

typedef struct Photos
{
    int total;
    int maxHold;
    Turn *photos;
    int turns;
} Photos;

Turn *calcStartPtr(Photos *photo)
{
    return &photo->photos[photo->total - photo->maxHold];
}

bool last(Photos *photo, Turn *currPtr)
{
    return &photo->photos[0] != currPtr;
}

bool allSame(Photos *photo)
{
    for(int i = 0; i < photo->maxHold; i++)
        if(photo->photos[0]!=photo->photos[i])
            return false;

    return true;
}

void rotate(Photos *photo, Turn *startPtr)
{
    int tempItem;
    for (int i = 0; i < photo->maxHold - 1; i++)
    {
        tempItem = *(startPtr + i) - *(startPtr + photo->maxHold - 1);
        /*printf("ITEM: %d\n", tempItem);*/
        if (tempItem < 0)
            *(startPtr + i) = 4 + tempItem;
        else
            *(startPtr + i) = tempItem;
    }
}

void debug(Photos *photo)
{
    printf("TURNS: %d\n", photo->turns);
    for(int i = 0; i < photo->total; i++)
        printf("%d ", photo->photos[i]);
    printf("\n");
}

void loop(Photos *photo)
{
    Turn *startPtr = calcStartPtr(photo);
    while(last(photo, startPtr))
    {
        /*debug(photo);*/
        rotate(photo, startPtr);
        photo->turns += *(startPtr + photo->maxHold - 1);
        *(startPtr + photo->maxHold - 1) = U;

        startPtr--;
    }

    /*debug(photo);*/
    if (allSame(photo))
        printf("%d\n", photo->turns + *startPtr);
    else
        printf("-1");
}

int main(void)
{
    Photos photo;
    photo.turns = 0;
    scanf("%d %d", &photo.total, &photo.maxHold);
    char tempPhotoHolder[photo.total];
    scanf("%s", tempPhotoHolder);

    // Allocate memory for the turn enum array
    photo.photos = (Turn*)malloc(photo.total * sizeof(int));

    // Convert from string to enum
    for(int i = 0; i < photo.total; i++)
    {
        switch(tempPhotoHolder[i])
        {
            case 'H':
                photo.photos[i] = H;
                break;
            case 'N':
                photo.photos[i] = N;
                break;
            case 'V':
                photo.photos[i] = V;
                break;
            default:
                photo.photos[i] = U;
        }
    }

    loop(&photo);

    free(photo.photos);
    return 0;
}
