struct node
{
    node *child[35] = { NULL };
    int cnt = 0;
    bool akhir = 0;
};

void insert(node *root,string word)
{
    node *tmp = root;
    for (int i = 0 ; i < word.size() ; i++)
    {
        int ix = word[i] - 'a' + 1;
        if (tmp -> child[ix] == NULL)
            tmp -> child[ix] = new node;
        tmp = tmp -> child[ix];
        (tmp -> cnt)++;
    }
    tmp -> akhir = true;
}
