/*
Đây là nơi chứa toàn bộ mã cho bài Assignment chúng mình, là chỗ chính thức để
các thành viên dễ dàng kiểm tra tiến độ và sửa đổi code.




CÁCH KIỂM TRA - tự copy về Dev-C và chạy




CÁCH UPDATE
- Để update code sẽ nên đi theo những bước sau
1. Copy code chưa sửa đổi, tạo file c hoặc docx mới rồi copy code này vào cho bên
   trong Folder Backups
2. Ghi lại những gì mình đã sửa đổi/thêm cho vào thư mục Backups -> changelogs  
   CÁCH FORMAT: [NGÀY/THÁNG GIỜ]: Những sửa đổi về code
3. Copy code mình đã sửa đổi/thêm và ghi đè lên code ở source.c chính (cái này)
   Nhớ tránh những dòng comment này khi ghi đè
4. [OPTIONAL] Thông báo với thành viên còn lại về sửa đổi.
*/




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>




#define MAX_ITEMS 100




// Structure to hold sport item information
typedef struct
{
    char itemName[50];
    char brandName[50];
    char description[500];
    char sportsField[50];
    double price;
    int gender;  // 1 = Female, 0 = Male, 2 = Unisex
    int type;    // 0 = Tools, 1 = Clothes, 2 = Protective Equipment
} SportItem;




void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}




void printLogo()
{  
    printf("\n\n");
    setColor(7);
    printf(
          " .oooooo..o ooooo ooo        ooooo\n"      
          "d8P'    `Y8 `888' `88.       .888'\n"      
          "Y88bo.       888   888b     d'888\n"      
          " `\"Y8888o.   888   8 Y88. .P  888\n"      
          "     `\"Y88b  888   8  `888'   888\n"      
          "oo     .d8P  888   8    Y     888\n"      
          "8\"\"88888P'  o888o o8o        o888o\n"      
          );
   
    setColor(10);
    printf("   SPORTS INVENTORY MANAGEMENT");
    setColor(7);
    printf("\n\n");
}




int isAdmin()
{  
    setColor(14);
    printf("==== WELCOME BACK ====\n");
    printf("You are a/an ...\n");
    setColor(11);
    printf("1. Administrator\n");
    printf("2. Customer\n");
    setColor(7);
   
    int choice;
    while(1)
    {  
        printf("\nEnter your choice (1-2): ");
        scanf("%d", &choice);
        if (choice == 1 || choice == 2)
            return ((choice == 2) ? 0 : 1);
       
        setColor(4);
        printf("\nInvalid choice! Please enter 1-2.\n");
        setColor(7);
    }
   
}
// Function to trim leading/trailing spaces
void trimSpaces(char *str)
{
    int i, start = 0, end = strlen(str) - 1;
    // Trim leading spaces
    while (isspace((unsigned char)str[start])) start++;




    // Trim trailing spaces
    while (end > start && isspace((unsigned char)str[end])) end--;




    // Shift characters and add null terminator
    for (i = start; i <= end; i++) {
        str[i - start] = str[i];
    }
    str[i - start] = '\0';
}




