

int expressiveWords(char * s, char ** words, int wordsSize){
    int count =0;
    int i=0; // this will be the index in strings which are part of words.
    int j =0; // this is the index in string s
    int n = strlen(s);
    for(int k=0;k<wordsSize;k++)
    {
        if(strlen(words[k]) <=  n)
        {
            for(i=0,j=0;j<n;j++)
            {
                if(s[j] == words[k][i])
                    i++;
                else if(j>0 && j<n-1 && (s[j-1] == s[j]) && (s[j] == s[j+1]) )
                {
                    j++; // incrementing j twice in this particular loop because we reached second instance of the same character and have also made sure that
                         // that the third instance is the right one
                }
                else if(!(j>1 && s[j]==s[j-1] &&s[j] ==s[j-2]))
                {
                    // compare that this is the fourth instance of the same character and in this case just increment the main counter for string s.
                    break;
                }
            }
            if(i==strlen(words[k]) && j==n )
                count++;
        }
    }
    
    return count;
}
