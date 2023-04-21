#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

struct Aluno 
{  
  string nome;
  double nota1, nota2, nota3, media;
};

int main() {

  ofstream fl;
  fl.open("meuArquivo.txt", ios::app);
  int ID_aluno = 1;
  while(true){
    char escolha;
    if (ID_aluno == 1){
      cout << "Deseja inserir um aluno? [y/n] " ;
    } else {
      cout << "Deseja inserir mais um aluno? [y/n] " ;
    }
    cin >> escolha;
    cin.ignore();
    double soma_notas = 0;
    if (escolha == 'y' || escolha == 'Y'){
      cout << "Digite o nome do " << ID_aluno << "o. aluno:" << endl;
      ID_aluno++;
      string nome_aluno;
      getline(cin, nome_aluno);
      fl << nome_aluno << endl;
      double nota_digitada;
      for (int i=0; i<3; i++){
        cout << "Digite a "<< i+1 << "a nota de " << nome_aluno <<": " << endl;
        cin >> nota_digitada;
        fl << nota_digitada << endl;
      }
    } else {
      fl.close();
      break;
    }
  }

  
  cout << fixed;
  cout.precision(2);
  
  map<int, Aluno>al;
  
  ifstream arquivo; //Cria uma variavel do tipo arquivo
  arquivo.open("meuArquivo.txt"); // Abre um arquivo para leitura

  string teste_nome;
  string teste_nome2;
  ID_aluno = 0;
  while (true) {
      arquivo >> teste_nome;
      if (teste_nome2 != teste_nome){
        teste_nome2 = teste_nome;
        al[ID_aluno].nome = teste_nome;

        arquivo >> al[ID_aluno].nota1;
        arquivo >> al[ID_aluno].nota2;
        arquivo >> al[ID_aluno].nota3;
        al[ID_aluno].media = (al[ID_aluno].nota1 + al[ID_aluno].nota2 + al[ID_aluno].nota3)/3;
        
      } else {
        break;
      }

    ID_aluno++;  
  
  }

  cout << endl;
    
  for (auto [i, aluno] : al) {
        cout << "Nome: " << aluno.nome << endl;
        cout << "Nota 1: " << aluno.nota1 << endl;
        cout << "Nota 2: " << aluno.nota2 << endl;
        cout << "Nota 3: " << aluno.nota3 << endl;
        cout << "Média: " << aluno.media << endl;
        cout << endl;
    }

  arquivo.close();
}