#include <iostream>
#include <stack>
#include <list>

#include <vector>

using namespace std;

class Compare{
public:
    bool operator()(const stack<int> & L1, const stack<int> & L2){
        return L1.empty() ? true : L2.empty() ? false : L1.top() < L2.top();
    }
};

void Borrar(list<stack<int>> & L, int elemento){

    list<stack<int>>::iterator it = L.begin();
    while( it != L.end()){
        if(!it->empty())
            if(it->top() == elemento)
                it->pop();
        if(it->empty())
            it = L.erase(it);
        else
            ++it;
    }

    L.sort(Compare());
}

int main() {

    vector<vector<int>> entrada = {{2,9,1},
                           {2,1,0},
                           {2},
                           {3,9,10,7},
                           {4,2},
                           {8,2}};
    list<stack<int>> L;

    for(int i = 0; i < entrada.size(); ++i){
        L.emplace_back();
        cout << "Pila " << i << ": ";
        for(vector<int>::reverse_iterator it = entrada[i].rbegin(); it !=  entrada[i].rend(); ++it){
            L.back().push(*it);
            cout << L.back().top() << " ";
        }
        cout << endl;
    }

    cout << endl << "Borrando y ordenando..." << endl;
    Borrar(L,2);

    int i = 0;
    for(list<stack<int>>::iterator it = L.begin(); it != L.end(); ++it, ++i){
        cout << "Pila " << i << ": ";
        while(!it->empty()){
            cout << it->top() << " ";
            it->pop();
        }
        cout << endl;
    }

    return 0;
}