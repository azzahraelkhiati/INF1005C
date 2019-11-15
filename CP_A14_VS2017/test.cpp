/**
*  Simples fonctions pour faire des tests unitaires.
*  \author Francois-R.Boyer@PolyMtl.ca
*  \date 2014-10
*  \file
*/
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h> // Pour SetConsoleTextAttribute

int nTests = 0, nTestsPasse = 0, nTestsCumulatif = 0, nTestsPasseCumulatif = 0;

std::streambuf* cinOriginal = std::cin.rdbuf();
std::streambuf* coutOriginal = std::cout.rdbuf();
std::stringbuf  cinPourTests("");
std::stringbuf  coutPourTests("");
static const HANDLE handleStderr = GetStdHandle(STD_ERROR_HANDLE);

std::ostream& couleurBon(std::ostream& o) {
	SetConsoleTextAttribute(handleStderr, 0x0A);
	return o;
}
std::ostream& couleurErreur(std::ostream& o) {
	SetConsoleTextAttribute(handleStderr, 0x0C);
	return o;
}
std::ostream& couleurAvertissement(std::ostream& o) {
	SetConsoleTextAttribute(handleStderr, 0x0E);
	return o;
}
std::ostream& couleurNormal(std::ostream& o) {
	SetConsoleTextAttribute(handleStderr, 0x07);
	return o;
}

class StreambufInterdit : public std::streambuf
{
private:
	// Surcharge des méthodes virtuelles de la classe de base:
	int_type underflow() {
		std::cerr << couleurErreur << "  Utilisation de 'cin' dans une fonction qui ne devrait pas.\n" << couleurNormal;
		return traits_type::eof();
	}
	int_type overflow(int c) {
		std::cerr << couleurErreur << "  Utilisation de 'cout' dans une fonction qui ne devrait pas.\n" << couleurNormal;
		return traits_type::eof();
	}
};
static StreambufInterdit streamInterdit;

template <typename T>
void affichageValeurTest(const T& valeur);

template <>
void affichageValeurTest(const std::string& valeur) {
	std::cerr << '"' << valeur << '"';
}

void simulerCinCout(const std::string& texte, bool coutInterdit)
{
	cinPourTests.str(texte);
	std::cin.clear();
	std::cin.rdbuf(texte.empty() ? (std::streambuf*)&streamInterdit : (std::streambuf*)&cinPourTests);
	
	coutPourTests.str("");
	std::cout.clear();
	std::cout.rdbuf(coutInterdit ? (std::streambuf*)&streamInterdit : (std::streambuf*)&coutPourTests);
}

void restaureCinCout()
{
	std::cin.clear();
	std::cin.rdbuf(cinOriginal);
	std::cout.clear();
	std::cout.rdbuf(coutOriginal);
}

void restaureCinCoutSiPasInterdit()
{
	if (std::cin.rdbuf() != &streamInterdit || std::cout.rdbuf() != &streamInterdit)
		restaureCinCout();
}

const std::string stringCoutDuTest()
{
	return coutPourTests.str();
}

void verifieCout(const std::string& reponsePrevue)
{
	restaureCinCoutSiPasInterdit();
	const std::string reponse = stringCoutDuTest();
	unsigned positionDansReponse = 0;
	unsigned positionDebut = 0;
	nTests++;
	while (positionDebut < reponsePrevue.length()) {
		unsigned positionFin = reponsePrevue.find_first_of('\n', positionDebut);
		if (positionFin == std::string::npos)
			positionFin = reponsePrevue.length();
		std::string aChercher = reponsePrevue.substr(positionDebut, positionFin - positionDebut);
		unsigned positionTrouvee = reponse.find(aChercher, positionDansReponse);
		if (positionTrouvee == std::string::npos) {
			std::cerr << "  " << couleurErreur << "N'a pas trouve" << couleurNormal << " '" << aChercher << "' dans '" << reponse.substr(positionDansReponse) << "'" << std::endl;
			return;
		}
		positionDansReponse = positionTrouvee + aChercher.length();
		positionDebut = positionFin + 1;
	}
	std::cerr << "  'cout' " << couleurBon << "correct." << couleurNormal << std::endl;
	nTestsPasse++;
}