// Function to input sport item from keyboard manually
void inputItem(SportItem items[], int *count)
{
    if (*count >= MAX_ITEMS)
    {
        setColor(4);
        printf("The inventory is full.\n");
        setColor(7);
        return;
    }




    int numOfItems;
    int continueInput = 1;
    while(continueInput)
    {
        printf("How many items do you want to add? (%d slots available): ", MAX_ITEMS - *count);
        scanf("%d", &numOfItems);




        if (numOfItems > (MAX_ITEMS - *count))
        {  
            setColor(4);
            printf("\nCannot add %d items, try again.\n\n", numOfItems);
            setColor(7);
            continue;
        }
       
        continueInput = 0;
    }




    int i;
    for (i = 0; i < numOfItems; ++i)
    {
        SportItem newItem;




        printf("Enter Item Name: ");
        scanf(" %[^\n]%*c", newItem.itemName);
        trimSpaces(newItem.itemName);




        printf("Enter Brand Name: ");
        scanf(" %[^\n]%*c", newItem.brandName);
        trimSpaces(newItem.brandName);




        printf("Enter Description: ");
        scanf(" %[^\n]%*c", newItem.description);
        trimSpaces(newItem.description);




        printf("Enter Sports Field: ");
        scanf(" %[^\n]%*c", newItem.sportsField);
        trimSpaces(newItem.sportsField);




        printf("Enter Price: ");
        scanf("%lf", &newItem.price);




        printf("Enter Gender (0: Male, 1: Female, 2: Unisex): ");
        scanf("%d", &newItem.gender);




        printf("Enter Type (0: Tools, 1: Clothes, 2: Protective Equipment): ");
        scanf("%d", &newItem.type);
       
        items[(*count)++] = newItem;
        setColor(10);
        printf("\nItem added successfully!\n\n");
        setColor(7);
    }
}




void inputItemFromFile(SportItem items[], int* count)
{
    FILE* file = fopen("items.csv", "r");
    if (!file)
    {    
        setColor(4);
        printf("\nUnable to open file.");
        setColor(7);
        return;
    }




    char currentLine[512];
    fgets(currentLine, sizeof(currentLine), file); // Read the header line (skip it)




    while (fgets(currentLine, sizeof(currentLine), file)) {
        if (*count >= MAX_ITEMS) break; // Prevent overflow




        // Use sscanf() to extract values
        sscanf(currentLine, "%49[^,],%49[^,],%499[^,],%49[^,],%lf,%d,%d",
               items[*count].itemName,
               items[*count].brandName,
               items[*count].description,
               items[*count].sportsField,
               &items[*count].price,
               &items[*count].gender,
               &items[*count].type);




        (*count)++;  // Increment item count
    }




    fclose(file); // Close the file
   
    setColor(10);
    printf("Successfully inputted items from items.csv!\n");
    setColor(7);
}




// Function to sort and display the sorted items
void sortItem(SportItem items[], int count) {
    while (1) {
        if (count == 0) {
            setColor(4);
            printf("No items available to sort.\n");
            setColor(7);
            return;
        }


        setColor(14);
        printf("\n==== SORT BY ====\n");
        setColor(11);
        printf("1. Item Name\n");
        printf("2. Brand Name\n");
        printf("3. Sports Field\n");
        printf("4. Price\n");
        printf("5. Return to Main Menu\n");
        setColor(7);


        int SortChoice;
        while (1) {
            printf("\nEnter your choice (1-5): ");
            scanf("%d", &SortChoice);
            while (getchar() != '\n');  


            if (SortChoice >= 1 && SortChoice <= 5) break;


            setColor(4);
            printf("\nInvalid choice! Please enter a number between 1 and 4.\n");
            setColor(7);
            break;
        }


        if (SortChoice == 5) return;


        if (SortChoice < 1 || SortChoice > 5) continue;


        // Sorting logic using Bubble Sort
        int i, j;
        SportItem tmp;
        for (i = 0; i < count - 1; i++) {
            for (j = count - 1; j > i; j--) {
                int cmp = 0;
                switch (SortChoice) {
                    case 1:
                        cmp = strcmp(items[j].itemName, items[j - 1].itemName);
                        break;
                    case 2:
                        cmp = strcmp(items[j].brandName, items[j - 1].brandName);
                        break;
                    case 3:
                        cmp = strcmp(items[j].sportsField, items[j - 1].sportsField);
                        break;
                    case 4:
                        if (items[j].price < items[j - 1].price) cmp = -1;
                        else if (items[j].price > items[j - 1].price) cmp = 1;
                        break;
                }
                if (cmp < 0) {
                    tmp = items[j];
                    items[j] = items[j - 1];
                    items[j - 1] = tmp;
                }
            }
        }


        // Print the sorted items after sorting
        setColor(14);
        printf("\n==== SORTED ITEMS =====\n");
        setColor(7);
        for (i = 0; i < count; i++) {
            switch (SortChoice) {
                case 1:
                    setColor(11);
                    printf("Name: %-20s ", items[i].itemName);
                    setColor(7);
                    printf("| Brand: %-15s | Field: %-15s | Price: $%.2f\n",
                           items[i].brandName, items[i].sportsField, items[i].price);
                    break;
                    case 2:
                    printf("Name: %-20s |", items[i].itemName);
                    setColor(11);
                    printf(" Brand: %-15s ", items[i].brandName);
                    setColor(7);
                    printf("| Field: %-15s | Price: $%.2f\n", items[i].sportsField, items[i].price);
                    break;
                case 3:
                    printf("Name: %-20s | Brand: %-15s |", items[i].itemName, items[i].brandName);
                    setColor(11);
                    printf(" Field: %-15s ", items[i].sportsField);
                    setColor(7);
                    printf("| Price: $%.2f\n", items[i].price);
                    break;
                case 4:
                    printf("Name: %-20s | Brand: %-15s | Field: %-15s |", items[i].itemName, items[i].brandName, items[i].sportsField);
                    setColor(11);
                    printf(" Price: $%.2f\n", items[i].price);
                    setColor(7);
                    break;
            }
        }


        printf("\nPress Enter to return to the SORT BY menu...");
        while (getchar() != '\n');
    }
}




