#include "prim.cpp"

using namespace std;

int main(int argc, char *argv[]) {
  ifstream infile1("inputFile1.txt");
  ifstream infile2("inputFile2.txt");
  ofstream outfile1("outputFile1.txt");
  ofstream outfile2("outputFile2.txt");

  prim(infile1, outfile1);
  bellman(infile2, outfile2);

  outfile1.close();
  outfile2.close();

  return 0;
}