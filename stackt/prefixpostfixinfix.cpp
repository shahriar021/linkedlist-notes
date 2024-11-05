

#include<bits/stdc++.h>
using namespace std;


int prefix(string x){

    stack<int>st;
    int n=x.length();
    for(int i=n-1;i>=0;i--){
        if(x[i]>='0'&&x[i]<='9'){
            st.push(x[i]-'0');
        }else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch(x[i]){
                case '+':
                    st.push(op1+op2);
                    break;

                case '-':
                    st.push(op1-op2);
                    break;

                case '*':
                    st.push(op1*op2);
                    break;

                case '/':
                    st.push(op1/op2);
                    break;            

                default:
                    return -1;    
            }
        }
    }


    return st.empty()?-1:st.top();

}

int postfix(string x){

    stack<int>st;
    int n=x.length();

    for(int i=0;i<n;i++){
        if(x[i]>='0'&&x[i]<='9'){
            st.push(x[i]-'0');
        }else{
            int o1=st.top();
            st.pop();
            int o2=st.top();
            st.pop();
            switch(x[i])
                {case '+':
                    st.push(o2+o1);
                    break;

                case '-':
                    st.push(o2-o1);
                    break;

                case '*':
                    st.push(o2*o1);
                    break;    

                case '/':
                    st.push(o2/o1);
                    break;    

                default:
                    return -1; }       
        }
    }

    return st.empty()?-1:st.top();

}

int main(){

    stack<int>st;


    // cout<<prefix("-+7*45+20")<<endl;
    cout<<postfix("563/-")<<endl;
    return 0;


}