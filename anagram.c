

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void freq(int hash[26], char *s, int len)
{
    for(int i=0;i<len;i++)
    {
        hash[s[i]-'a']++;
    }
}

int compare(int hashp[26],int hashs[26])
{
    for(int i=0;i<26;i++)
    {
        if(hashp[i] !=hashs[i])
            return 0;
    }
    return 1;
}

int* findAnagrams(char * s, char * p, int* returnSize){

    int lens = strlen(s);
    int lenp = strlen(p);
    
    // This array stores the frequency of characters in smaller string 
    int hashp[26]={0};
    
    // This array stores the frequncy of character in larger string, but it only takes care od characters in the window which is of
    // of size lenp.
    int hashs[26]={0};
    int count =0;
    
    *returnSize = 0;
    int *arr =(int *) malloc(sizeof(int) * lens);
    if(lenp>lens)
        return arr;
    
    // This is initially we are setting up the both the frequency.
    freq(hashp, p, lenp);
    freq(hashs, s, lenp);
    
    // If both the arrays are same we add the index in the returning array.
    if(compare(hashp, hashs))
    {
        arr[count] = 0;
        count++;
    }
    
    for(int i=lenp;i<lens;i++)
    {
        // Each time we remove one element and add another element in the window and compare if the arrays are same.
        hashs[s[i-lenp]-'a']--;
        hashs[s[i]-'a']++;
         if(compare(hashp, hashs))
        {
            arr[count] = i-lenp+1;
            count++;
        }
    }
    *returnSize = count;
    return arr;
}
