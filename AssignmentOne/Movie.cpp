#include "Movie.h"

Movie::Movie(int newMaxMovies) {
	maxMovies = newMaxMovies;
	noMovies = 0;
	movies = new MovieRec[maxMovies];

	ifstream fin("movie.data");

	if (!fin.is_open()) {
		cout << "movie.data failed to open" << endl;
		exit(-1);
	}
	for (int index = 0; index < maxMovies; index++) {
		if (fin.eof())
			break;

		fin >> movies[index].year;
		fin.ignore(80, '\n');
		getline(fin, movies[index].title);
		fin >> movies[index].duration;
		noMovies++;
	}
	fin.close();
}

int Movie::findMovies(string title) {
	for (int index = 0; index < noMovies; index++) {
		if (movies[index].title == title) {
			cout << "found";
			return index;
		}
	}
	cout << "Not Found";
	return -1;
}

void Movie::showMovies(string title) {
	bool found = false;

	for (int index = 0; index < noMovies; index++) {
		if (movies[index].title == title) {
			cout << "Year: " << movies[index].year << endl;
			cout << "Duration: " << movies[index].duration << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Movie not Found" << endl;
	}
}

int Movie::getNoMovies() {
	return noMovies;
}

void Movie::addMovie(int year, string title, double duration) {
	if (noMovies < maxMovies) {
		movies[noMovies].year = year;
		movies[noMovies].title = title;
		movies[noMovies].duration = duration;

		noMovies++;
	}
	else {
		cout << "Array is full" << endl;
	}
}

void Movie::writeMovies(ostream& fout) {
	for (int index = 0; index < noMovies; index++) {
		fout << movies[index].title << " " << movies[index].year << " " << movies[index].duration << endl;
	}
	fout << "Number of Movies: " << noMovies << endl;
}

