 #include<iostream>
using namespace::std;

struct Nodo{
	long IDENT;
	char NOMBRE[40];
	int EST;
	float TARIFA;
	char DIAG[120];
	Nodo *SIG;
} *p, *q, *r, *cabeza, *FIN;

void REGISTRAR_PACIENTE_V1(){
	
	char seguir='s';
	
	while(seguir=='s'){
				
		//Pido un nodo
		Nodo* p = new Nodo();
		
		if(p==NULL){
			cout<<"No hay memoria disponible en el sistema...."<<endl;
		}else{
			//Llenamos el nodo
			cout<<"******REGISTRAR PACIENTE******"<<endl;
			
			cout<<"Introduzca Documento de identidad: ";
			cin>>p->IDENT;		
			cout<<"Introduzca Nombre: ";
			gets(p->NOMBRE);
			cout<<"Introduzca Estrato (Solo numero): ";
			cin>>p->EST;
			cout<<"Introduzca Diagnostico: ";
			gets(p->DIAG);
			
			//calculo de tarifa
			if(p->EST<=2){
				p->TARIFA=1000;
			}else{
				if(p->EST==3){
					p->TARIFA=1500;		
				}else{
					p->TARIFA=10000;
				}
			}
			 
			//Balanceamos el nodo
			p->SIG=NULL;
			 
			//es el primero nodo de la lista???
			if(cabeza==NULL){
				cabeza=p;
			}else{
				//recorremos la lista desde la cabeza hasta el ultimo nodo
				//para añadir al final el nuevo paciente a la lista.
				r=cabeza;
				
				while(r->SIG!=NULL){
					r=r->SIG;
				}
				//ahora el apuntador "r" apunta al ultimo nodo de la lista
				//entonces añado el nievo despues del ultimo
				r->SIG=p;		
			}
				 
		 }
			cout<<"Desea agregar otro registro de PACIENTE a la lista? s/n: ";
			cin>>seguir;		
	}
	
}

void REGISTRAR_PACIENTE_V2(){
	char seguir='s';
	
	while(seguir=='s'){
		
		//Pido un nodo
		Nodo* p = new Nodo();
		
		if(p==NULL){
			cout<<"No hay memoria disponible en el sistema...."<<endl;
		}else{
			//Llenamos el nodo
			cout<<"******REGISTRAR PACIENTE******"<<endl;
			
			cout<<"Introduzca Documento de identidad: ";
			cin>>p->IDENT;		
			cout<<"Introduzca Nombre: ";
			cin>>p->NOMBRE;
			cout<<"Introduzca Estrato (Solo numero): ";
			cin>>p->EST;
			cout<<"Introduzca Diagnostico: ";
			cin>>p->DIAG;
			
			//calculo de tarifa
			if(p->EST<=2){
				p->TARIFA=1000;
			}else{
				if(p->EST==3){
					p->TARIFA=1500;		
				}else{
					p->TARIFA=10000;
				}
			}
			
			if(cabeza==NULL){
				cabeza=p;
				FIN=p;
			}else{
				FIN->SIG=p;
				FIN=p;
			}
			
			cout<<"Desea agregar otro registro de PACIENTE a la lista? s/n: ";
			cin>>seguir;
		
		}
	}
}

