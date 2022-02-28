#include "Translator.h"
#include "Model.h"
#include <iostream>
#include <cctype>
using namespace std;

Translator::Translator(){

}
Translator::~Translator(){

}
string Translator::translateEnglishWord(string eng){
  Model *m = new Model;
  string translation = "";
  for(int i = 0; i < eng.length();++i){
    if(eng[i] == eng[i+1]){
      translation += m -> translateDoubleCharacter(eng[i]);
      translation += eng[i];
      i++;
    }
    else{
      translation += m -> translateSingleCharacter(eng[i]);
    }
  }
  delete m;
  return translation;
}
string Translator::translateEnglishSentence(string sentence){
  string translation = "";
  string word = "";
  //Translator *t = new Translator;
  for(int i = 0; i < sentence.length(); ++i){
    while(sentence[i] != ' ' && sentence[i] != ',' && sentence[i] != '.' && sentence[i] != '!' && sentence[i] != '?' && sentence[i] != ';'){
      word += sentence[i];
      i++;
    }
    translation += translateEnglishWord(word);
    translation += sentence[i];
    word = "";
  }
  //delete m;
  return translation;
}
/*
boolean Translator::isVowel(char c){
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
    return true;
  }
  else{
    return false;
  }
}
*/
//Translation from tutnese to english
string Translator::translateTutWord(string tut){
  Model *m = new Model;
  string translation = "";
  for(int i = 0; i < tut.length();++i){
    if(tut[i] == 's' && tut[i+1] == 'q' && tut[i+2] == 'u' && tut[i+3] == 'a' && tut[i+4] == 't' /* && isVowel(tut[i+5])*/ ){
      i += 5;
      translation += tut[i];
    }
    else if(tut[i] == 's' && tut[i+1] == 'q' && tut[i+2] == 'u' && tut[i+3] == 'a'){
      i += 4;
      translation += tut[i];
    }
    translation += tut[i];

    if(tut[i] != 'a' && tut[i] != 'e' && tut[i] != 'i' && tut[i] != 'o' && tut[i] != 'u'){
      i += m -> skipChars(tolower(tut[i]));
    }
  }
  delete m;
  return translation;
}
string Translator::translateTutSentence(string tutSentence){
  string translation = "";
  string word = "";
  //Translator *t = new Translator;
  for(int i = 0; i < tutSentence.length(); ++i){
    while(tutSentence[i] != ' ' && tutSentence[i] != ',' && tutSentence[i] != '.' && tutSentence[i] != '!' && tutSentence[i] != '?' && tutSentence[i] != ';'){
      word += tutSentence[i];
      i++;
    }
    translation += translateTutWord(word);
    translation += tutSentence[i];
    word = "";
  }
  //delete m;
  return translation;
}
