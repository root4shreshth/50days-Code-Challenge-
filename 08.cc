#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> res(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    stack<int> st;

    for (int i = n - 1; i >= 0; --i)
    {

        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        res[i] = st.empty() ? -1 : st.top();

        st.push(arr[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