void REGISTRAR_PACIENTE_V3(){
	
	//declaramos variables
	char encontro='n', seguir='s';
	int dato,cont=0;
	
	while(seguir=='s'){
		cout<<""<<endl;
		cout<<"*****REGISTRAR PACIENTE V3*****"<<endl;
		cout<<"Introduzca la identificacion: ";//guardamos la identificacion en una variable para despues buscarla
		cin>>dato;
		p=cabeza;
		encontro='n';
		cont=0;
		
		//recorremos la lista y buscamos el dato ingresado
		while(encontro=='n' && p!=NULL){
			cont=cont+1;
			
			if(dato==p->IDENT){
				encontro='s';
				cout<<"Este Paciente ya se encuentra registrado en la posicion #"<<cont<<endl;
			}else{
				p=p->SIG;
			}
		}
		
		//si el dato ingresado no se encuentra en la lista, creamos un nodo nuevo y lo ingresamos a la lista
		if(encontro=='n'){
			cout<<"Se a detectado un nuevo Paciente"<<endl;
			//Pido un nodo
			Nodo* p = new Nodo();
		
			if(p==NULL){
				cout<<"No hay memoria disponible en el sistema...."<<endl;
			}else{
				//Llenamos el nodo
				cout<<"******REGISTRAR PACIENTE NUEVO******"<<endl;
			
				p->IDENT=dato;
				cout<<"Documento de identidad: "<<p->IDENT<<endl;
					
				cout<<"Introduzca Nombre: ";
				cin>>p->NOMBRE;
				cout<<"Introduzca Estrato (Solo numero): ";
				cin>>p->EST;
				cout<<"Introduzca Diagnostico: ";
				cin>>p->DIAG;
			
				//calculo de tarifa
				if(p->EST<=2){
					p->TARIFA=1000;
				}else{
					if(p->EST==3){
						p->TARIFA=1500;		
					}else{
						p->TARIFA=10000;
					}
				}
			
				if(cabeza==NULL){
					cabeza=p;
					FIN=p;
				}else{
					FIN->SIG=p;
					FIN=p;
				}
			}
		}
		cout<<"Desea registrar otro paciente? s/n: ";
		cin>>seguir;	
	}
}

void CONSULTAR_HISTORIA_V1(){
	
	int dato,cont=0,pos;
	char encontro='n', seguir='s';
	
	while(seguir=='s'){
		cout<<"*****CONSULTAR HISTORIA*****"<<endl<<endl;
		cout<<"Introduzca la identificacion a consultar?: ";
		cin>>dato;
		p=cabeza;
		encontro='n';
		cont=0;
		
		while(encontro=='n' && p!=NULL){
			cont=cont+1;
			
			if(dato==p->IDENT){
				encontro='s';
				pos=cont;
			}else{
				p=p->SIG;
			}	
		}
		
		if(encontro=='s'){
			cout<<"Encontrado el paciente en la posicion "<<pos<<endl;
		}else{
			cout<<"El PACIENTE consultado NO esta en la lista........"<<endl;
		}
		
		cout<<"Desea consultar otro paciente? s/n: ";
		cin>>seguir;	
	}
}

void CONSULTAR_HISTORIA_V2(){
	
	char encontro='n', seguir='s';
	int dato,cont=0;
	
	while(seguir=='s'){
		cout<<""<<endl;
		cout<<"*****CONSULTAR HISTORIA V2*****"<<endl;
		cout<<"Digite la identificacion a consultar: ";
		cin>>dato;
		p=cabeza;
		encontro='n';
		cont=0;
		
		while(encontro=='n' && p!=NULL){
			cont=cont+1;
			
			if(dato==p->IDENT){
				encontro='s';
				cout<<"Encontrado el Paciente en la posicion #"<<cont<<endl;
			}else{
				p=p->SIG;
			}
		}
		
		if(encontro=='n'){
			cout<<"Ese ID no esta en la lista ......"<<endl;
		}
		
		cout<<"Desea consultar otro dato? s/n: ";
		cin>>seguir;	
	}
}

void mostrar(){
				cout<<"Identidifacion: "<<p->IDENT;
				cout<<"Diagnostico: "<<p->DIAG;
				cout<<"Estrato: "<<p->EST;
}

