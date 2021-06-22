#include <iostream>
#include <string>


using namespace std;

/*===================================KUMPULAN VARIABEL DAN STRUCT ============================================ */
int pilihMenu, peringatan = 0;
int iKaryawan = 0, dataDaftarKaryawan = 0, iBarang = 0, dataDaftarBarang = 0; //variabel global
bool validasi; 
string loginIDkwn, loginPSkwn, cariIDkwn; 

struct barangData{ //data barang
	string nama, exp;
	int harga;
}infoBarang[40];

struct karyawanData{ //data karyawan
	string id;
	string password;
	string name; 
	string tglLahir;
	string status;
	int gaji;
}infoKaryawan[40];

struct admin { //data admin
	string id = "admin";
	string pass = "pass";
}infoAdmin;
/*============================AKHIR KUMPULAN VARIABEL DAN STRUCT ============================================ */
	


/*===================================KUMPULAN PROSEDUR DAN FUNCTION DARI ADMIN=============================== */
void tampilkanLoginAdmin(){ //prosedur tampilan login bagi admin
	cout << endl << endl;
	cout << "\t\t\t\tHALAMAN LOGIN ADMIN     \n";
	loginAdmin:
	cout << "\t\t\t\tID   : "; cin >> infoAdmin.id;
	cout << "\t\t\t\tPASS : "; cin >> infoAdmin.pass;
	
	if (infoAdmin.id == "admin" && infoAdmin.pass == "pass"){
		cout << "\t\t\t\tBerhasil Login!      \n";
	} else {
		++peringatan;
		
		if (peringatan <= 2) {
			cout << "\t\t\t\t[X] ID atau Pass anda salah!                 \n";
			goto loginAdmin;
		} else if (peringatan == 3) {
			cout << "\t\t\t\t[X] ID atau Password anda salah!             \n";
			cout << "\t\t\t\tAkses Login Ditolak                          \n"; 
			exit(0);
		}
	}
}

void karyawanBaru(){ //prosedur daftar karyawan baru
	cout << endl << endl;
	dataDaftarKaryawan ++;
	cout << "\t\t\tPENDAFTARAN KARYAWAN BARU     \n";
	cout << "\t\t\tID    Format : KRW01          \n";
	cout << "\t\t\tLAHIR Format : yyyy-mm-dd     \n";
	ulang:
	for (iKaryawan; iKaryawan < dataDaftarKaryawan; iKaryawan++){	
		cout << "\t\t\t===================================\n";
		cout << "\t\t\t[" << iKaryawan+1 << "]ID     : "   ; cin >> infoKaryawan[iKaryawan].id;
		cout << "\t\t\tPASS      : "                       ; cin >> infoKaryawan[iKaryawan].password; 
		/* */							                     cin.ignore();
		cout << "\t\t\tNAMA      : "                       ; getline(cin, infoKaryawan[iKaryawan].name); 
		cout << "\t\t\tLAHIR     : "                       ; cin >> infoKaryawan[iKaryawan].tglLahir; 
		cout << "\t\t\tGAJI      : Rp. "                   ; cin >> infoKaryawan[iKaryawan].gaji; 
		cout << "\t\t\tSTATUS    : "                       ; cin >> infoKaryawan[iKaryawan].status; 
		/* */							                     
		cout << "\t\t\t===================================\n";
	}
	
}
	

void updateDataKaryawan(){ //prosedur update data karyawan
	cout << "\n\n";
	int i = 0;
	cout << "\t\t\tUPDATE DATA KARYAWAN   BY ID    \n";
	cout << "\t\t\tINPUT ID : "                       ; cin >> loginIDkwn;
	for (i; i < dataDaftarKaryawan; i++){ //pencarian ID 
		if (infoKaryawan[i].id == loginIDkwn){
			cout << "\t\t\tID DITEMUKAN            \n";
			validasi = true;
			break;
		} 
	}
	if (validasi == true){ //name, password, status, 
	menuUbah:
		cout << "\t\t\tUBAH                        \n";
		cout << "\t\t\t[1]. NAMA                   \n";
		cout << "\t\t\t[2]. PASSWORD               \n";
		cout << "\t\t\t[3]. STATUS                 \n";
		cout << "\t\t\t[4]. GAJI                   \n";
		cout << "\t\t\tPilih Menu (1-4) : "; cin >> pilihMenu;
		cin.ignore();
		if (pilihMenu == 1){
			cout << "\t\t\tUBAH NAMA        : " <<         infoKaryawan[i].name << endl;
			cout << "\t\t\tMENJADI          : ";     getline(cin, infoKaryawan[i].name);
		} else if (pilihMenu == 2){
			cout << "\t\t\tUBAH PASSWORD    : " <<     infoKaryawan[i].password << endl;
			cout << "\t\t\tMENJADI          : ";        cin >> infoKaryawan[i].password;
		} else if (pilihMenu == 3){
			cout << "\t\t\tUBAH STATUS      : " <<       infoKaryawan[i].status << endl;
			cout << "\t\t\tMENJADI          : ";          cin >> infoKaryawan[i].status;
		} else if (pilihMenu == 4){
			cout << "\t\t\tUBAH GAJI        : Rp. " <<     infoKaryawan[i].gaji << endl;
			cout << "\t\t\tMENJADI          : Rp. ";        cin >> infoKaryawan[i].gaji;
		} else {
			goto menuUbah;
		}
	} else {
		cout << "\t\t\t[X]ID TIDAK DAPAT DITEMUKAN    \n";
	}
}