// Function to display sport item details
void displayItem(SportItem items)
{  
    printf("%-15s : %s\n", "Item Name", items.itemName);
    printf("%-15s : %s\n", "Brand Name", items.brandName);
    printf("%-15s : %s\n", "Description", items.description);
    printf("%-15s : %s\n", "Sports Field", items.sportsField);
    printf("%-15s : $%.2f\n", "Price", items.price);
    printf("%-15s : %s\n", "Gender",
           items.gender == 0 ? "Male" : (items.gender == 1 ? "Female" : "Unisex"));
    printf("%-15s : %s\n", "Type",
           items.type == 0 ? "Tools" : (items.type == 1 ? "Clothes" : "Protective Equipment"));

    printf("\n");
}




// Function to search sport items
void searchItems(SportItem items[], int count) {
    if (count == 0) {
        setColor(4);
        printf("No items available to search.\n");
        setColor(7);
        return;
    }


    while (1) {
        int found = 0;
        char query[100];
        int searchType;


        setColor(14);
        printf("\n==== SPORT ITEM LOOKUP ====\n");
        setColor(11);
        printf("1. Search by Index\n");
        printf("2. Search by Sports Field\n");
        printf("3. Search by Item Name\n");
        printf("4. Search by Brand Name\n");
        printf("5. Return to Main Menu\n");
        setColor(7);


        printf("\nEnter your choice: ");
        scanf("%d", &searchType);
        getchar();


        if (searchType == 5) return;


        if (searchType < 1 || searchType > 4) {
            setColor(4);
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
            setColor(7);
            continue;
        }


        switch (searchType) {
            case 1:
                printf("Enter Item Index (1-%d): ", count);
                break;
            case 2:
                printf("Enter Sports Field: ");
                break;
            case 3:
                printf("Enter Item Name: ");
                break;
            case 4:
                printf("Enter Brand Name: ");
                break;
        }


        fgets(query, sizeof(query), stdin);
        query[strcspn(query, "\n")] = 0;
        trimSpaces(query);


        for (int i = 0; i < count; i++) {
            int match = 0;
            switch (searchType) {
                case 1:
                    if (i + 1 == atoi(query)) {
                        match = 1;
                    }
                    break;
                case 2:
                    if (strcasecmp(items[i].sportsField, query) == 0) {
                        match = 1;
                    }
                    break;
                case 3:
                    if (strcasecmp(items[i].itemName, query) == 0) {
                        match = 1;
                    }
                    break;
                case 4:
                    if (strcasecmp(items[i].brandName, query) == 0) {
                        match = 1;
                    }
                    break;
            }


            if (match) {
                setColor(10);
                printf("\nItem Found!\n");
                setColor(7);
                displayItem(items[i]);
                found = 1;
            }
        }


        if (!found) {
            setColor(4);
            printf("No items found!\n");
            setColor(7);
        }


        printf("\nPress Enter to return to the SPORT ITEM LOOKUP menu...");
        while (getchar() != '\n');
    }
}




