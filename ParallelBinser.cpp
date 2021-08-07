while (change)
    {
        change = 0;
        reset();
       for (int i = 1 ; i <= k ; i++)
        {
            if (meteors[i].l <= meteors[i].r)
            {
                update(meteors[i].l,meteors[i].val);
                update(meteors[i].r + 1,-meteors[i].val);
            }
            else
            {
                update(meteors[i].l,meteors[i].val);
                update(1,meteors[i].val);
                update(meteors[i].r + 1,-meteors[i].val);
            }
            while (!mids[i].empty())
            {
                int ix = mids[i].front();
                mids[i].pop();
                ll sum = 0;
                for (int j = 0 ; j < punya[ix].size() ; j++)
                {
                    sum += query(punya[ix][j]);
                    if (sum >= target[ix]) break;
                }
                if (sum < target[ix])
                    lo[ix] = mid[ix] + 1;
                else
                {
                    hi[ix] = mid[ix] - 1;
                    ans[ix] = mid[ix];
                }
                if (lo[ix] <= hi[ix])
                {
                    change = 1;
                    mid[ix] = (lo[ix] + hi[ix]) >> 1;
                    mids[mid[ix]].push(ix);
                }
            }
        }
    }
