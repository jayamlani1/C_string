/* 
 * 1249. Minimum Remove to Make Valid Parentheses
 * Your task is to remove the minimum number of parentheses
 * ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string
 */

struct stack
{
   // Because we are taking care of only one type of parantheses, I am just tracking the location of
   // of opening parantheses. 
  
    int a;
    struct stack *next;
};

struct stack* pop( struct stack *root, int *loc)
{
    *loc = root->a;
    if(root->next == NULL)
    {
       // If I reach the bottom of the stack do not send NULL
       // Make the location as -1, and this condition is used in code.
        root->a = -1;
        return root;
    }
    return root->next;
}

struct stack *push(struct stack *root, int loc)
{
    struct stack *temp = (struct stack *) malloc(sizeof(struct stack));
    // push the location of the opening bracket.
  
    temp->a = loc;
    temp->next = root;
    return temp;
}

char * minRemoveToMakeValid(char * s){

    int len = strlen(s);
    
    char *ans = (char *) malloc(sizeof(char) * (len + 1) );
    
    // Keeps track of the location eligible for printing.
    int arr[len];
    struct stack *root = (struct stack *) malloc(sizeof(struct stack));
    root->a = -1;
    root->next = NULL;
    
    for(int i=0;i<len;i++)
    {
        arr[i] = 0;
        if(s[i] == '(')
        {
          // if the opening bracket push it on the stack.
            root = push(root, i);
        }
        else if(s[i] == ')')
        {
          // if closing bracket see there is any value in the stack.
          // make the current string location and location for the opening bracket eligible for printing.
            if(root->a != -1)
            {
                int loc;
                root = pop(root, &loc);
                arr[i] = 1;
                arr[loc] = 1;
            }
        }
        else
        {
            arr[i] = 1;
        }
    }
    int j = 0;
    for(int i=0;i<len;i++)
    {
        if(arr[i] == 1)
        {
          // Only store the location eligible for printing.
            ans[j] = s[i];
            j++;
        }
    }
    ans[j] = '\0';
    return ans;
}