void tampilkanFullDataKaryawan(){ //prosedur menampilkan semua data karyawan
	cout << "\n\n"; 
	cout << "\t\t\tFULL DATA KARYAWAN               \n\n";
	if (dataDaftarKaryawan == 0){
		cout << "\t\t\t[X]DATA BELUM ADA                 \n";
	} else {
		for (int i = 0 ; i < dataDaftarKaryawan; i++){
			cout << "\t\t\tAKUN KE-" << i+1 <<endl;
			cout << "\t\t\t===========================================================================  \n";
			cout << "\t\t\t= ID       : " << infoKaryawan[i].id <<                                     "\n";
			cout << "\t\t\t= PASS     : " << infoKaryawan[i].password <<                               "\n";
			cout << "\t\t\t= NAMA     : " << infoKaryawan[i].name <<                                   "\n";
			cout << "\t\t\t= TGLLAHIR : " << infoKaryawan[i].tglLahir <<                               "\n";
			cout << "\t\t\t= STATUS   : " << infoKaryawan[i].status <<                                 "\n";
			cout << "\t\t\t= GAJI     : Rp. " << infoKaryawan[i].gaji <<                               "\n";
			cout << "\t\t\t===========================================================================  \n";
		}
	}
	
	
}

/* search karyawan dengan mencari ID*/
void cariKaryawan(){ //algoritma sequencial 
	int i = 0;
	cout << "\n\n";
	cout << "\t\t\tSEARCH DATA KARYAWAN BY ID          \n\n";
	cout << "\t\t\tINPUT ID : "                             ; cin >> cariIDkwn;
	for (i; i < dataDaftarKaryawan; i++){
		if(infoKaryawan[i].id == cariIDkwn){
			validasi = true;
			break;
		}
	}
	
	if (validasi == true){
		cout << "\t\t\t DATA KARYAWAN DITEMUKAN           \n";
		cout << "\t\t\t===========================================================================  \n";
		cout << "\t\t\t= ID       : " << infoKaryawan[i].id <<                                     "\n";
		cout << "\t\t\t= PASS     : " << infoKaryawan[i].password <<                               "\n";
		cout << "\t\t\t= NAMA     : " << infoKaryawan[i].name <<                                   "\n";
		cout << "\t\t\t= TGLLAHIR : " << infoKaryawan[i].tglLahir <<                               "\n";
		cout << "\t\t\t= STATUS   : " << infoKaryawan[i].status <<                                 "\n";
		cout << "\t\t\t= GAJI     : Rp. " << infoKaryawan[i].gaji <<                               "\n";
		cout << "\t\t\t===========================================================================  \n";
	} else {
		cout << "\t\t\t[X]DATA TIDAK DITEMUKAN             \n";
	}
}

/*===================================AKHIR KUMPULAN PROSEDUR DAN FUNCTION DARI ADMIN========================= */



/*===================================KUMPULAN PROSEDUR DAN FUNCTION DARI KARYAWAN============================ */
void tampilkanLoginKaryawan(){ //prosedur tampilan login untuk karyawan
	cout << endl << endl;
	
	if (dataDaftarKaryawan == 0){
		cout << "\t\t\tDATA AKUN KARYAWAN TIDAK ADA, SILAHKAN DAFTAR MELALUI ADMIN!!\n";
		validasi = false;
	} else {
		cout << "\t\t\t\tHALAMAN LOGIN KARYAWAN     \n";
		
		for (int i = 0; i < dataDaftarKaryawan; i++){
			cout << "\t\t\t\tID   : "                      ; cin >> loginIDkwn;
			cout << "\t\t\t\tPASS : "                      ; cin >> loginPSkwn;
			if (infoKaryawan[i].id == loginIDkwn && infoKaryawan[i].password == loginPSkwn){
				cout << "\t\t\t\tBerhasil Login!    \n";
				validasi = true;
				break;
			} else {
				if (peringatan == 2) {
					cout << "\t\t\t\t[X]ID atau Password anda salah!              \n";
				} else if (peringatan == 3) {
					cout << "\t\t\t\t[X] ID atau Password anda salah!             \n";
					cout << "\t\t\t\tAkses Login Ditolak                          \n";
					exit(0);
				}
			}
		}
	}

}


