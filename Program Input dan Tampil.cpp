#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	
	ofstream dataRegistrasi;
	ifstream dataTampil;
	bool sudah = false;
	string username, again, output;
	char choice;
	int jumlah = 0;
	
	string menampilkan; //untuk ifstream
	
	dataRegistrasi.open("reg.txt", ios::app);
	
	cout << "NB: masukkan username hanya satu kata\n\n";
	
	while(!sudah){
		
		cout << "Masukkan Username: ";
		getline(cin, username);
		cout << "again(yes)? ";
		getline(cin, again);
		cout << endl;
		
		dataRegistrasi << username << endl;
		if( again == "yes" ){
			sudah = true;
		}else {
			continue;
		}
	}
	dataRegistrasi.close();
	
	x:
		
	dataTampil.open("reg.txt");
	cout << "ingin menampilkan berapa username(y/n)? ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y'){
		
		while(!dataTampil.eof()){
			jumlah ++;
			dataTampil >> menampilkan;
			
		//	getline(dataTampil, menampilkan);
		//	output.append(menampilkan);
			
			cout << menampilkan << endl;
			
		}
		
		cout << "NB: username terakhir tidak dihitung\n";
		cout << "jumlah username anda adalah: " << jumlah-1 << endl;
		
	} else if (choice == 'n' || choice == 'N' ){
		
		exit(0);
	
	} else {
		goto x;
	}
	
	cin.get();
	return 0;
}
