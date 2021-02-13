#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>


using namespace std;

int main (){
	int acak, pilih;
	char lagi;
	srand(time(NULL));
	awal:
		acak =rand()%3;
	system("cls");
		cout <<"==========Permainan Batu Gunting Kertas==========\n\n";
		cout <<"\t===== PILIH =====\n";
		cout <<"[1]. Batu\n";
		cout <<"[2]. Kertas\n";
		cout <<"[3]. Gunting\n";
		cout <<"[4]. Keluar\n";
		cout <<"Input Pilihan : ";
		cin >>pilih;
		cout<<endl<<endl;
		
	//BAGIAN BATU	
	if (pilih == 1){
		cout <<"Pilihan Kamu adalah 'Batu' \n";
		if (acak == 0){
			cout<<"Pilihan Komputer\t : Batu\n\n";
			cout<<"\t-DRAW-\n\n";
			lagiS1E1:
				cout<<"Again (y/n)? ";cin>>lagi;
				cout<<endl;
					if(lagi =='y'){
							goto awal;
						}else if(lagi == 'n'){
							exit(0);
						}else{
							cout <<"Type Again!\n\n";
					goto lagiS1E1;
				}
				
		}else if(acak == 1){
			cout<<"Pilihan Komputer\t : Kertas\n\n";
			cout<<"\t-KAMU KALAH HAHAHA-\n\n";
			lagiS1E2:
				cout <<"Again(y/n)? ";cin>>lagi;
				cout<<endl;
				if(lagi == 'y'){
					goto awal;
				}else if(lagi == 'n'){
					exit(0);
				}else{
					cout <<"Type Again!\n\n";
					goto lagiS1E2;
				}
				
		}else if(acak == 2){
			cout<<"Pilihan Komputer\t : Gunting\n\n";
			cout <<"\t-KAMU MENANG NIH, SELAMAT YAA-\n\n";
			lagiS1E3:
				cout <<"Again(y/n)? ";cin>>lagi;
				cout<<endl;
				if(lagi == 'y'){
					goto awal;
				}else if(lagi == 'n'){
					exit(0);
				}else{
					cout<<"Type Again!\n\n";
					goto lagiS1E3;
				}
		}
	
			
	//BAGIAN KERTAS
	}else if (pilih == 2){
		cout <<"Pilihan Kamu adalah 'Kertas' \n";
		if (acak == 0){
			cout<<"Pilihan Komputer\t : Batu\n\n";
			cout<<"\t-KAMU MENANG NIH, SELAMAT YAA-\n\n";
			lagiS2E1:
				cout <<"Again(y/n)? ";cin>>lagi;
				cout<<endl;
				if(lagi == 'y'){
					goto awal;
				}else if(lagi == 'n'){
					exit(0);
				}else{
					cout<<"Type Again!\n\n";
					goto lagiS2E1;
				}
				
		}else if(acak == 1 ){
			cout<<"Pilihan Komputer\t : Kertas\n\n";
			cout<<"\t-DRAW-\n\n";
			lagiS2E2:
				cout<<"Again(y/n)? ";cin>>lagi;
				cout<<endl;
				if (lagi == 'y'){
					goto awal;
				}else if(lagi == 'n'){
					exit(0);
				}else{
					cout<<"Type Again!\n\n";
					goto lagiS2E2;
				}
				
		}else if(acak == 2){
			cout<<"Pilihan Komputer\t : Gunting\n\n";
			cout<<"\t-KAMU KALAH HAHAHA-\n\n";
			lagiS2E3:
				cout<<"Again(y/n)? ";cin>>lagi;
				cout<<endl;
				if (lagi == 'y'){
					goto awal;
				}else if(lagi == 'n'){
					exit(0);
				}else{
					cout<<"Type again!\n\n";
					goto lagiS2E3;
				}
		}
		
	
	
	//BAGIAN GUNTING
	}else if(pilih == 3){
		cout <<"Pilihan Kamu adalah 'Gunting' \n";
		if (acak == 0 ){
			cout<<"Pilihan Komputer\t : Batu\n\n";
			cout<<"\t-KAMU KALAH HAHAHA-\n\n";
			lagiS3E1:
				cout<<"Again(y/n)? ";cin>>lagi;
				if(lagi == 'y'){
					goto awal;
				}else if(lagi == 'n'){
					exit(0);
				}else{
					cout<<"Tupe again!\n\n";
					goto lagiS3E1;
				}
		}else if (acak == 1){
			cout<<"Pilihan Komputer\t : Kertas\n\n";
			cout<<"\t-KAMU MENANG NIH, SELAMAT YAA-\n\n";
			lagiS3E2:
				cout<<"Again(y/n)? ";cin>>lagi;
				if(lagi == 'y'){
					goto awal;
				}else if(lagi == 'n'){
					exit(0);
				}else{
					cout<<"Type Again!\n\n";
					goto lagiS3E2;
				}
		}else if (acak == 2){
			cout <<"Pilihan Komputer\t : Gunting\n\n";
			cout <<"\t-DRAW-\n\n";
			lagiS3E3:
				cout<<"Again(y/n)? ";cin>>lagi;
				if(lagi == 'y'){
					goto awal;
				}else if(lagi == 'n'){
					exit(0);
				}else{
					cout<<"Type Again!\n\n";
					goto lagiS3E3;
				}
		}
		
	//KELUAR
	}else if (pilih == 4){
		cout <<"TERIMAKASIH TELAH BERMAIN DAN TELAH MENGGUNAKAN PROGRAM INI! \n \n ";
		exit(0);
	}else{
		goto awal;
	} 
	
	cin.get();
	return 0;
	
			
}
