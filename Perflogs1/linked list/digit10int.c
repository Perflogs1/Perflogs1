#include <stdio.h>

#include <stdlib.h>

struct node {
  int data;
  struct node * next;
};
// To Create a Linked List
struct node * createLL(struct node * head, int data) {
  head = (struct node * ) malloc(sizeof(struct node));
  head -> data = data;
  head -> next = NULL;
  return head;
}
// To Insert a Node at begining
struct node * insertNode(struct node * head, int data) {
  struct node * ptr = (struct node * ) malloc(sizeof(struct node));
  if (head == NULL) {
    return createLL(head, data);
  } else {
    ptr -> data = data;
    ptr -> next = head;
  }
  return ptr;
}
// to insert a node at last
struct node * insertNodeLast(struct node * head, int data) {
  struct node * tempNode = head;
  struct node * ptr = (struct node * ) malloc(sizeof(struct node));
  if (head == NULL) {
    return createLL(head, data);
  } else {
    while (tempNode -> next != NULL) {
      tempNode = tempNode -> next;
    }
    ptr -> data = data;
    ptr -> next = NULL;
    tempNode -> next = ptr;
  }
  return head;
}
// to traverse the Linked List
void linkedListTraversal(struct node * ptr) {
  int i = 0;
  while (ptr != NULL) {
    printf("%d", ptr -> data);
    ptr = ptr -> next;
    i++;
  }
  printf("\n");
}
// to traverse and print the address
void linkedListTraversalAdd(struct node * ptr) {
  int i = 0;
  while (ptr != NULL) {
    printf("%d ", ptr -> data);
    printf("Address is %p", ptr);
    ptr = ptr -> next;
    i++;

  }
  printf("\n");
}
struct node * reverse(struct node * node) {
  if (node == NULL || node -> next == NULL) {
    return node;
  }
  struct node * temp = reverse(node -> next);
  node -> next -> next = node;
  node -> next = NULL;
  return temp;
}
// Add the two Linked List
struct node * addLL(struct node * l1, struct node * l2) {
  struct node * l3 = NULL;
  int carry = 0;
  while (l1 != NULL || l2 != NULL || carry != 0) {
    int val1 = 0;
    int val2 = 0;
    if (l1 != NULL)
      val1 = l1 -> data;
    if (l2 != NULL)
      val2 = l2 -> data;
    int sum = val1 + val2 + carry;
    int digit = sum % 10;
    l3 = insertNode(l3, digit);
    carry = sum / 10;
    if (l1 != NULL) {
      l1 = l1 -> next;
    }
    if (l2 != NULL) {
      l2 = l2 -> next;
    }
  }
  return l3;
}
struct node * substractLL(struct node * l1, struct node * l2) {
  if (l2 == NULL) {
    return l1;
  }
  if (l1 == NULL) {
    l2 -> data = -l2 -> data;
    return l2;
  }
  struct node * head = (struct node * ) malloc(sizeof(struct node));
  head -> data = -1;
  head -> next = NULL;
  struct node * itr = head;
  struct node * c1 = l1;
  struct node * c2 = l2;
  int carry = 0;
  while (c1 != NULL) {
    int diff = carry + c1 -> data - (c2 != NULL ? c2 -> data : 0);
    if (diff < 0) {
      carry = -1;
      diff += 10;
    } else {
      carry = 0;
    }
    struct node * temp = (struct node * ) malloc(sizeof(struct node));
    temp -> data = diff;
    temp -> next = NULL;
    itr -> next = temp;
    itr = itr -> next;
    c1 = c1 -> next;
    if (c2 != NULL) {
      c2 = c2 -> next;
    }
  }
  return reverse(head -> next);
}
struct node * multipleTwoLL(struct node * l1, struct node * l2) {
  int num1 = 0, num2 = 0;
  while (l1 || l2) {
    if (l1) {
      num1 = num1 * 10 + l1 -> data;
      l1 = l1 -> next;
    }
    if (l2) {
      num2 = num2 * 10 + l2 -> data;
      l2 = l2 -> next;
    }
  }
  int result = num1 * num2;
  struct node * l3 = NULL;

