bool hasword(int n, int m, int i, int j, int *visited, char **board, char *word,  int len)
{
    if(word[len] == '\0')
        return true;
    
    if(i<0 || j<0 || i>=m || j>=n)
        return false;
    
    bool ispossible = false;
    
    if(visited[(i*n) +j]==0 && word[len] ==board[i][j])
    {
        visited[(i*n) +j]=1;
        ispossible = hasword(n, m, i+1, j, visited, board, word, len+1) ||
            hasword(n, m, i-1, j, visited, board, word, len+1) ||
            hasword(n, m, i, j+1, visited, board, word, len+1) ||
            hasword(n, m, i, j-1, visited, board, word, len+1);
    
        if(ispossible == false)
        {
            visited[(i*n)+j] = 0;
        }
       
    }
    
    return ispossible;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){

    int m = boardSize; 
	int n = *boardColSize;
   
    
    if(n<1 || m<1 || word ==NULL)
    {
        return false;
    }
    /*int *visited;
    visited = (int *)malloc(sizeof(int) * m * n);
    memset(visited, 0, m*n);
    */
    
    int visited[m][n];
   for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            visited[i][j] = 0;
        }
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            // Here we are trying to find the word from the first character.
            // That is why length of the word traversed so far which is the                 
            // last parameter is sent as zero.
            
            if(hasword(n, m, i, j, visited, board, word, 0))
                return true;
        }
    }
    return false;
    
}