void barangBaru(){ //prosedur untuk input barang
	dataDaftarBarang ++;
	cout << "\n\n";
	cout << "\t\t\tINPUT DATA BARANG             \n\n";
	cout << "\t\t\tEXP Format : yyyy-mm-dd         \n";
	cin.ignore();
	for (iBarang ; iBarang < dataDaftarBarang; iBarang++){
		cout << "\t\t\t======================================================\n";
		cout << "\t\t\t" << iBarang+1 << ".>NAMA BARANG     : " ; getline(cin, infoBarang[iBarang].nama);											        
		cout << "\t\t\t   EXP             : "                   ; cin >> infoBarang[iBarang].exp;							 
		cout << "\t\t\t   HARGA           : Rp. "               ; cin >> infoBarang[iBarang].harga;
		cout << "\t\t\t======================================================\n";
	}
}


void filterHarga(){ //prosedur untuk filterharga buuble short (ascending dan descending)
	menuFilterHarga: 
	int tempDesc, tempAsc;
	string tempString;
	if (dataDaftarBarang == 0){
		cout << "\t\t\t[X] DATA BARANG TIDAK ADA ATAU KOSONG\n";
	} else {
		pilihMenuFilterHarga:
		cout << "\n\n";
		cout << "\t\t\tINPUT DATA BARANG             \n\n";
		cout << "\t\t\t[1]. Mahal - Murah              \n";
		cout << "\t\t\t[2]. Murah - Mahal              \n";
		cout << "\t\t\t[3]. Kembali                    \n";
		cout << "\t\t\tPilihan Menu (1-3) : "             ; cin >> pilihMenu;
		
		//MAHAL - MURAH (Descending)
		if (pilihMenu == 1){
			cout << "\t\t\tMAHAL - MURAH        \n";
			for (int i = 0; i <dataDaftarBarang; i++){ //proses bubble short Descending
				for (int k = i+1; k < dataDaftarBarang; k++){
					if (infoBarang[i].harga < infoBarang[k].harga){
						
						tempDesc = infoBarang[i].harga; // bagian harga
						infoBarang[i].harga = infoBarang[k].harga;
						infoBarang[k].harga = tempDesc;
						
						tempString = infoBarang[i].nama; //bagian nama
						infoBarang[i].nama = infoBarang[k].nama;
						infoBarang[k].nama = tempString;
						
						tempString = infoBarang[i].exp; //bagian exp
						infoBarang[i].exp = infoBarang[k].exp;
						infoBarang[k].exp = tempString;
					}
				}
			}
			cout << "\t\t\t===========================================================================  \n";
			for (int i = 0; i < dataDaftarBarang; i++){ //menampilkan hasil dari bubble short descending
				cout << "\t\t\tRp. " << infoBarang[i].harga << endl; //menampilkan nama,exp, dan harga
				cout << "\t\t\tNama : " << infoBarang[i].nama << endl;
				cout << "\t\t\tExp  : " << infoBarang[i].exp << endl;
			}
			cout << "\t\t\t===========================================================================  \n";
			
			//MURAH - MAHAL (Ascending)	
		} else if (pilihMenu == 2){
			cout << "\t\t\tMURAH - MAHAL        \n";
			for (int i = 0; i < dataDaftarBarang-1; i++){ //proses bubble short Ascending
				for (int k = 0; k < dataDaftarBarang-1-i; k++){
					if (infoBarang[k].harga > infoBarang[k+1].harga){
						tempAsc = infoBarang[k].harga; //bagian harga
						infoBarang[k].harga = infoBarang[k+1].harga;
						infoBarang[k+1].harga = tempAsc;
						
						tempString = infoBarang[k].nama; //bagian nama
						infoBarang[k].nama = infoBarang[k+1].nama;
						infoBarang[k+1].nama = tempString;
						
						tempString = infoBarang[k].exp; //bagian exp
						infoBarang[k].exp = infoBarang[k+1].exp;
						infoBarang[k+1].exp = tempString;
					}
				}
			}
			cout << "\t\t\t===========================================================================  \n";
			for (int i = 0; i < dataDaftarBarang; i++){ //menampilkan hasil dari bubble short Ascending
				cout << "\t\t\tRp. " << infoBarang[i].harga << endl; //menampilkan nama,exp, dan harga
				cout << "\t\t\tNama : " << infoBarang[i].nama << endl;
				cout << "\t\t\tExp  : " << infoBarang[i].exp << endl;
			}
			cout << "\t\t\t===========================================================================  \n";
			
			
		} else if (pilihMenu == 3){
			
		} else {
			goto menuFilterHarga;
		}
		
	}
}


