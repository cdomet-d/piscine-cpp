class Toto
{
private:
	int i;

public:
	Toto(int i); // Constructeur
};

int main(int, char**)
{
	Toto tableau[3]; 
}
class Toto
{
private:
// declarations sans intérêt
public:
// Toto(int i=3); // Constructeur
// par défaut !
};
int main(int, char**)
{
Toto tableau[3]; // Correct !
// tous les objets
// sont construits
// avec la valeur 3
}
P