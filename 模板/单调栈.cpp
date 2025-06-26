for(int i = 1; i <= n ;i ++){
    while(!st.empty() && a[st.top()] > a[i]){
        st.pop();
    }
    st.push(i);
}