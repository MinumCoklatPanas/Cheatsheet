#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <bits/stdc++.h>

using namespace std;

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>,
rb_tree_tag,tree_order_statistics_node_update>
ordered_set;
gp_hash_table<int,int> gp;
