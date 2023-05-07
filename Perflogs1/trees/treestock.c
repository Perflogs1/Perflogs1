#include<stdio.h>

#include<malloc.h>

#include<string.h>

#include<conio.h>

#include<time.h>

struct node {
  int code;
  char name[55];
  int price;
  int stock;
  int dayr;
  int monthr;
  int yearr;
  int daye;
  int monthe;
  int yeare;
  struct node * left;
  struct node * right;
};

int currDay;
int currMonth;
int currYear;
int tempDay;
int tempMonth;
int tempYear;

// str.cpy
struct node * createNode(int code, char name[], int price, int stock, int dayr, int monthr, int yearr, int daye, int monthe, int yeare) {
  struct node * n;
  n = (struct node * ) malloc(sizeof(struct node));
  n -> code = code;
  strcpy(n -> name, name);
  n -> price = price;
  n -> stock = stock;
  n -> dayr = dayr;
  n -> monthr = monthr;
  n -> yearr = yearr;
  n -> daye = daye;
  n -> monthe = monthe;
  n -> yeare = yeare;
  n -> left = NULL;
  n -> right = NULL;
  return n;
}
// struct node* insert(struct node* root, int code, char name[], int
//price, int stock, char date[], char expiry[]) {
  // if(root == NULL){
  // root = createNode(code, name, price, stock, date, expiry);
  // return root;
  // }
  // else if(code <= root->code){
  // root->left = insert(root->left, code, name, price, stock,
  