static void affichageRatio(int numerateur, int denominateur) {
	if (numerateur == denominateur)
		std::cerr << couleurBon;
	else
		std::cerr << couleurErreur;
	std::cerr << numerateur << "/" << denominateur << couleurNormal;
}
void affichageStatistiquesTests() {
	restaureCinCout();
	nTestsCumulatif += nTests;
	nTestsPasseCumulatif += nTestsPasse;
	std::cerr << "  ";
	affichageRatio(nTestsPasse, nTests);
	std::cerr << " ont reussi (";	
	affichageRatio(nTestsPasseCumulatif, nTestsCumulatif);
	std::cerr << " cumulatif)." << std::endl << std::endl;
	nTests = nTestsPasse = 0;
}

//{ principalement de http://www.codeproject.com/Articles/71529/Exception-Injection-Throwing-an-Exception-in-Other
class ThreadAbort
{
	__declspec (noreturn) static void throw_();
public:
	static bool raiseInThread(HANDLE hThread); // Note that this will not work when thread is inside a blocking system function.
	static void dontOptimize() throw (...);
	static HANDLE currentThreadHandle();
};

__declspec (noreturn) void ThreadAbort::throw_()
{
	// just throw
	throw ThreadAbort();
}

void ThreadAbort::dontOptimize() throw (...)
{
	// By this awkward method we may convince the compiler that during the runtime
	// the exception *may* be thrown.
	// However it may not actually.
	volatile int i = 0;
	if (i)
		throw_();
}


bool ThreadAbort::raiseInThread(HANDLE hThread)
{
	bool ok = false;

	// Suspend the thread, so that we won't have surprises
	DWORD dwVal = SuspendThread(hThread);
	if (INFINITE != dwVal) {
		// Get its context (processor registers)
		CONTEXT ctx;
		ctx.ContextFlags = CONTEXT_CONTROL;
		if (GetThreadContext(hThread, &ctx)) {
			// Jump into our Throw() function
			ctx.Eip = (DWORD)(DWORD_PTR)throw_;

			if (SetThreadContext(hThread, &ctx))
				ok = true;
		}

		// go ahead
		ResumeThread(hThread);
	}
	return ok;
}

//}

bool estDansLeDebogueur = IsDebuggerPresent() != 0;

void fonctionDeLimiteDeTemps(HANDLE filAppelant, int limiteMillisecondes, volatile bool* aFini) {
	using std::chrono::milliseconds;
	using std::chrono::system_clock;

	system_clock::time_point endTime = system_clock::now() + milliseconds(limiteMillisecondes);
	while (!*aFini && system_clock::now() < endTime) {
		std::this_thread::yield(); //sleep_for(milliseconds(5));
	}
	if (!*aFini) {
		ThreadAbort::raiseInThread(filAppelant);
	}
	CloseHandle(filAppelant);
}

HANDLE descripteurDuFilActuel()
{
	// C++11 : 'thread_id' n'a pas de méthode 'native_handle', donc il n'y a pas moyen d'avoir un descripteur natif pour 'this_thread'; on utilise donc les fonctions de l'OS.
	HANDLE pseudoDescripteurDuFil = GetCurrentThread();
	HANDLE reelDescripteurDuFil;
	HANDLE descripteurDuProcess = GetCurrentProcess();
	DuplicateHandle(
		descripteurDuProcess, pseudoDescripteurDuFil,
		descripteurDuProcess, &reelDescripteurDuFil,
		0, FALSE, DUPLICATE_SAME_ACCESS);
	return reelDescripteurDuFil;
}

void tempsExpire(int numeroLigne, const std::string& texteA) {
	restaureCinCoutSiPasInterdit();
	std::cerr << "  " << numeroLigne << ": " << texteA << " : " << couleurErreur << "ne termine pas." << couleurNormal << std::endl;
}

static std::thread* filDeLimiteDeTemps = nullptr;

void terminerLimiteDeTemps() {
	if (filDeLimiteDeTemps) {
		filDeLimiteDeTemps->join();
		delete filDeLimiteDeTemps;
		filDeLimiteDeTemps = nullptr;
	}
}
void commencerLimiteDeTemps(int limiteMillisecondes, volatile bool& aFini) {
	terminerLimiteDeTemps();
	filDeLimiteDeTemps = new std::thread(fonctionDeLimiteDeTemps, descripteurDuFilActuel(), limiteMillisecondes, &aFini);
}
