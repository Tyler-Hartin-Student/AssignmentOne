#include "Movie.h"

int main() {
	Movie movie(50);
	movie.addMovie(2003, "Finding Nemo", 100);
	movie.addMovie(2001, "Shrek", 90);
	movie.addMovie(1995, "Toy Story", 81);

	cout << "Number of Movies loaded: " << movie.getNoMovies() << endl;
	cout << "All movies:" << endl;
	movie.writeMovies(cout);

	

	cout << "Searching for Movie in array" << endl;
	movie.showMovies("Inception");

	cout << "searching for a movie that is not in the array" << endl;
	movie.showMovies("Finding Nemo");

	ofstream fout("MovieList.txt");
	movie.writeMovies(fout);
	fout.close();

	
	system("pause");
}