#include <iostream>
using namespace std;

class Medico{
private:
  string nombreCom, especialidad;
  static int contadors;
  int numeroMed;
public:
  Medico(){

    this->numeroMed = ++contadors;
  }
  Medico(string nombreCom, string especialidad){
    this->contadors = 0;
    this->nombreCom = nombreCom;
    this->especialidad = especialidad;
  }
  string getNombreCom(){
    return this->nombreCom;
  }
  string getEspecialidad(){
    return this->especialidad;
  }
  void toString(){
    cout<<"Nombre Completo: "<<this->nombreCom<<'\n';
    cout<<"Especialidad: "<<this->especialidad<<'\n';
  }
  friend class Paciente;
};

class Paciente{
private:
  string nombreCom;
  int edad;
  string padecimiento;
  Medico *MedicoEspecialista;
  /* */
  int contador;
public:
  Paciente(){
    //this->contador =  4;//MedicoEspecialista->contador;
  }
  Paciente(string nombreCom, int edad, string padecimiento){
    //this->contador = MedicoEspecialista->contador;
    this->nombreCom = nombreCom;
    this->edad = edad;
    this->padecimiento = padecimiento;
  }
  string getNombreCom(){
    return this->nombreCom;
  }
  int getEdad(){
    return this->edad;
  }
  string getPadecimiento(){
    return this->padecimiento;
  }
  void asociarMedico(){
    MedicoEspecialista = new Medico();
    this->contador = MedicoEspecialista->numeroMed;
    cout<<"Medico Numero: "<<this->contador<<'\n';
    cout<<"Ingrese nombre completo del medico: "; cin>>MedicoEspecialista->nombreCom;
    cout<<"Ingrese especialidad: "; cin>>MedicoEspecialista->especialidad;
  }
  void toString(){
    cout<<"Nombre Completo: "<<this->nombreCom<<'\n';
    cout<<"Edad: "<<this->edad<<'\n';
    cout<<"Padecimiento: "<<this->padecimiento<<'\n';
    cout<<"\tDatos del Medico Especialista"<<'\n';
    MedicoEspecialista->toString();
  }
};

int main(){
  Paciente ObjPacienteA ("Juan Carlos G.", 25, "Gripe");
  Paciente ObjPacienteB ("Adriana Z.", 38, "Gastritis");

  ObjPacienteA.asociarMedico();
  ObjPacienteB.asociarMedico();

  ObjPacienteA.toString();
  ObjPacienteB.toString();
  return 0;
}
