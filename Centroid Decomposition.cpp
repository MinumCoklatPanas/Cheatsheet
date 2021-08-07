const int N = 100005;
 
vector<int> seen; // record each vertice visited in current decomposition
int size[N]; // size of subtree 
int worst[N]; // size of heaviest subtree when this vertice is taken as root
bool taken[N]; // flag for already taken vertice, effectively blocking from other tree
vector<int> adj[N]; // adjacency in tree
int parent[N]; // parent in centroid tree
 
void dfs(int now,int prv) {
  worst[now] = 0;
  size[now] = 1;
  seen.push_back(now);
  for(int nex : adj[now]) {
    if(nex == prv || taken[nex]) continue;
    dfs(nex,now);
    worst[now] = max(worst[now],size[nex]);
    size[now] += size[nex];
  }
}
 
// prv is centroid from previous step, which created this tree
void makeCentroidTree(int now,int prv) {
  seen.clear();
  dfs(now,0);
  int root = now;
  int best = worst[now];
  
  // find centroid
  for(int inside : seen) {
    worst[inside] = max(worst[inside],size[now] - size[inside]);
    if(worst[inside] < best) {
      best = worst[inside];
      root = inside;
    }
  }
  
  parent[root] = prv;
  taken[root] = 1;
  
  // make centroid for newly created tree from separation
  for(int nex : adj[root]) {
    if(!taken[nex]) {
      makeCentroidTree(nex,root);
    }
  }
}
 
void traverse(int now) {
  int cur = now;
  while(cur) {
    // notice that in original tree, every descendant of cur except the descendant of now's ancestor which is child of cur
    // have LCA which is cur
    // we can use that property to solve problems like QTREE5
    
    cur = parent[cur];
  }
}
