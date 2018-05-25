#include <iostream>
#include <string>
using namespace std;

template<typename T> class Lista;
template<typename T>
class Nodo
{
	friend class Lista<T>;
	T valor;
	Nodo<T>*next;
	public:
		Nodo(T &datos):valor(datos), next(0){};
		T getValor(){return valor;};
};


template<typename T>
class Lista
{
	Nodo<T> *first;
	Nodo<T> *last;
	Nodo<T> *nuevoNodo(T &);	
	public:
		Lista();
		~Lista();
		void pushFrente(T &);
		void pushFinal(T &);
		bool popFrente( T &);
		bool popFinal(T &);
		bool isEmpty();
		void print();
};

template<typename T>
Lista <T>::Lista() 
{
	first=0;
	last=0;
}

template<typename T>
Lista <T>:: ~Lista()
{
	if(!isEmpty())
	{
		Nodo <T>*actual=first;
		Nodo<T>*temp;
		while(actual!= 0)
		{
			temp=actual;
			cout<<temp->valor<<endl;
			actual=actual->next;
			delete temp;
		}
	}
}

template <typename T>
void Lista<T>:: pushFrente(T &dato)
{
	Nodo<T>*nuevo = nuevoNodo(dato);
	if (isEmpty())
		first = last = nuevo;
	else
	{
		nuevo->next=first;
		first=nuevo;
	}
		
}
template <typename T>
void Lista<T>:: pushFinal(T &dato)
{
	Nodo< T>*nuevo = nuevoNodo(dato);
	if(isEmpty())
		first=last=nuevo;
	else
	{
		last->next=nuevo;
		last=nuevo;
	}
		
}

template <typename  T>
bool Lista<T>::popFrente(T &dato)
{
	if(isEmpty())
		return false;
	else
	{
		Nodo <T> *temp =first;
		if(first==last)
			first=last=0;
		else
		{
			first=first->next;
		}
			
		dato = temp->valor;
		delete temp;
		return true;
		
	}
		
}
template <typename  T>
bool Lista<T>::popFinal(T &dato)
{
	if(isEmpty())
		return false;
	else
	{
		Nodo <T> *temp=last;
		if(first==last)
			first=last=0;
		else
		{
		
			Nodo <T>*actual=first;
			while(actual->next != last)
				actual=actual->next;
				
		last=actual;
		actual->next=0;
		}
		dato=temp->valor;
		delete temp;
		return true;			
	}
}
template <typename  T>
bool Lista<T>::isEmpty()
{
	return first==0;
}

template <typename  T>
Nodo<T>*Lista<T>::nuevoNodo(T &dato)
{
	return new Nodo<T>(dato);
}
template <typename  T>
void Lista<T>::print()
{
	if (isEmpty())
	{
		cout<<"\n Lista Vacia"<<endl;
		return;
	}
		
	Nodo<T>*actual=first;
	cout<<"La lista es: ";
	while(actual!=0)
	{
		cout<< actual->valor<<" ";
		actual=actual->next;
	}
	cout<<endl;
}
void instrucciones()
{
	cout<<"Ingrese una opcion: "<<endl;
	cout<<" 1 pushFrente"<<endl;
	cout<<" 2 pushFinal"<<endl;
	cout<<" 3 popFrente"<<endl;
	cout<<" 4 popFinal"<<endl;
	cout<<" 5 salir"<<endl;
}

template<typename T>
void comprobar(Lista <T> &o, string &type)
{
	instrucciones();
	int op;
	T valor;
	do
	{	cout<<"\n ? ";
		cin>>op; 
		switch(op)
		{
			case 1:
				cout<< "Escriba tipo de dato "<<type<<": "; cin>>valor;
				o.pushFrente(valor);
				o.print();
				break;
			case 2:
				cout<< "Escriba tipo de dato "<<type<<": "; cin>>valor;
				o.pushFinal(valor);
				o.print();
				break;
			case 3:
				if (o.popFrente(valor))
					cout<< valor <<" se elimino de la lista"<<endl;
				o.print();
				break;
			case 4:
				if (o.popFinal(valor))
					cout<< valor <<" se elimino de la lista"<<endl;
				o.print();								
		}
	}while(op!=5);
}


int main()
{
	
	Lista<int> xsEnteros;
	string s="entero";
	comprobar(xsEnteros,s);


	return 0;
}
