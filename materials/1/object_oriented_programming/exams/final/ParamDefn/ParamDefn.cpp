#include <cstdio>
#include <iostream>
using namespace std;

#include "ParamDefn.h"

bool isValidValue(char *value) {
  for (int i = 0; i < strlen(value); i++) {
    if (value[i] == '#') {
      int j = i + 1;

      for (;; j++) {
        if (value[j] < '0' || value[j] > '9') {
          break;
        }
      }

      return !(j == i + 1);
    }
  }

  return false;
}

ParamDefn::ParamDefn(char *name, char *value) : SimpleDefn(name) {
  if (!isValidValue(value)) {
    throw "Value is not valid";
  } else {
    delete[] this->value;

    this->value = new char[strlen(value) + 1];
    strcpy(this->value, value);
  }
}

bool inArr(char **arr, int arrLen, char *str) {
  for (int i = 0; i < arrLen; i++) {
    if (strcmp(arr[i], str) == 0) {
      return true;
    }
  }

  return false;
}

int getElIndex(char **arr, int arrLen, char *str) {
  for (int i = 0; i < arrLen; i++) {
    if (strcmp(arr[i], str) == 0) {
      return i;
    }
  }

  return -1;
}

void ParamDefn::printValue() const {
  int arrLen = 0;
  char **arr = new char *[arrLen];

  for (int i = 0; i < strlen(value); i++) {
    if (value[i] == '#') {

      int argIndex = 0;

      arrLen++;
      arr[arrLen - 1] = new char[100];

      arr[arrLen - 1][argIndex] = '#';

      int j = i + 1;

      for (;; j++) {
        if (value[j] < '0' || value[j] > '9') {
          break;
        } else {
          argIndex++;
          arr[arrLen - 1][argIndex] = value[j];
        }
      }

      if (j == i + 1) {
        delete[] arr[arrLen - 1];
      }
    }
  }

  int onceArrLen = 0;
  char **onceArr = new char *[onceArrLen];

  for (int i = 0; i < arrLen; i++) {
    if (!inArr(onceArr, onceArrLen, arr[i])) {
      onceArr[onceArrLen] = new char[100];
      strcpy(onceArr[onceArrLen], arr[i]);

      onceArrLen++;
    }
  }

  char **onceArrVal = new char *[onceArrLen];

  for (int i = 0; i < onceArrLen; i++) {
    cout << "Enter value for " << onceArr[i] << ": ";

    char *val;
    cin >> val;

    onceArrVal[i] = new char[strlen(val) + 1];
    strcpy(onceArrVal[i], val);
  }

  // for (int i = 0; i < onceArrLen; i++) {
  //   cout << onceArrVal[i] << endl;
  // }

  int index = 0;

  for (int i = 0; i < strlen(value); i++) {
    if (value[i] == '#') {
      int j = i + 1;

      for (;; j++) {
        if (value[j] < '0' || value[j] > '9') {
          break;
        }
      }

      if (j != i + 1) {
        cout << onceArrVal[getElIndex(onceArr, arrLen, arr[index])];
        index++;

        i = j;
      }
    } else {
      cout << value[i];
    }
  }

  cout << endl;

  for (int i = 0; i < onceArrLen; i++) {
    delete[] onceArr[i];
    delete[] onceArrVal[i];
  }
  delete[] onceArr;
  delete[] onceArrVal;

  for (int i = 0; i < arrLen; i++) {
    delete[] arr[i];
  }
  delete[] arr;
}
