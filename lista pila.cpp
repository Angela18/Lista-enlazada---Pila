#include<iostream>
using namespace std;

template<typename T>
class Nodo{
private:
    T dato;
    Nodo<T> *next;
public:
    Nodo(T);
    ~Nodo();
};

template<typename T>
Nodo<T>::Nodo(T _dato){
    dato = _dato;
    next = nullptr;
}

template<typename T>
Nodo<T>::~Nodo(){
}

template<typename T>
class Pila{
    Nodo<T> *inicio;
public:
    Pila();
    void push(); //apila
    void pop(); //desapilar
    void show(); //mostrar
    void top(); //tope
    void tam(); //tamaño de pila
};

template<typename T>
Pila<T>::Pila(){
    inicio = nullptr;
}

template<typename T>
void Pila<T>::push(){
    int valor;
    Nodo<T> *aux = new Nodo<T>(valor);
    cout<<"Ingresa un valor: ";
    cin>>valor;
    aux->dato = valor;
    aux->next = nullptr;
    if(inicio != nullptr)
        aux->next=inicio;
    inicio=aux;
    cout<<"Nuevo valor insertado en  la pila!\n";
}

template<typename T>
void Pila<T>::pop(){
    Nodo<T> *temp;
    if(inicio == nullptr){
        cout<<"\nLa pila esta vacia! \n\n";
    }
    else{
        temp = inicio;
        inicio = inicio->next;
        cout<<"\El valor eliminado es: "<<temp->dato<<"\n"<<endl;
        delete temp;
    }
}

template<typename T>
void Pila<T>::show(){
    Nodo<T> *aux1 = inicio;
    if(inicio == nullptr){
        cout<<"\nLa pila esta vacia!\n\n";
    }
    else{
        cout<<"Pila:\n"<<endl;
        while(aux1 != nullptr){
            cout<<aux1->dato<<"\n"<<endl;
            aux1 = aux1->next;
        }
    }
}

template<typename T>
void Pila<T>::top(){
    Nodo<T> *aux1 = inicio;
    if(inicio == nullptr){
        cout<<"\nLa pila esta vacia!\n\n";
    }
    else{
        cout<<"Valor TOP:\n"<<endl;
        cout<<aux1->dato<<"\n"<<endl;
    }
}

template<typename T>
void Pila<T>::tam(){
    Nodo<T> *aux1 = inicio;
    if(inicio == nullptr){
        cout<<"\nLa pila esta vacia!\n\n";
    }
    else{
        int cont = 0;
        while(aux1){
            cont++;
            aux1 = aux1->next;
        }
        cout<<"El tamaño de la pila es: "<<cont<<"\n"<<endl;
    }
}

int main(){
    Pila<int> pila;
    int opcion;
    while(1){
        cout<<"---- Pila en lista enlazada ----"<<endl;
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Show"<<endl;
        cout<<"4.Top"<<endl;
        cout<<"5.Tamaño"<<endl;
        cout<<"6.Salir"<<endl;
        cout<<"\nIngresa tu opcion: ";
        cin>>opcion;
        switch(opcion){
        case 1:
            pila.push();
            break;
        case 2:
            pila.pop();
            break;
        case 3:
            pila.show();
            break;
        case 4:
            pila.top();
            break;
        case 5:
            pila.tam();
            break;
        case 6:
            return 0;
            break;
        default:
            cout<<"Por favor ingrese una opcion correcta.\n";
            break;
        }
    }
    return 0;
}
