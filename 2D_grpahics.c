#include <stdio.h>
#include <stdlib.h>
#define ROWS 25
#define COLS 60
char canvas[ROWS][COLS];
void initializeCanvas()
{
    int i, j;
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            canvas[i][j] = '_';
        }
    }
}
void displayCanvas()
{
    int i, j;
    printf("\n");
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLS; j++){
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawRectangle(char symbol)
{
    int row, col, height, width;
    int i, j;
    printf("Starting Row: ");
    scanf("%d", &row);
    printf("Starting Column: ");
    scanf("%d", &col);
    printf("Height: ");
    scanf("%d", &height);
    printf("Width: ");
    scanf("%d", &width);
    for(i = row; i < row + height && i < ROWS; i++){
        for(j = col; j < col + width && j < COLS; j++){
            canvas[i][j] = symbol;
        }
    }
}
void drawLine(char symbol)
{
    int i, row1, col1, row2, col2;
    printf("Row1 Col1: ");
    scanf("%d %d", &row1, &col1);
    printf("Row2 Col2: ");
    scanf("%d %d", &row2, &col2);
    if(row1 == row2)
    {
        if(col1 > col2){
            int temp = col1;
            col1 = col2;
            col2 = temp;
        }
        for(i = col1; i <= col2; i++){
            canvas[row1][i] = symbol;
        }
    }
    else if(col1 == col2)
    {
        if(row1 > row2){
            int temp = row1;
            row1 = row2;
            row2 = temp;
        }
        for(i = row1; i <= row2; i++){
            canvas[i][col1] = symbol;
        }
    }
}
void drawTriangle(char symbol)
{
    int row, col, height;
    int i, j;

    printf("Top Row: ");
    scanf("%d", &row);

    printf("Left Column: ");
    scanf("%d", &col);

    printf("Height: ");
    scanf("%d", &height);

    for(i = 0; i < height; i++)
    {
        for(j = 0; j <= i; j++)
        {
            if(row + i < ROWS && col + j < COLS)
            {
                canvas[row + i][col + j] = symbol;
            }
        }
    }
}

void drawCircle(char symbol)
{
    int centerRow, centerCol, radius;
    int i, j;

    printf("Center Row: ");
    scanf("%d", &centerRow);

    printf("Center Column: ");
    scanf("%d", &centerCol);

    printf("Radius: ");
    scanf("%d", &radius);

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            int x = i - centerRow;
            int y = j - centerCol;

            int value = x * x + y * y;

            if(value >= radius * radius - radius &&
               value <= radius * radius + radius){
                canvas[i][j] = symbol;
            }
        }
    }
}

void addObject()
{
    int choice;
    printf("\n1. Rectangle");
    printf("\n2. Line");
    printf("\n3. Triangle");
    printf("\n4. Circle");
    printf("\nChoice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            drawRectangle('*');
            break;

        case 2:
            drawLine('*');
            break;

        case 3:
            drawTriangle('*');
            break;

        case 4:
            drawCircle('*');
            break;
    }
}
void deleteObject(){
}
void modifyObject(){
}
int main()
{
    int choice;
    initializeCanvas();
    do
    {
        printf("\n1. Add Object");
        printf("\n2. Delete Object");
        printf("\n3. Modify Object");
        printf("\n4. Display Picture");
        printf("\n5. Clear Canvas");
        printf("\n6. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                addObject();
                break;

            case 2:
                deleteObject();
                break;

            case 3:
                modifyObject();
                break;

            case 4:
                displayCanvas();
                break;

            case 5:
                initializeCanvas();
                printf("Canvas Cleared.\n");
                break;

            case 6:
                break;

            default:
                printf("Invalid Choice.\n");
        }

    } while(choice != 0);
    return 0;
}

