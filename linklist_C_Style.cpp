#include<iostream>

struct list
{
   int data;
   struct list* next;
};

void append(struct list** ll)
{
   struct list* temp;
   temp = *ll;

   if (*ll == NULL)
   {
      temp = (struct list*)malloc(sizeof(struct list));
      *ll = temp;

   }
   else
   {
      while (temp->next != NULL)
      {
         temp = temp->next;
      }
      temp->next = (struct list*)malloc(sizeof(struct list));
      temp = temp->next;
   }

   printf("\nEnter data:");
   int num = 5;
   //scanf_s("%d", &num);
   temp->data = num;
   temp->next = NULL;
}

void display(struct list* ll)
{
   while (ll != NULL)
   {
      printf("\t%d ", ll->data);
      ll = ll->next;
   }
}

int linkedlist()
{
   struct list* ll;
   ll = NULL;
   append(&ll);
   append(&ll);
   append(&ll);
   append(&ll);

   display(ll);

   return 0;
}

 int main()
{
   std::cout << "Hello World!\n";

   linkedlist();
}