void removeItem(SportItem items[], int* count)
{  
    int index = 0;
    int choice;
    int turnPageLeftAvail = 0;
    int turnPageRightAvail = 1;
    int continueInput = 1;


    do
    {  
        if (*count == 0)
        {  
            setColor(4);
            printf("No items to remove.\n");
            setColor(7);
            break;
        }


        int endIndex = 10;
        if ((index + endIndex) >= *count)
            endIndex = (*count) % 10;
       
        setColor(14);
        printf("\n==== REMOVABLE ITEMS LIST ====\n");
        setColor(11);
       
        int i;
        for (i = 0; i < 10; ++i)
        {
            if ((index + i) >= *count)
                break;


            setColor(11);
            printf("%d. %s - %s\n", i + 1, items[index + i].itemName, items[index + i].brandName);
            setColor(7);
        }


        setColor(11);
        printf("\nIf you don't want to remove any item, press '0' to return to Main Menu.\n");
        setColor(7);
        if (index == 0)
            turnPageLeftAvail = 0;
        else
        {
            turnPageLeftAvail = 1;
            printf("11. Go back\n");
        }
        if ((index + 10) > *count)
            turnPageRightAvail = 0;
        else
        {
            turnPageRightAvail = 1;
            printf("12. Next\n");
        }


        printf("Enter your choice (0-%d): ", endIndex);
        scanf("%d", &choice);


        switch(choice)
        {
        case 0:
            continueInput = 0;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            if (choice > endIndex)
            {
                setColor(4);
                printf("\nInvalid choice! Please enter a number between 1-%d.\n", endIndex);
                setColor(7);
                continue;
            }
            for (i = index + choice - 1; i < *count - 1; ++i)
                items[i] = items[i + 1];
               
            (*count)--;
            setColor(10);
            printf("\nItem removed successfully!\n");
            setColor(7);


            printf("\nPress Enter to return to the ITEMS LIST menu...");
            while (getchar() != '\n');
            getchar();  
            break;
        case 11:
            if (turnPageLeftAvail)
                index -= 10;
            break;
        case 12:
            if (turnPageRightAvail)
                index += 10;
            break;
        default:
            setColor(4);
            printf("\nInvalid choice! Please enter a number between 1-%d, 11, 12, or 0.\n", endIndex);
            setColor(7);
            break;
        }


    } while(continueInput);
}




void removeAll(SportItem items[], int* count)
{
    while (1)
    {
        if (*count == 0)
        {  
            setColor(4);
            printf("No items available to remove.\n");
            setColor(7);
            return;
        }


        int found = 0;
        int removedCount = 0;
        char query[100];
        int searchType;


        while (1)
        {  
            setColor(14);
            printf("\n==== REMOVE ALL INSTANCES BY =====\n");
            setColor(11);
            printf("1. Brand Name\n");
            printf("2. Sports Field\n");
            printf("3. Gender\n");
            printf("4. Type\n");
            printf("5. Return to Main Menu\n");
            setColor(7);


            printf("\nEnter your choice: ");
            scanf("%d", &searchType);
            while (getchar() != '\n');


            if (searchType == 5) return;


            if (searchType >= 1 && searchType <= 4)
                break;


            setColor(4);
            printf("\nInvalid choice! Please enter 1-5.\n");
            setColor(7);
        }


        switch (searchType)
        {
            case 1:
                printf("Enter Brand Name: ");
                break;
            case 2:
                printf("Enter Sports Field: ");
                break;
            case 3:
                printf("Enter Gender (0 = Male, 1 = Female, 2 = Unisex): ");
                break;
            case 4:
                printf("Enter Type (0 = Tools, 1 = Clothes, 2 = Protective Equipment): ");
                break;
            default:
                setColor(4);
                printf("Invalid search type!\n");
                setColor(7);
                return;
        }


        fgets(query, sizeof(query), stdin);
        query[strcspn(query, "\n")] = 0;
        trimSpaces(query);


        for (int i = 0; i < *count; )
        {
            int match = 0;
            switch (searchType)
            {
            case 1:
                if (strcasecmp(items[i].brandName, query) == 0)
                    match += 1;
                break;
            case 2:
                if (strcasecmp(items[i].sportsField, query) == 0)
                    match += 1;
                break;
            case 3:
                if (items[i].gender == atoi(query))
                    match += 1;
                break;
            case 4:
                if (items[i].type == atoi(query))
                    match += 1;
                break;
            }


            if (match)
            {
                for (int j = i; j < *count - 1; j++)
                    items[j] = items[j + 1];
                (*count)--;
                found = 1;
                removedCount++;
            }
            else
                i++;
        }


        if (found)
        {
            setColor(10);
            printf("\n%d items removed successfully!\n", removedCount);
            setColor(7);
        }
        else
        {
            setColor(4);
            printf("\nNo items found!\n");
            setColor(7);
        }


        printf("\nPress Enter to return to the REMOVE ALL INSTANCES BY menu...");
        while (getchar() != '\n');
    }
}




