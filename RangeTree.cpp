
struct query{
	ll ask;
	ll x1;
	ll y1;
	ll x2=INF;
	ll y2=INF;
};

vector<ll> awal;
query tab[100010];
vector<ll> tree[400010];

void ins(ll node,ll l,ll r,ll x,ll y)
{
	vector<ll>::iterator it=upper_bound(tree[node].begin(),tree[node].end(),y);
	it=tree[node].insert(it,y);
	if (l==r) return;
	ll child=node<<1;
	ll mid=(l + r)>>1;
	(x>awal[mid] ? ins(child|1,mid+1,r,x,y) : ins(child,l,mid,x,y));
}

void hapus(ll node,ll l,ll r,ll x,ll y)
{
	tree[node].erase(lower_bound(tree[node].begin(),tree[node].end(),y));
	if (l==r) return;
	ll child=node<<1;
	ll mid=(l + r)>>1;
	(x>awal[mid] ? hapus(child|1,mid+1,r,x,y) : hapus(child,l,mid,x,y));
}

ll Get(ll node,ll nodeL,ll nodeR,ll x1,ll y1,ll x2,ll y2)
{
	if (x1>awal[nodeR] || x2<awal[nodeL]) return 0;
	if (x1<=awal[nodeL] && awal[nodeR]<=x2)
	{
		return ((upper_bound(tree[node].begin(),tree[node].end(),y2))-(lower_bound(tree[node].begin(),tree[node].end(),y1)));
	}
	ll child=node<<1;
	ll mid=(nodeL + nodeR)>>1;
	ll res=0;
	res=Get(child,nodeL,mid,x1,y1,x2,y2)+Get(child|1,mid+1,nodeR,x1,y1,x2,y2);
	return res;
}