void tampilkanFullDataBarang(){ //MENAMPILKAN SEMUA DATA BARANG 
	cout << "\n\n";
	cout << "\t\t\tINPUT DATA BARANG             \n\n";
	if (dataDaftarBarang == 0){
		cout << "\t\t\t[X]DATA BELUM ADA                 \n";
	} else {
		for (int i = 0 ; i < dataDaftarBarang; i++){
			cout << "\t\t\tBARANG KE-" << i+1 <<endl;
			cout << "\t\t\t===========================================================================  \n";
			cout << "\t\t\t= NAMA     : " << infoBarang[i].nama <<                                     "\n";
			cout << "\t\t\t= EXP      : " << infoBarang[i].exp <<                                      "\n";
			cout << "\t\t\t= HARGA    : " << infoBarang[i].harga <<                                    "\n";
			cout << "\t\t\t===========================================================================  \n";
		}
	}
}

/*=============================AKHIR KUMPULAN PROSEDUR DAN FUNCTION DARI KARYAWAN============================ */


/*===================================BAGIAN UTAMA DARI PROGRAM =============================================== */
int main(){ 
	pilihModeLogin:
	cout << endl << endl;
	cout << "\t\t\t\tPILIH MODE LOGIN      \n";
	/*   *TAMPILAN MODE  */
	cout << "\t\t\t\t[1]. Admin              \n";
	cout << "\t\t\t\t[2]. Karyawan           \n";
	cout << "\t\t\t\t[3]. Selesai            \n";
	cout << "\t\t\t\tInput (1-3) : "            ; cin >> pilihMenu;
	/*   *TAMPILAN AKHIR MODE  */



	if (pilihMenu == 1){ //menampilkan login admin
		tampilkanLoginAdmin(); //jika loginnya salah, maka program akan exit dan tampilan menu tidak ditampilkan
		
		/* TAMPILAN MENU ADMIN*/
		menuAdmin:
		cout << endl << endl;
		cout << "\t\t\t\tMENU ADMIN                  \n";
		cout << "\t\t\t[1]. Daftar Karyawan Baru     \n";
		cout << "\t\t\t[2]. Perbarui Data Karyawan   \n";
		cout << "\t\t\t[3]. Tampilkan Data Karyawan   \n";
		cout << "\t\t\t[4]. Cari Karyawan             \n";
		cout << "\t\t\t[5]. Logout                    \n";
		cout << "\t\t\tPilih Menu (1-5) : "              ; cin >> pilihMenu;
		if (pilihMenu == 1){ 
			karyawanBaru();
			goto menuAdmin;
		} else if (pilihMenu == 2){ 
			updateDataKaryawan();
			goto menuAdmin;
		} else if (pilihMenu == 3){
			tampilkanFullDataKaryawan();
			goto menuAdmin;
		} else if (pilihMenu == 4){
			cariKaryawan();
			goto menuAdmin;
		} else if (pilihMenu == 5){
			goto pilihModeLogin; //balik ke menu pilihan mode
		} else {
			goto menuAdmin;
		}
		/* AKHIR TAMPILAN MENU ADMIN */

		
		
	} else if (pilihMenu == 2){ 
		tampilkanLoginKaryawan(); //jika loginnya salah, maka program akan exit dan tampilan menu tidak ditampilkan
		
		
		if (validasi == true){
			/* MENU PILIHAN KARYAWAN */
			menuKaryawan:
				cout << "\n\n";
				cout << "\t\t\t\tMENU KARYAWAN               \n";
				cout << "\t\t\t[1]. Input Barang             \n";
				cout << "\t\t\t[2]. Filter Harga             \n";
				cout << "\t\t\t[3]. Tampilkan Data Barang    \n";
				cout << "\t\t\t[4]. Logout                   \n";
				cout << "\t\t\tPilih Menu (1-4) : "             ; cin >> pilihMenu;
				if (pilihMenu == 1){
					barangBaru();
					goto menuKaryawan;
				} else if (pilihMenu == 2){
					filterHarga();
					goto menuKaryawan;
				} else if (pilihMenu == 3){
					tampilkanFullDataBarang();
					goto menuKaryawan;
				} else if (pilihMenu == 4){
					goto pilihModeLogin; //balik ke menu pilihan mode
				} else {
					goto menuKaryawan;
				}
				/* AKHIR MENU PILIHAN KARYAWAN */
		} else {
			goto pilihModeLogin;
		}
		
		
	} else if (pilihMenu == 3){
		exit(0); 
	}else {
		goto pilihModeLogin;
	}
	
}
/*=============================AKHIR BAGIAN UTAMA DARI PROGRAM =============================================== */
