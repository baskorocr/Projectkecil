#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
using namespace std;

bool ketemu=false;
bool TempRegisAdmin=false;
int i, pil,x,pos,n=1, tempRegis=n,ubahData;
double topup,beli;
long int pin,id;
string LogUser;
string LogAdmin;


struct user
{
	char nama[50];
	char pass[50];
	string alamat;
	long int NomerID;
	double saldo;
};

struct admin
{
	string userAdmin;
	int pinAdmin;
};

struct obat
{
	char namaObat[50];
	char keterangan[30];
	double harga;
};

void UbahAdmin(admin &adm);
void BeliObat();
void CekListObat();
void AccTopup();
void TopUp();
void DataAkun(user &usr);
void UbahData();
void MenuAdmin();
void AdminProsesLogin();

	
	user usr[50];
	admin adm[10];
	obat obt[50];


int main()
{
	
	portal:
	system("cls");
	cout<<"Portal Menu"<<endl;
	cout<<"========================"<<endl;
	cout<<"1. Admin"<<endl;
	cout<<"2. User"<<endl;
	cout<<"Silakan Pilih: ";
	cin>>pil;
	if(pil==1)
	{	
		AdminProsesLogin();
	}
	else
	{

		menu:
			
			system("cls");
			cout<<" ____________________________________________________ "<<endl;
	        cout<<"|                   Apotek Online                    |"<<endl;
	        cout<<"|               Mitra Selamat Sentosa                |"<<endl;
	        cout<<"|            Jln. Tengku Imam Syahid No 5            |"<<endl;
	        cout<<"|____________________________________________________|"<<endl;
	        cout<<"|_____________________Menu User______________________|"<<endl;
	        cout<<"|    1. Pendaftaran User                             |"<<endl;
	        cout<<"|    2. Top Up Saldo                                 |"<<endl;
	        cout<<"|    3. Cek List Obat                                |"<<endl;
	        cout<<"|    4. Beli Obat                                    |"<<endl;
	        cout<<"|    5. Keluar                                       |"<<endl;
	        cout<<"|____________________________________________________|"<<endl;
	        cout<<" Pilihan Anda : "; cin>>pil;
	        
	        if(pil==1)
	        {
				lagi:
					system("cls");
					cout<<"Cek Ketersediaan ID : ";
					cin>>id;
					for (i=0; i<n; i++)
					{
						if(id==usr[i].NomerID)
						{
							ketemu=true;
						}
						else
						{
							ketemu=false;
						}
					}
					if(ketemu)
					{
						cout<<"ID anda Sudah terpakai, silakan cari lagi";
						getch();
						goto lagi;
					}
					else
					{	
						cout<<"ID Anda pilih kosong  dan sudah kami daftarkan"<<endl;
						cout<<"Masukan Nama Anda : ";
						cin>>usr[n].nama;
						cout<<"Masukan Password Akun anda : ";
						cin>>usr[n].pass;
						cout<<"Masukan alamat anda : ";
						cin>>usr[n].alamat;
					}
					n=n+1;
					usr[i].NomerID=id;
					goto menu;
			}
			if(pil==2)
	        {

				
			}
			if(pil==3)
	        {
	        	
			}
			if(pil==4)
	        {
	        	
			}
			if(pil==5)
			{
				cout<<"Anda Keluar aplikasi";
				ketemu=true;
				main();
			}
		}
	
	
}

void AdminProsesLogin()
{
		if(ketemu==false)
		{
			adm[0].userAdmin="admin";
			adm[0].pinAdmin=1234;
			cout<<"Masukan default Username Admin : ";
			cin>>LogAdmin;
			cout<<"Masukan default Pin Admin : ";
			cin>>pin;
			if(LogAdmin==adm[0].userAdmin && pin==adm[0].pinAdmin)
			{	
				system("cls");
				UbahAdmin(adm[0]);
				ketemu=true;
				main();
				
			}
			else
			{
				cout<<"Admin Default salah, silakan Kontak : Developer";
				getch();
				main();
				
			}
		}
		else
		{
			system("cls");
			cout<<"Login Admin"<<endl;
				cout<<"========================"<<endl;
		        cout<<"Masukan Username : ";
	        	cin>>LogAdmin;
	        	cout<<"Masukan Pin : ";
	        	cin>>pin;
	        	
		        	if(LogAdmin==adm[0].userAdmin && pin==adm[0].pinAdmin)
		        	{
		        		kembali:
		        		system("cls");
		        		MenuAdmin();
		        		
					}
					else
					{
						cout<<"gagal";
						main();
					}
					
					
		}
}

void UbahAdmin(admin &adm)
{	
	cout<<"Ubah data Admin"<<endl;
	cout<<"========================"<<endl;
	cout<<"Masukan Username Anda : ";
	cin>>adm.userAdmin;
	cout<<"Masukan Pin Admin: ";
	cin>>pin;		
	adm.pinAdmin=pin;
}

void DataAkun(user &usr)
{
	cout<<"Nama : "<<usr.nama<<endl;
}

void TopUp()
{
	
}
void AccTopup()
{
	
}
void CekListObat()
{
	
}
void BeliObat()
{
	
}

void MenuAdmin()
{			
			admin:
			system("cls");
			cout<<" ____________________________________________________ "<<endl;
	        cout<<"|                   Apotek Online                    |"<<endl;
	        cout<<"|               Mitra Selamat Sentosa                |"<<endl;
	        cout<<"|            Jln. Tengku Imam Syahid No 5            |"<<endl;
	        cout<<"|____________________________________________________|"<<endl;
	        cout<<"|_____________________Menu Admin_____________________|"<<endl;
	        cout<<"|    1. Acc TopUp Saldo                              |"<<endl;
	        cout<<"|    2. Input Obat                                   |"<<endl;
	        cout<<"|    3. Acc pesan Obat                               |"<<endl;
			cout<<"|    4. Keluar                                       |"<<endl;	        
	        cout<<"|____________________________________________________|"<<endl;
	        cout<<endl;
	        cout<<"Masukan Pilihan anda : ";
	        cin>>pil;
	        if(pil==1)
	        {
	        	
			}
			if(pil==2)
	        {
	        	
			}
			if(pil==3)
	        {
	        	
			}
			if(pil==4)
	        {
	        	getch();
	        	main();
			}


}


