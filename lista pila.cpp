#include<iostream>
#define NULL 0
using namespace std;

template<typename T>
class Nodo{
public:
    T dato;
    Nodo<T> *next;

    Nodo(T);
    ~Nodo();
};

template<typename T>
Nodo<T>::Nodo(T _dato){
    dato = _dato;
    next = NULL;
}

template<typename T>
Nodo<T>::~Nodo(){
}
///CLASE PILA
template<typename T>
class Pila{
    Nodo<T> *inicio;
public:
    Pila();
    void push();
    void pop();
    void show();
    void top();
    void tam();
};

template<typename T>
Pila<T>::Pila(){
    inicio = NULL;
}

template<typename T>
void Pila<T>::push(){
    int valor;
    Nodo<T> *aux = new Nodo<T>(valor);
    cout<<"Ingresa un valor: ";
    cin>>valor;
    aux->dato = valor;
    aux->next = NULL;
    if(inicio != NULL)
        aux->next=inicio;
    inicio=aux;
    cout<<"Nuevo valor insertado en  la pila!\n";
}

template<typename T>
void Pila<T>::pop(){
    Nodo<T> *temp;
    if(inicio == NULL){
        cout<<"\nLa pila esta vacia! \n\n";
    }
    else{
        temp = inicio;
        inicio = inicio->next;
        cout<<"\nEl valor eliminado es: "<<temp->dato<<"\n"<<endl;
        delete temp;
    }
}

template<typename T>
void Pila<T>::show(){
    Nodo<T> *aux1 = inicio;
    if(inicio == NULL){
        cout<<"\nLa pila esta vacia!\n\n";
    }
    else{
        cout<<"Pila:\n"<<endl;
        while(aux1 != NULL){
            cout<<aux1->dato<<"\n"<<endl;
            aux1 = aux1->next;
        }
    }
}

template<typename T>
void Pila<T>::top(){
    Nodo<T> *aux1 = inicio;
    if(inicio == NULL){
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
    if(inicio == NULL){
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
///CLASE COLA
template<typename T>
class Cola{
    Nodo<T> *adelante;
    Nodo<T> *atras;
public:
    Cola();
    void insertar();
    void eliminar();
    void mostrar();
};

template<typename T>
Cola<T>::Cola(){
    adelante = NULL;
    atras = NULL;
}

template<typename T>
void Cola<T>::insertar(){
    int valor;
    cout<<"Ingrese una valor:";
    cin>>valor;
    Nodo<T> *aux = new Nodo<T>(valor);
    aux->dato = valor;
    aux->next = NULL;
    if(adelante == NULL){
        adelante = aux;
    }
    else{
        atras->next = aux;
    }

    atras = aux;
    cout<<"Nuevo valor insertado en la cola!\n";
}

template<typename T>
void Cola<T>::eliminar(){
    int numero;
    Nodo<T> *aux = adelante;
    numero = aux->dato;
    if(adelante == NULL){
        cout<<"\nLa cola esta vacia! \n\n";
    }
    else{
        adelante = adelante->next;
        cout<<"\nEl valor eliminado es: "<<aux->dato<<"\n"<<endl;
    }
    delete aux;
}

template<typename T>
void Cola<T>::mostrar(){
    Nodo<T> *aux = adelante;
    if(adelante == NULL){
        cout<<"\nLa cola esta vacia!\n\n";
    }
    else{
        cout<<"Cola:\n"<<endl;
        while(aux != NULL){
            cout<<aux->dato<<"\n"<<endl;
            aux = aux->next;

        }
    }
}

int main(){
    Pila<int> pila;
    Cola<int> cola;
    int opcion;
    while(1){
        cout<<"---- Pila en lista enlazada ----"<<endl;
        cout<<"1.Push"<<endl;
        cout<<"2.Pop"<<endl;
        cout<<"3.Show"<<endl;
        cout<<"4.Top"<<endl;
        cout<<"5.Tamaño"<<endl;
        cout<<"---- Cola en lista enlazada ----"<<endl;
        cout<<"6.Insertar Cola"<<endl;
        cout<<"7.Eliminar Cola"<<endl;
        cout<<"8.Mostrar Cola"<<endl;
        cout<<"9.Salir"<<endl;
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
            cola.insertar();
            break;
        case 7:
            cola.eliminar();
            break;
        case 8:
            cola.mostrar();
            break;
        case 9:
            return 0;
            break;
        default:
            cout<<"Por favor ingrese una opcion correcta.\n";
            break;
        }
    }
    return 0;
}