  while (result) {
    l3 = insertNode(l3, result % 10);
    result = result / 10;
  }
  return l3;
}

// multiplication proper code
struct node * multiplyLLWithDigit(struct node * head, int dig) {
  struct node * dummy = (struct node * ) malloc(sizeof(struct node));
  dummy -> data = -1;
  dummy -> next = NULL;
  struct node * ac = dummy;
  struct node * curr = head;
  int carry = 0;
  while (curr != NULL || carry != 0) {
    int sum = carry + (curr != NULL ? curr -> data * dig : 0);
    int digit = sum % 10;
    carry = sum / 10;
    // struct node *dummy2 = (struct node *)malloc(sizeof(struct node));
    // dummy2->data = digit;
    // dummy2->next = NULL;
    // ac->next = dummy2;
    ac = insertNodeLast(ac, digit);
    if (curr != NULL) {
      curr = curr -> next;
    }
    ac = ac -> next;
  }
  return dummy -> next;
}
void addTwoLinkedList(struct node * head, struct node * ansItr) {
  struct node * c1 = head;
  struct node * c2 = ansItr;
  int carry = 0;
  while (c1 != NULL || carry != 0) {
    int sum = carry + (c1 != NULL ? c1 -> data : 0) + (c2 -> next != NULL ? c2 -> next -> data : 0);
    int digit = sum % 10;
    carry = sum / 10;
    if (c2 -> next != NULL) {
      c2 -> next -> data = digit;
    } else {
      // struct node *dummy2 = (struct node *)malloc(sizeof(struct node));
      // dummy2->data = digit;
      // dummy2->next = NULL;
      // c2->next = dummy2;
      c2 = insertNodeLast(c2, digit);
    }
    if (c1 != NULL) {
      c1 = c1 -> next;
    }
    c2 = c2 -> next;
  }
}
struct node * multiplyTwoLLProper(struct node * l1, struct node * l2) {
  // l1 = reverse(l1);
  // l2 = reverse(l2);
  struct node * l2_Itr = l2;
  struct node * dummy = (struct node * ) malloc(sizeof(struct node));
  dummy -> data = -1;
  dummy -> next = NULL;
  struct node * ansItr = dummy;
  while (l2_Itr != NULL) {
    struct node * prod = multiplyLLWithDigit(l1, l2_Itr -> data);
    l2_Itr = l2_Itr -> next;
    addTwoLinkedList(prod, ansItr);
    ansItr = ansItr -> next;
  }
  return reverse(dummy -> next);
}

int main() {
  struct node * head1 = NULL;
  struct node * head2 = NULL;
  printf("Enter the First Number: \n");
  int num1;
  scanf("%d", & num1);
  while (num1 != 0) {
    int r = num1 % 10;
    num1 = num1 / 10;
    head1 = insertNodeLast(head1, r);
  }
  printf("My 1st Number is:\n");
  linkedListTraversal(head1);
  linkedListTraversalAdd(head1);

  // printf("Enter the Size of Linked List 2: \n");
  // int userSize2;
  // scanf("%d", &userSize2);
  // for (int i = 0; i < userSize2; i++)
  // {
  // int index = i + 1;
  // printf("Enter the %d Node Value:\n", index);
  // int tempNodeValue;
  // scanf("%d", &tempNodeValue);
  // head2 = insertNode(head2, tempNodeValue);
  // }
  printf("Enter the Second Number: \n");
  int num2;
  scanf("%d", & num2);
  while (num2 != 0) {
    int r = num2 % 10;
    num2 = num2 / 10;
    head2 = insertNodeLast(head2, r);
  }
  printf("My 2nd Number is:\n");
  linkedListTraversal(head2);
  linkedListTraversalAdd(head2);
  printf("Addition is: \n");
  struct node * additionLL = addLL(head1, head2);
  linkedListTraversal(additionLL);
  printf("Substraction is: \n");
  struct node * subLL = substractLL(head1, head2);
  linkedListTraversal(subLL);
  printf("Multiplication is: \n");
  struct node * multiplyLL = multipleTwoLL(reverse(head1), reverse(head2));
  linkedListTraversal(multiplyLL);
}