void ACTUALIZAR_INFORMACION_PACIENTE(){
	
	int dato,cont;
	char encontro, seguir='s';
	
	while(seguir=='s'){
		
		cout<<""<<endl;
		cout<<"*****ACTUALIZAR INFORMACION DEL PACIENTE*****"<<endl;
		cout<<"Introduzca la identificacion a actualizar: ";
		cin>>dato;
		
		p=cabeza;
		encontro='n';
		cont=0;
		
		while(p!=NULL){
			cont=cont+1;
			
			if(encontro=='n' && dato==p->IDENT){
				encontro='s';
				cout<<"Encontrado el Paciente en la posicion #"<<cont<<endl;
				cout<<"Identidifacion: "<<p->IDENT<<endl;
				cout<<"Diagnostico: "<<p->DIAG<<endl;
				cout<<"Estrato: "<<p->EST<<endl;
				
				cout<<"Digite su nuevo diagnostico: ";
				cin>>p->DIAG;
				cout<<"Digite su nuevo estrato: ";
				cin>>p->EST;
				
				if(p->EST<=2){
					p->TARIFA=1000;
				}else{
					if(p->EST==3){
						p->TARIFA=1500;		
					}else{
						p->TARIFA=10000;
					}
				}
				
				cout<<"*Datos actualizados correctamente!*"<<endl;
			}else{
				p=p->SIG;
			}
		}
		
		if(encontro=='n'){
			cout<<"Ese ID no está en la lista ......"<<endl;
		}
		
		cout<<"Desea actualiar otro dato? s/n: ";
		cin>>seguir;		
	}	
}

void RETIRAR_HISTORIA_DE_PACIENTE(){
	
	int dato;
	char seguir='s', encontro;
	
	while(seguir=='s'){
		cout<<""<<endl;
		cout<<"*****RETIRAR HISTORIA PACIENTE*****"<<endl;
		cout<<"Introduzca la Identificacion que desea retirar: ";
		cin>>dato;
		
		if(cabeza==NULL){
			cout<<"La lista está vacia";
		}else{
			p=cabeza;
			encontro='n';
			
			while(encontro=='n' && p!=NULL){
				if(p->IDENT==dato){
					encontro='s';
				}else{
					p=p->SIG;
				}
			}
			
			if(encontro=='n'){
				cout<<"No esta ese dato en la lista";
			}else{
				//Está en un ultimo nodo?
				if(p->SIG==NULL){//si, esta de ultimo
					
					//rojo
					//entonces ubicamos OTRO apuntador ANTES de p
					q=cabeza;
					while(q->SIG!=p){
						q=q->SIG;
					}
					//ya "q" está apuntando a un nodo ANTES de p, entonces
					//"Desengancho" el nodo al cual apunta p
					q->SIG=p->SIG;
					//y ahora "Libero" el nodo al cual apunta p
					delete p;
					cout<<"Borrado Satisfactoriamente!"<<endl;
					//rojo
					
				}else{
					//esta en el primer nodo?
					if(p=cabeza){//si, está en el PRIMERO
						cabeza=cabeza->SIG;
						//y ahora "Libero" el nodo al cual apuna p
						delete p;
						cout<<"Borrado Satisfactoriamente!"<<endl;
					}else{
						//esta en un nodo INTERMEDIO cualquiera
						
						//azul
						//entonces ubicamos OTRO apuntador ANTES de p
						q=cabeza;
						while(q->SIG!=p){
							q=q->SIG;
						}
						//ya "q" está apuntando a un nodo ANTES de p entonces
						//"Desengancho" el nodo al cual apunta p
						q->SIG=p->SIG;
						//y ahora "Libero" el nodo al cual apuna p
						delete p;
						cout<<"Borrado Satisfactoriamente!"<<endl;
					}
				}
			}		
		}
		cout<<"Desea borrar otro valor? [s/n]: ";
		cin>>seguir;
	}	
}

int main(){
//REGISTRAR_PACIENTE_V1();
//REGISTRAR_PACIENTE_V2();
REGISTRAR_PACIENTE_V3();
CONSULTAR_HISTORIA_V2();
//ACTUALIZAR_INFORMACION_PACIENTE();
//CONSULTAR_HISTORIA_V1();
//RETIRAR_HISTORIA_DE_PACIENTE();
//CONSULTAR_HISTORIA_V2();

return 0;
}