// }
// else{
// root->right = insert(root->right, code, name, price, stock,
//date, expiry);
// }
// return root;
// }
struct node * insertName(struct node * root, int code, char name[], int price, int stock, int dayr, int monthr, int yearr, int daye, int monthe,
  int yeare) {
  if (root == NULL) {
    root = createNode(code, name, price, stock, dayr, monthr, yearr,
      daye, monthe, yeare);
    return root;
  }
  int result = strcmp(name, root -> name);
  // printf("%s and %s result is %d: \n", name, root->name, result);
  if (result <= 0) {

    root -> left = insertName(root -> left, code, name, price, stock,
      dayr, monthr, yearr, daye, monthe, yeare);
  } else {
    root -> right = insertName(root -> right, code, name, price, stock,
      dayr, monthr, yearr, daye, monthe, yeare);
  }
  return root;
}
struct node * search(struct node * root, int key) {
  if (root == NULL) {
    return NULL;
  }
  if (key == root -> code) {
    return root;
  } else if (key < root -> code) {
    return search(root -> left, key);
  } else {
    return search(root -> right, key);
  }
}
void inorder(struct node * root) {
  if (root != NULL) {
    inorder(root -> left);
    printf("%d ", root -> code);
    printf("%s ", root -> name);
    inorder(root -> right);
  }
}
int isLeapYear(int year) {
  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
    return 1;
  } else {
    return 0;
  }
}
int isValidDate(int day, int month, int year) {
  if (month < 1 || month > 12) {
    return 0;
  }
  if (day < 1 || day > 31) {
    return 0;

  }
  if (year > currYear) {
    return 0;
  }
  if (year == currYear && month > currMonth) {
    return 0;
  }
  if (month == currMonth && year == currYear && day > currDay) {
    return 0;
  }
  if (month == 2) {
    if (isLeapYear(year) && day <= 29) {
      return 1;
    } else if (!isLeapYear(year) && day <= 28) {
      return 1;
    } else {
      return 0;
    }
  }
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day <=
    30) {
    return 1;
  }
  if ((month == 1 || month == 3 || month == 5 || month == 7 || month ==
      8 || month == 10 || month == 12) && day <= 31) {
    return 1;
  }
  return 0;
}
int checkExpiry(int day, int month, int year) {
  if (year < tempYear) {
    return 0;
  }
  if (year == tempYear && month < tempMonth) {
    return 0;
  }
  if (month == tempMonth && year == tempYear && day < tempDay) {
    return 0;
  }
  return 1;
}
int main() {
  struct node * root;
  root = NULL;
  int input = 0;
  time_t t;

  t = time(NULL);
  struct tm tm = * localtime( & t);
  printf("Current Date: %d-%d-%d \n", tm.tm_mday, tm.tm_mon + 1,
    tm.tm_year + 1900);
  currDay = tm.tm_mday;
  currMonth = tm.tm_mon + 1;
  currYear = tm.tm_year + 1900;
  while (input != -1) {
    printf("Enter '1' for Adding Item\n");
    printf("Enter '2' for Searching Item\n");
    printf("Enter '3' for Lexicographic Order\n");
    printf("Enter Your Input: \n");
    scanf("%d", & input);
    if (input == 1) {
      int code;
      char name[1000];
      int price;
      int stock;
      int dayr;

      int monthr;
      int yearr;
      int daye;
      int monthe;
      int yeare;

      printf("Enter the Code:\n");
      scanf("%d", & code);
      // while(temp != 1){
      // printf("Invalid code.. Re-Enter the code: \n");
      // // scanf("%d", &code);
      // scanf("%c", (int *) stdin);
      // fgets(code,1000,stdin);
      // }
      // while(scanf("%d", &code) != 1){
      // printf("Invalid code.. Re-Enter the code: \n");
      // scanf("%d", &code);
      // }
      // if(scanf("%d", &code) != 1){
      // goto reEnter;
      // }
      // reEnter:
      // printf("Enter the code again: \n");
      // scanf("%d", &code);
      // scanf("%d", &code);
      printf("Enter the name:\n");
      // scanf("%s", &name);
      scanf("%c", (char * ) stdin);
      fgets(name, 1000, stdin);
      printf("Enter the price:\n");
      scanf("%d", & price);
      printf("Enter the stock:\n");
      scanf("%d", & stock);
      while (stock < 0) {
        printf("Stock cannot be less than zero.. Re-Enter: \n");
        scanf("%d", & stock);
      }
      printf("Enter the Date Received (dd-mm-yyyy):\n");

      scanf("%d-%d-%d", & dayr, & monthr, & yearr);
      tempDay = dayr;
      tempMonth = monthr;
      tempYear = yearr;
      while (!isValidDate(dayr, monthr, yearr)) {
        printf("The date is invalid\n");
        printf("Re-Enter the Date Received (dd-mm-yyyy):\n");
        scanf("%d-%d-%d", & dayr, & monthr, & yearr);
      }
      printf("Enter the expiry date (dd-mm-yyyy):\n");
      scanf("%d-%d-%d", & daye, & monthe, & yeare);
      // !checkExpiry(daye, monthe, yeare)
      // int validdate = isValidDate(daye, monthe, yeare);
      while (!isValidDate(daye, monthe, yeare)) {
        printf("The Expiry date is invalid\n");
        printf("Re-Enter the expiry date (dd-mm-yyyy):\n");
        scanf("%d-%d-%d", & daye, & monthe, & yeare);
      }
      while (!checkExpiry(daye, monthe, yeare)) {
        printf("The Expiry date is invalid\n");
        printf("Re-Enter the expiry date (dd-mm-yyyy):\n");
        scanf("%d-%d-%d", & daye, & monthe, & yeare);
      }
      root = insertName(root, code, name, price, stock, dayr,

        monthr, yearr, daye, monthe, yeare);

    } else if (input == 2) {
      int key;
      printf("Enter the Code of Item to be searched: \n");
      scanf("%d", & key);
      struct node * temp = search(root, key);
      if (temp != NULL) {
        printf("Code: %d\n", temp -> code);
        printf("Name: %s\n", temp -> name);
        printf("Price: %d\n", temp -> price);
        printf("Stock: %d\n", temp -> stock);
        printf("Date Received: %d-%d-%d\n", temp -> dayr, temp ->monthr, temp -> yearr);

          
          

        printf("Expiry Date: %d-%d-%d\n", temp -> daye, temp ->monthe, temp -> yeare);

          
          

      } else {
        printf("Not Found.");
      }
    } else if (input == 3) {
      printf("The lexicographic order is: \n");
      inorder(root);

      printf("\n");
    }
  }
  // root = insertName(root, 20, "dhruv", 11, 1, "a", "a");
  // root = insertName(root, 25, "om", 11, 1, "a", "a");
  // root = insertName(root, 10, "prathamesh", 11, 1, "a", "a");
  // root = insertName(root, 8, "divyanshu", 11, 1, "a", "a");
  // root = insertName(root, 12, "a", 11, 1, "a", "a");
  inorder(root);
}