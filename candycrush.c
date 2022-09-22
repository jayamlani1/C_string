#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack
{
int count;
char value;
struct stack *next;
}st;

st *push(char a, int b, st *root)
{
	st *temp = (st *) malloc(sizeof(st));
	temp->value = a;
	temp->count = b;
	temp->next = root;
	return temp;
}

st * pop(st * root)
{
	return root->next;
}


int main()
{
	char *input  = (char *) malloc(sizeof(char) *100);
	int len;
	// accept the string
	printf("Enter The string : ");
	scanf("%s", input);

	if(input == NULL)
		return 0;

	len = strlen(input);

	st *root = (st *) malloc(sizeof(st));

	// Start of the stack, just to mark as end

	root->value = '$';
	root->count = 0;	
	root->next = NULL;

	
	for(int i=len-1;i>=0;i--)
	{

    // if the top value in the stack is same as the current string value and the count stored in the stack is 2.
    // We have reached the threshold of three and now we can remove all the common elements.
		if(root->value == input[i] && root->count == 2)
		{
			while(root->value == input[i])
				i--;
			i++;
      // Remember to pop out two top elements as now top element is with count 2 and second from top is with count 1.
			root = pop(root);
			root = pop(root);		
		}
		else if(root->value == input[i])
		{
      // The character is repeated twice now, so add the element to the stack with count 2
			root = push( input[i] , 2, root); 
		}
		else
    {
       // the character has arrived only once so add the count as one.
			root = push(input[i], 1, root);
    }
	}

  // the reason we went from end of the string to beginning is that we wanted it to be easy to print the stack elents.
  // because the stack would work from top to botton or the last element added will be removed the first.
  
	while(root->value !='$')
	{
		//int locl = root->count;
		char cmp = root->value;
		printf("%c", cmp);
		root = pop(root);
	}

}
