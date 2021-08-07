struct node
{
    ll l;
    ll r;
    ll val;
    bool flag;
};

vector< node > tree;

void update(ll TreeIdx,ll nodeL,ll nodeR,ll queryL,ll queryR)
{
    if (queryL > nodeR || queryR < nodeL) return;
    // cout << nodeL << " " << nodeR << endl;
    if (tree[TreeIdx].flag) return;
    if (queryL <= nodeL && nodeR <= queryR)
    {
        tree[TreeIdx].val = nodeR - nodeL + 1;
        tree[TreeIdx].flag = 1;
        return;
    }
    ll mid = (nodeL + nodeR) >> 1;
    if (tree[TreeIdx].l == -1)
    {
        if (!tree[TreeIdx].flag)
        {
            tree[TreeIdx].l = tree.size();
            tree.push_back((node){-1,-1,0,0});
            tree[TreeIdx].r = tree.size();
            tree.push_back((node){-1,-1,0,0});
        }
        else
        {
            tree[TreeIdx].l = tree.size();
            tree.push_back((node){-1,-1,mid - nodeL + 1,1});
            tree[TreeIdx].r = tree.size();
            tree.push_back((node){-1,-1,nodeR - mid,1});
        }
    }
    else
    if (tree[TreeIdx].flag)
    {
        tree[tree[TreeIdx].l].val = mid - nodeL + 1;
        tree[tree[TreeIdx].l].flag = 1;
        tree[tree[TreeIdx].r].val = nodeR - mid;
        tree[tree[TreeIdx].r].flag = 1;
    }
    if (queryL <= mid) update(tree[TreeIdx].l,nodeL,mid,queryL,queryR);
    if (queryR > mid) update(tree[TreeIdx].r,mid + 1,nodeR,queryL,queryR);
    tree[TreeIdx].val = tree[tree[TreeIdx].l].val + tree[tree[TreeIdx].r].val;
}

ll query(ll TreeIdx,ll nodeL,ll nodeR,ll queryL,ll queryR)
{
    if (queryL > nodeR || queryR < nodeL) return 0;
    if (tree[TreeIdx].val == 0) return 0;
    if (tree[TreeIdx].flag)
    {
        return queryR - queryL + 1;
    }
    ll mid = (nodeL + nodeR) >> 1;
    if (tree[TreeIdx].l == -1)
    {
        if (!tree[TreeIdx].flag)
        {
            tree[TreeIdx].l = tree.size();
            tree.push_back((node){-1,-1,0,0});
            tree[TreeIdx].r = tree.size();
            tree.push_back((node){-1,-1,0,0});
        }
        else
        {
            tree[TreeIdx].l = tree.size();
            tree.push_back((node){-1,-1,mid - nodeL + 1,1});
            tree[TreeIdx].r = tree.size();
            tree.push_back((node){-1,-1,nodeR - mid,1});
        }
    }
    else
    if (tree[TreeIdx].flag)
    {
        tree[tree[TreeIdx].l].val = mid - nodeL + 1;
        tree[tree[TreeIdx].l].flag = 1;
        tree[tree[TreeIdx].r].val = nodeR - mid;
        tree[tree[TreeIdx].r].flag = 1;
    }
    ll ans = 0ll;
    if (queryL <= mid) ans += query(tree[TreeIdx].l,nodeL,mid,queryL,min(mid,queryR));
    if (queryR > mid) ans += query(tree[TreeIdx].r,mid + 1,nodeR,max(mid + 1,queryL),queryR);
    return ans;
}
