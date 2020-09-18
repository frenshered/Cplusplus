#include <iostream>
using namespace std;

int main() {
  int arr[5];
  for (int i = 0; i < 5; i++) {
    cout << "Enter:" << endl;
    cin >> arr[i];
  }

  for (int i = 0; i < 5; i++) {
    cout << arr[i] << '\t';
  }

  int x;
  bool yes = false;
  cout << "Enter number for search in array: ";
  cin >> x;

  for (int i = 0; i < 5; i++) {
    if (x == arr[i]) {
      cout << "\nTrue" << endl;
      yes = true;
      break;
    }
  }

  if (yes == false) {
    cout << "False" << endl;
  }

  int ret;
  cout << "Return ?" << endl;
  cin >> ret;

  if (ret == 0) {
    main();
  }

  return 0;
}
