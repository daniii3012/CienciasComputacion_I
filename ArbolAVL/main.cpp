/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/

#include <iostream>	
#include <stdlib.h>	
#include "Nodo.cpp"	
#include "ArbolAVL.h"	
#include "ArbolBinarioOrdenado.h"	

using namespace std;	
int comparar(int a, int b);	

template <class T>	
void verArbol( Node<T>* Node, int n){	
	if(Node==NULL)	
		return;	
	verArbol(Node->getRight(), n+1);	

	for(int i=0; i<n; i++)	
		cout<<"\t\t";	

	cout<< Node->getData() <<endl;	

	verArbol(Node->getLeft(), n+1);	
}	

 int main(int argc, char **argv) {	
	int (*fptr)(int, int);	
	fptr = comparar;	
	AVLTree<int>* avl = new AVLTree<int>(fptr);	
	
	while (1){
        cout << "1) Insertar" << endl;
        cout << "2) Eliminar" << endl;
        cout << "3) Imprimir" << endl;
        cout << "4) Salir" << endl;
        
        int opc, num;
        cout << "Ingrese una opcion: ";
        cin >> opc;
        
        switch(opc){
        case 1:
        	cout << "Ingrese un numero: ";
        	cin >> num;
        	avl -> add(num);
        	system("cls");
            break;
        case 2:
        	cout << "Ingrese un numero a eliminar: ";
        	cin >> num;
        	avl -> remove(num);
        	system("cls");
            break;
        case 3:
        	system("cls");
        	cout << "Inorden: ";	
			avl -> showInOrder();	
			cout << "Preorden: ";	
			avl -> showPreOrder();	
			cout << "Posorden: ";	
			avl -> showPostOrder();
			cout << endl;
			//cout << endl << "Por niveles" << endl;	
			//avl -> showPerLevel();
            break;
        case 4:
            exit(1);
        default:
            cout << "Ingrese una opcion correcta" << endl;
        }
    }
	return 0;	
}	

 int comparar(int a, int b) {	
 	int x;
 	if(a==b)
 		x=0;
 	if(a<b)
 		x=-1;
 	else 
 		x=1;
	return x;
}