int main() {
    SportItem items[MAX_ITEMS];
    int count = 0, choice;




    printLogo();


    // Adding sample items
    items[count++] = (SportItem){"Football Kits", "Adidas", "Standard equipment and attire worn by players", "Football", 95.00, 0, 1};
    items[count++] = (SportItem){"Football Boots", "Puma", "Shoes worn when playing football", "Football", 90.00, 0, 0};
    items[count++] = (SportItem){"Goalkeeper Gloves", "Nike", "Essential gear for goalkeepers", "Football", 129.99, 0, 2};


    // 0 = Customer, 1 = Admin
    if (isAdmin())
        do
        {  
            setColor(14);
            printf("\n\n===== MAIN MENU =====\n");
            setColor(11);
            printf("1. Input Item\n");
            printf("2. Input Item from file\n");
            printf("3. Sort Item\n");
            printf("4. Search Item\n");
            printf("5. Remove an item\n");
            printf("6. Remove all instances of a value\n");
            printf("7. Exit\n");
            setColor(7);
            printf("\nEnter your choice (1-7): ");
            scanf("%d", &choice);




            switch (choice)
            {
            case 1:
                inputItem(items, &count);
                break;
            case 2:
                inputItemFromFile(items, &count);
                break;
            case 3:
                sortItem(items, count);
                break;
            case 4:
                searchItems(items, count);
                break;
            case 5:
                removeItem(items, &count);
                break;
            case 6:
                removeAll(items, &count);
                break;
            case 7:
                setColor(12);
                printf("\n---- EXITING PROGRAM ----\n");
                setColor(7);
                break;
            default:
                setColor(4);
                printf("Invalid choice! Please enter 1-7.\n");
                setColor(7);
            }
        } while (choice != 7);
   
    else
        do
        {  
            setColor(14);
            printf("\n\n===== MAIN MENU =====\n");
            setColor(11);
            printf("1. Input Item\n");
            printf("2. Input Item from file\n");
            printf("3. Sort Item\n");
            printf("4. Search Item\n");
            printf("5. Remove an item\n");
            printf("6. Exit\n");
            setColor(7);
            printf("\nEnter your choice (1-6): ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                inputItem(items, &count);
                break;
            case 2:
                inputItemFromFile(items, &count);
                break;
            case 3:
                sortItem(items, count);
                break;
            case 4:
                searchItems(items, count);
                break;
            case 5:
                removeItem(items, &count);
                break;
            case 6:
                setColor(12);
                printf("\n---- EXITING PROGRAM ----\n");
                setColor(7);
                break;
            default:
                setColor(4);
                printf("Invalid choice! Please enter 1-6.\n");
                setColor(7);
            }
        } while (choice != 6);
   


    return 0;
}

