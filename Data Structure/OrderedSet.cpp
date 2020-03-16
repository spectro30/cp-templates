#include<bits/stdc++.h>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
    ordered_set st;
    st.insert(0);
    st.insert(2);
    st.insert(4);
    cout << st.order_of_key(4) << endl;
    cout << *(st.find_by_order(1)) << endl;
    return 0;
}

