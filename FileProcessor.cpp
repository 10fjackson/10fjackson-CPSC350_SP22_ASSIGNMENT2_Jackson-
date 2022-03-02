#include "Translator.h"
#include "Model.h"
#include "FileProcessor.h"
#include <iostream>
#include <fstream>
using namespace std;
FileProcessor::FileProcessor(){

}
FileProcessor::~FileProcessor(){

}
void FileProcessor::processFile(string fileName){
  string contents;
  string line;
  ifstream myfile(fileName);
  if(myfile.is_open()){
    while(getline(myfile,line)){
      contents += line;
    }
  }
  Translator *t = new Translator();
  string input;
  cout<<"Enter 'E2T' to translate an English file or 'T2E' to translate a Tutnese file"<<endl;
  cin>>input;
  if(input == "T2E"){
    cout<<t->translateTutSentence(contents)<<endl;
  }
  else if(input == "E2T"){
    cout<<t->translateEnglishSentence(contents)<<endl;
  }
  else{
    cout<<"Please enter 'E2T' for English to Tutnese translation or 'T2E' for Tutnese to English translation"<<endl;
  }
  delete t;
}
