#include <iostream>
using namespace std;

class Nodo
{
	public:
		int dato;
		Nodo *next;
		Nodo():dato(0), next(NULL){}
		Nodo(int d): dato(d), next(NULL){}
		Nodo(Nodo* lista): dato(lista->dato),next(lista->next){};
};
class Lista_en : public Nodo
{
	public:
		Nodo* xs;
		Lista_en(): xs(NULL){}
		Lista_en(int valor)
		{
			Nodo *n=new Nodo(valor);
        	xs=n;	
		}
	
		void Insertar(int valor)
		{
			Nodo *nuevo_nodo= new Nodo(valor);
			Nodo* aux1;
			Nodo* aux2;
			aux1=xs;
			
			if (xs==aux1)
				xs=nuevo_nodo;
			else
				aux2->next=nuevo_nodo;
			nuevo_nodo->next=aux1;
		}
		void mostrar()
		{
			while(xs!=NULL)
			{
				cout << xs->dato<<endl;
				xs=xs->next;
			}
		}

		void eliminar()
		{
			if (xs==NULL)
				cout<<"No hay elementos..."<<endl;
			else
			{
				Nodo* anterior;
				Nodo* posterior=xs;
				Nodo* temp;
				int valor;
				mostrar();
				cout<<"Elemento a eliminar: "; cin>>valor;
				while(posterior!=NULL)
				{
					if (posterior->dato== valor)
					{
						temp=posterior->next;
						delete posterior;
						anterior->next=temp;
						xs=anterior;
						break;						
					}
					else
					{
						anterior=posterior	;
						posterior=posterior->next;
						
					}		
				}
				mostrar();
			}
		}		
};

int main()
{
	Lista_en l;
	l.Insertar(3);
	l.Insertar(4);
	l.Insertar(5);
	l.eliminar();
	cout <<"\n"<< "ok";
	return 0;
}
