#pragma once
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

struct MovieRec {
	int year;
	string title;
	double duration;
};

class Movie {
	public:
		Movie(int newMaxMovies);
		void showMovies(string title);
		int getNoMovies();
		void addMovie(int year, string title, double duration);
		void writeMovies(ostream& fout);

	private:
		int maxMovies;
		int noMovies;
		MovieRec* movies;
		int findMovies(string);
		
};