#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aluno {
private:
    string nome;
    int matricula;
    string dataNascimento;

public:
    Aluno(string _nome, int _matricula, string _dataNascimento) : nome(_nome), matricula(_matricula), dataNascimento(_dataNascimento) {}

    void obterInformacoes() const { 
        cout << "Nome: " << nome << endl;
        cout << "Matrícula: " << matricula << endl;
        cout << "Data de Nascimento: " << dataNascimento << endl;
    }

    int getMatricula() const { 
        return matricula;
    }
};

class Professor {
private:
    string nome;
    int codigoProfessor;
    string areaEspecializacao;

public:
    Professor(string _nome, int _codigoProfessor, string _areaEspecializacao) : nome(_nome), codigoProfessor(_codigoProfessor), areaEspecializacao(_areaEspecializacao) {}

    void obterInformacoes() const { 
        cout << "Nome: " << nome << endl;
        cout << "Código de Professor: " << codigoProfessor << endl;
        cout << "Área de Especialização: " << areaEspecializacao << endl;
    }
};


class Disciplina {
private:
    string nome;
    int codigoDisciplina;
    int cargaHoraria;

public:
    Disciplina(string _nome, int _codigoDisciplina, int _cargaHoraria) : nome(_nome), codigoDisciplina(_codigoDisciplina), cargaHoraria(_cargaHoraria) {}

    void obterInformacoes() const { 
        cout << "Nome: " << nome << endl;
        cout << "Código da Disciplina: " << codigoDisciplina << endl;
        cout << "Carga Horária: " << cargaHoraria << " horas" << endl;
    }
};

class Turma {
private:
    int codigoTurma;
    Disciplina disciplina;
    Professor professorResponsavel;
    vector<Aluno> alunosMatriculados;

public:
    Turma(int _codigoTurma, Disciplina _disciplina, Professor _professorResponsavel) : codigoTurma(_codigoTurma), disciplina(_disciplina), professorResponsavel(_professorResponsavel) {}

    void adicionarAluno(Aluno aluno) {
        alunosMatriculados.push_back(aluno);
    }

    void removerAluno(int matricula) {
        for (auto it = alunosMatriculados.begin(); it != alunosMatriculados.end(); ++it) {
            if (it->getMatricula() == matricula) {
                alunosMatriculados.erase(it);
                break;
            }
        }
    }

    void obterInformacoes() const { 
        cout << "Código da Turma: " << codigoTurma << endl;
        cout << "Disciplina: ";
        disciplina.obterInformacoes();
        cout << "Professor Responsável: ";
        professorResponsavel.obterInformacoes();
        cout << "Alunos Matriculados:" << endl;
        for (const auto& aluno : alunosMatriculados) {
            aluno.obterInformacoes(); 
        }
    }
};

int main() {
 
    Aluno aluno1("João", 12345, "01/01/2000");
    Aluno aluno2("Maria", 67890, "15/05/2001");

    Professor professor("Dr. Silva", 101, "Matemática");

    Disciplina disciplina("Matemática Básica", 201, 60);

    Turma turma(1, disciplina, professor);

    turma.adicionarAluno(aluno1);
    turma.adicionarAluno(aluno2);

    turma.obterInformacoes();

    return 0;
}
