int strStr(char * haystack, char * needle){

    int lena = strlen(haystack);
    int lenb = strlen(needle);
    
    if(lenb == 0)
        return 0;
    
    if(lena<lenb)
        return -1;
    
    
    int found =0;
    for(int i=0;i<=lena-lenb;i++)
    {
        
        if(haystack[i]==needle[0])
        {
            found =1;
            for(int j=1;j<lenb;j++)
            {
                if( ( (i+j)>=lena ) || (haystack[i+j] != needle[j]) )
                {
                    found = 0;
                    break;
                }
            }
            if(found==1)
                return i;
        }
    }
    
    return -1;
}
